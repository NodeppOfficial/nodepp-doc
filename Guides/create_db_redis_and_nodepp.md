# Connecting and Interacting with a Redis Database

This example demonstrates how to use the Nodepp framework to connect to a Redis database. By using Nodepp's asynchronous exec() method, you can send commands to Redis (like SET and GET) without blocking your application's execution. This is ideal for high-performance, I/O-bound tasks like caching and real-time data management.

```cpp
#include <nodepp/nodepp.h>
#include <redis/http.h>

using namespace nodepp;

void onMain() {

    redis_t db ("db://user:pass@localhost:8000");

    db.exec(" SET FOO BAT ");

    db.exec("GET FOO",[]( string_t data ){
        console::log( "->", data )
    });

}
```

For more information, check out **[Nodepp-Redis Grithub Repository](https://github.com/NodeppOficial/nodepp-redis)**
