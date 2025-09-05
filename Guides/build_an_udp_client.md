# Building a Simple UDP Client

This example demonstrates how to create a basic User Datagram Protocol (UDP) client. Unlike TCP, UDP is a connectionless protocol, which means it sends data without first establishing a persistent connection with the server. This makes it faster and more efficient for applications where speed is more critical than guaranteed delivery, such as online gaming, live streaming, and voice chat.

```cpp
#include <nodepp/nodepp.h>
#include <nodepp/udp.h>

using namespace nodepp;

void onMain(){

    auto client = udp::client();

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
