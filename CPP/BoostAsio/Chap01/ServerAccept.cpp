#include<boost/asio.hpp>
#include<iostream>

using namespace boost;

int main() {
    // The size of the queue containing the pending connection
    // requests.
    const int BACKLOG_SIZE = 30;
    // obtain protocol port number
    unsigned short port_num = 3333;

    // creating a server endpoint
    asio::ip::tcp::endpoint ep(asio::ip::address_v4::any(), port_num);

    asio::io_service ios;

    try {
        // instantiating and opening an acceptor socket
        asio::ip::tcp::acceptor acceptor(ios, ep.protocol());

        // Binding the accpetor socket to the server endpoint
        acceptor.bind(ep);

        // starting to listen for incoming connection
        acceptor.listen(BACKLOG_SIZE);

        // creating an active socket
        asio::ip::tcp::socket sock(ios);

        // processing the next connection request
        // and connecting the active socket to the client
        acceptor.accept(sock);

        std::cout <<"Connected ..." <<std::endl;
    } catch (system::system_error &e) {
        std::cout <<"Error occured! Error code = " <<e.code()
                  <<". Message: " <<e.what();

        return e.code().value();
    }

    return (0);
}