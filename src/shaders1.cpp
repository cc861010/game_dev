//https://learnopengl.com/code_viewer_gh.php?code=src/1.getting_started/2.1.hello_triangle/hello_triangle.cpp


#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
void processInput(GLFWwindow *window){
    if(glfwGetKey(window,GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window,true);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}

//settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

const char *vertexShaderSource = "#version 330 core\n"
                                 "layout (location=0) in vec3 aPos;\n"
                                 "out vec4 vertexColor;\n"
                                 "void main()\n"
                                 "{\n"
                                 "  gl_Position = vec4(aPos.x,aPos.y,aPos.z,1.0);\n"
                                 "  vertexColor = vec4(0.5, 0.0, 0.0, 1.0);\n"
                                 "}\0";

const char *fragementShaderSource = "#version 330 core\n"
                                    "out vec4 FragColor;\n"
                                    "in vec4 vertexColor;\n"
                                    "void main()\n"
                                    "{\n"
                                    "   FragColor = vertexColor;\n"
                                    "}\n\0";

int main() {
    //glfw: initialize and configure
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    //uncomment this statement to fix compilation on OS X
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT,GL_TRUE);
#endif
    //glfw window creation
    GLFWwindow *window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "learnOpenGL", NULL, NULL);
    if (window == NULL) {
        std::cout << "Failed to create GLFW window" << std::endl;
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    //glad: load all OpenGl function pointers
    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    //build and compile our shader program
    int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    //check for shader compile errors
    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::shader::vertex::compilation_failed\n" << infoLog << std::endl;
        exit(-1);
    }
    //fragment shader
    int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragementShaderSource, NULL);
    glCompileShader(fragmentShader);
    //check for shader compile errors
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << "error:shader::fragment::compile_failed\n" << infoLog << std::endl;
        exit(-1);
    }

    //link shaders
    int shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    //check for linking errors
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout << "ERROR::shader:program::linking_failed\n" << infoLog << std::endl;
    }
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    //set up vertex data (and buffer(s)) and configure vertex attributes
    float vertices[] = {
            -0.5f, -0.5f, 0.0f, //left
            0.5f, -0.5f, 0.0f, //right
            0.0f, 0.5f, 0.0f //top
    };

    unsigned int VBO,VAO;
    glGenVertexArrays(1,&VAO);
    //bind the vertex array object first, then bind and set vertex buffer(s),and then configure
    //vertex attributes(s)
    glBindVertexArray(VAO);

    glGenBuffers(1,&VBO);
    glBindBuffer(GL_ARRAY_BUFFER,VBO);
    glBufferData(GL_ARRAY_BUFFER,sizeof(vertices),vertices,GL_STATIC_DRAW);

    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,3*sizeof(float),(void*)0);
    glEnableVertexAttribArray(0);
    //note that this is allowed,the call to glVertexAttribPointer registered VBO as
    //the vertex attribute's bound vertex buffer object so afterwards we can safety
    //unbind
    glBindBuffer(GL_ARRAY_BUFFER,0);
    //you can unbind the vao afterwards so other vao calls won't accidentally modify
    //this vao,but this rarely happens,Modifying other
    //vaos requires a call to glBindVertexArray anyways so we generally don't unbind vaos(nor vbos)
    //when it's not directly necessary
    //glBindVertexArray(0);

    //uncomment this call to draw in wireframe polygons.
    //glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);

    //render loop
    while(!glfwWindowShouldClose(window)){
        //input
        processInput(window);
        //render
        glClearColor(0.2f,0.3f,0.3f,1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        //draw our first triangle
        glUseProgram(shaderProgram);
        //seeing as we only have a single VAO there's no need to bind it every time
        //but we'll do so to keep things a bit more organized
        //glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES,0,3);
        //glBindVertexArray(0) //no need to unbind it every time

        //glfw: swap buffers and poll io events(keys pressed/released,mouse moved etc.)
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    //optional: de-allocate all resources once they've outlived their purpose;
    glDeleteVertexArrays(1,&VAO);
    glDeleteBuffers(1,&VBO);

    // optional: de-allocate all resources once they've outlived their purpose:
    glfwTerminate();
    return 0;

}

