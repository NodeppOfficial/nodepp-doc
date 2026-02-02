# Hashing Passwords with Argon2

Argon2 is a robust, modern hashing algorithm designed to be resistant to various attacks, including brute-force and side-channel attacks. It's the recommended algorithm for password hashing due to its memory-hard and time-hard properties, making it an excellent choice for securing user credentials.

```cpp
#include <nodepp/nodepp.h>
#include <nodepp/encoder.h>
#include <argon/argon2.h>

using namespace nodepp;

void onMain() {

    ptr_t<uchar> hash ( 32, '\0' );
    argon2_t argon;

    argon.hash( hash, "password" );
    console::log( encoder::hex::get( hash ) );

}
```

For more information, check out **[Nodepp-Argon2 Grithub Repository](https://github.com/NodeppOficial/nodepp-argon2)**
