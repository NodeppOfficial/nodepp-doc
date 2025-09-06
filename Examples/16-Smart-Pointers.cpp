#include <nodepp/nodepp.h>

using namespace nodepp;

class object { public: uint data = 10;
      object(){ console::log("created"); }
     ~object(){ console::log("deleted"); }
};

void onMain() {

    ptr_t<object> ptr = new object();

    process::add( coroutine::add( COROUTINE(){
        static int x = 10;
    coBegin

        while( x-->0 ){
            console::info( "->", ptr->data );
            coDelay( 1000 );
        }

    coFinish
    }));

}
