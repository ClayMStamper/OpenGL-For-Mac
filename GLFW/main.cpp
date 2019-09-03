#include <iostream>

#define GLEW_STATIC
#include <GL/glew.h>

#include <GLFW/glfw3.h>

const GLint WIDTH = 800, HEIGHT = 600;

int main(){
    
    glfwInit();
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); //only needed on mac
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    
    GLFWwindow *window = glfwCreateWindow(WIDTH, HEIGHT, "Learn OpenGL", nullptr, nullptr);
    
    if (window == nullptr){
        
        std::cout << "Window null" << std::endl;
        return -1;
        
    }
    
    /*two lines for mac
     - have to get window size unique to particular mac because retina display
     */
    int screenWidth = 0;
    int screenHeight = 0;
    glfwGetFramebufferSize(window, &screenWidth, &screenHeight);
    
    if (window == nullptr){
        
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        
        return -1;
        
    }
    
    glfwMakeContextCurrent(window);
    
    //
    glewExperimental = GL_TRUE;
    
    if (GLEW_OK != glewInit()){
        printf("GLEW init failed!");
        return -1;
    }
    
    glViewport(0, 0, screenWidth, screenHeight);
    
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
        glClearColor(0.2f, 0.3f, 0.4f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
    }
    
    glfwTerminate();
    return 0;
    
}
