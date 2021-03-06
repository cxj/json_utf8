About
-----

json\_utf8 is a \*nix-only, UTF-8 only fork of the [SimpleJSON](https://github.com/mjpa/SimpleJSON) library.

The SimpleJSON library is cross platform, and uses UTF-16 "wide" characters and strings.  These "wide" strings are difficult to convert to and from the far more common UTF-8 strings used by most C++ programmers on POSIX systems.

This library (json\_utf8) attempts to make life easier for the rest of us using UTF-8 strings.

json\_utf8 is a simple JSON library written in C++. It is designed to be easy
to use.

The library consists of 2 classes - JSON and JSONValue. The JSON class acts
similar to the Javascript JSON object and contains Parse() and Stringify()
methods for dealing with decoding and encoding JSON text. The JSONValue class
is the class that deals with representing the various JSON values in a C++ way.

Included with the source code is a demo application to give a basic example of
how the library works and run some tests on the library. Linux users should
just need the basic development tools installed.

This library requires no 3rd party libraries and so can be dropped into any
existing project effortlessly. It has been tested on FreeBSD, MacOSX and Linux.
