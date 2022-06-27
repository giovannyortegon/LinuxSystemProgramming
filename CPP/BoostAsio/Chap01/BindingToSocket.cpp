#include<boost/asio.hpp>
#include<iostream>

using namespace boost;

int main() {
    unsigned short port_num = 333;

    // Create an endpoint
    asio::ip::tcp::endpoint ep(asio::ip::address_v4::any(), port_num);
    // Used by accpetor class constructor
    asio::io_service ios;
    // Creating and opening an acceptor socket
    asio::ip::tcp::acceptor acceptor(ios, ep.protocol());

    boost::system::error_code ec;

    // Binding the acceptor socket
    acceptor.bind(ep, ec);
    if (ec.value() != 0) {  // Handing errors if any
        std::cout <<"Failed to bind the acceptor socket."
                  <<" Error code = " <<ec.value()
                  <<". Message: " <<ec.message() <<std::endl;

        return (ec.value());
    }

    return (0);
}