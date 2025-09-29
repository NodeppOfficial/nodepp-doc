#include <nodepp/nodepp.h>
#include <nodepp/observer.h>

using namespace nodepp;

void onMain() {

    observer_t obj ({ { "a", 0 }, { "b", 0 } });
    
    obj.on( "b", []( any_t A, any_t B ){
        console::done( " B:>", (int)A, "|", (int)B );
    });

    obj.on( "a", []( any_t A, any_t B ){
        console::error( "A:>", (int)A, "|", (int)B );
    });
    
    obj.set( "a", 10 ); obj.set( "b", 20 );

}