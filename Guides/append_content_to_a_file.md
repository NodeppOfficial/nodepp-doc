# Append Content To A File

Nodepp provides two simple ways to append content to a file, both using the fs.h header. Appending means adding new data to the end of a file without overwriting its existing content. This is useful for tasks like logging events or continuously writing data.

### Method 1: The fs::append_file() Function

The most direct way to append data is by using the static function fs::append_file(). This function takes the file path and the content to be appended as arguments. It handles opening and closing the file automatically, making it ideal for quick, single-use operations.

```cpp
#include <nodepp/nodepp.h>
#include <nodepp/stream.h>
#include <nodepp/fs.h>

using namespace nodepp;

void onMain() {
    // This will create the file if it doesn't exist.
    // Otherwise, it will add "Hello World!" to the end of the file.
    fs::append_file( "my_log_file.txt", "Hello World!\n" );
}
```

### Method 2: The file_t Class

For more control or when you need to perform multiple write operations on the same file, you can use the file_t class. This approach requires you to explicitly open the file in append mode and then manually write to it.

```cpp
#include <nodepp/nodepp.h>
#include <nodepp/stream.h>
#include <nodepp/fs.h>

using namespace nodepp;

void onMain() {
    // Open the file in append mode ("a").
    auto file = file_t( "my_log_file.txt", "a" );
    // Write the content to the file.
    file.write( "Hello World !\n" );
    // The file is automatically closed when 'file' is destroyed.
}
```

Both methods achieve the same result: adding content to the end of a file. The first method is simpler for one-off tasks, while the second provides more flexibility for complex file handling scenarios.
