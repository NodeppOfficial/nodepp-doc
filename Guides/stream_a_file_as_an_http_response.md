# Stream A File Over HTTP Response

Serving files directly from disk is a common task for any web server. The most efficient way to do this, especially for large files, is by using streams. Instead of reading the entire file into memory and then sending it all at once, streaming reads and sends the file in small, manageable chunks. This approach is more memory-efficient and provides a better user experience by allowing the client to start processing the data as it arrives.

```cpp
#include <nodepp/nodepp.h>
#include <nodepp/http.h>
#include <nodepp/path.h>
#include <nodepp/fs.h>

using namespace nodepp;

void onMain(){

    auto server = http::server([=]( http_t cli ){

        auto file = fs::readable( "LICENSE" );

        cli.write_header( 200, header_t({
            { "content-length", string::to_string( file.size() ) },
            { "content-type", path::mimetype( "LICENSE.txt" ) }
        }));

        stream::pipe( file, cli );

    });

    server.listen( "localhost", 3000, [=]( socket_t server ){
        console::log("-> http://localhost:3000 <-");
    });

}
```
