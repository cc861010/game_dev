#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;

out vec3 ourColor;

void main()
{
//    1.Adjust the vertex shader so that the triangle is upside down: solution.
//    gl_Position = vec4(aPos.x,-aPos.y,aPos.z, 1.0);

//    2.Specify a horizontal offset via a uniform and move the triangle to the right side of the screen in the vertex shader using this offset value: solution.
//    gl_Position = vec4(aPos.x+0.5,aPos.y,aPos.z, 1.0);

    gl_Position = vec4(aPos.x,aPos.y,aPos.z, 1.0);

//3. Output the vertex position to the fragment shader using the out keyword and set the fragment's color equal to this vertex position (see how even the vertex position values are interpolated across the triangle). Once you managed to do this;
//try to answer the following question: why is the bottom-left side of our triangle black?
    //ourColor = aPos;


    ourColor = aColor;
}