#pragma once

#include "ofMain.h"
#include "ParticleLow.h"
#include "Particle.h"
#include "Emitter.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		int countParticles();
		void activateAllParticles();

		ofIcoSpherePrimitive icoSphere;

		std::vector<Emitter*> v_emittersLow;
		
		ofTrueTypeFont f_particlesCountFont;
		ofImage myTexture;

		bool debugActive;
		bool rotateActive;

		int ii = 0;
		int tab_lowIndex[28] = { 13, 14, 18, 19, 22, 23, 24, 26, 30, 32, 49, 50, 
			51, 52, 57, 59, 63, 65, 70, 71, 75, 76, 78, 82, 83, 84, 85, 86 };
};