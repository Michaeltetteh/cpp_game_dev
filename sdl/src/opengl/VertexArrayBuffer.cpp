#include "VertexArrayBuffer.h"


VertexArrayBuffer::VertexArrayBuffer(
        const float *verts,
        unsigned int numVerts,
        const unsigned int *indices,
        unsigned int numIndices)
{
    //create vertex array object
    glGenVertexArrays(1,&mVertexArray);
    glBindVertexArray(mVertexArray);

    //create vertex buffer object
    glGenBuffers(1,&mVertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER,mVertexBuffer);
    //copy verts data into vertex buffer
    glBufferData(
        GL_ARRAY_BUFFER,                        // (target) The active buffer type to write to
        numVerts * 3 * sizeof(float),           // (size) Number of bytes to copy
        verts,                                  // (data) source to copy from
        GL_STATIC_DRAW                          // (usage) Specifies the expected usage pattern of the data store
    );

    //create index buffer
    glGenBuffers(1,&mIndexBuffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,mIndexBuffer);
    glBufferData(
            GL_ELEMENT_ARRAY_BUFFER,
            numIndices * sizeof(unsigned int),
            indices,
            GL_STATIC_DRAW
    );

    //specify the vertex attribute layout
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(
            0,                      //(index)Attribute index (0 for first one)
            3,                      //(size)Number of components 3(x,y,z)
            GL_FLOAT,               // Types of components
            GL_FALSE,               // normalized
            sizeof(float) * 3,      // stride (byte offset between consecutive vertices’ attributes)
            0                       // (pointer) Offset from start of vertex to this attribute
    );

}

VertexArrayBuffer::~VertexArrayBuffer()
{
    // destroys vertex buffer, index buffer, and vertex array objects
    glDeleteBuffers(1,&mVertexBuffer);
    glDeleteBuffers(1,&mIndexBuffer);
    glad_glDeleteVertexArrays(1,&mVertexArray);
}

void VertexArrayBuffer::SetActive()
{
    glBindVertexArray(mVertexArray);
}