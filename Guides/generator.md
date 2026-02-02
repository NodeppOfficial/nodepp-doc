# Generators

Generators are a special type of function in programming that provide a way to create iterators. Unlike regular functions that return a single value and then terminate, generators can be paused and resumed, allowing them to generate a sequence of values over time.

```cpp
#include <nodepp/nodepp.h>

using namespace nodepp;

GENERATOR( process_1 ) {

    int counter = 10;

    coEmit(){
    coBegin

        while( counter-->0 ){
            console::done( ":>", counter );
            coNext;
        }

    coFinish
    }

};

void onMain(){

    process_1 A; while( A() > 0 ){
        console::log( "->", A.counter );
    }

}
```
