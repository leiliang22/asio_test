// Wait a timer asynchronously.
// Use a lambda as the wait handler.
#include <iostream>

#define BOOST_ASIO_NO_DEPRECATED
#include "boost/asio.hpp"
#include "boost/core/ignore_unused.hpp"
#include "boost/date_time/posix_time/posix_time.hpp"

int main() {
    // Your program will have at least one io_context object, which represents your
    // program's link to the operating system's I/O services. 
    boost::asio::io_context io_context;

    // To perform I/O operations your program will need an I/O object such as a timer
    boost::asio::deadline_timer timer(io_context, boost::posix_time::seconds(3));

    //  a completion handler is a function or function object with the signature:
    // void handler(const boost::system::error_code& ec);
    timer.async_wait([](boost::system::error_code ec) {
        boost::ignore_unused(ec);
        std::cout << "Hello, World!" << std::endl;
    });
    
    // A call to io_context::run() blocks while there 
    // are unfinished asynchronous operations
    io_context.run();
    
    // While inside the call to io_context::run(), the io_context dequeues 
    // the result of the operation, translates it into an error_code, 
    // and then passes it to your completion handler. 
    
    return 0;
}
