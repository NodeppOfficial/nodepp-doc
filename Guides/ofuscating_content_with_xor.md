# Ofuscating Content With XOR

The `crypto.h` header includes the `crypto::encrypt::XOR()` function, which can be used to obfuscate plaintext content using the XOR encoding technique. This function takes the original plaintext as input and applies the XOR encoding to it, generating an obfuscated version of the content. This can be a useful technique for protecting sensitive information or hiding the true nature of the data.

```cpp
#define SECRET "MY_SECRET_KEY"

#include <nodepp/nodepp.h>
#include <nodepp/crypto.h>

using namespace nodepp;

void onMain() {

    auto XOR = crypto::encrypt::XOR( SECRET );

    XOR.update( "hello world!" );
    console::log( XOR.get() ); // message ^= secret
    
}
```

Or if you want to encrypt as a fileStream

```cpp
#define SECRET "MY_SECRET_KEY"

#include <nodepp/nodepp.h>
#include <nodepp/crypto.h>
#include <nodepp/fs.h>

using namespace nodepp;

void onMain() {

    auto fout = fs::writable( "PATH_TO_FILE1" ); 
    auto file = fs::readable( "PATH_TO_FILE2" ); 
    auto XOR  = crypto::encrypt::XOR( SECRET );

    file.onData([=]( string_t data ){
        XOR.update( data );
    });

    XOR.onData([=]( string_t data ){
        fout.write( data );
    });

    stream::pipe( file );
    
}
```