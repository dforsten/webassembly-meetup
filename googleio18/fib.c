#include <emscripten.h>

EMSCRIPTEN_KEEPALIVE
int fib(int n) {
    int i, t, a = 0, b = 1;
    for (i = 0; i < n; i++) {
        t = a + b;
        a = b;
        b = t;
    }
    return b;
}

int main(int argc, char ** argv) {
  printf("Fibonacci for 12: %d\n", fib(12));
}
