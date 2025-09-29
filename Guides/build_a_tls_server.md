# Building a Simple TLS Server

This example demonstrates how to create a secure TCP server that listens for incoming connections using Transport Layer Security (TLS). Just like a TLS client, a TLS server is essential for establishing an encrypted connection, protecting sensitive data as it's transmitted over the network.

```cpp
#include <nodepp/nodepp.h>
#include <nodepp/tls.h>

using namespace nodepp;

void onMain(){


    ssl_t ssl; //( "./ssl/cert.key", "./ssl/cert.crt" );

    auto server = tls::server( &ssl );

    server.onConnect([=]( ssocket_t cli ){

        console::log("connected to:", cli.get_fd());

        cli.onData([=]( string_t data ){
            console::log( data );
        });

        cli.onClose([=](){
            console::log("closed");
        });

        cli.write("Hello World!");
        stream::pipe( cli );

    });

    server.listen( "localhost", 8000, []( ssocket_t srv ){
        console::log("-> tls://localhost:8000 <-");
    });

}
```
