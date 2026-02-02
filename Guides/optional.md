# optional_t | Error Handling

The `optional_t` class in the Nodepp library is a powerful tool for handling optional values in a robust and structured manner. This class provides a way to represent and work with values that may or may not be present, helping to eliminate the risk of null or undefined references and improve the overall quality and reliability of your code.

```cpp
#include <nodepp/nodepp.h>
#include <nodepp/optional.h>

using namespace nodepp;

void onMain(){

    optional_t<string_t> x;
    if( x.has_value() ) console::done( x.value() );
    else                console::error( "x is empty" );

    optional_t<string_t> y ("y has value");
    if( y.has_value() ) console::done( y.value() );
    else                console::error( "y is empty" );

}
```