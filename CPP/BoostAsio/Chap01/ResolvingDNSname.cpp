#include<boost/asio.hpp>
#include<iostream>

using namespace boost;

int main() {
    // name and host
    std::string host = "samplehost.com";
    std::string port_num = "3333";

    asio::io_service ios;
    asio::ip::tcp::resolver::query resolver_query(host, port_num,
                                                  asio::ip::tcp::resolver::query::numeric_service);
    asio::ip::tcp::resolver resolver(ios);
    boost::system::error_code ec;

    asio::ip::tcp::resolver::iterator it = resolver.resolve(resolver_query, ec);

    if (ec.value() != 0) {
        std::cout <<"Failed to resolve a DNS name."
                  <<" Error code = " <<ec.value()
                  <<". Message = " <<ec.message();

        return (ec.value());
    }

    return (0);
}