# Symmetric Encryption & Decryption in Nodepp

Symmetric encryption is a type of encryption where the same key is used for both encrypting and decrypting data. This method is highly efficient, making it ideal for securing large amounts of data, such as entire files. The Nodepp crypto.h library provides a robust set of symmetric encryption and decryption algorithms. This guide demonstrates how to securely process a file, encrypting or decrypting its contents as a stream to handle large files without loading them into memory.

### 1. Encrypting a File

The crypto::encrypt namespace provides a variety of algorithms for encrypting files. The example below uses the AES-128-CBC algorithm to read a file, encrypt it chunk by chunk, and write the encrypted data to a new file.

```cpp
#define SECRET "MY_SECRET_KEY"

#include <nodepp/nodepp.h>
#include <nodepp/crypto.h>
#include <nodepp/fs.h>

using namespace nodepp;

void onMain() {

    auto fout = fs::writable( "PATH_TO_FILE1" );
    auto file = fs::readable( "PATH_TO_FILE2" );

    auto fd   = crypto::encrypt::AES_128_CBC( SECRET );

    file.onClose([=](){ console::log("Encrypted"); });

    file.onData([=]( string_t data ){
        fd.update( data );
    });

    fd.onData([=]( string_t data ){
        fout.write( data );
    });

    stream::pipe( file );

}
```

Algorithms Supported by `crypto::encrypt`

- `crypto::encrypt::TRIPLE_DES_CFB()`
- `crypto::encrypt::TRIPLE_DES_CBC()`
- `crypto::encrypt::TRIPLE_DES_ECB()`
- `crypto::encrypt::AES_128_CBC()`
- `crypto::encrypt::AES_192_CBC()`
- `crypto::encrypt::AES_256_CBC()`
- `crypto::encrypt::AES_128_ECB()`
- `crypto::encrypt::AES_192_ECB()`
- `crypto::encrypt::AES_256_ECB()`
- `crypto::encrypt::DES_CFB()`
- `crypto::encrypt::DES_CBC()`
- `crypto::encrypt::DES_ECB()`
- `crypto::encrypt::XOR()`

### 2. Decrypting a File

The crypto::decrypt namespace mirrors the encryption process, using the same algorithms and streaming approach to securely decrypt content. The key used for decryption must be identical to the one used for encryption.

```cpp
#define SECRET "MY_SECRET_KEY"

#include <nodepp/nodepp.h>
#include <nodepp/crypto.h>
#include <nodepp/fs.h>

using namespace nodepp;

void onMain() {

    auto fout = fs::writable( "PATH_TO_FILE1" );
    auto file = fs::readable( "PATH_TO_FILE2" );

    auto fd   = crypto::decrypt::AES_128_CBC( SECRET );

    file.onClose([=](){ console::log("Decrypted"); });

    file.onData([=]( string_t data ){
        fd.update( data );
    });

    fd.onData([=]( string_t data ){
        fout.write( data );
    });

    stream::pipe( file );

}
```

Algorithms Supported by `crypto::decrypt`

- `crypto::decrypt::TRIPLE_DES_CFB()`
- `crypto::decrypt::TRIPLE_DES_CBC()`
- `crypto::decrypt::TRIPLE_DES_ECB()`
- `crypto::decrypt::AES_128_CBC()`
- `crypto::decrypt::AES_192_CBC()`
- `crypto::decrypt::AES_256_CBC()`
- `crypto::decrypt::AES_128_ECB()`
- `crypto::decrypt::AES_192_ECB()`
- `crypto::decrypt::AES_256_ECB()`
- `crypto::decrypt::DES_CFB()`
- `crypto::decrypt::DES_CBC()`
- `crypto::decrypt::DES_ECB()`
- `crypto::decrypt::XOR()`
