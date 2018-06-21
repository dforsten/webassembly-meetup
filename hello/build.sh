if [ ! -d "build" ]; then
  mkdir build
fi
cd build
emcc ../hello.c -s WASM=1 -o hello.html
cd ..