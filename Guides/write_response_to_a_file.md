# Writing an HTTP Response to a File

When retrieving data from an HTTP request, especially for large files like images, videos, or archives, it's often more efficient to write the response directly to disk rather than holding the entire content in memory. The Nodepp framework provides two powerful methods for this: using a stream-based, asynchronous approach with stream::pipe() or a synchronous, await-based method.

### 1. Asynchronous Streaming (stream::pipe)

This is the recommended method for handling large files. It reads data from the network in small chunks and writes each chunk to the file immediately, minimizing memory usage and improving performance. This approach is non-blocking, allowing other operations to run concurrently.

```cpp
#include <nodepp/nodepp.h>
#include <nodepp/http.h>
#include <nodepp/fs.h>

using namespace nodepp;

void onMain(){

    fetch_t args;
            args.method = "GET";
            args.url = "http://www.google.com/";
            args.headers = header_t({
                { "Host", url::host(args.url) }
            });

    http::fetch( args )

    .then([]( http_t cli ){
        auto file = fs::writable("PATH_TO_FILE");

        cli.onData([]( string_t chunk ){
            console::log( chunk );
        });

        stream::pipe( cli, file );
    })

    .fail([]( except_t err ){
        console::error( err );
    });

}
```

### 2. Synchronous await Method

For smaller responses, you can read the entire body into memory first and then write it to a file. This method is simpler but can consume a lot of memory for large files.

```cpp
#include <nodepp/nodepp.h>
#include <nodepp/http.h>
#include <nodepp/fs.h>

using namespace nodepp;

void onMain(){

    fetch_t args;
            args.method = "GET";
            args.url = "http://www.google.com/";
            args.headers = header_t({
                { "Host", url::host(args.url) }
            });

    http::fetch( args )

    .then([]( http_t cli ){
        auto data = stream::await( cli );
        fs::write_file( "PATH_TO_FILE", data );
    })

    .fail([]( except_t err ){
        console::error( err );
    });

}
```
