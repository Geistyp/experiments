//  [1/9/2014 GeistYp]
#pragma once

#include "ofMain.h"
#include "GLFW/glfw3.h"
#include "ofAppGLFWWindow.h"

static void error_callback(int error, const char* description)
{
	fputs(description, stderr);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}

class MultiWindow : public ofThread
{
public:

	void setup(string name, int w, int h, GLFWwindow* shared, std::function<void(void)> f)
	{
		winTitle = name;
		width	= w;
		height	= h;
		shared_context = shared;
		render_function = f;

		glfwSetErrorCallback(error_callback);
		wptr = glfwCreateWindow(width, height, winTitle.c_str(), NULL, shared_context);

		startThread();
	}

	void threadedFunction()
	{

		glfwMakeContextCurrent(wptr);

		glfwSetKeyCallback(wptr, key_callback);

		while (!glfwWindowShouldClose(wptr))
		{
			glfwMakeContextCurrent(wptr);

			ofPushMatrix();
			glViewport(0, 0, width, height);

			glDrawBuffer(GL_FRONT);
			
			setupScreenPerspective(width, height);
			
			render_function();

			//glFlush();
			glfwSwapBuffers(wptr);
			//glfwPollEvents();			// work?
			ofPopMatrix();
		}

		glfwDestroyWindow(wptr);


	}

	void setupScreenPerspective(float width, float height, float fov = 60, float nearDist = 0, float farDist = 0) {


		float viewW = width;
		float viewH = height;

		float eyeX = viewW / 2;
		float eyeY = viewH / 2;
		float halfFov = PI * fov / 360;
		float theTan = tanf(halfFov);
		float dist = eyeY / theTan;
		float aspect = (float)viewW / viewH;

		if (nearDist == 0) nearDist = dist / 10.0f;
		if (farDist == 0) farDist = dist * 10.0f;

		glMatrixMode(GL_PROJECTION );
		ofMatrix4x4 persp;
		persp.makePerspectiveMatrix(fov, aspect, nearDist, farDist);
		glLoadMatrixf(persp.getPtr());

		glMatrixMode(GL_MODELVIEW);
		ofMatrix4x4 lookAt;
		lookAt.makeLookAtViewMatrix(ofVec3f(eyeX, eyeY, dist), ofVec3f(eyeX, eyeY, 0), ofVec3f(0, 1, 0));
		glLoadMatrixf(lookAt.getPtr());

		// flip vertical
		glScalef(1, -1, 1);
		glTranslatef(0, -height, 0);
	}

	std::function<void(void)> render_function;

	GLFWwindow* wptr;
	GLFWwindow* shared_context;

	int width;
	int height;

	string winTitle;
};