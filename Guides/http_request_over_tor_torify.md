# Making HTTP Requests Over Tor with Nodepp and Torify

The Tor network (The Onion Router) is a system that enables anonymous communication. By routing internet traffic through a series of volunteer-operated relays, Tor conceals a user's IP address and location, making it an essential tool for privacy and security.

This example demonstrates how to make an HTTP request anonymously over the Tor network using Nodepp and the Torify library. This is particularly useful for applications that require enhanced privacy or need to access content without revealing the client's origin.

```cpp
#include <nodepp/nodepp.h>
#include <nodepp/url.h>
#include <tor/http.h>

using namespace nodepp;

void onMain() {

    tor_fetch_t args;
    args.timeout = 0; // Disable Fetch timeout
    args.method  = "GET";
    args.tor     = "tcp://localhost:9050";
    args.url     = "http://check.torproject.org/";
    args.headers = header_t({
        { "Host", url::hostname( args.url ) }
    });

    tor::http::fetch( args )

    .then([]( http_t cli ){
        console::log( cli.read() );
    })

    .fail([]( except_t err ){
        console::log(err);
    });

}
```

For more information, check out **[Nodepp-Torify Grithub Repository](https://github.com/NodeppOficial/nodepp-torify)**
