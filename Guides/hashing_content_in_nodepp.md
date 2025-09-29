# Hashing Content In Nodepp

The `crypto.h` header in the `Nodepp` standard library provides the `crypto::hash` namespace, which offers a variety of secure hashing algorithms that can be used to hash content. These hashing algorithms, such as `SHA256` and `MD5`, are available without the need for any third-party dependencies. This makes the `crypto::hash` namespace a convenient and self-contained solution for securely hashing data in `Nodepp` applications.

```cpp
#include <nodepp/nodepp.h>
#include <nodepp/crypto.h>

using namespace nodepp;

void onMain() {

    auto sha = crypto::hash::SHA256();

    sha.update( "Hello " );
    sha.update( "World " );
    sha.update( "!!!!! " );

    console::log( sha.get() ); // 77d73d290bcfa71c004a6103280a293a58cfd49dec5a3a7628ca7a16b2180c0e

}
```

Algorithms Allowed by `crypto::hash`

- `crypto::hash::MD4()`
- `crypto::hash::MD5()`
- `crypto::hash::SHA1()`
- `crypto::hash::SHA256()`
- `crypto::hash::SHA384()`
- `crypto::hash::SHA512()`
- `crypto::hash::SHA3_256()`
- `crypto::hash::SHA3_384()`
- `crypto::hash::SHA3_512()`
- `crypto::hash::RIPEMD160()`
