# Write Environment Variables

This code demonstrates how to create and set a new environment variable within your program using Nodepp's process::env module. Environment variables are a key-value store used to hold configuration settings outside of your code, which is useful for things like managing API keys, database connection strings, or application-specific settings that may change between different environments (e.g., development, testing, and production).

```cpp
#include <nodepp/nodepp.h>

using namespace nodepp;

void onMain() {

    process::env::set("HELLO","WORLD!");

    console::log( process::env::get("HELLO") ); // WORLD!

}
```
