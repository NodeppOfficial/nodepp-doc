# Checking for File Existence

This example demonstrates how to use the Nodepp framework to check if a file exists at a given path. Performing this check is a crucial step before attempting to read from or write to a file, as it helps prevent runtime errors and ensures your program behaves reliably.

```cpp
#include <nodepp/nodepp.h>
#include <nodepp/stream.h>
#include <nodepp/fs.h>

using namespace nodepp;

void onMain() {

    if( !fs::exists_file("PATH_TO_FILE") ){
        process::error("File Does Not Exists");
    } else {
        auto file = fs::readable( "PATH_TO_FILE" );
        auto data = stream::await( file );
        console::log( "->", data );
    }

}
```
