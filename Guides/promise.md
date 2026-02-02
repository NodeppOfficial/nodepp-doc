# Promises

Promises are a powerful feature in Nodepp that provide a cleaner and more intuitive way to handle asynchronous operations. A Promise is an object that represents the eventual completion (or failure) of an asynchronous operation and its resulting value.

In Nodepp, Promises are commonly used to simplify the handling of asynchronous code, which is a key component of Nodepp development. Promises allow you to write asynchronous code that is more readable and easier to manage, compared to traditional callback-based approaches.

```cpp
#include <nodepp/nodepp.h>
#include <nodepp/promise.h>
#include <nodepp/timer.h>

using namespace nodepp;

void onMain() {

    promise_t<int,except_t>([=]( res_t<int>, rej_t<except_t> rej ){
        timer::timeout([=](){ res(10); },1000);
    })

    .then([=]( int res ){
        console::done(":>",res);
    })

    .fail([=]( except_t rej ){
        console::error(":>",rej);
    });

}
```

###  HTTP Fetch Request
This example uses promises to handle an asynchronous HTTP request.

```cpp
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
```
