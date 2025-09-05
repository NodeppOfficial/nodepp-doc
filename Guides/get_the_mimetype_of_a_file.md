# Get The MIME Type Of A File

The `path.h` library allows you to read and process path related data. So use the `path::mimetype()` property to read the MIME type of a file

```cpp
#include <nodepp/nodepp.h>
#include <nodepp/path.h>

using namespace nodepp;

void onMain() {

    path::mimetype( "main.cpp" );  // text/X-CPP

    path::mimetype( "image.svg" ); // image/svg+xml

    path::mimetype( "file.pdf" );  // application/pdf

}
```