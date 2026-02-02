# Converting Plaintext To Base64 Format

Nodepp provides convenient functions in its encoder module for converting strings between Base64 and plaintext formats. This is commonly used for encoding binary data into a text-based format for transmission over protocols that only support text, such as HTTP.

### Plaintext to Base64

to encode a regular plaintext string into Base64, use the encoder::base64::atob() function. This is the reverse operation, where atob stands for "ASCII to Binary" and btoa for "Binary to ASCII," though in this context, they refer to the conversion of plaintext to Base64 and vice versa, respectively.

```cpp
#include <nodepp/nodepp.h>
#include <nodepp/encoder.h>

using namespace nodepp;

void onMain() {

    auto b64  = "Hello World!";
    auto data = encoder::base64::atob( b64 );

    console::log( data ); // SGVsbG8gV29ybGQh

}
```
