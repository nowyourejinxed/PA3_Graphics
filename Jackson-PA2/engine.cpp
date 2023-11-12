//Sabrina Jackson: added comments
#include "engine.h"

//class constructor, sets attributes
Engine::Engine(const char* name, int width, int height)
{
  m_WINDOW_NAME = name;
  m_WINDOW_WIDTH = width;
  m_WINDOW_HEIGHT = height;

}

//class destructor
Engine::~Engine()
{
  delete m_window;
  delete m_graphics;
  m_window = NULL;
  m_graphics = NULL;
}

//Initializes a window and graphics class
bool Engine::Initialize()
{
  // Start a window
  m_window = new Window(m_WINDOW_NAME, &m_WINDOW_WIDTH, &m_WINDOW_HEIGHT);
  if(!m_window->Initialize())
  {
    printf("The window failed to initialize.\n");
    return false;
  }

  // Start the graphics
  m_graphics = new Graphics();
  if(!m_graphics->Initialize(m_WINDOW_WIDTH, m_WINDOW_HEIGHT))
  {
    printf("The graphics failed to initialize.\n");
    return false;
  }

 
  // No errors
  return true;
}


void Engine::Run()
{
  m_running = true;

  while (!glfwWindowShouldClose(m_window->getWindow()))
  {
      ProcessInput();
      Display(m_window->getWindow(), glfwGetTime());
      glfwPollEvents();
  }
  m_running = false;

}
//processes key inputs from user
void Engine::ProcessInput()
{
    if (glfwGetKey(m_window->getWindow(), GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(m_window->getWindow(), true);
}

unsigned int Engine::getDT()
{
    return glfwGetTime();
}

//returns current time
long long Engine::GetCurrentTimeMillis()
{
    return (long long) glfwGetTime();
}

//displays, updates window with graphics
void Engine::Display(GLFWwindow* window, double time) {

    m_graphics->Render();

    m_window->Swap();

    m_graphics->Update(time, speed);
}
static void cursorPositionCallBack(GLFWwindow* window, double xpos, double ypos) {
    //cout << xpos << " " << ypos << endl;
}
