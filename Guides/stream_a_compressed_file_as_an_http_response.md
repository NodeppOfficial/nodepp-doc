# Stream a Compressed File Over an HTTP Response

Serving large files efficiently is crucial for web performance. By compressing files before sending them to a client, you can significantly reduce bandwidth usage and improve load times. HTTP compression, commonly using Gzip, allows you to send a smaller, compressed version of a file, which the client's browser automatically decompresses. This guide demonstrates how to stream a file from disk, compress it with Gzip, and send it as an HTTP response using Nodepp.

```cpp
#include <nodepp/nodepp.h>
#include <nodepp/http.h>
#include <nodepp/path.h>
#include <nodepp/zlib.h>
#include <nodepp/fs.h>

using namespace nodepp;

void onMain(){

    auto server = http::server([=]( http_t cli ){

        auto file = fs::readable( "LICENSE" );

        cli.write_header( 200, header_t({
            { "content-length", string::to_string( file.size() ) },
            { "content-type", path::mimetype( "LICENSE.txt" ) },
            { "content-encoding", "gzip" },
        }));

        zlib::gzip::pipe( file, cli );

    });

    server.listen( "localhost", 3000, [=]( socket_t server ){
        console::log("-> http://localhost:3000 <-");
    });

}
```
