#include <nodepp/nodepp.h>
#include <nodepp/ws.h>

using namespace nodepp;

void onMain() {

    auto server = ws::server();

    server.onConnect([=]( ws_t cli ){

        console::log("connected");
        cli.write( "Hello World" );

        cli.onClose([=](){ 
            console::log("closed"); 
        });

        cli.onData([=]( string_t data ){ 
            console::log( data ); 
        });

    });

    server.listen( "localhost", 8000, [=]( socket_t server ){
        console::log("http://localhost:8000");
    });

}