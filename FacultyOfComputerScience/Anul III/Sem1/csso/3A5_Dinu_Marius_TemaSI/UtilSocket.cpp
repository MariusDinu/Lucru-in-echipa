#include "UtilSocket.h"
#include "arpa/inet.h"
#include <unistd.h>
#include <cstring>
#include <memory>
#include <stdexcept>
#include <bits/unique_ptr.h>

util_socket::Socket::Socket()
{
    this->raw_socket = socket ( AF_INET, SOCK_STREAM, 0 );
}

util_socket::Socket::Socket(RawSocket raw_socket)
{
    this->raw_socket = raw_socket;
}

void util_socket::Socket::close() const
{
    ::close ( this->raw_socket );
}

void util_socket::Socket::write(const std::string & message) const
{
    RawMessage raw_message;
    raw_message.fill( 0 );

    std::memcpy ( raw_message.data(), message.c_str(), message.length() );

    if ( -1 == ::write ( this->raw_socket, raw_message.data(), raw_message.size() ) )
        throw std::runtime_error ( "Write Error" );
}

void util_socket::Socket::write( int value ) const
{
    if ( -1 == ::write ( this->raw_socket, & value, sizeof ( value ) ) )
        throw std::runtime_error ( "Write Error" );
}

std::string util_socket::Socket::read_string() const
{
    RawMessage raw_message;

    switch ( ::read ( this->raw_socket, raw_message.data(), raw_message.size() ) )
    {
        case -1: throw std::runtime_error ( "Read Error" );
        case 0:  throw std::runtime_error ( "Read Disconnect" );
    }

    std::string message = std::string ( raw_message.cbegin(), raw_message.cend() );
    message.shrink_to_fit();
    return message.append("\0");
}

int util_socket::Socket::read_int () const
{
    int value = 0;
    switch ( ::read ( this->raw_socket, & value, sizeof ( value ) ) )
    {
        case -1: throw std::runtime_error ( "Read Error" );
        case 0:  throw std::runtime_error ( "Read Disconnect" );
    }
    return value;
}

bool util_socket::Socket::connect(const std::string & ip, uint16_t port) const
{
    sockaddr_in server_address;
    server_address.sin_addr.s_addr  = inet_addr ( ip.c_str() );
    server_address.sin_port         = port;
    server_address.sin_family       = AF_INET;

    return 0 == ::connect ( this->raw_socket, ( sockaddr * ) ( & server_address ), sizeof ( sockaddr_in ) );
}

util_socket::ServerSocket::ServerSocket(uint16_t port) : Socket ()
{
    sockaddr_in server_address;
    server_address.sin_addr.s_addr  = INADDR_ANY;
    server_address.sin_port         = port;
    server_address.sin_family       = AF_INET;

    int option = 1;
    setsockopt( this->raw_socket, SOL_SOCKET, SO_REUSEADDR, & option, sizeof ( int ) );

    if ( -1 == bind ( this->raw_socket, ( sockaddr * ) ( & server_address ), sizeof ( sockaddr_in ) ) )
        throw std::runtime_error ( "Bind Error" );

    if ( -1 == listen ( this->raw_socket, 1u << 6u ) )
        throw std::runtime_error ( "Listen Error" );
}

util_socket::Socket util_socket::ServerSocket::accept()
{
    return Socket ( ::accept ( this->raw_socket, std::make_unique< sockaddr > ( ).get(), std::make_unique< socklen_t > ( sizeof ( sockaddr ) ).get() ) );
}
