# Converting Base64 To Plaintext Format

Nodepp provides convenient functions in its encoder module for converting strings between Base64 and plaintext formats. This is commonly used for encoding binary data into a text-based format for transmission over protocols that only support text, such as HTTP.

### Base64 to Plaintext

To convert a Base64 string back into its original plaintext format, you can use the encoder::base64::btoa() function. This function takes a Base64-encoded string and returns a new plaintext string.

```cpp
#include <nodepp/nodepp.h>
#include <nodepp/encoder.h>

using namespace nodepp;

void onMain() {

    auto b64  = "SGVsbG8gV29ybGQh";
    auto data = encoder::base64::btoa( b64 );

    console::log( data ); // Hello World!

}
```
