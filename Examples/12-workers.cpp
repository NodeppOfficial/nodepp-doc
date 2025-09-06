#include <nodepp/nodepp.h>
#include <nodepp/worker.h>

using namespace nodepp;

void onMain() {

    worker::add( coroutine::add( COROUTINE(){
        static int x = 10;
    coBegin

        while( x-->0 ){
            console::info( "->", x );
            coDelay( 1000 );
        }

    coFinish
    }));

}
