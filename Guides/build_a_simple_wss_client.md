# Building a Simple WebSocket Client with TLS

This example demonstrates how to create a secure WebSocket client using the Nodepp framework. While standard WebSockets **(ws://)** provide a fast, bidirectional connection, they are not encrypted. To ensure data privacy and integrity, especially for sensitive information, you must use WebSocket Secure **(WSS)**, which is built on top of TLS/SSL.

```cpp
#include <nodepp/nodepp.h>
#include <nodepp/timer.h>
#include <nodepp/wss.h>
#include <nodepp/fs.h>

using namespace nodepp;

void onMain() {

    ssl_t ssl; //( "./ssl/cert.key", "./ssl/cert.crt" );

    auto client = wss::client( "wss://localhost:8000/", &ssl );

    client.onConnect([=]( wss_t cli ){

        console::log("connected");

        cli.onData([]( string_t chunk ){
            console::log("client:>",chunk);
        });

        cli.onClose([](){
            console::log("closed");
            process::exit(1);
        });

    });

}
```
