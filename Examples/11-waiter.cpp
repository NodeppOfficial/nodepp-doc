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