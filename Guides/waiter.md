# wait Event Handling

This example demonstrates how to use the nodepp::wait_t object to handle and emit custom events. The wait_t object acts as an event dispatcher, allowing you to attach different behaviors (callbacks) to named events.

```cpp
#include <nodepp/nodepp.h>
#include <nodepp/wait.h>

using namespace nodepp;

void onMain() {

    wait_t<string_t> event; 

    event.on( "onOpen", [](){ 
        console::done(" onOpen emitted "); 
    });

    event.once( "onClose", [](){ 
        console::done(" onClose emitted "); 
    });
    
    event.emit( "onOpen"  );
    event.emit( "onClose" );

}
```