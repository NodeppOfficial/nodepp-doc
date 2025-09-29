# Process::Error | Error Handling

In Nodepp, the `process::error` is a mechanism that provides functionality similar to the `throw(except_t(value))`. This feature allows you to explicitly raise and handle exceptions within your Nodepp-based applications.

```cpp
#include <nodepp/nodepp.h>

using namespace nodepp;

void onMain() {
    try {
        process::error( "Something Went Wrong" );
    } catch( except_t err ) {
        console::log( err );
    } 
}
```