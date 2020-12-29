# pong-template

A project to showcase [sgg](https://github.com/liarokapisv/sgg)'s new packaging.

## Dependencies

This package requires the [sgg](https://github.com/liarokapisv/sgg) library to be installed. Check the documentation
for more information. We will be using vcpkg in order to fetch the testing dependencies.

```
vcpkg install gtest
vcpkg install rapidcheck
```


## Configuring & Building

```
cmake -B build -DCMAKE_TOOLCHAIN_FILE=$VCPKG_INSTALL_DIR/scripts/buildsystems/vcpkg.cmake
cmake --build build
cmake --build build --target run_tests
./build/pong_exe
```
