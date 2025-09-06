# Read a JSON File With Nodepp

This code snippet demonstrates how to read a file and parse its contents as a JSON **(JavaScript Object Notation)** object using Nodepp's streaming and JSON utilities. This is a common pattern for loading configuration files or data from a file system.

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
