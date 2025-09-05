# Except_t | Error Handling

The `except_t` class provided by the Nodepp library is designed to offer comprehensive information about errors that occur during program execution. This class encapsulates the necessary details about an exception, making it easier to handle and understand errors that arise within the application.

```cpp
#include <nodepp/nodepp.h>

using namespace nodepp;

void onMain() {
    try {
        throw except_t( "Something Went Wrong" );
    } catch( except_t err ) {
        console::log( err );
    }
}
```

```cpp
#include <nodepp/nodepp.h>
#include <nodepp/json.h>

using namespace nodepp;

void onMain() {
    try {
        json::parse( R"( { )" );
    } catch( except_t err ) {
        console::log( err ); // Invalid JSON Format
    }
}
```
