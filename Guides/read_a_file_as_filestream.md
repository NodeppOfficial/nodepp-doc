# Read A File As FileStream

Reading a file as a stream is an efficient way to handle large files without loading their entire content into memory at once. A stream processes data in small, manageable chunks, which is essential for performance and memory management, especially in applications that handle large files, such as video or log files.

The `fs::readable()` function accepts a path and returns a `file_t` instance. The `file_t` class allows you to lazily read the file in a variety of formats. Use `stream::pipe()` to consume the file incrementally as a ReadableStream.

```cpp
#include <nodepp/nodepp.h>
#include <nodepp/stream.h>
#include <nodepp/fs.h>

using namespace nodepp;

void onMain() {

    auto file = fs::readable( "PATH_TO_FILE" );

    file.onData([]( string_t data ){
        console::log( data );
    });

    file.onClose([](){
        console::success( "DONE" );
    });

    stream::pipe( file );

}
```

### Awaiting the Entire Stream
For smaller files or when you need the entire content at once, you can use stream::await() to read the entire file into a single string. This is a synchronous operation that blocks execution until the entire file is read.

```cpp
#include <nodepp/nodepp.h>
#include <nodepp/stream.h>
#include <nodepp/fs.h>

using namespace nodepp;

void onMain() {

    auto file = fs::readable( "PATH_TO_FILE" );
    auto data = stream::await( file );

}
```
