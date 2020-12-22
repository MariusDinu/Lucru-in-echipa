#ifndef DINUIS_UTILCRYPTO_H
#define DINUIS_UTILCRYPTO_H

#include <cstdint>
#include <array>
#include <cstdlib>
#include <list>
#include <ostream>

namespace util_crypto
{
    using BasicBlock            = std::array < uint8_t, 16 >;

    using Key                   = BasicBlock;
    using InitializationVector  = BasicBlock;
    using PlaintextBlock        = BasicBlock;
    using CiphertextBlock       = BasicBlock;

    CiphertextBlock base_encryption(const PlaintextBlock & plaintext_block,const Key & key);
    PlaintextBlock base_decryption(const CiphertextBlock & ciphertext_block,const Key & key);
    std::ostream & operator <<(std::ostream & stream,const BasicBlock & block);
    BasicBlock operator ^(const BasicBlock & block_a,const BasicBlock & block_b);
    std::list < BasicBlock > split(const std::string & string);
    std::string unify(const std::list < BasicBlock > & blocks);
    std::string ecb_encryption(const std::string & plaintext,const Key & key);
    std::string ecb_decryption(const std::string & ciphertext,const Key & key);
    std::string ofb_encryption(const std::string & plaintext,const Key & key,const InitializationVector & initialization_vector);
    std::string ofb_decryption(const std::string & ciphertext,const Key & key,const InitializationVector & initialization_vector);
    BasicBlock from_string(const std::string & string);
    std::string to_string(const BasicBlock & block, bool replace = true, char invalid_character_replacement = '.');
    std::string to_hex_string(const BasicBlock & block);
};


#endif //DINUIS_UTILCRYPTO_H
