#include <nodepp/nodepp.h>
#include <nodepp/timer.h>

using namespace nodepp;

void onMain() {

    //Interval: a setInterval equivalent
    auto A = timer::interval([=](){ 
        static int x=0; x++; x %= 1000;
        console::done("Interval:",x," seconds");
    },1000);

    //Timeout: a setTimeout equivalent
    auto B = timer::timeout([=](){
        console::error("timeout: 10 seconds");
    },10000);

    //Clear the timers
    timer::clear(A); timer::clear(B);

}