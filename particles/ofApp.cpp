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

	// load texture
	myTexture.loadImage("nyan.png");
	myTexture.resize(myTexture.getWidth() / 10, myTexture.getHeight() / 10);
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
	for (ofVec3f & v : icoSphereVertices) {
		v.rotate(spinX, spinY, 0);
	}
	
	//update emitters locations
	for (size_t i = 0; i < icoSphereVertices.size(); i++)
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

	ofEnableBlendMode(OF_BLENDMODE_ADD);
	for (size_t i = 0; i < v_emittersLow.size(); i++)
	{
		v_emittersLow[i]->drawParticles(&myTexture);
		//v_emittersLow[i]->drawSelf();
	}
	ofDisableBlendMode();

	ofSetColor(ofColor(255, 255, 255));
	char fpsStr[255]; // an array of chars
	sprintf(fpsStr, "FPS: %f\nParticles: %d", ofGetFrameRate(),countParticles());
	f_particlesCountFont.drawString(fpsStr, 1, 10);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	switch (key)
	{
		case 'a':
			for (size_t i = 0; i < v_emittersLow.size(); i++)
			{
				v_emittersLow[i]->activate();
			}
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
