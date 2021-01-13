#include "UtilCrypto.h"

#include <openssl/aes.h>
#include <bits/unique_ptr.h>
#include <sstream>
#include <iomanip>
#include <cstring>

#define in :
#define ref auto &
#define cref const auto &

util_crypto::CiphertextBlock util_crypto::base_encryption
(
        const PlaintextBlock & plaintext_block,
        const Key & key
)
{
    CiphertextBlock ciphertext_block;
    std::unique_ptr < AES_KEY > aes_key ( new AES_KEY () );

    AES_set_encrypt_key( key.data(), 128, aes_key.get() );
    AES_encrypt ( plaintext_block.data(), ciphertext_block.data(), aes_key.get() );

    return ciphertext_block;
}

util_crypto::PlaintextBlock util_crypto::base_decryption
(
        const CiphertextBlock & ciphertext_block,
        const Key & key
)
{
    PlaintextBlock plaintext_block;
    std::unique_ptr < AES_KEY > aes_key ( new AES_KEY () );

    AES_set_decrypt_key( key.data(), 128, aes_key.get() );
    AES_decrypt ( ciphertext_block.data(), plaintext_block.data(), aes_key.get() );

    return plaintext_block;
}

std::ostream & util_crypto::operator <<
(
        std::ostream & stream,
        const util_crypto::BasicBlock & block
)
{
    return ( stream << std::string ( block.begin(), block.end() ) );
}

util_crypto::BasicBlock util_crypto::from_string
(
        const std::string & string
)
{
    BasicBlock block;
    block.fill( 0 );

    for ( auto i = 0; i < std::min ( 16lu, string.length() ); i++ )
        block [i] = string [i];

    return block;
}

static bool is_character ( char c )
{
    return c >= 32 && c <= 126;
}

std::string util_crypto::to_string
(
        const BasicBlock & block,
        bool replace,
        char invalid_character_replacement
)
{
    std::string string ( block.begin(), block.end() );

    if ( ! replace )
        return string.append("\0");

    for ( ref character in string )
        if ( ! is_character( character ) )
            character = invalid_character_replacement;

    return string;
}

util_crypto::BasicBlock util_crypto::operator ^
(
        const BasicBlock & block_a,
        const BasicBlock & block_b
)
{
    BasicBlock block_c;

    for ( auto i = 0; i < block_c.size(); i++ )
        block_c [i] = block_a [i] ^ block_b [i];
    return block_c;
}

std::string util_crypto::to_hex_string
(
        const BasicBlock & block
)
{
    std::stringstream os;
    for ( auto byte in block )
        os << "0x" << std::hex << std::setfill('0') << std::setw(2) << static_cast < uint32_t > ( byte ) << ' ';

    return os.str();
}

std::list < util_crypto::BasicBlock > util_crypto::split
(
        const std::string & string
)
{
    std::list < util_crypto::BasicBlock > blocks;

    uint32_t len = std::strlen ( string.c_str() );
    for ( uint32_t i = 0lu, count = len/ 16; i < count; ++i )
    {
        blocks.emplace_back( );
        std::memcpy ( blocks.back().data(), string.data() + i * 16, 16 );
    }

    if ( len % 16 != 0 )
    {
        blocks.emplace_back( );
        std::memcpy ( blocks.back().data(), string.data() + len / 16 * 16, len % 16 );
    }

    return blocks;
}

std::string util_crypto::unify
(
        const std::list<BasicBlock> & blocks
)
{
    std::stringstream os;
    for ( ref block in blocks )
        os << block;
    return os.str();
}

std::string util_crypto::ecb_encryption
(
        const std::string & plaintext,
        const Key & key
)
{
    std::stringstream os;
    for ( cref block in split ( plaintext ) )
        os << base_encryption ( block, key );

    return os.str();
}

std::string util_crypto::ecb_decryption
(
        const std::string & ciphertext,
        const Key & key
)
{
    std::stringstream os;
    for ( cref block in split ( ciphertext ) )
        os << base_decryption ( block, key );

    return os.str();
}

std::string util_crypto::ofb_encryption
(
        const std::string & plaintext,
        const Key & key,
        const InitializationVector & initialization_vector
)
{
    std::stringstream os;
    InitializationVector iv = initialization_vector;

    for ( cref block in split ( plaintext ) )
        os << ( ( iv = base_encryption( iv, key ) ) ^ block );

    return os.str();
}

std::string util_crypto::ofb_decryption
(
        const std::string & ciphertext,
        const Key & key,
        const InitializationVector & initialization_vector
)
{
    return ofb_encryption( ciphertext, key, initialization_vector );
}