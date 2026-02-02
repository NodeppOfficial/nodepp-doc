# Deleting Files and Directories with Nodepp

The Nodepp framework offers simple, synchronous functions for managing files and directories. This guide shows how to use the fs::remove_file() and fs::remove_folder() functions to delete files and empty folders.

### fs::remove_file()

The fs::remove_file() function is used to synchronously delete a single file. It takes the path to the file as its only argument.

```cpp
#include <nodepp/nodepp.h>
#include <nodepp/fs.h>

using namespace nodepp;

void onMain() {

    fs::remove_file( "PATH_TO_FILE" );

}
```

### fs::remove_folder()

The fs::remove_folder() function is used to synchronously delete an empty directory. This function will fail if the directory contains any files or subdirectories.

```cpp
#include <nodepp/nodepp.h>
#include <nodepp/fs.h>

using namespace nodepp;

void onMain() {

    fs::remove_folder( "PATH_TO_FOLDER" );

}
```
