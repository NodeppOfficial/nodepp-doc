# Building a Simple HTTPS Server with Nodepp

An HTTPS server is a web server that uses TLS (Transport Layer Security) to encrypt all communications between the server and the client. This is crucial for securing data and ensuring user privacy. When a browser connects to an HTTPS server, a secure connection is established using a digital certificate, preventing eavesdropping and data tampering.

This guide demonstrates how to create a basic, non-blocking HTTPS server using the Nodepp framework. The server will listen on a specific port and respond to all incoming requests with an encrypted message.

```cpp
#include <nodepp/nodepp.h>
#include <nodepp/https.h>

using namespace nodepp;

void onMain(){

    ssl_t ssl; //( "./ssl/cert.key", "./ssl/cert.crt" );

    auto server = https::server([=]( https_t cli ){

        console::log( cli.path, cli.get_fd() );

        cli.write_header( 200, header_t({
            { "content-type", "text/html" }
        }));

        cli.write( "Welcome to Nodepp!" );
        cli.close();

    }, &ssl );

    server.listen( "localhost", 3000, [=]( ssocket_t server ){
        console::log("-> https://localhost:3000 <-");
    });

}
```
