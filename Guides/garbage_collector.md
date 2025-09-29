# Garbge Collector

Nodepp doesn't have a traditional garbage collector but instead uses a smart pointer called ptr_t for automatic memory management. This mechanism simplifies memory handling by automatically deleting an object when its last reference is gone, preventing memory leaks. ptr_t is also designed to be safely shared between different asynchronous tasks and multithreaded processes, which is crucial for building concurrent applications.

The provided examples demonstrate how ptr_t works. A ptr_t is created and a coroutine is added to decrement the object's data member. When the coroutine finishes and the ptr_t goes out of scope, the memory is automatically freed, as shown by the "deleted" message.

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

 The second example illustrates how ptr_t manages its reference count when shared across different process tasks. Notice how the count changes, and the memory is only released when the last reference is dropped. This reference-counting mechanism ensures safe, shared ownership of heap-allocated objects.

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
