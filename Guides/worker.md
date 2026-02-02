# Workers

Workers in Nodepp are a way to execute CPU-intensive tasks in parallel without blocking the main event loop. This allows Nodepp applications to take advantage of multi-core processors and improve overall performance.

```cpp
#include <nodepp/nodepp.h>
#include <nodepp/worker.h>

using namespace nodepp;

void onMain(){

    ptr_t<int> x = new int(100); mutex_t mut;

    worker::add( mutex::add( mut, coroutine::add( COROUTINE(){
    coBegin

        while( *x > 0 ){
            console::info("Hello World",*x); *x-=1;
            coDelay( 100 ); coNext; 
        }

    coFinish
    }) ));

    worker::add( mutex::add( mut, coroutine::add( COROUTINE(){
    coBegin

        while( *x > 0 ){
            console::done("Hello World",*x); *x-=1;
            coDelay( 100 ); coNext; 
        }

    coFinish
    }) ));

}
```
