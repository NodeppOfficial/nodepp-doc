# Read File As Buffer

This code demonstrates how to read the entire contents of a file and store it in a buffer, which is a raw data container. Reading a file into a buffer is essential when you need to handle binary data like images, audio files, or compressed archives, or when you need to perform low-level manipulations on the file's content.

```cpp
#include <nodepp/nodepp.h>
#include <nodepp/stream.h>
#include <nodepp/fs.h>

using namespace nodepp;

void onMain() {

    auto file = fs::readable( "LICENSE" );
    auto data = stream::await( file );
    auto bffr = array_t<uchar>( data.size() );

    memcpy( data.get(), bffr.get(), data.size() );

    console::log( bffr.join() );

}
```
