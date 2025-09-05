# Corouines

Coroutines are a programming construct that allow for the cooperative multitasking of different sections of code within a single thread of execution. Unlike traditional subroutines **(functions)** that have a single entry and exit point, coroutines can be suspended and resumed, allowing for more flexible control flow.

```cpp
#include <nodepp/nodepp.h>
#include <nodepp/fs.h>

using namespace nodepp;

void onMain(){

    auto fd = fs::readable( "LICENSE" );

    process::add( coroutine::add( COROUTINE(){
    coBegin

        while( fd.is_available() ){
            console::log( ":>", fd.read_line().slice(0,-1) );
            coNext;
        }

    coFinish
    }));

    process::add( coroutine::add( COROUTINE(){
    coBegin

        while( fd.is_available() ){
            console::done("Hello World");
            coNext;
        }

    coFinish
    });

}
```
