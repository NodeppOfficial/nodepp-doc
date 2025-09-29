# Building a Simple WebSocket Client

WebSockets provide a persistent, two-way communication channel between a client and a server, making them perfect for real-time applications like chat apps, games, and live data dashboards. This example shows you how to build a simple WebSocket client using the Nodepp framework and its ws.h header.

The code is event-driven, meaning you set up listeners for specific events—like a successful connection, receiving data, or the connection closing—and then define what should happen when those events occur.

```cpp
#include <nodepp/nodepp.h>
#include <nodepp/ws.h>

using namespace nodepp;

void onMain() {

    auto client = ws::client( "ws://localhost:8000/" );

    client.onConnect([=]( ws_t cli ){

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
