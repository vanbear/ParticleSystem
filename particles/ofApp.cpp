#include "ofApp.h"
#include "Particle.h"
#include "ParticleLow.h"

//--------------------------------------------------------------
void ofApp::setup(){
	// Window Settings
	ofSetWindowShape(1024, 720);

	//Scene Settings
	ofSetBackgroundColor(0, 0, 0);

	// Particles Counter
	f_particlesCountFont.loadFont("verdana.ttf", 8);
}

//--------------------------------------------------------------
void ofApp::update(){
	float randem = ofRandomf(); //cout << "randem" << randem << endl;
	if (randem > .2)
	{
		v_lowparticles.push_back(new ParticleLow(-1000.0f, ofRandom(720), ofRandom(-1000,1000)));
		v_lowparticles.back()->setSpeed(10, 0, 0);
	}

	// If there are any particles
	if (v_lowparticles.size()>0)
		for (size_t i = 0; i < v_lowparticles.size(); i++)
		{
			ParticleLow* particle = v_lowparticles[i];
			// destroy particle when lifetime exceeded, else just update and increase time lived
			if (particle->isDead())
				v_lowparticles.erase(v_lowparticles.begin() + i);
			else 
			{ 
				particle->updatePosition(); 
				particle->m_lifespan--;
			}

		}
}

//--------------------------------------------------------------
void ofApp::draw(){

	// draw all particles
	if (v_lowparticles.size()>0)
		for (size_t i = 0; i < v_lowparticles.size(); i++)
		{
			v_lowparticles[i]->draw();
		}

	//FPS counter
	char fpsStr[255];
	sprintf(fpsStr, "FPS: %.0f \nparticles: %d", ofGetFrameRate(), (int)v_lowparticles.size());
	f_particlesCountFont.drawString(fpsStr, 10, 15);


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
