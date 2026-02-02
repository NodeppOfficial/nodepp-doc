# Timers

In the Nodepp library, timers provide a robust and flexible way to schedule the execution of asynchronous tasks at specific points in time. This feature is essential for building applications that require precise timing or the coordination of multiple, time-dependent operations.

```cpp
#include <nodepp/nodepp.h>
#include <nodepp/timer.h>

using namespace nodepp;

void onMain(){

    auto A = timer::interval([=](){
        console::done("set interval");
    },1000);

    auto B = timer::timeout([=](){
        console::error("set timeout");
    },10000);

    auto C = timer::add( coroutine::add( COROUTINE(){
        static uchar x = 100;
    coBegin

        while( x-->0 ){
            console::log(" timer task ");
            coNext;
        }

        process::exit(1);

    coFinish
    }),10000);

}
```
