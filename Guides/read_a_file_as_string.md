# Read A File As String

This code demonstrates how to read a file piece by piece using Nodepp's fs::readable() and file_t. Instead of loading the entire file into memory at once, this method reads the file in chunks, making it highly memory-efficient for handling large files.

```cpp
#include <nodepp/nodepp.h>
#include <nodepp/fs.h>

using namespace nodepp;

void onMain() {

    auto file = fs::readable( "PATH_TO_FILE" );

    while( file.is_available() ){
        console::log( file.read() );
    }

}
```
