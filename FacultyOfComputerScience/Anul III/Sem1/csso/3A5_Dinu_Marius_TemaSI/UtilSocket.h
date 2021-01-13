#ifndef DINUIS_UTILSOCKET_H
#define DINUIS_UTILSOCKET_H

#include <string>
#include <array>

namespace util_socket
{
    using RawSocket     = int;
    using RawMessage    = std::array < uint8_t, 1u << 16u >;

    class Socket
    {
    protected:
        RawSocket raw_socket;
    public:
        Socket ();
        Socket ( RawSocket raw_socket );

        void close () const;
        void write ( const std::string & message ) const;
        void write ( int value ) const;
        std::string read_string () const;
        int read_int () const;
        bool connect ( const std::string & ip, uint16_t port ) const;
    };

    class ServerSocket : public Socket
    {
    public:
        ServerSocket ( uint16_t port );
        Socket accept ();
    };
}

#endif //DINUIS_UTILSOCKET_H
