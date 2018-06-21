#include <emscripten.h>
#include <math.h>

EM_JS(void, drawCircle, (float y, float x, float r), {
    const canvas = document.querySelector('canvas');
    const context = canvas.getContext('2d');
    context.fillStyle = '#ff0000';
    context.beginPath();
    context.arc(x, y, r, 0, 2 * Math.PI);
    context.fill();
});

EM_JS(void, clearCanvas, (), {
    const canvas = document.querySelector('canvas');
    const context = canvas.getContext('2d');
    context.clearRect(0, 0, canvas.width, canvas.height)
});

static float t = 0.0;
extern "C" {
    EMSCRIPTEN_KEEPALIVE
    void update() {
        const float dt = 1.0f / 60.0f;
        t += dt;
        clearCanvas();
        drawCircle(350.0 + (sin(t) * 200), 275.0 - (sin(t*2) * 200), 50.0);
    }
} // extern "C"

int main() {
    drawCircle(400.0, 300.0, 50.0);
    return 0;
}
