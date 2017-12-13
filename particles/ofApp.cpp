#include "ofApp.h"
#include "Emitter.h"
#include "Particle.h"
#include "ParticleLow.h"

using namespace std;

double icoPosX;
double icoPosY;

//--------------------------------------------------------------
void ofApp::setup(){
	// Window Settings
	ofSetWindowShape(1024, 720);
	ofSetFrameRate(60);

	//Scene Settings
	ofSetBackgroundColor(0, 0, 0);
	debugActive = true;
	rotateActive = false;

	// load texture
	myTexture.loadImage("nova_1.png");
	myTexture.setAnchorPoint(myTexture.getWidth() / 2, myTexture.getHeight() / 2);

	// Particles Counter
	f_particlesCountFont.loadFont("verdana.ttf", 8);

	// Sphere
	double icoPosX = ofGetWidth()*.5;
	double icoPosY = ofGetHeight()*.5;

	icoSphere.setRadius(100);
	icoSphere.setPosition(icoPosX, icoPosY, 0);
	icoSphere.setResolution(1);

	// get icoSphere vertices actual locations
	ofMesh mesh = icoSphere.getMesh();
	vector<ofVec3f>& icoSphereVertices = mesh.getVertices();

	//create emitters in these locations
	for (size_t i=0; i < icoSphereVertices.size(); i++)
	{
		float x = icoSphere.getX() + icoSphereVertices[i][0];
		float y = icoSphere.getY() + icoSphereVertices[i][1];
		float z = icoSphere.getZ() + icoSphereVertices[i][2];
		v_emittersLow.push_back(new Emitter(x, y, z));
	}

}

//--------------------------------------------------------------
void ofApp::update(){
	// spin dat sphere
	float spinX = sin(ofGetElapsedTimef()*.35f);
	float spinY = cos(ofGetElapsedTimef()*.075f);

	//update vertices locations
	vector<ofVec3f> & icoSphereVertices = icoSphere.getMesh().getVertices();
	if (rotateActive)
	for (ofVec3f & v : icoSphereVertices) {
		v.rotate(spinX, spinY, 0);
	}
	
	//update emitters locations
	for (int i = 0; i < icoSphereVertices.size(); i++)
	{
		v_emittersLow[i]->updatePosition(
			icoSphereVertices[i][0]+icoSphere.getX(), 
			icoSphereVertices[i][1]+icoSphere.getY(), 
			icoSphereVertices[i][2]+icoSphere.getZ()
		);
		v_emittersLow[i]->updateParticles();
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	// icoSphere
	
	
	//ofNoFill();
	ofSetColor(ofColor(255, 255, 255));
	icoSphere.drawWireframe();

	
	for (int i = 0; i < v_emittersLow.size(); i++)
	{
		v_emittersLow[i]->drawParticles(&myTexture);
		
	}
	if (debugActive)
	{
		ofSetColor(ofColor(0, 255, 0));
		v_emittersLow[0]->drawSelf();
		ofSetColor(ofColor(255, 0, 0));
		v_emittersLow[ii]->drawSelf();
	}
	ofDisableBlendMode();
	ofSetColor(ofColor(255, 255, 255));
	char fpsStr[255]; // an array of chars
	sprintf(fpsStr, "Selected Emitter:%d\nFPS: %f\nParticles: %d\nA - activate emitters\nD - debug info\nS - toggle rotating", ii,ofGetFrameRate(),countParticles());
	if (debugActive) f_particlesCountFont.drawString(fpsStr, 1, 10);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	switch (key)
	{
		case 'a':
		case 'A':
			for (size_t i = 0; i < v_emittersLow.size(); i++)
			{
				v_emittersLow[i]->activate();
			}
			ii++;
			break;
		case 'd':
		case 'D':
			debugActive = !debugActive;
			break;
		case 's':
		case 'S':
			rotateActive = !rotateActive;
			break;
		default:
			break;
	}
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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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

//--------------------------------------------------------------
int ofApp::countParticles()
{
	int s = 0;
	for (int i = 0; i < v_emittersLow.size(); i++)
	{
		s += v_emittersLow[i]->getParticlesCount();
	}
	return s;
}
