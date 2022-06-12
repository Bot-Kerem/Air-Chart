#ifndef AC_WINDOW_H
#define AC_WINDOW_H

#include<GLFW/glfw3.h>

namespace AirChart
{
    class Window {
        public:
            Window(int width, int height, const char* title);
            ~Window();

            void update();
            void close();

            bool isClosed();

            GLFWwindow* getWindow();

            static void pollEvents();
            static void init();
            static void terminate();

        private:
            GLFWwindow* window;
            int width;
            int height;
            int posX;
            int posY;
    };
};
#endif
