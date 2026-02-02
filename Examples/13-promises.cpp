#include <nodepp/nodepp.h>
#include <nodepp/promise.h>
#include <nodepp/timer.h>

using namespace nodepp;

void onMain() {

    promise_t<int,except_t>([=]( res_t<int> res, rej_t<except_t> rej ){
        timer::timeout([=](){ res(10); },1000);
    })

    .then([=]( int res ){
        console::done(":>",res);
    })

    .fail([=]( except_t rej ){
        console::error(":>",rej);
    });

}
