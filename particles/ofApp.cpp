#include "ofApp.h"
#include "Emitter.h"
#include "Particle.h"
#include "ParticleBlueCircles.h"

using namespace std;

double icoPosX;
double icoPosY;

//--------------------------------------------------------------
void ofApp::setup(){
	// --------------------------------------------- APP INITIALIZATION
	// Window Settings
	ofSetWindowShape(1024, 720);
	ofSetFrameRate(60);

	//Scene Settings
	ofSetBackgroundColor(10, 15, 20);
	debugActive = true;
	rotateActive = false;

	// -------------------------------------------------- MEDIA LOADING
	// load texture
	myTexture.loadImage("nova_1.png");
	myTexture.setAnchorPoint(myTexture.getWidth() / 2, myTexture.getHeight() / 2);

	// load debug info font
	f_particlesCountFont.loadFont("verdana.ttf", 8);

	// FFT initialization
	fftSmoothed = new float[8192];
	for (int i = 0; i < 8192; i++) {
		fftSmoothed[i] = 0;
	}
	nBandsToGet = 128;
	m_tickCount = 0;
	m_tickFrequency = 2;
	// load song
	musicIsPlaying = false;
	music.loadSound("robinson.mp3");
	music.setVolume(1.0f);
	music.play();
	music.setLoop(true);

	// ------------------------------------------------ CREATING OBJECTS
	// setup icoSphere
	icoSphere.setRadius(100);
	icoSphere.setPosition(ofGetWidth()*.5, ofGetHeight()*.5, 0);
	icoSphere.setResolution(1);

	// get icoSphere vertices actual locations...
	ofMesh mesh = icoSphere.getMesh();
	vector<ofVec3f>& icoSphereVertices = mesh.getVertices();

	//...and create emitters in these locations
	for (size_t i=0; i < icoSphereVertices.size(); i++)
	{
		float x = icoSphere.getX() + icoSphereVertices[i][0];
		float y = icoSphere.getY() + icoSphereVertices[i][1];
		float z = icoSphere.getZ() + icoSphereVertices[i][2];
		v_emitters.push_back(new Emitter(x, y, z));
	}

}

//--------------------------------------------------------------
void ofApp::update() {
	// --------------------------FFT SETTINGS
	if (musicIsPlaying)
		music.setPaused(false);
	else
		music.setPaused(true);

	ofSoundUpdate(); // update the sound playing system

					 //	grab the fft, and put in into a "smoothed" array,
					 //	by taking maximums, as peaks and then smoothing downward
	float * val = ofSoundGetSpectrum(nBandsToGet);				// request 128 values for fft
	avgSound = 0;
	for (int i = 0; i < nBandsToGet; i++) {
		fftSmoothed[i] *= 0.6f;								// let the smoothed calue sink to zero:
		if (fftSmoothed[i] < val[i]) fftSmoothed[i] = val[i];	// take the max, either the smoothed or the incoming:
		avgSound += fftSmoothed[i];
	}
	// average loudness
	avgSound /= nBandsToGet;

	// trigger emitters
	if (m_tickCount == m_tickFrequency)
	{
		if (fftSmoothed[0] > 4)
		{
			activateAllEmitters();
		}
		if (fftSmoothed[27] > 0.4f)
		{
			activateRingEmitters();
		}
		m_tickCount = 0;
	}
	else
		m_tickCount++;

	// -------------------------- OBJECTS
	// spin dat sphere
	float spinX = sin(ofGetElapsedTimef()*.35f)*(avgSound*10);
	float spinY = cos(ofGetElapsedTimef()*.075f)*(avgSound*10);
	cout << avgSound << endl;
	//update vertices locations
	vector<ofVec3f> & icoSphereVertices = icoSphere.getMesh().getVertices();
	if (rotateActive)
	for (ofVec3f & v : icoSphereVertices) {
		v.rotate(spinX, spinY, 0);
	}
	
	//update emitters locations
	for (int i = 0; i < icoSphereVertices.size(); i++)
	{
		v_emitters[i]->updatePosition(
			icoSphereVertices[i][0]+icoSphere.getX(), 
			icoSphereVertices[i][1]+icoSphere.getY(), 
			icoSphereVertices[i][2]+icoSphere.getZ()
		);
		v_emitters[i]->updateParticles();
	}


	

}

