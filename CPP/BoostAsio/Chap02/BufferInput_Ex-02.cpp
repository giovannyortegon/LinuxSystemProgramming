#include<boost/asio.hpp>
#include<iostream>
#include<memory>

using namespace boost;

int main() {
    const size_t BUF_SIZE_BYTES = 0;

    // Allocating the buffer
    std::unique_ptr<char[]> buf(new char[BUF_SIZE_BYTES]);

    // creating buffer representation
    asio::mutable_buffers_1 input_buf = asio::buffer(static_cast<void *>(buf.get()), BUF_SIZE_BYTES);

    return (0);
}