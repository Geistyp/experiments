#include "ofApp.h"
#include <functional>

#include "GLFW/glfw3.h"

GLFWwindow* window;

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

	image.draw(0, 0);
}

//--------------------------------------------------------------
void ofApp::renderNextWindow(){

	ofClear(0);

	image.draw(0, 0);

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
