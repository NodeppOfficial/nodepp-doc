# Installation 

Get familiar with the basic setup and overview of Nodepp.

First, you need to install a C++ compiler and a git client in your PC.
```bash
# C++ Compiler & Git Client
    🪟: pacman -S mingw-w64-ucrt-x86_64-gcc git
    🐧: sudo apt install build-essential git
```

If you are using a windows machine, We'll recommend you Install [MSYS2](https://www.msys2.org/) before.

### Dependencies

```bash
# Openssl
    🪟: pacman -S mingw-w64-ucrt-x86_64-openssl
    🐧: sudo apt install libssl-dev
```

```bash
# Zlib
    🪟: pacman -S mingw-w64-ucrt-x86_64-zlib
    🐧: sudo apt install zlib1g-dev
```

<br>

### Usage

- **1st:** Clone the github repository
```bash
    git clone https://github.com/NodeppOficial/nodepp ; cd nodepp
```

- **2nd:** Write Your Code
```cpp
#include <nodepp/nodepp.h>

using namespace nodepp;

void onMain() {
    console::log("Hello World");
}
```

- **3rd:** Compile the project
```bash
    🪟: g++ -o main main.cpp -I ./include -lws2_32 ; ./main.exe
    🐧: g++ -o main main.cpp -I ./include ; ./main
```