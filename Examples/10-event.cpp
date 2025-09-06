#include <nodepp/nodepp.h>
#include <nodepp/event.h>

using namespace nodepp;

void onMain() {

    event_t<> event; 

    event.on([](){ 
        console::done("execute too many times"); 
    });

    event.once([](){ 
        console::done("execute only once"); 
    });
    
    event.emit();

}