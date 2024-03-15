#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "vendor/stb_image/stb_image.h"

#include "ft_OpenGL.h"
#include "ImGuiDebugger.h"
#include "Shader.h"
#include "Texture.h"

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
    window = glfwCreateWindow(540, 540, "Hello World", NULL, NULL);
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
    


    

    float vertices[] = {
        // positions          // colors           // texture coords
         0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // top right
         0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // bottom right
        -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // bottom left
        -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // top left 
    };

    unsigned int indices[] = {
    0, 1, 3, // first triangle
    1, 2, 3  // second triangle
    };

    unsigned int VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);
    //important to first bind the Vertex array object, then the vertex buffer

    unsigned int vb;
    glGenBuffers(1, &vb);
    glBindBuffer(GL_ARRAY_BUFFER, vb);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    unsigned int ib;
    glGenBuffers(1, &ib);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ib);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    //position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT,GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    //color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    //texture coords
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);


    int width, height, nrChannels;
    unsigned char* data = stbi_load("./res/textures/container.jpg", &width, &height, &nrChannels, 0);

    stbi_set_flip_vertically_on_load(true);



    Shader shader("./res/shaders/VertexShader.glsl", "./res/shaders/FragmentShader.glsl");
    shader.Bind();

    Texture texture1("./res/textures/container.jpg", GL_RGB, 0);
    Texture texture2("./res/textures/awesomeface.png", GL_RGBA, 1);
    shader.SetUniform1i("texture1", 0);
    shader.SetUniform1i("texture2", 1);



    //glm::vec4 vec(1.0f, 0.0f, 0.0f, 1.0f);
    //glm::mat4 trans = glm::mat4(1.0f);
    //Print4x4Matrix(trans);
    ////trans = glm::translate(trans, glm::vec3(1.0f, 1.0f, 0.0f));

    //trans = glm::rotate(trans, glm::radians(90.0f), glm::vec3(0.0, 0.0, 1.0));
    //Print4x4Matrix(trans);
    //trans = glm::scale(trans, glm::vec3(0.5, 0.5, 0.5));
    //Print4x4Matrix(trans);
    //vec = trans * vec;
    //PrintVec4(vec);


    





    ImGuiDebugger imGui(window);
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

        glm::mat4 trans = glm::mat4(1.0f);
        trans = glm::rotate(trans, (float)glfwGetTime(), glm::vec3(0.0f, 0.0f, 1.0f));
        shader.SetUniformMatrix4fv("transform", trans);


        //float timeValue = glfwGetTime();
        //float greenValue = (sin(timeValue) / 2.0f) + 0.5f;
        //shader.SetUniform4f("ourColor", 0.0f, greenValue, 0.0f, 1.0f);


        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);


        imGui.Render();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    imGui.Destroy();

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &vb);
    glDeleteBuffers(1, &ib);

    glfwTerminate();
    return 0;
}