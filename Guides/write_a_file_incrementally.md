# Write A File Incrementally

Nodepp provides an API for incrementally writing to a file. This is useful for writing large files, or for writing to a file over a long period of time.

Call `fs::writable()` to retrieve a `file_t` instance in writable mode. This instance can be used to efficiently store & flush data asynchronously it to disk. You can write & flush data many times.

```cpp
#include <nodepp/nodepp.h>
#include <nodepp/fs.h>

using namespace nodepp;

void onMain() {

    auto file = fs::writable( "PATH_TO_FILE" );

    file.write( "Hello " );
    file.write( "World " );
    file.write( "!!!!! " );

    file.close();

}
```

When you're done writing to the file, call `.close()` to auto-flush the buffer and close the file.

