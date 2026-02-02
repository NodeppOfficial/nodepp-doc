# Ofuscate Plaintext With XOR Encoding

The `encoder.h` header includes the `encoder::XOR::get()` function, which can be used to obfuscate plaintext content using the XOR encoding technique. This function takes the original plaintext as input and applies the XOR encoding to it, generating an obfuscated version of the content. This can be a useful technique for protecting sensitive information or hiding the true nature of the data.

```cpp
#define PASS "SECRET_PASSWORD"

#include <nodepp/nodepp.h>
#include <nodepp/encoder.h>

using namespace nodepp;

void onMain() {

    auto data = "Hello World!";
    
    auto XOR  = encoder::XOR::get( data, PASS );
    console::log( XOR ); // data ^= PASS

    auto ROX  = encoder::XOR::get( XOR, PASS );
    console::log( ROX ); // Hello World!
    
}
```