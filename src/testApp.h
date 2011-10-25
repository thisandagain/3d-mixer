#ifndef _TEST_APP
#define _TEST_APP


#include "ofMain.h"

class testApp : public ofBaseApp{

	public:

		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
		void audioOut(float * input, int bufferSize, int nChannels);
		
		
		ofSoundStream soundStream;

		float   xaxis;
		float   yaxis;
		float   zaxis;
	
		float 	pan;
		float	tilt;
		int		sampleRate;
		bool 	bNoise;
		float 	volume;
	
		vector <float> c1Audio;
		vector <float> c2Audio;
		vector <float> c3Audio;
		vector <float> c4Audio;
		vector <float> c5Audio;
		vector <float> c6Audio;
		vector <float> c7Audio;
		vector <float> c8Audio;
		
		//------------------- for the simple sine wave synthesis
		float 	targetFrequency;
		float 	phase;
		float 	phaseAdder;
		float 	phaseAdderTarget;
};

#endif
