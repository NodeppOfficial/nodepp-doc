# Read a JSON File With Nodepp

The `fs::readable` function accepts a path and returns a `file_t` instance. The `file_t` class allows you to lazily read the file in a variety of formats. Use `json::parse` to read and parse the contents of a `.json` file as a plain object.

```cpp
#include <nodepp/nodepp.h>
#include <nodepp/stream.h>
#include <nodepp/json.h>
#include <nodepp/fs.h>

using namespace nodepp;

void onMain() {

    auto file = fs::readable( "PATH_TO_FILE" );
    auto data = stream::await( file );
    auto obj  = json::parse( data );

    console::log( "->", json::stringify( obj ) );

}
```