//
// Created by Yevhenii on 20/05/2019.
//

#ifndef BOOST_ACIO_EXAMPLE_CONNECTION_H
#define BOOST_ACIO_EXAMPLE_CONNECTION_H


#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <boost/noncopyable.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include "reply.h"
#include "request.h"
#include "request_handler.h"
#include "request_parser.h"

namespace http {
    namespace server3 {

/// Represents a single connection from a client.
        class connection
                : public boost::enable_shared_from_this<connection>,
                  private boost::noncopyable
        {
        public:
            /// Construct a connection with the given io_context.
            explicit connection(boost::asio::io_context& io_context,
                                request_handler& handler);

            /// Get the socket associated with the connection.
            boost::asio::ip::tcp::socket& socket();

            /// Start the first asynchronous operation for the connection.
            void start();

        private:
            /// Handle completion of a read operation.
            void handle_read(const boost::system::error_code& e,
                             std::size_t bytes_transferred);

            /// Handle completion of a write operation.
            void handle_write(const boost::system::error_code& e);

            /// Strand to ensure the connection's handlers are not called concurrently.
            boost::asio::strand<boost::asio::io_context::executor_type> strand_;

            /// Socket for the connection.
            boost::asio::ip::tcp::socket socket_;

            /// The handler used to process the incoming request.
            request_handler& request_handler_;

            /// Buffer for incoming data.
            boost::array<char, 8192> buffer_;

            /// The incoming request.
            request request_;

            /// The parser for the incoming request.
            request_parser request_parser_;

            /// The reply to be sent back to the client.
            reply reply_;
        };

        typedef boost::shared_ptr<connection> connection_ptr;

    } // namespace server3
} // namespace http

#endif //BOOST_ACIO_EXAMPLE_CONNECTION_H
