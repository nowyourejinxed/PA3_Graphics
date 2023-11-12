#include "pyramid.h"

Pyramid::Pyramid()
{
	setupVertices();
	setupBuffers();
	setupModelMatrix(glm::vec3(0., 0., 0.), 0., 1.);
}

Pyramid::Pyramid(glm::vec3 pivot)
{
	setupVertices();
	setupBuffers();
	setupModelMatrix(pivot, glm::radians(0.0f), 1.f);
}
Pyramid::Pyramid(glm::vec3 pivot, float angle)
{
	setupVertices();
	setupBuffers();
	setupModelMatrix(pivot, glm::radians(angle), 1.f);
}
Pyramid::Pyramid(glm::vec3 pivot, float angle, float scale)
{
	setupVertices();
	setupBuffers();
	setupModelMatrix(pivot, glm::radians(angle), scale);
}

void Pyramid::setupVertices() {
	Vertices = {
				{{0.0f, 2.0f, 0.0f}, {1.0f, 1.0f, 1.0f}},
				{{1.0f, 0.0f, 1.0f}, {0.0f, 1.0f, 0.0f}},
				{{-1.0f, 0.0f, 1.0f}, {1.0f, 0.0f, 0.0f}},
				{{-1.0f, 0.0f, -1.0f}, {1.0f, 0.0f, 0.0f}},
				{{1.0f, 0.0f, -1.0f}, {0.0f, 0.0f, 1.0f}}
	};

	Indices = {
	  0, 1, 2,
	  0, 2, 3,
	  0, 3, 4,
	  0, 4, 1,
	  1, 2, 3,
	  3, 4, 1
	};



}
void Pyramid::setupBuffers() {
	// For OpenGL 3
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glGenBuffers(1, &VB);
	glBindBuffer(GL_ARRAY_BUFFER, VB);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * Vertices.size(), &Vertices[0], GL_STATIC_DRAW);

	glGenBuffers(1, &IB);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IB);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * Indices.size(), &Indices[0], GL_STATIC_DRAW);
}



Pyramid::~Pyramid()
{
	Vertices.clear();
	Indices.clear();
}


void Pyramid::Render(GLint posAttribLoc, GLint colAttribLoc)
{
	// Bind VAO
	glBindVertexArray(vao);
	// enable the vertex attribute arrays 
	// this is the poistion attrib in the vertex shader
	glEnableVertexAttribArray(posAttribLoc);
	// this is the color attribe in the vertex shader
	glEnableVertexAttribArray(colAttribLoc);
	// Bind VBO(s)
	glBindBuffer(GL_ARRAY_BUFFER, VB);
	glVertexAttribPointer(posAttribLoc, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);
	glVertexAttribPointer(colAttribLoc, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, color));
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IB);

	

	// Draw call to OpenGL
	glDrawElements(GL_TRIANGLES, Indices.size(), GL_UNSIGNED_INT, 0);

	// disable the vertex attributes
	glDisableVertexAttribArray(posAttribLoc);
	glDisableVertexAttribArray(colAttribLoc);

	// unbind VBO(s) and ElementBuffer(s)
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

}
void Pyramid::setupModelMatrix(glm::vec3 pivot, float angle, float scale) {
	pivotLocation = pivot;
	model = glm::translate(glm::mat4(1.0f), pivotLocation);
	model *= glm::rotate(glm::mat4(1.f), angle, glm::vec3(0., 1., 0));
	model *= glm::scale(glm::vec3(scale, scale, scale));
}

