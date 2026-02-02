# Get The MIME Type Of A File

This example shows how to use Nodepp's path::mimetype() function to get the MIME type of a file. The path.h library provides tools for handling file path data, and this specific function is designed to return the correct MIME type based on the file extension.

A MIME type **(Multipurpose Internet Mail Extensions)** is a two-part identifier for file formats and content types on the internet. It helps programs, like web browsers, understand how to handle a file—for example, whether to display an image, play a video, or execute a script. The format is typically type/subtype

```cpp
#include <nodepp/nodepp.h>
#include <nodepp/path.h>

using namespace nodepp;

void onMain() {

    path::mimetype( "main.cpp" );  // text/X-CPP

    path::mimetype( "image.svg" ); // image/svg+xml

    path::mimetype( "file.pdf" );  // application/pdf

}
```
