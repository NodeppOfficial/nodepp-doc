# Read Environment Variables

The current environment variables can be accessed via `process::env`, to read an **Environment Variable**, you can use `process::env::get()`, the first argument must be the name of the variable you want to read.  

```cpp
#include <nodepp/nodepp.h>

using namespace nodepp;

void onMain() {

    console::log( process::env::get("HOME") );

}
```