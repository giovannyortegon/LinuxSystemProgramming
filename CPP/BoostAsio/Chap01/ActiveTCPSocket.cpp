#include<boost/asio.hpp>
#include<iostream>

using namespace boost;

int main() {
    // socket constructor
    asio::io_service ios;
    // TCP protocol
    asio::ip::tcp protocol = asio::ip::tcp::v4();
    // Instancing Active TCP protocol
    asio::ip::tcp::socket sock(ios);
    // store error information
    boost::system::error_code ec;

    // open socket
    sock.open(protocol, ec);
    if (ec.value() != 0) {
        // Print error failed socket
        std::cout <<"Failed to open the socket! Error code = "
                  <<ec.value() <<". Message: " <<ec.message();

        return (ec.value());
    }
    return (0);
}