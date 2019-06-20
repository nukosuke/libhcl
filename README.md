# LibHCL
[![CodeFactor](https://www.codefactor.io/repository/github/nukosuke/libhcl/badge)](https://www.codefactor.io/repository/github/nukosuke/libhcl)

[HCL2](https://github.com/hashicorp/hcl2/blob/master/hcl/hclsyntax/spec.md) parser library for C

## Installation

N/A currently

## Documentation

[Online Document](https://nukosuke.github.io/libhcl)

Also, you can generate documentation for master branch or specific revision.
It requires [Doxygen](http://www.doxygen.nl/). Doxygen outputs HTML document in `docs/` directory.

``` sh
$ doxygen Doxyfile
```

## Build

LibHCL requires [gcc](https://gcc.gnu.org/)/[clang](https://clang.llvm.org/) C compiler and [CMake](https://cmake.org/).

``` sh
$ cmake .
$ make
```

## License

MPL-2.0

See the file [LICENSE](./LICENSE) for details.
