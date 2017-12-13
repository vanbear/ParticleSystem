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
	// draw icoSphere
	ofSetColor(ofColor(200, 200, 200));
	icoSphere.drawWireframe();

	// update particles as objects created by each emitter
	for (int i = 0; i < v_emittersLow.size(); i++)
	{
		v_emittersLow[i]->drawParticles(&myTexture);
		
	}
	
	// debug info
	if (debugActive)
	{
		// draw all emitters
		for (size_t i = 0; i < v_emittersLow.size(); i++)
		{
			v_emittersLow[i]->drawSelf();
		}
		
		// draw ring emitters (blue)
		for (int i = 0; i < size(tab_RingParticlesIndex); i++)
		{
			ofSetColor(ofColor(0, 0, 255));
			v_emittersLow[tab_RingParticlesIndex[i]]->drawSelf();
		}

		// draw first emitter (green)
		ofSetColor(ofColor(0, 255, 0));
		v_emittersLow[0]->drawSelf();

		// draw selected emitter (red)
		ofSetColor(ofColor(255, 0, 0));
		v_emittersLow[selectedParticleIndex]->drawSelf();

	}
	ofDisableBlendMode();

	// DRAW DEBUG INFO
	ofSetColor(ofColor(255, 255, 255));
	char fpsStr[255]; // an array of chars
	// create string
	sprintf(fpsStr, 
		"\
		FPS: %f\n\
		Particles: %d\n\
		N or M - Select Emitter:%d\n\
		D - toggle debug info\n\
		R - toggle rotating\n\
		A - activate all emitters\n\
		S - activate selected emitter\n\
		Z - activate ring emitters\n\
		X - activate random emitters\
		", 
		ofGetFrameRate(), countParticles(), selectedParticleIndex);
	if (debugActive) f_particlesCountFont.drawString(fpsStr, 1, 10);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	vector<ofVec3f> & icoSphereVertices = icoSphere.getMesh().getVertices();
	switch (key)
	{
		// emitters 
		case 'a':
		case 'A':
			activateAllEmitters();
			break;
		case 's':
		case 'S':
			activateSelectedEmitter(selectedParticleIndex);
			break;
		case 'z':
		case 'Z':
			activateRingEmitters();
			break;
		case 'x':
		case 'X':
			activateNRandomEmitters(10);
			break;
		// debug mode
		case 'd':
		case 'D':
			debugActive = !debugActive;
			break;
		// select emitter
		case 'n':
		case 'N':
			selectedParticleIndex--;
			if (selectedParticleIndex < 0) selectedParticleIndex = v_emittersLow.size()-1;
			break;
		case 'm':
		case 'M':
			selectedParticleIndex++;
			if (selectedParticleIndex > v_emittersLow.size()-1) selectedParticleIndex = 0;
			break;
		// toggle rotate
		case 'r':
		case 'R':
			rotateActive = !rotateActive;
			break;
		// rotate up
		case 'u':
		case 'U':
			for (ofVec3f & v : icoSphereVertices) {
				v.rotate(1, 0, 0);
			}
			break;
		// rotate down
		case 'j':
		case 'J':
			for (ofVec3f & v : icoSphereVertices) {
				v.rotate(-1, 0, 0);
			}
			break;
		// default
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

void ofApp::activateAllEmitters()
{
	for (size_t i = 0; i < v_emittersLow.size(); i++)
	{
		v_emittersLow[i]->activate();
	}
}

void ofApp::activateSelectedEmitter(int i)
{
		v_emittersLow[i]->activate();
}


void ofApp::activateRingEmitters()
{
	for (int i = 0; i < size(tab_RingParticlesIndex); i++)
	{
		ofSetColor(ofColor(0, 0, 255));
		v_emittersLow[tab_RingParticlesIndex[i]]->activate();
	}
}

void ofApp::activateNRandomEmitters(int n)
{
	for (int i = 0; i < n; i++)
	{
		int emitter = ofRandom(0, v_emittersLow.size());
		activateSelectedEmitter(emitter);
	}
}