#include<iostream>
#include<boost/asio.hpp>

using namespace boost;

int main() {
    asio::io_service ios;
    asio::ip::udp protocol = asio::ip::udp::v6();
    asio::ip::udp::socket sock(ios);

    boost::system::error_code ec;

    sock.open(protocol, ec);
    if(ec.value() != 0) {
        std::cout <<"Failed to open the socket! Error code = "
                  <<ec.value() <<". Message: " <<ec.value();

        return (ec.value());
    }

    return (0);
}