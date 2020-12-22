#include "UtilCrypto.h"
#include "UtilSocket.h"
#include <iostream>

using namespace util_crypto;
using namespace util_socket;
using namespace std;

enum Mode
{
    ECB = 0,
    OFB = 1
};

int main()
{
    Key k3 = {
            0x34, 0x46, 0x98, 0xa9,
            0xce, 0xb1, 0x9e, 0xfa,
            0x4a, 0xb1, 0x0e, 0x11,
            0xe4, 0x4e, 0x71, 0xec
    };

    Socket node_socket;
    if ( ! node_socket.connect("127.0.0.1", 35000))
    {
        std::cerr << "please start node A first\n";
        return 0;
    }

    auto chosen_mode = node_socket.read_int();

    Socket km_socket;

    km_socket.connect( "127.0.0.1", 34000 );

    km_socket.write( chosen_mode );

    Key key;
    InitializationVector iv;
    iv.fill(0);
    if ( chosen_mode == ECB )
    {
        key = from_string ( ecb_decryption ( km_socket.read_string(), k3 ) );
    }
    else
    {
        key = from_string ( ecb_decryption( km_socket.read_string(), k3 ) );
        iv = from_string ( ecb_decryption( km_socket.read_string(), k3 ) );
    }

    km_socket.write(1);
    cout << "Received Key : " << to_hex_string (key) << "\nReceived IV :  " << to_hex_string (iv) << '\n';
    cout << "Waiting to receive info from A...\n";

    auto ciphertext = node_socket.read_string();

    if ( chosen_mode == ECB )
        std::cout << ecb_decryption ( ciphertext, key ) << '\n';
    if ( chosen_mode == OFB )
        std::cout << ofb_decryption ( ciphertext, key, iv ) << '\n';

    km_socket.close();
    node_socket.close();
}

