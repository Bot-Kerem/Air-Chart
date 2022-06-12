#include<AirChart/window.h>

using namespace AirChart;

int main() {

    Window::init();
    Window window(800, 600, "AirChart");

    while(!window.isClosed()) {
        window.pollEvents();
        window.update();
    }
    Window::terminate();
    
    return 0;
}