/**
 * @package  3dmixer
 * @author  Andrew Sliwinski <andrew@unitedworkshop.com>
 */

/**
 * Define
 */
#ifndef _TEST_APP
#define _TEST_APP

/**
 * Includes
 */
#include "ofMain.h"

/**
 * Creates class as an extension of ofBaseApp.
 */
class testApp : public ofBaseApp{

	public:

		// Basic
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
		
		// Define functions
        void audioGUI(int x, int y, int guiw, int nChannels);
		void audioOut(float * input, int bufferSize, int nChannels);
		
		// Sound stream
		ofSoundStream soundStream;

		// Trackers
		float   xaxis;
		float   yaxis;
		float   zaxis;
	
		float 	pan;
		float	tilt;
		int		sampleRate;
		bool 	bNoise;
		float 	volume;
	
		// Output channels (# of channels + 1)
        vector <float> channel[9];
		
		// Sine wave synthesis
		float 	targetFrequency;
		float 	phase;
		float 	phaseAdder;
		float 	phaseAdderTarget;
};

#endif
