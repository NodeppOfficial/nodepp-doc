# Make A DNS Request

The Nodepp `dns.h` header provides the `dns::lookup()` function to resolve a hostname to its corresponding IPv4 address. This function takes a hostname as input and returns the IPv4 address as a `string_t` if the lookup is successful. If the lookup fails, the function returns `nullptr` instead.

```cpp
#include <nodepp/nodepp.h>
#include <nodepp/dns.h>

using namespace nodepp;

void onMain() {
    auto name = "www.google.com";
    console::log( dns::lookup(name) ); // 142.250.64.228
}
```

To get IPv6 instead, `dns.h` provides the `lookup_ipv6()` function to resolve a hostname to its corresponding IPv6 address.

```cpp
#include <nodepp/nodepp.h>
#include <nodepp/dns.h>

using namespace nodepp;

void onMain() {
    auto name = "www.google.com";
    console::log( dns::lookup_ipv6(name) ); // 2607:f8b0:4008:807::2004
}
```
