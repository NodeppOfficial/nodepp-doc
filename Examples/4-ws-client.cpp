#include <nodepp/nodepp.h>
#include <nodepp/timer.h>
#include <nodepp/fs.h>
#include <nodepp/ws.h>

using namespace nodepp;

void onMain() {

    auto client = ws::client( "ws://localhost:8000/" );
    
    client.onConnect([=]( ws_t cli ){ 
        
        console::log("connected"); 

        cli.onData([]( string_t chunk ){ 
            console::log("client:>",chunk); 
        });

        cli.onClose([](){ 
            console::log("closed"); 
            process::exit(1);
        });

    });

}