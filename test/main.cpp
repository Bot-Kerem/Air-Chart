#include<AirChart/window.h>
#include<AirChart/ogl.h>

using namespace AirChart;

int main() {

    Window::init();
    Window window(800, 600, "AirChart");

    GL::init();

    GL::setClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    while(!window.isClosed()) {
        window.pollEvents();
        GL::clear();
        window.update();
    }
    Window::terminate();
    
    return 0;
}