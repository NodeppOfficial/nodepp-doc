# Building a Simple UDP Server

This example demonstrates how to create a basic User Datagram Protocol (UDP) server. As a connectionless protocol, UDP doesn't maintain an active connection with a client. Instead, it simply listens for incoming datagrams and responds to the sender. This makes it a great choice for applications where low latency is more important than guaranteed data delivery, such as video streaming or online games.

```cpp
#include <nodepp/nodepp.h>
#include <nodepp/udp.h>

using namespace nodepp;

void onMain(){

    auto server = udp::server();

    server.onConnect([=]( socket_t cli ){

        cli.onData([=]( string_t data ){
            console::log( data );
        });

        cli.onClose([=](){
            console::log("closed");
        });

        cli.write("Hello World!");
        stream::pipe( cli );

    });

    server.listen( "localhost", 8000, []( socket_t srv ){
        console::log("-> udp://localhost:8000 <-");
    });

}
```
