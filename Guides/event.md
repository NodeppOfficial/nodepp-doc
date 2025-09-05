# Event

In the Nodepp library, the event-driven architecture is a fundamental concept that allows you to handle multiple asynchronous interactions within your application. `event_t` provide a powerful and flexible way to decouple different components of your Nodepp-based system, enabling them to communicate and coordinate with each other in a non-blocking manner.

```cpp
#include <nodepp/nodepp.h>
#include <nodepp/event.h>
#include <nodepp/timer.h>

using namespace nodepp;

void onMain(){

    event_t<> ev;

    ev.on([](){ static uint x = 0; x++;
        console::done( string::format( "Hello World! %u", x ) );
    });

    ev.emit(); // Hello World! 1
    ev.emit(); // Hello World! 2
    ev.emit(); // Hello World! 3
    ev.emit(); // Hello World! 4

}
```
