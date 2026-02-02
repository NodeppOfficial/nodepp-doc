# Asymmetric Encryption and Decryption with RSA

This example demonstrates how to perform asymmetric encryption and decryption using the RSA algorithm within the Nodepp framework's crypto.h header. Asymmetric encryption uses a pair of keys: a public key for encryption and a private key for decryption.

### Encryption with the Public Key

To encrypt a message, you use the crypto::encrypt::RSA class. The process involves generating a key pair, saving the keys, and then using the public key to encrypt the data.

```cpp
#include <nodepp/nodepp.h>
#include <nodepp/crypto.h>

using namespace nodepp;

void onMain() {
    string_t msg = "Hello World!";

    // Create an RSA object and generate a 2048-bit key pair.
    crypto::encrypt::RSA RSA;
    RSA.generate_keys( 2048 );

    // Save the keys to files.
    RSA.write_public_key ( "PUBLIC.txt" );
    RSA.write_private_key( "PRIVATE.txt" );

    // Encrypt the message using the public key.
    auto encrypted_data = RSA.public_encrypt( msg );

    console::log( encrypted_data.size(), encrypted_data );
}
```

### Decryption with the Private Key

To decrypt a message, you use the private key that corresponds to the public key used for encryption. This is the core of asymmetric cryptography: **only the holder of the private key can read the message**.

```cpp
#include <nodepp/nodepp.h>
#include <nodepp/crypto.h>

using namespace nodepp;

void onMain() {
    // The encrypted message must be read or passed here.
    // For this example, let's assume we have it from the encryption step.
    string_t encrypted_msg_placeholder = "placeholder_for_encrypted_data";

    crypto::encrypt::RSA RSA;

    // Load the private key from the file.
    RSA.read_private_key( "PRIVATE.txt" );

    // Decrypt the message using the private key.
    auto decrypted_data = RSA.private_decrypt( encrypted_msg_placeholder );

    console::log( decrypted_data.size(), decrypted_data );
}
```
