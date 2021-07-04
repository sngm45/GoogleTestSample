#!/bin/bash
rm -rf ./build
mkdir build
cd build
echo "Platform: $(uname -s)"
if [ "$(expr substr $(uname -s) 1 10)" == 'MINGW32_NT' ]; then
cmake .. -G "MinGW Makefiles"
mingw32-make
elif [ "$(expr substr $(uname -s) 1 10)" == 'MINGW64_NT' ]; then
cmake .. -G "MSYS Makefiles"
mingw32-make
else
cmake ..
make
fi
./MyTest/MyTest