# Regular Expressions

This code demonstrates how to use regular expressions in Nodepp for powerful string pattern matching. Regular expressions, often shortened to regex, are sequences of characters that define a search pattern. They are highly effective for tasks like parsing text, validating input, and extracting specific data.

```cpp
#include <nodepp/nodepp.h>
#include <nodepp/regex.h>

using namespace nodepp;

void onMain(){

    string_t message = R"(
        ![Imagen1](URL1)
        ![Imagen2](URL2)
        ![Imagen3](URL3)
        ![Imagen4](URL5)
    )";

    regex_t reg ("!\\[([^\\]]+)\\]\\(([^\\)]+)\\)");

    console::log( "-- --" );
    for( auto &x: reg.match_all( message ) ){
         console::log( "->", x );
    }

    console::log( "-- --" );
    for( auto &x: reg.get_memory() ){
         console::log( "->", x );
    }

}
```
