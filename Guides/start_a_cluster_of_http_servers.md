# Starting a Cluster of HTTP Servers

In high-traffic web applications, a single server instance can become a bottleneck. Clustering is a technique that leverages multiple processes (or "workers") to handle incoming requests, distributing the workload and improving performance. This approach enables a single server to take full advantage of a multi-core CPU, providing automatic load balancing and increased resilience.

This guide demonstrates how to create a cluster of HTTP servers using Nodepp's cluster.h and http.h modules.

```cpp
#include <nodepp/nodepp.h>

#include <nodepp/cluster.h>
#include <nodepp/http.h>

using namespace nodepp;

void server( int process ){

    auto server = http::server([=]( http_t cli ){
        //HTTP Logic Inside
    });

    server.listen( "localhost", 8000, [=]( socket_t server ){
        //Optional Callbac
    });

}

void onMain(){

    if( process::is_child() ){ server( os::pid() ); } else {
        for( auto x = os::cpus(); x--; ){
             auto y = cluster::add();
        }
    }

}
```
