# Read Environment Variables

This code demonstrates how to read environment variables, which are key-value pairs stored outside of your application's code. They are commonly used to manage configuration settings, such as database credentials, API keys, and file paths, without hardcoding them directly into the source.

```cpp
#include <nodepp/nodepp.h>

using namespace nodepp;

void onMain() {

    process::env::init( ".env" );
    console::log( process::env::get("HOME") );

}
```
