#ifndef GAME_H
#define GAME_H

// Standard Headers
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

// GL headers
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

// Game configs
#include "config.hpp"

class Game {
    public:
        Game();
        ~Game();

        void init();
        void run();
        void update(double delta_time);
        void render();

    private:
        GLFWwindow* m_window;

        bool m_running;
        int m_screenWidth;
        int m_screenHeight;

};

#endif