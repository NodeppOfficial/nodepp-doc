# Authenticating Sessions with JWT

This example demonstrates how to create, verify, and decode JSON Web Tokens (JWT) using the Nodepp framework. JWTs are a standard for securely transmitting information between parties as a JSON object. They're commonly used for authentication to verify a user's identity and grant them access to protected resources.

### How JWT Authentication Works
The process involves three main steps:

- **Creation (encode):** A server creates a JWT, which contains a JSON payload of user information (e.g., user ID, roles). This payload is signed with a secret key to ensure its integrity. The server then sends this token to the client.

- **Verification (verify):** When the client sends the JWT back with subsequent requests, the server uses the same secret key to verify the token's signature. If the signature is valid, the server knows the token hasn't been tampered with.

- **Decoding (decode):** Once the token is verified, the server can safely extract the payload to get the user information and proceed with the request.

```cpp
#define SECRET "HELLO_WORLD_PASS"

#include <nodepp/nodepp.h>
#include <nodepp/json.h>
#include <jwt/jwt.h>

using namespace nodepp;

void onMain() {

    // 1. Create the JSON payload for the token.
    object_t obj ({
        { "user", "EDBC_REPO" },
        { "pass", "123456789" },
        { "payl", "Hello World" }
    });

    // 2. Encode the JSON payload into a JWT using the HS256 algorithm and a secret key.
    auto token = jwt::encode( json::stringify(obj), SECRET );

    // 3. Verify the token using the same secret key.
    if( jwt::verify( token, SECRET ) ) {
        conio::done( "valid token: " ); console::log( token );
        // 4. If the token is valid, decode the payload to access the data.
        console::log( "payload", jwt::decode( token ) );
    } else {
        conio::error( "invalid token: " );
        console::log( token );
    }
}
```

For more details and examples, visit the **[Nodepp JWT Github Repository](https://github.com/NodeppOficial/nodepp-jwt)**.
