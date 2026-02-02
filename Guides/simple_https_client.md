# Building a Simple HTTPS Client with Nodepp

An HTTPS client is essential for secure communication over the internet. Unlike standard HTTP, HTTPS uses TLS (Transport Layer Security) to encrypt all data exchanged between the client and server. This ensures that sensitive information, like passwords and personal data, remains private and protected from interception. The Nodepp framework provides a straightforward API to handle these secure connections.

This example demonstrates how to create a simple HTTPS client to make a GET request to google.com, handling the encrypted data stream and potential errors.

```cpp
#include <nodepp/nodepp.h>
#include <nodepp/https.h>

using namespace nodepp;

void onMain(){

    ssl_t ssl; //( "./ssl/cert.key", "./ssl/cert.crt" );

    fetch_t args;
            args.method = "GET";
            args.url = "https://www.google.com/";
            args.headers = header_t({
                { "Host", url::host(args.url) }
            });

        //  args.file = file_t("PATH","r");
        //  args.body = "MYBODY";

    https::fetch( args, &ssl )

    .then([]( https_t cli ){
        cli.onData([]( string_t chunk ){
            console::log( chunk.size(), ":>", chunk );
        }); stream::pipe( cli );
    })

    .fail([]( except_t err ){
        console::error( err );
    });

}
```
