#include<boost/asio.hpp>
#include<iostream>

using namespace boost;
using namespace std;

int main(){
    asio::streambuf buf;

    ostream output(&buf);

    // writting the message to the stream-based buffer
    output <<"Message1\nMessage2";

    // read all data from a streambuf
    istream input(&buf);

    // we'll read data into this string
    string message1;
    getline(input, message1);

    // now message1 string contains 'Message1';

    cout <<message1;

    string message2;

    return (0);
}