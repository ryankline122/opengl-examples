#include "headers/Game.hpp"

Game::Game() : 
m_screenWidth(SCREEN_WIDTH),
m_screenHeight(SCREEN_HEIGHT){}


Game::~Game(){
}


void Game::init(){

    if (!glfwInit()){
        fprintf(stderr, "Failed to initialize GLFW\n");
        return; 
    }

    glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // OpenGL 3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Open a window and create its context
    m_window = glfwCreateWindow(1024, 768, TITLE, NULL, NULL);
    if (m_window == NULL){
        fprintf(stderr, "Failed to open window");
        glfwTerminate();
        return;
    }

    glfwMakeContextCurrent(m_window);
    if (glewInit() != GLEW_OK){
        fprintf(stderr, "Failed to intialize GLEW\n");
        return;
    }

    run();
}


void Game::run(){
    glfwSetInputMode(m_window, GLFW_STICKY_KEYS, GL_TRUE);

    do{
        glClear( GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(m_window);
        glfwPollEvents();
    }
    while(
        glfwGetKey(m_window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
        glfwWindowShouldClose(m_window) == 0
    );

}


void Game::update(double delta_time){
    // Update game objects here
}


void Game::render(){

}