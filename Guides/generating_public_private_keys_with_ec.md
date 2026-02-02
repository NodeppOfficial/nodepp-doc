# Generating Public & Private Keys With EC

The Nodepp `crypto.h` module includes the `crypto::ec` namespace, which provides a set of algorithms and functions for working with elliptic curve cryptography (ECC). ECC is a type of public-key cryptography that uses the algebraic structure of elliptic curves over finite fields to provide secure curveion, digital signatures, and other cryptographic operations. The `crypto::ec` namespace in `Nodepp` allows developers to leverage the power of elliptic curve cryptography in their applications.

```cpp
#include <nodepp/nodepp.h>
#include <nodepp/crypto.h>

using namespace nodepp;

void onMain() {

    auto ec = crypto::curve::SECP128R1();

    console::log( "->", ec.get_public_key () );
    console::log( "->", ec.get_private_key() );

}
```

Algorithms Supported by `crypto::curve`

- `crypto::curve::PRIME256V1()`
- `crypto::curve::PRIME192V1()`
- `crypto::curve::SECP128R1()`
- `crypto::curve::SECP128R2()`
- `crypto::curve::SECP160R1()`
- `crypto::curve::SECP160R2()`
- `crypto::curve::SECP160K1()`
- `crypto::curve::SECP256K1()`
