#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "ft_OpenGL.h"

#include "ImGuiDebugger.h"

#include "Shader.h"

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(960, 540, "Hello World", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    if (glewInit() != GLEW_OK)
        std::cout << "Error!" << std::endl;

    std::cout << glGetString(GL_VERSION) << std::endl;
    


    Shader shader("./res/shaders/VertexShader.glsl", "./res/shaders/FragmentShader.glsl");

    float vertices[] = {
        //positions           //color
        -0.5f, -0.5f, 0.0f,   1.0f,  0.0f, 0.0f, //v1
         0.5f, -0.5f, 0.0f,   0.0f,  1.0f, 0.0f, //v2
         0.0f,  0.5f, 0.0f,   0.0f,  0.0f, 1.0f  //v3
    };

    unsigned int VAO;
    unsigned int VBO;

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    //important to first bind the Vertex array object, then the vertex buffer
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    //position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT,GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    //color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    shader.Bind();

    glDrawArrays(GL_TRIANGLES, 0, 3);
    ImGuiDebugger imGui(window);
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);


        //float timeValue = glfwGetTime();
        //float greenValue = (sin(timeValue) / 2.0f) + 0.5f;
        //shader.SetUniform4f("ourColor", 0.0f, greenValue, 0.0f, 1.0f);




        glDrawArrays(GL_TRIANGLES, 0, 3);


        imGui.Render();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    imGui.Destroy();

    glfwTerminate();
    return 0;
}