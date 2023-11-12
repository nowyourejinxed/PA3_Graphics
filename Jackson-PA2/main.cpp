#include <iostream>

#include "engine.h"

int main(int argc, char** argv)
{
	// Start an engine and run it then cleanup after

	glewInit(); //sab added
	glfwInit();
	// Create the engine
	Engine* engine = new Engine("Tutorial Window Name", 800, 600);

	// Engine initialization

	if (!engine->Initialize()) {
		printf("The engine failed to start.\n");
		delete engine;
		engine = NULL;
		return 1;
	}

	// Run the engine
	engine->Run();

	// Destroy the engine
	delete engine;
	engine = NULL;

	return 0;
}
