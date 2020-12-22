#include "UtilCrypto.h"
#include "UtilSocket.h"


using namespace util_crypto;
using namespace util_socket;

enum Mode
{
    ECB = 0,
    OFB = 1
};

int main() {
    Key k3 = {
            0x34, 0x46, 0x98, 0xa9,
            0xce, 0xb1, 0x9e, 0xfa,
            0x4a, 0xb1, 0x0e, 0x11,
            0xe4, 0x4e, 0x71, 0xec
    };

    Key k1 = {
            0x91, 0x43, 0x5e, 0x6b,
            0x8c, 0xbe, 0xaf, 0xf3,
            0xf2, 0xe8, 0xc1, 0xcc,
            0x4f, 0xea, 0xa6, 0x61
    };

    Key k2 = {
            0x42, 0x9a, 0x91, 0x41,
            0xee, 0xf1, 0xf3, 0x45,
            0x81, 0x11, 0xa3, 0x89,
            0x15, 0xa6, 0x73, 0xc3
    };

    InitializationVector initialization_vector = {
            0x11, 0x10, 0x33, 0x22,
            0x44, 0x55, 0x66, 0x77,
            0x99, 0x88, 0xaa, 0xbb,
            0xee, 0xdd, 0xcc, 0xff
    };

    ServerSocket ss ( 34000 );

    auto first_socket = ss.accept();
    auto second_socket = ss.accept();

    auto first_mode = first_socket.read_int();
    auto second_mode = second_socket.read_int();

    if ( first_mode == ECB )
    {
        std::string encrypted_key = ecb_encryption( std::string ( k1.cbegin(), k1.cend() ), k3 );

        first_socket.write( encrypted_key );
        second_socket.write( encrypted_key );
    }
    else
    {
        std::string encrypted_key = ecb_encryption( std::string ( k2.cbegin(), k2.cend() ), k3 );
        std::string encrypted_iv = ecb_encryption( std::string ( initialization_vector.cbegin(), initialization_vector.cend() ), k3 );

        first_socket.write(encrypted_key);
        first_socket.write(encrypted_iv);

        second_socket.write(encrypted_key);
        second_socket.write(encrypted_iv);
    }

    first_socket.read_int();
    second_socket.read_int();

    first_socket.close();
    second_socket.close();
    ss.close();

    return 0;
}
