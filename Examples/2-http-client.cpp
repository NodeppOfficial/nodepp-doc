#include <nodepp/nodepp.h>
#include <nodepp/http.h>

using namespace nodepp;

void onMain() {

    fetch_t args;
            args.method = "GET";
            args.url = "http://www.google.com/";
            args.headers = header_t({ 
                { "Host", url::host(args.url) } 
            });

    http::fetch( args )

    .then([]( http_t cli ){
        auto data = stream::await( cli );
        console::log( "->", data );
    })

    .fail([]( except_t err ){
        console::error( err );
    });

}