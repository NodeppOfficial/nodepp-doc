# Observers

Observers are a design pattern in Nodepp that provide a way to implement the Observer pattern, which is a behavioral design pattern that allows objects to be notified when the state of another object changes.

```cpp
#include <nodepp/nodepp.h>
#include <nodepp/observer.h>

using namespace nodepp;

observer_t obj ({
    { "a", 0 },
    { "b", 0 }
});

void onMain(){

    obj.once( "b", []( any_t A, any_t B ){
        console::done( " B:>", (int)A, "|", (int)B );
    });

    obj.on( "a", []( any_t A, any_t B ){
        console::error( "A:>", (int)A, "|", (int)B );
    });

    obj.set( "b", rand() % 10 );
    obj.set( "a", rand() % 10 );

}
```
