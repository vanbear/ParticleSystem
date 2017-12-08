#include "ofApp.h"
#include "Particle.h"
#include "ParticleLow.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetWindowShape(1024, 720);
	ofSetBackgroundColor(0, 0, 0);
}

//--------------------------------------------------------------
void ofApp::update(){
	float randem = ofRandomf(); cout << "randem" << randem << endl;
	if (randem > .5)
	{
		v_lowparticles.push_back(new ParticleLow(0, ofRandom(720), ofRandom(1000)));
		v_lowparticles.back()->setSpeed(1, 0, 0);
	}

	if (v_lowparticles.size()>0)
		for (size_t i = 0; i < v_lowparticles.size()-1; i++)
		{
			v_lowparticles[i]->updatePosition();
		}
}

//--------------------------------------------------------------
void ofApp::draw(){
	if (v_lowparticles.size()>0)
		for (size_t i = 0; i < v_lowparticles.size()-1; i++)
		{
			v_lowparticles[i]->draw();
		}
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
