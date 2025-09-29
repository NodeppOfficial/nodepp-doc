# Writing a String to a File in Nodepp

Writing data to a file is a fundamental I/O operation. The Nodepp framework offers two primary methods for this: a simple synchronous function for quick, one-off writes and a stream-based asynchronous method for more efficient handling of larger data.

### 1. Synchronous Method (fs::write_file)

The fs::write_file() function is the simplest way to write a string to a file. It is a synchronous operation, meaning the program will pause and wait for the entire string to be written to the file before continuing. This is ideal for small amounts of data or when the application's flow depends on the write operation completing immediately.

```cpp
#include <nodepp/nodepp.h>
#include <nodepp/fs.h>

using namespace nodepp;

void onMain() {

    string_t path = "/path/to/file.txt";
    string_t data = "Hello World!";

    fs::write_file( path, data );

}
```

### 2. Asynchronous Stream Method (fs::writable)

For larger data, using a writable stream is a more efficient, non-blocking approach. The fs::writable() function creates a file_t object that acts as a stream. Data is written to this stream asynchronously, preventing the application from freezing.

```cpp
#include <nodepp/nodepp.h>
#include <nodepp/fs.h>

using namespace nodepp;

void onMain() {

    auto file fs::writable("/path/to/file.txt");
    string_t data = "Hello World!";

    file.write( data );

}
```
