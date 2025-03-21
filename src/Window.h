#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

class Cube
{
};

enum class WindowMode {
    FULLSCREEN,
    WINDOWED,
};

class Window {
private:
    GLFWwindow* m_window;

public:
    Window(const int width, const int height, const char* const window_title, WindowMode window_mode = WindowMode::WINDOWED) {
        // glfw: initialize and configure
        if (!glfwInit()) {
            std::cout << "Failed to initialize GLFW \n";
            exit(1);
        }
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        if (window_mode == WindowMode::FULLSCREEN) {
            // Ottieni il monitor primario
            GLFWmonitor* monitor = glfwGetPrimaryMonitor();

            // Ottieni la risoluzione video del monitor
            const GLFWvidmode* mode = glfwGetVideoMode(monitor);

            // Crea la finestra in modalità fullscreen
            m_window = glfwCreateWindow(mode->width, mode->height, window_title, monitor, NULL);
        } else if(window_mode == WindowMode::WINDOWED) {
            m_window = glfwCreateWindow(width, height, window_title, NULL, NULL);
        }
        
        // glfw window creation
        if (m_window == NULL) {
            std::cout << "Failed to create window" << std::endl;
            glfwTerminate();
            exit(1);
        }
        glfwMakeContextCurrent(m_window);

        // glad: load all OpenGL function pointers
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
            std::cout << "Failed to initialize GLAD" << std::endl;
            exit(1);
        }
    }

    ~Window() {
        glfwTerminate();
    }

    bool isOpen() const {
        return !glfwWindowShouldClose(m_window);
    }

    void display() const {
        glfwPollEvents();
        glfwSwapBuffers(m_window);
    }


    //Getter for width and heigth of the window
    int getWindowWidth() const {
        int width;
        glfwGetWindowSize(m_window, &width, NULL);
        return width;
    }

    int getWindowHeight() const {
        int height;
        glfwGetWindowSize(m_window, NULL, &height);
        return height;
    }
};