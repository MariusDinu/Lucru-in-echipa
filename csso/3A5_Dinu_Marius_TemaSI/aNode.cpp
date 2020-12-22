#include "UtilCrypto.h"
#include "UtilSocket.h"
#include <iostream>
#include <fstream>
#include <sstream>

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

    ServerSocket ss ( 35000 );

    auto node_socket = ss.accept();

    int chosen_mode = -1;
    cout << "Please select AES mode : (0 = ecb. 1 = ofb) : ";
    cin >> chosen_mode;
    while ( chosen_mode != ECB && chosen_mode != OFB )
    {
        cout << "Please select AES mode : (0 = ecb. 1 = ofb) : ";
        cin >> chosen_mode;
    }

    node_socket.write( chosen_mode );

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

    string file_path;
    string file_contents;
    ifstream input_stream;

    cout << "Input to be encrypted file path : ";
    cin >> file_path;

    input_stream.open (file_path.c_str() );

    while ( ! input_stream.is_open() )
    {
        cout << "Bad path. Input again : ";
        cin >> file_path;

        input_stream.open (file_path.c_str() );
    }

    input_stream.seekg (0, ios::end);
    file_contents.reserve ( static_cast < uint32_t > ( input_stream.tellg() ) );
    input_stream.seekg(0, ios::beg);

    stringstream stream;
    stream << input_stream.rdbuf();
    file_contents = stream.str();


    string encrypted_file_contents;

    if ( chosen_mode == ECB ) {
        encrypted_file_contents = ecb_encryption(file_contents, key);
        std::cout << ecb_decryption ( encrypted_file_contents, key );
    }
    else {
        encrypted_file_contents = ofb_encryption(file_contents, key, iv);
        std::cout << ofb_decryption ( encrypted_file_contents, key, iv );
    }

    node_socket.write( encrypted_file_contents );

    input_stream.close();

    ss.close();
    km_socket.close();
    node_socket.close();
}


