# Write Environment Variables

The current environment variables can be accessed via `process::env`, to write a new **Environment Variable**, you can use `process::env::set()`, the first argument must be the name of the variable you want to write and the second argument must be the value as `string_t`.  

```cpp
#include <nodepp/nodepp.h>

using namespace nodepp;

void onMain() {

    process::env::set("HELLO","WORLD!");

    console::log( process::env::get("HELLO") ); // WORLD!

}
```