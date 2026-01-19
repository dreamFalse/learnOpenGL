#ifndef SHADER_H 
#define SHADER_H 

#include <glad/glad.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader 
{
public:
    // 程序ID
    unsigned int ID; 

    // 构造器读取并构建着色器
    Shader(const char* vertexPath, const char* fragmentPath); 
    // 使用激活程序
    void use(); 
    // uniform 工具函数
    void setBool(const std::string &name, bool value) const; 
    void setInt(const std::string &name, int value) const; 
    void setFloat(const std::string &name, float value) const; 
}; 

Shader::Shader(const char* vertexPath, const char* fragmentPath) 
{
    // 1. 从文件路径获取顶点/片段着色器
    std::string vertexCode; 
    std::string fragmentCode; 
    std::ifstream vShaderFile; 
    std::ifstream fShaderFile; 
    // 保证ifstream对象可以抛出异常
    vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit); 
    fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit); 
    try 
    {
        // 打开文件
        vShaderFile.open(vertexPath); 
        fShaderFile.open(fragmentPath); 
        std::stringstream vShaderStream, fShaderStream; 
        // 读取文件的缓冲内容到数据流
        vShaderStream << vShaderFile.rdbuf(); 
        fShaderStream << fShaderFile.rdbuf(); 
        // 关闭文件处理器
        vShaderFile.close(); 
        fShaderFile.close(); 
        // 轮换数据流到string 
        vertexCode = vShaderStream.str(); 
        fragmentCode = fShaderStream.str(); 
    }
    catch(std::ifstream::failure e) {
        std::cout << "ERROR::SHADER::FILE_NOT_SUCCESSFULLY_READ" << std::endl; 
    }
    const char* vShaderCode = vertexCode.c_str(); 
    const char* fShaderCode = fragmentCode.c_str(); 

    // 2. 编译着色器
    unsigned int vertex, fragment; 
    int success; 
    char infoLog[512]; 

    // 顶点着色器
    
}

void Shader::use()
{
    glUseProgram(ID); 
}

#endif 