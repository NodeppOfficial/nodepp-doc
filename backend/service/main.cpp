/*────────────────────────────────────────────────────────────────────────────*/

#include <nodepp/nodepp.h>
#include <nodepp/cluster.h>
#include <express/http.h>

using namespace nodepp;

/*────────────────────────────────────────────────────────────────────────────*/

void client_compilation() {

    header_t list ({
        { "http://localhost:8000/template/index.html", "/index.html" },
        { "http://localhost:8000/template/guide.html", "/guide.html" },
        { "http://localhost:8000/template/docs.html" , "/docs.html"  }
    });

    list.map([=]( type::pair<string_t,string_t> data ){

        fetch_t args;
                args.method = "GET";
                args.url    = data.first;

        http::fetch( args )

        .then([=]( http_t cli ){
            auto dir = path::join( "..", data.second );
            console::log( "->", data.second );
            auto out = file_t( dir, "w" );
            stream::pipe( cli, out );
        })

        .fail([=]( except_t err ){
            console::log( err );
        });

    });

}

/*────────────────────────────────────────────────────────────────────────────*/

void onMain() {

    if( !process::is_child() ){

        auto app = express::http::add();

        app.USE( "/template", express::http::file( "template" ) );
        app.USE( nullptr    , express::http::file( ".." ) );

        app.listen( "localhost", 8000, []( ... ){
            console::log( "-> http://localhost:8000" );
            cluster::add().onData([=]( string_t data ){
                conio::log( "->", data );
            });
        });

    } else { client_compilation(); }

}

/*────────────────────────────────────────────────────────────────────────────*/
