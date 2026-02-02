# Building a Simple TLS Client

This example demonstrates how to create a secure TCP client using Transport Layer Security (TLS). TLS, the successor to SSL, is the standard protocol for establishing an encrypted connection between a client and a server. This is essential for protecting sensitive data like passwords and personal information during transmission.

```cpp
#include <nodepp/nodepp.h>
#include <nodepp/tls.h>

using namespace nodepp;

void onMain(){

    ssl_t ssl; //( "./ssl/cert.key", "./ssl/cert.crt" );

    auto client = tls::client( &ssl );

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
