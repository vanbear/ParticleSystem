#pragma once

#include "ofMain.h"
#include "ParticleBlueCircles.h"
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

		// camera
		ofEasyCam camera;

		// emitters stuff
		int countParticles();
		void activateAllEmitters(int selectedParticle);
		void activateSelectedEmitter(int i, int selectedParticle);
		void activateRingEmitters(int selectedParticle);
		void activateNRandomEmitters(int n, int selectedParticle);

		// sphere
		ofIcoSpherePrimitive icoSphere;

		// emitters holder
		std::vector<Emitter*> v_emitters;
		
		// drawing
		ofTrueTypeFont f_particlesCountFont;

		// audio
		ofSoundPlayer music;
		float avgSound;
		float* fftSmoothed;
		int nBandsToGet;
		bool musicIsPlaying;

		int m_tickCount;
		int m_tickFrequency;

		// setting togglers
		bool debugActive;
		bool rotateActive;

		// emitter indexes
		int selectedEmitterIndex = 0;
		int t_RingEmittersIndex[28] = { 13, 14, 18, 19, 22, 23, 24, 26, 30, 32, 49, 50, 
			51, 52, 57, 59, 63, 65, 70, 71, 75, 76, 78, 82, 83, 84, 85, 86 };
};