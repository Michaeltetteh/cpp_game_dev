#ifndef LEARNSDL_VERTEXARRAYBUFFER_H
#define LEARNSDL_VERTEXARRAYBUFFER_H

#include <glad/glad.h>

class VertexArrayBuffer {
public:
    VertexArrayBuffer(const float* verts, unsigned int numVerts,const unsigned int* indices, unsigned int numIndices);
    ~VertexArrayBuffer();

    //actives this vertex array buffer
    void SetActive();

    unsigned int GetNumVerts() const { return mNumVerts;}
    unsigned int GetNumIndicies() const { return mNumIndices;}

private:
    //How many vertices in the vertex buffer?
    unsigned int mNumVerts;
    //How many indices in the index buffer
    unsigned  int mNumIndices;
    //OpenGL ID of the vertex buffer
    unsigned  int mVertexBuffer;
    //OpenGL ID of the index buffer
    unsigned  int mIndexBuffer;
    //OpenGL ID of the vertex array object
    unsigned  int mVertexArray;
};


#endif
