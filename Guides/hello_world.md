# Getting Started: Hello World! in Nodepp 👋

This is the most basic example of a Nodepp application, demonstrating how to print a message to the console. This simple program serves as the entry point for all Nodepp applications and is a great way to verify that your development environment is set up correctly.

```cpp
#include <nodepp/nodepp.h>
#include <nodepp/http.h>

using namespace nodepp;

void onMain() {

    console::log("hello world!");

}
```
