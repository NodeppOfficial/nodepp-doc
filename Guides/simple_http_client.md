# Creating a Simple HTTP Client with Nodepp

An HTTP client is a program that sends requests to an HTTP server to retrieve, create, update, or delete resources. The Nodepp framework provides a robust and easy-to-use API for this purpose, allowing you to interact with web services and APIs. The http::fetch function is the core of this functionality, designed for asynchronous, non-blocking requests.

This example will walk you through setting up a basic HTTP client to make a GET request to google.com and handle the response.

```cpp
#include <nodepp/nodepp.h>
#include <nodepp/http.h>

using namespace nodepp;

void onMain(){

    fetch_t args;
            args.method = "GET";
            args.url = "http://www.google.com/";
            args.headers = header_t({
                { "Host", url::host(args.url) }
            });

        //  args.file = file_t("PATH","r");
        //  args.body = "MYBODY";

    http::fetch( args )

    .then([]( http_t cli ){
        console::log( cli.headers["Host"] );
        cli.onData([]( string_t chunk ){
            console::log( chunk );
        }); stream::pipe( cli );
    })

    .fail([]( except_t err ){
        console::error( err );
    });

}
```
