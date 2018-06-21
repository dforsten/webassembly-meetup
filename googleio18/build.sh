emcc -s WASM=1 -o fib.js fib.c -s EXTRA_EXPORTED_RUNTIME_METHODS='["cwrap"]'
