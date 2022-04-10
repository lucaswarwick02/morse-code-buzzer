IF EXIST %~dp0build RMDIR  /S /Q %~dp0build

mkdir build && cd build
cmake -G "MinGW Makefiles" ..

cd ../

cd %~dp0build/morse-code-translator
mingw32-make