# Building a Simple WebSocket Server with TLS

This example demonstrates how to create a secure WebSocket server using the Nodepp framework. While standard WebSockets **(ws://)** provide a fast, bidirectional connection, they are not encrypted. For applications that handle sensitive data, you must use WebSocket Secure **(WSS)**, which is built on top of TLS/SSL. This ensures that all data transmitted is encrypted and authenticated.

```cpp
#include <nodepp/nodepp.h>
#include <nodepp/timer.h>
#include <nodepp/https.h>
#include <nodepp/path.h>
#include <nodepp/date.h>
#include <nodepp/wss.h>
#include <nodepp/fs.h>

using namespace nodepp;

void onMain(){

    ssl_t ssl; //( "./ssl/cert.key", "./ssl/cert.crt" );

    auto server = https::server([=]( https_t cli ){
        /* Server logic here */
    }, &ssl ); 
    
    wss::server( server );

    server.onConnect([=]( wss_t cli ){

        console::log("connected");

        cli.onData([=]( string_t data ){
            console::log( data );
        });

        cli.onClose([=](){
            console::log("closed");
        });

    });

    server.listen( "localhost", 8000, [=]( ssocket_t server ){
        console::log("-> https://localhost:8000 <-");
    });

}
```
