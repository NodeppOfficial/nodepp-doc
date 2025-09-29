# Building a Simple HTTP Server with Nodepp

An HTTP server is a fundamental component of web development, acting as the backbone for serving web content. It's a program that waits for client requests and responds with the appropriate data, such as HTML pages, images, or JSON. This example demonstrates how to create a basic, non-blocking HTTP server using the Nodepp framework.

This server will listen on a specific port and respond to every incoming request with a simple "Welcome to Nodepp!" message.

```cpp
#include <nodepp/nodepp.h>
#include <nodepp/http.h>

using namespace nodepp;

void onMain(){

    auto server = http::server([=]( http_t cli ){

        console::log( cli.path, cli.get_fd() );

        cli.write_header( 200, header_t({
            { "content-type", "text/html" }
        }));

        cli.write( "Welcome to Nodepp!" );
        cli.close();

    });

    server.listen( "localhost", 3000, [=]( socket_t server ){
        console::log("-> http://localhost:3000 <-");
    });

}
```
