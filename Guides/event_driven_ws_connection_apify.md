# Event-driven Websocket connection:

This example demonstrates how to transform a raw WebSocket connection into a more structured, event-driven system using the apify and ws libraries in Nodepp. This approach is more robust and scalable than simply handling raw data, as it allows you to define custom events and separate the logic for different actions.

### Server Implementation

```cpp
#include <nodepp/nodepp.h>
#include <apify/apify.h>
#include <nodepp/ws.h>

using namespace nodepp;

void onMain() {
    auto app = apify::add<ws_t>();
    auto srv = ws::server();

    app.on("METHOD","/PATH",[=]( apify_t<ws_t> cli ){
        console::log( cli.message );
        cli.emit( "DONE", "/PATH", "done" );
    });

    srv.onConnect([=]( ws_t cli ){

        cli.onData([=]( string_t data ){
            app.next( cli, data );
        });

        cli.onClose([=](){
            console::log("Disconnected");
        }); console::log("Connected");

    });

    srv.listen("localhost",8000,[=](...){
        console::log( "ws:/localhost:8000" );
    }); console::log( "Started" );

}
```

### Client Implementation

```cpp
#include <nodepp/nodepp.h>
#include <apify/apify.h>
#include <nodepp/ws.h>

using namespace nodepp;

void onMain(){
    auto srv = ws::client( "ws://localhost:8000" );
    auto app = apify::add<ws_t>();

    app.on("DONE","/PATH",[=]( apify_t<ws_t> cli ){
        console::log( cli.message );
    });

    srv.onConnect([=]( ws_t cli ){

        cli.onData([=]( string_t data ){
            app.next( cli, data );
        });

        srv.onClose([=](){
            console::log("Disconnected");
        }); console::log("Connected");

        apify::add(cli).emit("METHOD","/PATH","hello world!");

    });

}
```
