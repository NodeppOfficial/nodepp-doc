# Writing to Standard Output (stdout) in Nodepp

Standard output (stdout) is the default channel for a program to print information to the console or terminal. It's essential for displaying status messages, logging data, and interacting with the user. The Nodepp framework provides several ways to write to stdout, from a simple logging function to a powerful stream-based approach.

### Simple Logging with console::log()

For most basic use cases, the console::log() function is the most convenient way to print data to the console. It automatically handles formatting and appends a newline character, making it perfect for quick debugging and displaying messages.

```cpp
#include <nodepp/nodepp.h>

using namespace nodepp;

void onMain() {

    console::log("Hello World !");

}
```

### Stream-based I/O with fs::std_output()

For more advanced scenarios, Nodepp exposes stdout as a writable stream via the fs::std_output() function. This stream-based approach allows for more control and is particularly useful for piping data directly to the console.

```cpp
#include <nodepp/nodepp.h>
#include <nodepp/fs.h>

using namespace nodepp;

void onMain() {

    auto file = fs::std_output();

    file.write( "Hello World! \n" );

}
```

### Streaming a File's Contents to stdout

This powerful use case demonstrates how to pipe the contents of a file directly to the console in real time. It's a highly efficient way to display large files without loading the entire content into memory.

```cpp
#include <nodepp/nodepp.h>
#include <nodepp/stream.h>
#include <nodepp/fs.h>

using namespace nodepp;

void onMain() {

    auto fint = fs::readable( "PATH_TO_FILE" );
    auto file = fs::std_output();

    stream::pipe( fint, file );

}
```
