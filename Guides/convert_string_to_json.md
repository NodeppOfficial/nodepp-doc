# Converting a JSON String to a Nodepp Object

To convert a JSON-formatted string **(string_t)** into a usable Nodepp object **(object_t)**, you use the json::parse() function from the json.h module. This process, known as parsing, takes a string and builds a structured object that you can access and manipulate in your C++ code.  The function returns an object_t on success or nullptr if the string is not valid JSON.

```cpp
#include <nodepp/nodepp.h>
#include <nodepp/json.h>

using namespace nodepp;

void onMain() {

    // A raw string literal containing a JSON object.
    string_t json_data = R"({
        "var1": 1000,
        "var2": true,
        "var3": {
            "var1": "Hello World"
        },
        "var4": [10, 20, 30, 40, 50]
    })";

    // Parse the JSON string into a Nodepp object_t.
    object_t obj = json::parse(json_data);

    // Access and print the values from the parsed object.
    // Use .as<Type>() to cast the value to the correct C++ type.

    // Access a number
    console::log("-> var1:", obj["var1"].as<int>());

    // Access an element from an array
    console::log("-> var4[2]:", obj["var4"][2].as<int>());

    // Access a value from a nested object
    console::log("-> var3.var1:", obj["var3"]["var1"].as<string_t>());

    // Access a boolean and use a conditional (ternary) operator
    console::log("-> var2 is true?", obj["var2"].as<bool>() ? "🟢" : "🔴");
}
```
