# Garbge Collector

Garbage Collector in Nodepp isn't more than just a simple Smart Pointer `ptr_t` optimized to be shared among other `Async Tasks` and `Multithreaded processes`.

```cpp
#include <nodepp/nodepp.h>

using namespace nodepp;

class object { public: uint data = 10;
      object(){ console::log("created"); }
     ~object(){ console::log("deleted"); }
};

void onMain() {

    ptr_t<object> ptr = new object();

    process::add( coroutine::add( COROUTINE(){
    coBegin

        while( ptr->data --> 0 ){
            console::log( ptr->data );
            coDelay( 1000 );
        }

    coFinish
    }));

}
```

Here is a more complex example:

```cpp
#include <nodepp/nodepp.h>

using namespace nodepp;

void onMain(){

    ptr_t<uint> GC = new uint(10);

    console::log("-- --");
    console::log( "value->", *GC );
    console::log( "addr ->",  GC );
    console::log( "count->",  GC.count() );

    process::add([=](){ // <- note = and not & | this is important to correctly share the memory across tasks

        console::log("-- --");
        console::log( "value->", *GC );
        console::log( "addr ->",  GC );
        console::log( "count->",  GC.count() );

    return -1;
    });

    process::await([&](){ // <- note & instead = | but you are still able to use =

        console::log("-- --");
        console::log( "value->", *GC );
        console::log( "addr ->",  GC );
        console::log( "count->",  GC.count() );

    return -1;
    });

    console::log("-- --");
    console::log( "value->", *GC );
    console::log( "addr ->",  GC );
    console::log( "count->",  GC.count() );

}
```
