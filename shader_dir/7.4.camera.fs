#version 330 core
out vec4 FragColor; 

in vec2 TexCoord; 

// texture samplers 
uniform sampler2D texture1; 
uniform sampler2D texture2; 

void main()
{
    // 按照 80% container 20% awesomeface 线性插值进行贴图
    FragColor = mix(texture(texture1, TexCoord), texture(texture2, TexCoord), 0.2); 
}