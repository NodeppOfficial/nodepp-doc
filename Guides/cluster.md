# clustering

In Nodepp, clusters allow you to create child processes that share a single server port. This powerful feature lets your application utilize multi-core systems, significantly improving performance and handling more concurrent connections. By distributing the workload across multiple processes, you can prevent a single process from becoming a bottleneck.

```cpp
#include <nodepp/nodepp.h>
#include <nodepp/cluster.h>
#include <nodepp/http.h>
#include <nodepp/fs.h>

using namespace nodepp;

// This function contains the logic for the HTTP server
void run_server(int process_id) {
    auto server = http::server([=](http_t client) {
        // Your HTTP server logic goes here
        // e.g., handling requests, sending responses
    });

    server.listen("localhost", 8000, [=](socket_t server_socket) {
        // Optional callback to confirm the server is listening
        console::log("Server running on port 8000. Process ID:", process_id);
    });
}

// Main function that starts the application
void on_main() {
    // Check if the current process is a child (worker)
    if (process::is_child()) {
        run_server(os::pid());
    } else {
        // If it's the main (master) process, spawn workers
        int num_cpus = os::cpus();
        for (int i = 0; i < num_cpus; ++i) {
            cluster::add(); // Add a new worker process
        }
    }
}
```
