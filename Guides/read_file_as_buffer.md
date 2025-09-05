# Read File As Buffer

The `fs::readable()` function accepts a path and returns a `file_t` instance. The `file_t` class allows you to lazily read the file in a variety of formats.

To read the file into a Buffer instance, first read the file using `fs::await()` or `fs::pipe()` to consume the entire file and convert the data as `array_t`.

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