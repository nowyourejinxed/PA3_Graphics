#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <iostream>
using namespace std;

#include "graphics_headers.h"
#include "camera.h"
#include "shader.h"
#include "object.h"
#include "cube.h"
#include "pyramid.h"

class Graphics
{
  public:
    Graphics();
    ~Graphics();
    bool Initialize(int width, int height);
    void Update(unsigned int dt, glm::vec3 speed);
    void Render();
    void ApplyRotation(float, bool);
    Cube* getInteractWithCube();

    Cube* getCube() { return m_cube; }

    Pyramid* getInteractWithPyramid();

    Pyramid* getPyramid() { return m_pyramid; }

  private:
    std::string ErrorString(GLenum error);

    Camera *m_camera;
    Shader *m_shader;

    GLint m_projectionMatrix;
    GLint m_viewMatrix;
    GLint m_modelMatrix;
    GLint m_vertPos;
    GLint m_vertCol;

    //Object* m_triangle;
    Cube* m_cube;
    Pyramid* m_pyramid;

};

#endif /* GRAPHICS_H */
