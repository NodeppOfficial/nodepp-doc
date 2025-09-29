<br>

# Array
```cpp
#include <nodepp/array.h>
```

<hr>

#### class array_t<T> ( const V (&value)[N] )

#### class array_t<T> ( const ptr_t<T>& buffer )

#### class array_t<T> ( ulong size, const T& value )

#### class array_t<T> ( T* buffer, const ulong& size )

<hr>

#### T* array_t::begin()

#### T* array_t::end()

<hr>

#### ulong array_t::first()

#### ulong array_t::last()

#### ulong array_t::size()

<hr>

#### bool array_t::empty()

<hr>

#### long array_t::index_of( function_t<bool,T> callback )

#### ulong array_t::count( function_t<bool,T> callback )

#### T array_t::reduce( function_t<T,T,T> callback )

<hr>

#### bool array_t::every( function_t<bool,T> callback )

#### bool array_t::some( function_t<bool,T> callback )

#### bool array_t::none( function_t<bool,T> callback )

#### void array_t::map( function_t<void,T&> callback )

<hr>

#### ptr_t<int> array_t::find( const array_t& data, ulong offset=0 )

#### ptr_t<int> array_t::find( const T& data, ulong offset=0 )

#### int array_t::compare( const array_t& other )

<hr>

#### array_t array_t::sort( function_t<bool,T,T> callback )

<hr>

#### array_t array_t::replace( function_t<bool,T> callback, const T& targ )

#### array_t array_t::remove( function_t<bool,T> callback )

#### array_t array_t::reverse()

#### array_t array_t::copy()

<hr>

#### void array_t::resize( const V&... args )

#### void array_t::fill( const char& argc )

<hr>

#### void array_t::insert( ulong index, ulong N, const T& value )

#### void array_t::insert( ulong index, const array_t& value )

#### void array_t::insert( ulong index, const V (&value)[N] )

#### void array_t::insert( ulong index, ulong N, T* value )

#### void array_t::insert( ulong index, const T& value )

<hr>

#### void array_t::erase( ulong start, ulong end )

#### void array_t::erase( ulong index )

<hr>

#### void array_t::unshift( const T& value )

#### void array_t::push( const T& value )

#### void array_t::shift()

#### void array_t::pop()

<hr>

#### void array_t::clear()

#### void array_t::erase()

#### void array_t::free()

<hr>

#### string_t array_t::join()

#### string_t array_t::join( string_t c )

<hr>

#### array_t array_t::slice( long start, ulong end )

<hr>

#### array_t array_t::splice( long start, long end )

#### array_t array_t::splice( long start, ulong end, const V (&value)[N] )

<hr>

#### ptr_t<T> array_t::ptr()

#### T* array_t::c_arr()

#### T* array_t::data()

#### T* array_t::get()

<br>