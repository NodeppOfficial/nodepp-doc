# Building a Simple TCP Client

This example demonstrates how to create a basic TCP client to establish a connection with a TCP server. The Transmission Control Protocol (TCP) is a fundamental internet protocol that provides a reliable, connection-oriented communication channel. This means once a connection is established, data is guaranteed to be delivered in the correct order without any loss.

```cpp
#include <nodepp/nodepp.h>
#include <nodepp/tcp.h>

using namespace nodepp;

void onMain(){

    auto client = tcp::client();

    client.onOpen([=]( socket_t cli ){

        cli.onData([=]( string_t data ){
            console::log( data );
        });

        cli.onClose.once([=](){
            console::log("closed");
        });

        cli.write("Hello World!");
        stream::pipe( cli );

    });

    client.connect( "localhost", 8000 );

}
```
