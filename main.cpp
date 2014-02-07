#include <X11/X.h>
#include <X11/Xlib.h>
#include <strings.h>
#include <memory.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <GLFW/glfw3.h>
#include <vector>

#include <iostream>

using namespace std;


static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}

int quitApp() {
	glfwTerminate();
	return -1;
}

/*bool loadObject(const char * path,
    std::vector < glm::vec3 > & out_vertices,
    std::vector < glm::vec2 > & out_uvs,
    std::vector < glm::vec3 > & out_normals) {

	
}*/

int main(int argc, char* argv[3]) {

	GLFWwindow* window;
	GLFWmonitor* monitor;
	int width,height;

	/* Initialize the library */
	if (!glfwInit())
		return quitApp();

	monitor = glfwGetPrimaryMonitor();
	if (!monitor) 
		return quitApp();

	const GLFWvidmode* videoMode = glfwGetVideoMode(monitor);
	if (!videoMode)
		return quitApp();

	width = videoMode->width;
	height = videoMode->height;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(width, height, "Hello World", monitor, NULL);
	if (!window)
		return quitApp();

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	glfwSetKeyCallback(window, key_callback);

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */

		/* Swap front and back buffers */
		float ratio;
        	int width, height;
        	glfwGetFramebufferSize(window, &width, &height);
        	ratio = width / (float) height;
        	glViewport(0, 0, width, height);
        	glClear(GL_COLOR_BUFFER_BIT);
        	glMatrixMode(GL_PROJECTION);
        	glLoadIdentity();
        	glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
        	glMatrixMode(GL_MODELVIEW);
        	glLoadIdentity();
        	glRotatef((float) glfwGetTime() * 50.f, 0.f, 0.f, 1.f);
        	glBegin(GL_TRIANGLES);
        	glColor3f(1.f, 0.f, 0.f);
        	glVertex3f(-0.6f, -0.4f, 0.f);
        	glColor3f(0.f, 1.f, 0.f);
        	glVertex3f(0.6f, -0.4f, 0.f);
        	glColor3f(0.f, 0.f, 1.f);
        	glVertex3f(0.f, 0.6f, 0.f);
       	 	glEnd();


		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();

	return 0;
}
