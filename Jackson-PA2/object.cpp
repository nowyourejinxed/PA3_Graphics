#include "object.h"

Object::Object()
{
	// Vertex Set Up
	setupVerticies();

	// Model Set Up
	angle = 0.0f;
	pivotLocation = glm::vec3(0.f, 0.f, 0.f);
	model = glm::translate(glm::mat4(1.0f), pivotLocation);

	// Buffer Set Up
	if (!InitBuffers()) {
		printf("Some buffers not initialized.\n");
	}
}
Object::Object(glm::vec3 pivot)
{
	// Vertex Set Up
	setupVerticies();

	// Model Set Up
	angle = 0.0f;
	pivotLocation = pivot;
	model = glm::translate(glm::mat4(1.0f), pivotLocation);

	// Buffer Set Up
	if (!InitBuffers()) {
		printf("Some buffers not initialized.\n");
	}
}



Object::~Object()
{
	Vertices.clear();
	Indices.clear();
}


glm::mat4 Object::GetModel()
{
	return model;
}

void Object::Render(GLint posAttribLoc, GLint colAttribLoc)
{
	// Bind VAO
	glBindVertexArray(vao);

	// Bind VBO(s)
	glBindBuffer(GL_ARRAY_BUFFER, VB);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IB);

	// enable the vertex attribute arrays 
	// this is the poistion attrib in the vertex shader
	glEnableVertexAttribArray(posAttribLoc);
	// this is the color attribe in the vertex shader
	glEnableVertexAttribArray(colAttribLoc);
	glVertexAttribPointer(posAttribLoc, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);
	glVertexAttribPointer(colAttribLoc, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, color));

	// Draw call to OpenGL
	glDrawElements(GL_TRIANGLES, Indices.size(), GL_UNSIGNED_INT, 0);

	// disable the vertex attributes
	glDisableVertexAttribArray(posAttribLoc);
	glDisableVertexAttribArray(colAttribLoc);

	// unbind VBO(s) and ElementBuffer(s)
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

}
bool Object::InitBuffers() {

	// For OpenGL 3
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glGenBuffers(1, &VB);
	glBindBuffer(GL_ARRAY_BUFFER, VB);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * Vertices.size(), &Vertices[0], GL_STATIC_DRAW);

	glGenBuffers(1, &IB);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IB);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * Indices.size(), &Indices[0], GL_STATIC_DRAW);

	return true;
}

void Object::setupVerticies() {
	Vertices = 
	{
		  {{1.0f, -1.0f, -1.0f}, {0.0f, 0.0f, 0.0f}},
		  {{1.0f, -1.0f, 1.0f}, {1.0f, 0.0f, 0.0f}},
		  {{-1.0f, -1.0f, 1.0f}, {0.0f, 1.0f, 0.0f}},
		  {{-1.0f, -1.0f, -1.0f}, {0.0f, 0.0f, 1.0f}},
		  {{1.0f, 1.0f, -1.0f}, {1.0f, 1.0f, 0.0f}},
		  {{1.0f, 1.0f, 1.0f}, {1.0f, 0.0f, 1.0f}},
		  {{-1.0f, 1.0f, 1.0f}, {0.0f, 1.0f, 1.0f}},
		  {{-1.0f, 1.0f, -1.0f}, {1.0f, 1.0f, 1.0f}}
	};

	Indices = 
	{
	  2, 3, 4,
	  8, 7, 6,
	  1, 5, 6,
	  2, 6, 7,
	  7, 8, 4,
	  1, 4, 8,
	  1, 2, 4,
	  5, 8, 6,
	  2, 1, 6,
	  3, 2, 7,
	  3, 7, 4,
	  5, 1, 8
	};

	for (unsigned int i = 0; i < Indices.size(); i++)
	{
		Indices[i] = Indices[i] - 1;
	}

}

