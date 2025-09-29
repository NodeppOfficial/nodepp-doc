# Compressing and Decompressing Files with Zlib

The zlib module in Nodepp provides a simple way to compress and decompress files using various algorithms. This is particularly useful for reducing file sizes for storage or network transfer.

### Gzip Compression

To compress a file using the gzip algorithm, you can use the zlib::gzip::pipe method. This method takes a readable stream and a writable stream and pipes the compressed data from the source to the destination.

```cpp
#include <nodepp/nodepp.h>
#include <nodepp/zlib.h>
#include <nodepp/fs.h>

using namespace nodepp;

void onMain() {

    auto write= fs::writable("PATH_1");
    auto read = fs::readable("PATH_2");

    read.onClose.once([](){
        console::log("Compressed");
    });

    zlib::gzip::pipe( read, write );

}
```

### Gunzip Decompression

To decompress a file that was compressed with gzip, use the zlib::gunzip::pipe method. This works in the same way, but in reverse.

```cpp
#include <nodepp/nodepp.h>
#include <nodepp/zlib.h>
#include <nodepp/fs.h>

using namespace nodepp;

void onMain() {

    auto write= fs::writable("PATH_1");
    auto read = fs::readable("PATH_2");

    read.onClose.once([](){
        console::log("Dempressed");
    });

    zlib::gunzip::pipe( read, write );

}
```
