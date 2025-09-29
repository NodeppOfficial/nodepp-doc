# Copying Files

This example demonstrates how to copy a file from a source to a destination using Nodepp's asynchronous streaming API. Instead of loading the entire file into memory at once, this method uses stream::pipe() to efficiently transfer data in small chunks. This non-blocking approach is ideal for handling large files, preventing your application from freezing or becoming unresponsive during the copy process.

```cpp
#include <nodepp/nodepp.h>
#include <nodepp/stream.h>
#include <nodepp/fs.h>

using namespace nodepp;

void onMain() {
    // Create a readable stream for the source file.
    // Replace "Input.txt" with the path to the file you want to copy.
    auto input_file = fs::readable("Input.txt");

    // Create a writable stream for the destination file.
    // Replace "Output.txt" with the desired path for the copied file.
    auto output_file = fs::writable("Output.txt");

    // The onClose event handler is triggered when the input stream is closed,
    // which signifies that the entire file has been read and copied.
    input_file.onClose([]() {
        console::log("File copy completed successfully!");
    });

    // Use stream::pipe() to efficiently transfer data from the readable stream
    // to the writable stream. This is a non-blocking operation.
    stream::pipe(input_file, output_file);
}
```