//--------------------------------------------------------------
void ofApp::draw(){

	// draw icoSphere
	ofSetColor(ofColor(200, 200, 200));
	icoSphere.drawWireframe();

	// update particles as objects created by each emitter
	for (int i = 0; i < v_emitters.size(); i++)
	{
		v_emitters[i]->drawParticles(&myTexture);
		
	}

	// draw inside circle
	ofSetColor(ofColor(255, 255, 255, 50));
	ofNoFill();
	ofDrawCircle(icoSphere.getX(), icoSphere.getY(), (fftSmoothed[0] * 10) + icoSphere.getRadius());
	ofDrawCircle(icoSphere.getX(), icoSphere.getY(), (fftSmoothed[1] * 10) + icoSphere.getRadius());
	ofDrawCircle(icoSphere.getX(), icoSphere.getY(), (fftSmoothed[2] * 10) + icoSphere.getRadius());
	ofFill();
	
	// debug info
	if (debugActive)
	{
		// draw all emitters
		for (size_t i = 0; i < v_emitters.size(); i++)
		{
			v_emitters[i]->drawSelf();
		}
		
		// draw ring emitters (blue)
		for (int i = 0; i < size(t_RingEmittersIndex); i++)
		{
			ofSetColor(ofColor(0, 0, 255));
			v_emitters[t_RingEmittersIndex[i]]->drawSelf();
		}

		// draw first emitter (green)
		ofSetColor(ofColor(0, 255, 0));
		v_emitters[0]->drawSelf();

		// draw selected emitter (red)
		ofSetColor(ofColor(255, 0, 0));
		v_emitters[selectedEmitterIndex]->drawSelf();

		// draw FFT preview
		float width = (float)(5 * 128) / nBandsToGet;
		for (int i = 0; i < nBandsToGet; i++) {
			if (i % 10 == 0) ofSetColor(ofColor(255, 0, 0));
			else ofSetColor(ofColor(255, 255, 255));
			// (we use negative height here, because we want to flip them
			// because the top corner is 0,0)
			ofDrawRectangle(i*width, ofGetHeight(), width, -(fftSmoothed[i] * 50));
		}

	}

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
		ofGetFrameRate(), countParticles(), selectedEmitterIndex);
	if (debugActive) f_particlesCountFont.drawString(fpsStr, 1, 10);

	char beatStr[255];
	sprintf(beatStr,
		"%.2f \n%.2f \n", 
		fftSmoothed[0], fftSmoothed[27]);
	if (debugActive) f_particlesCountFont.drawString(beatStr, ofGetWidth()-50, 10);
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
			activateSelectedEmitter(selectedEmitterIndex);
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
			selectedEmitterIndex--;
			if (selectedEmitterIndex < 0) selectedEmitterIndex = v_emitters.size()-1;
			break;
		case 'm':
		case 'M':
			selectedEmitterIndex++;
			if (selectedEmitterIndex > v_emitters.size()-1) selectedEmitterIndex = 0;
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
		// play/pause music
		case 'p':
		case 'P':
			musicIsPlaying = !musicIsPlaying;
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
	for (int i = 0; i < v_emitters.size(); i++)
	{
		s += v_emitters[i]->getParticlesCount();
	}
	return s;
}

void ofApp::activateAllEmitters()
{
	for (size_t i = 0; i < v_emitters.size(); i++)
	{
		v_emitters[i]->activate();
	}
}

void ofApp::activateSelectedEmitter(int i)
{
		v_emitters[i]->activate();
}


void ofApp::activateRingEmitters()
{
	for (int i = 0; i < size(t_RingEmittersIndex); i++)
	{
		ofSetColor(ofColor(0, 0, 255));
		v_emitters[t_RingEmittersIndex[i]]->activate();
	}
}

void ofApp::activateNRandomEmitters(int n)
{
	for (int i = 0; i < n; i++)
	{
		int emitter = ofRandom(0, v_emitters.size());
		activateSelectedEmitter(emitter);
	}
}