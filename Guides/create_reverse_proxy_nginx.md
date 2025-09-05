# Create A Reverse Proxy With Nginx

A reverse proxy acts as an intermediary, forwarding client requests to one or more backend servers. This setup is crucial for distributing traffic, enhancing security, and improving performance. This example, we create a reverse proxy that can route requests for /blog to a server hosting, while routing requests for /contact to a different server.

```cpp
#include <nodepp/nodepp.h>
#include <nginx/http.h>

using namespace nodepp;

void onMain() {

    auto app = nginx::http::add();

    app.add( "move", "/contact", object_t({
        { "href"   , "http://google.com" },
        { "timeout", 30000 }, { "limit", 25 },
    }));

    app.add( "pipe", "/blog", object_t({
        { "href"   , "http://localhost:8001/blog" },
        { "timeout", 30000 }, { "limit", 25 },
    }));

    app.add( "file", nullptr, object_t({
        { "path"   , "./www" },
        { "timeout", 30000 },{ "limit", 25 },
    }));

    app.listen( "0.0.0.0", 8000, []( ... ){
        console::log( "Listening -> http://localhost:3000" );
    });

}
```

For more information, check out **[Nodepp-Nginx Grithub Repository](https://github.com/NodeppOficial/nodepp-nginx)**
