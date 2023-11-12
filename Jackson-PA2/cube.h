//Sabrina Jackson
#ifndef CUBE_H
#define CUBE_H
#include <vector>
#include "graphics_headers.h"

class Cube
{
public:
    Cube();
    ~Cube();
    void Initialize(GLint posAttribLoc, GLint colAttribLoc);
    void Update(unsigned int dt);
    void Render(GLint posAttribLoc, GLint colAttribLoc);
    void createVertices();

    glm::mat4 GetModel();

    void setSpeed(glm::vec3 spd) { m_speed = spd; }
    void setRotation(float rot) { m_rotation = rot; }

private:
    glm::mat4 model;
    std::vector<Vertex> Vertices;
    std::vector<unsigned int> Indices;

    GLuint vao;

    GLuint VB;
    GLuint IB;

    glm::vec3 m_speed = glm::vec3(0., 0., 0.);
    glm::vec3 m_position = glm::vec3(0., 0., 0.);
    glm::vec3 m_orientation = glm::vec3(0., 1., 0.);
    float angle;
    float m_rotation;
};


#endif // !CUBE_H

