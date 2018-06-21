#include <emscripten.h>

EM_JS(void, drawCircle, (float y, float x, float r), {
    const canvas = document.querySelector('canvas');
    const context = canvas.getContext('2d');
    context.fillStyle = '#ff0000';
    context.beginPath();
    context.arc(x, y, r, 0, 2 * Math.PI);
    context.fill();
});

int main() {
    drawCircle(400.0, 300.0, 50.0);
    return 0;
}
