# Popen

The `popen_t` class in the Nodepp library provides a robust and flexible way to spawn asynchronous processes within your application. This feature allows you to execute external programs or commands in a non-blocking manner, enabling you to improve the performance and responsiveness of your Nodepp-based applications.

```cpp
#include <nodepp/nodepp.h>
#include <nodepp/popen.h>

using namespace nodepp;

void onMain(){

    array_t<string_t> cmd ({ "curl", "http://www.google.com/", "-Ls" });
    auto fd = popen::async( cmd[0], cmd );

    fd.onDout([]( string_t chunk ){
        conio::done("stdout: ");
        console::log( chunk );
    });

    fd.onDerr([]( string_t chunk ){
        conio::error("stderr: ");
        console::log( chunk );
    });

    fd.onData([]( string_t chunk ){
        console::log( ":>", chunk );
    });

}
```