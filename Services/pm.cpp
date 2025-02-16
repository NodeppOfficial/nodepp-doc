#define MAX_FILENO 10485760

#include <nodepp/nodepp.h>
#include <nodepp/popen.h>

using namespace nodepp;

bool active = true;

void _init_( const string_t& x, const map_t<string_t,uchar>& pm ) {
    if( !active ){ return; }
    auto pid = popen::async(x); console::log( x, "started" );
    pid.onData ([=]( string_t data ){ console::log(data); });
    pid.onDerr ([=]( string_t data ){ console::log(data); });
    pid.onClose.once([=](){ console::log( x, "closed" ); _init_( x, pm ); });
}

void onMain(){

    map_t<string_t,uchar> pm ({ { "./prxy", 4 } });

    for  ( auto &x: pm.keys() ){ auto y = pm[x]; 
    while( y-->0 ){ _init_( x, pm ); }}

    console::log( "pm -> started" );
    process::onSIGEXIT([=](){ active = false; });
    
}