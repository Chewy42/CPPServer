#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>
#include <boost/asio.hpp>
#include <iostream>
#include <string>

namespace beast = boost::beast;         // from <boost/beast.hpp>
namespace http = beast::http;           // from <boost/beast/http.hpp>
namespace net = boost::asio;            // from <boost/asio.hpp>
using tcp = net::ip::tcp;               // from <boost/asio/ip/tcp.hpp>

// This function produces an HTTP response for the given request.
http::response<http::string_body> handle_request(http::request<http::string_body> const& req) {
    if (req.target() == "/hello-world" && req.method() == http::verb::get) {
        http::response<http::string_body> res{http::status::ok, req.version()};
        res.set(http::field::server, "Boost.Beast");
        res.set(http::field::content_type, "text/plain");
        res.body() = "Hello, World!";
        res.prepare_payload();
        return res;
    } else {
        http::response<http::string_body> res{http::status::not_found, req.version()};
        res.set(http::field::server, "Boost.Beast");
        res.set(http::field::content_type, "text/plain");
        res.body() = "Resource not found";
        res.prepare_payload();
        return res;
    }
}

int main() {
    try {
        auto const address = net::ip::make_address("0.0.0.0");
        unsigned short port = 8080;

        net::io_context ioc{1};
        tcp::acceptor acceptor{ioc, {address, port}};
        tcp::socket socket{ioc};

        std::cout << "Server is running on port " << port << std::endl;

        acceptor.accept(socket);

        beast::flat_buffer buffer;
        http::request<http::string_body> req;
        http::read(socket, buffer, req);

        auto res = handle_request(req);
        http::write(socket, res);

        socket.shutdown(tcp::socket::shutdown_send);
    } catch (std::exception const& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}