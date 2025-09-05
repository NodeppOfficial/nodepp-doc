# Read A File As String

The `fs::readable()` function accepts a path and returns a `file_t` instance. The `file_t` class allows you to lazily read the file in a variety of formats. Use `read()` to read the contents as a string.

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