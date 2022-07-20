/* TCPClient.cpp */
#include<boost/asio.hpp>
#include<iostream>

using namespace boost;

int main(int argc, char * argv[]) {
    // std::string raw_ip_address = argv[1];
    std::string raw_ip_address = "127.0.0.1";
    // unsigned short port_num = argv[2];
    unsigned short port_num = 3333;

    try {
        asio::ip::tcp::endpoint ep(asio::ip::address::from_string(raw_ip_address),
                                   port_num);
        asio::io_service ios;

        // creating and opening a socket
        asio::ip::tcp::socket sock(ios, ep.protocol());
        // connecting a socket
        sock.connect(ep);
    } catch(system::system_error &e) {
        std::cout <<"Error occurred! Error code = " <<e.code()
                  <<". Message: " <<e.what();
        return (e.code().value());
    }

    return (0);
}