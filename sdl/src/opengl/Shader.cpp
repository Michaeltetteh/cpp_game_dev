#include "Shader.h"
#include <SDL.h>
#include <fstream>
#include <sstream>

Shader::Shader()
        : mVertexShader(0)
        , mFragShader(0)
        , mShaderProgram(0)
{}

Shader::~Shader()
{}

bool Shader::Load(const std::string& vertName, const std::string& fragName)
{
    // Compile vertex and pixel shaders
    if (!CompileShader(vertName,
                       GL_VERTEX_SHADER,
                       mVertexShader) ||
        !CompileShader(fragName,
                       GL_FRAGMENT_SHADER,
                       mFragShader))
    {
        return false;
    }

    // Now create a shader program that
    // links together the vertex/frag shaders
    mShaderProgram = glCreateProgram();
    glAttachShader(mShaderProgram, mVertexShader);
    glAttachShader(mShaderProgram, mFragShader);
    glLinkProgram(mShaderProgram);

    // Verify that the program linked successfully
    if (!IsValidProgram())
    {
        return false;
    }

    return true;
}

void Shader::Unload()
{
    // Delete the program/shaders
    glDeleteProgram(mShaderProgram);
    glDeleteShader(mVertexShader);
    glDeleteShader(mFragShader);
}

void Shader::SetActive()
{
    // Set this program as the active one
    glUseProgram(mShaderProgram);
}

void Shader::SetMatrixUniform(const char* name, const Matrix4& matrix)
{
    // Find the uniform by this name
    GLuint loc = glGetUniformLocation(mShaderProgram, name);
    // Send the matrix data to the uniform
    glUniformMatrix4fv(loc, 1, GL_TRUE, matrix.GetAsFloatPtr());
}

bool Shader::CompileShader(const std::string& fileName,
                           GLenum shaderType,
                           GLuint& outShader)
{
    // Open file
    std::ifstream shaderFile(fileName);
    if (shaderFile.is_open())
    {
        // Read all the text into a string
        std::stringstream sstream;
        sstream << shaderFile.rdbuf();
        std::string contents = sstream.str();
        const char* contentsChar = contents.c_str();

        // Create a shader of the specified type
        outShader = glCreateShader(shaderType);
        // Set the source characters and try to compile
        glShaderSource(outShader, 1, &(contentsChar), nullptr);
        glCompileShader(outShader);

        if (!IsCompiled(outShader))
        {
            SDL_Log("Failed to compile shader %s", fileName.c_str());
            return false;
        }
    }
    else
    {
        SDL_Log("Shader file not found: %s", fileName.c_str());
        return false;
    }

    return true;
}

bool Shader::IsCompiled(GLuint shader)
{
    GLint status;
    // Query the compile status
    glGetShaderiv(shader, GL_COMPILE_STATUS, &status);

    if (status != GL_TRUE)
    {
        char buffer[512];
        memset(buffer, 0, 512);
        glGetShaderInfoLog(shader, 511, nullptr, buffer);
        SDL_Log("GLSL Compile Failed:\n%s", buffer);
        return false;
    }

    return true;
}

bool Shader::IsValidProgram()
{

    GLint status;
    // Query the link status
    glGetProgramiv(mShaderProgram, GL_LINK_STATUS, &status);
    if (status != GL_TRUE)
    {
        char buffer[512];
        memset(buffer, 0, 512);
        glGetProgramInfoLog(mShaderProgram, 511, nullptr, buffer);
        SDL_Log("GLSL Link Status:\n%s", buffer);
        return false;
    }

    return true;
}


void Shader::SetVec3Uniform(const std::string &name,const glm::vec3 value) const
{
    glUniform3fv(glGetUniformLocation(mShaderProgram, name.c_str()), 1, &value[0]);
}