# Advanced HTTP Server | High-Performance HTTP Server with File Streaming

This example demonstrates how to build an efficient HTTP server using the Nodepp framework in C++. The server is optimized for transferring large files by using file streams and handling HTTP range requests, making it ideal for serving multimedia content like videos and audio.

```cpp
#include <nodepp/nodepp.h>
#include <nodepp/timer.h>
#include <nodepp/http.h>
#include <nodepp/path.h>
#include <nodepp/date.h>
#include <nodepp/fs.h>

using namespace nodepp;

void onMain(){

    // Create an HTTP server instance.
    auto server = http::server([=]( http_t cli ){

        // Determine the file path.
        string_t dir = "www/index.html";
        if( cli.path != "/" )
            dir = path::join( "www", cli.path );

        console::log( cli.path, cli.get_fd() );

        // Check if the file exists.
        if( !fs::exists_file(dir) ){
            cli.write_header( 404, header_t({
                { "content-type", "text/plain" }
            }) );
            cli.write("Oops: 404 Error");
            cli.close(); return;
        }

        auto str = fs::readable( dir );

        // Handle a full file request.
        if( cli.headers["Range"].empty() ){

            cli.write_header( 200, header_t({
                { "Content-Length", string::to_string(str.size()) },
                { "Content-Type",   path::mimetype(dir) }
            }));

            // Stream the file if it's not a video or audio file.
            // Note: Media players handle streaming differently using range requests.
            if(!regex::test(path::mimetype(dir),"audio|video",true) )
                stream::pipe( str, cli );

        } else { // Handle a range request.

            array_t<string_t> range = regex::match_all(cli.headers["Range"],"\\d+",true);
            ulong rang[3]; rang[0] = string::to_ulong( range[0] );
                  rang[2] = min( rang[0]+CHUNK_MB(10), str.size() );
                  rang[1] = min( rang[0]+CHUNK_MB(10), str.size()-1 );

            cli.write_header( 206, header_t({
                { "Content-Range", string::format("bytes %lu-%lu/%lu",rang[0],rang[1],str.size()) },
                { "Content-Type",  path::mimetype(dir) },
                { "Accept-Range", "bytes" }
            }));

            // Set the stream to read only the requested range.
            str.set_range( rang[0], rang[2] );
            stream::pipe( str, cli );

        }

    });

    // Start the server and listen for connections.
    server.listen( "localhost", 8000, [=]( socket_t /*unused*/ ){
        console::log("server started at http://localhost:8000");
    });

}
```
