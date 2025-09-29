# Building a Simple WebSocket Server

WebSockets enable real-time, bidirectional communication between a server and a client over a single, long-lived connection. This makes them the perfect choice for applications that require instant updates, such as chat applications, live feeds, and online gaming. This example demonstrates how to build a basic WebSocket server using the Nodepp framework.

```cpp
#include <nodepp/nodepp.h>
#include <nodepp/http.h>
#include <nodepp/ws.h>
#include <nodepp/fs.h>

using namespace nodepp;

void onMain(){

    auto server = http::server([=]( http_t cli ){
        /* Server logic here */
    }); ws::server( server );

    server.onConnect([=]( ws_t cli ){

        console::log("connected");

        cli.onData([=]( string_t data ){
            console::log( data );
        });

        cli.onClose([=](){
            console::log("closed");
        });

    });

    server.listen( "localhost", 8000, [=]( socket_t server ){
        console::log("-> http://localhost:8000 <-");
    });

}
```
