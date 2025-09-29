# Converting JSON Objects to Strings

To convert a Nodepp object_t (a C++ representation of a JSON object) into a JSON-formatted string, you use the json::stringify() function from the json.h module. This function is essential for sending data over the network, as JSON is a text-based data interchange format.

```cpp
#include <nodepp/nodepp.h>
#include <nodepp/json.h>

using namespace nodepp;

void onMain() {

    object_t obj ({
        { "var1", "Hello World" },
        { "var2", objec_t({
            "var1", 10
        })},
        { "var3", true }
    });

    console::log( json::stringify( obj ) );

}
```
