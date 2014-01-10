#include "ofApp.h"
#include <functional>

#include "GLFW/glfw3.h"

GLFWwindow* window;

ofMutex mutex;

//--------------------------------------------------------------
void ofApp::setup(){

	window = glfwGetCurrentContext();

	image.loadImage("Penguins.jpg");

	win.setup("Test Multi Window", 1024, 768, window, std::bind(&ofApp::renderNextWindow, this));

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

	glfwMakeContextCurrent(window);

	// lock share resource to prevent twinkle between two window
	mutex.lock();
	image.draw(0, 0);
	mutex.unlock();
}

//--------------------------------------------------------------
void ofApp::renderNextWindow(){

	ofClear(0);

	// lock share resource to prevent twinkle between two window
	mutex.lock();
	image.draw(0, 0);
	mutex.unlock();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
