#pragma once
#ifndef PYRAMID_H
#define PYRAMID_H

#include <vector>
#include "graphics_headers.h"
#include "object.h"

class Pyramid : public Object
{
public:
    Pyramid();
    ~Pyramid();
    Pyramid(glm::vec3 pivot);
    Pyramid(glm::vec3 pivot, float angle);
    Pyramid(glm::vec3 pivot, float angle, float scale);
    void Initialize(GLint posAttribLoc, GLint colAttribLoc);
    void Update(glm::mat4 matModel);
    void Render(GLint posAttribLoc, GLint colAttribLoc);
    

    glm::mat4 GetModel() { return model; };

private:
    glm::mat4 model;
    glm::vec3 pivotLocation;
    std::vector<Vertex> Vertices;
    std::vector<unsigned int> Indices;

    GLuint vao;

    GLuint VB;
    GLuint IB;

    
    float angle;
   

    void setupVertices();
    void setupBuffers();
    void setupModelMatrix(glm::vec3 pivotLocation, float angle, float scale);
};

#endif 
