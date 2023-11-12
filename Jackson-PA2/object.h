#ifndef OBJECT_H
#define OBJECT_H

#include <vector>
#include "graphics_headers.h"

class Object
{
  public:
    Object();
    Object(glm::vec3 pivot);
    ~Object();
   
    void Update(unsigned int dt);
    void Render(GLint posAttribLoc, GLint colAttribLoc);
   
    glm::mat4 GetModel();

    bool InitBuffers();
    void setupVerticies();
    
  private:
    glm::mat4 model;
    glm::vec3 pivotLocation;
    std::vector<Vertex> Vertices;
    std::vector<unsigned int> Indices;

    GLuint vao;

    GLuint VB;
    GLuint IB;


    float angle;

};

#endif /* OBJECT_H */
