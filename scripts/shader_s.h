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

    unsigned int ID;

    Shader(const char* vertexPath, const char* fragmentPath)
    {
        std::string vertexCode;
        std::string fragmentCode;
        std::ifstream vShaderFile;
        std::ifstream fShaderFile;

        vShaderFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);
        fShaderFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);

        try
        {
            vShaderFile.open(vertexPath);
            fShaderFile.open(fragmentPath);
            std::stringstream vShaderStream, fShaderStream;

            vShaderStream<<vShaderFile.rdbuf();
            fShaderStream<<fShaderFile.rdbuf();

            vShaderFile.close();
            fShaderFile.close();

            vertexCode=vShaderStream.str();
            fragmentCode=fShaderStream.str();
        }
        catch(std::ifstream::failure e)
        {
            std::cout << "ERROR::SHADER::::FILE_NOT_SUCESFULLY_READ" << std::endl;
        }
    const char* vShaderCode = vertexCode.c_str();
    const char* fShaderCode = fragmentCode.c_str();



    }
    void use();
    void setBool(const std::string &name, bool value) const;
    void setInt(const std::string &name, bool value) const;
    void setFloat(const std::string &name, bool value) const;


};

#endif