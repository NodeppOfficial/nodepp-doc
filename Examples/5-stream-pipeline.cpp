#include <nodepp/nodepp.h>
#include <nodepp/fs.h>

using namespace nodepp;

void onMain() {

    auto write= fs::writable("PATH_1");
    auto read = fs::readable("PATH_2");

    read.onClose.once([](){ 
        console::log("done"); 
    });

    stream::pipe( read, write );

}