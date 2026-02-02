# Observers

This code demonstrates the Observer design pattern using Nodepp's observer_t. The Observer pattern is a behavioral pattern where an object, known as the subject, maintains a list of its dependents, called observers, and notifies them automatically of any state changes. This is a powerful way to implement event handling and reactive programming.

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
