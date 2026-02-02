# Signing Content With HMAC

The `crypto.h` header in the `Nodepp` standard library provides the `crypto::hmac` namespace, which offers a variety of secure signing algorithms that can be used to sign content. These signing algorithms, such as `SHA256` or `MD5`, are available without the need for any third-party dependencies. This makes the `crypto::hmac` namespace a convenient and self-contained solution for securely signing data in `Nodepp` applications.

```cpp
#define SECRET "MY_SECRET_KEY"

#include <nodepp/nodepp.h>
#include <nodepp/crypto.h>

using namespace nodepp;

void onMain() {

    auto sha = crypto::hmac::SHA256( SECRET );

    sha.update( "Hello " );
    sha.update( "World " );
    sha.update( "!!!!! " );

    console::log( sha.get() ); // 854fb4758c79c665829a4b5c1377d6c7321a5c5432b992a4f8fe4a162d3196ca

}
```

Algorithms Allowed by `crypto::hmac`

- `crypto::hmac::MD4()`
- `crypto::hmac::MD5()`
- `crypto::hmac::SHA1()`
- `crypto::hmac::SHA256()`
- `crypto::hmac::SHA384()`
- `crypto::hmac::SHA512()`
- `crypto::hmac::SHA3_256()`
- `crypto::hmac::SHA3_384()`
- `crypto::hmac::SHA3_512()`
- `crypto::hmac::RIPEMD160()`