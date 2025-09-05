# Copying a File to Another Location

This code snippet demonstrates how to efficiently copy a file from one location to another using Nodepp's asynchronous stream API. It uses stream::pipe() to transfer data in a fast, non-blocking manner, which is ideal for large files.

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
