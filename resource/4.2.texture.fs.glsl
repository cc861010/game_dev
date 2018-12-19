#version 330 core
out vec4 FragColor;

in vec3 ourColor;
in vec2 TexCoord;

// texture samplers
uniform sampler2D texture1;
uniform sampler2D texture2;

void main()
{
	// linearly interpolate between both textures (80% container, 20% awesomeface)
	//FragColor = mix(texture(texture1, TexCoord), texture(texture2, TexCoord), 0.5);
	// Make sure only the happy face looks in the other/reverse direction by changing the fragment shader
	//vec2 newTexCoord = vec2(0.8-TexCoord.x,0.7-TexCoord.y);
	vec2 newTexCoord = vec2(TexCoord.x,TexCoord.y);
	FragColor = mix(texture(texture1, TexCoord), texture(texture2, newTexCoord), 0.9);
}