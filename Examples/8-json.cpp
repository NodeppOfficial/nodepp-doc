#include <nodepp/nodepp.h>
#include <nodepp/json.h>

using namespace nodepp;

void onMain() {

    string_t data = R"({
        "var1": 1000,
        "var2": true,
        "var3": { 
            "var1": "Hello World"
        },
        "var4": [ 10, 20, 30, 40, 50 ]
    })";

    auto obj = json::parse( data );

    console::log( "->", obj["var1"].as<int>() );
    console::log( "->", obj["var4"][2].as<int>() );
    console::log( "->", obj["var3"]["var1"].as<string_t>() );
    console::log( "->", obj["var2"].as<bool>() ? "🟢":"🔴" );
    
    console::log( json::stringify( obj ) );

}