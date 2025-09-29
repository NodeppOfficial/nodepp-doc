<br>

# Nodepp
```cpp
#include <nodepp/nodepp.h>
```

<hr>

#### void process::start( int argc, char** args )

#### void process::start()

#### void process::stop()

<hr>

#### void process::error( const T&... message )

#### void process::abort()

#### void process::exit()

<hr>

#### int process::spawn( const T&... arguments )

<hr>

#### void process::clear()

#### bool process::empty()

#### ulong process::size()

#### void process::next()

<hr>

#### void* process::add( const T& callback, const V&... arguments )

#### void process::await( const T& callback, const V&... arguments )

<hr>

#### bool process::is_parent()

#### bool process::is_child()

<hr>

#### string_t process::shell()

#### string_t process::home()

<br>