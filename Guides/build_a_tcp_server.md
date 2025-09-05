# Building a Simple TCP Server

This example demonstrates how to create a basic TCP server that listens for incoming connections. The Transmission Control Protocol (TCP) provides a reliable, connection-oriented communication channel, making it ideal for applications where data integrity is critical, such as chat applications or file transfers.

```cpp
#include <nodepp/nodepp.h>
#include <nodepp/tcp.h>

using namespace nodepp;

void onMain(){

    auto server = tcp::server();

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
        console::log("-> tcp://localhost:8000 <-");
    });

}
```
