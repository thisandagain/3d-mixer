/**
 * @package  3dmixer
 * @author  Andrew Sliwinski <andrew@unitedworkshop.com>
 */

/**
 * Includes
 */
#include "testApp.h"

/**
 * Setup
 */
void testApp::setup(){

    // GL basics
	ofBackground(34, 34, 34);
    ofSetFrameRate(30);
    
    // -----------------------------
    
	// 8 output channels,
	// 0 input channels
	// 22050 samples per second
	// 512 samples per buffer
	// 4 num buffers (latency)
	
	int bufferSize		= 256;
	sampleRate 			= 44100;
    sample.load("/Users/asliwinski/Desktop/startrek.wav");              // Supports mono or stereo WAV files
	sample.setLooping(true);
    sample.setSpeed(1.0f);
	sample.generateWaveForm(&waveForm);
    sample.play();
    
	bNoise 				= true;
    volume              = 0.5f;
    xaxis               = 0.5f;
    yaxis               = 0.5f;
    zaxis               = 0.5f;
    
    for (int c = 1; c <= 8; c++) {
        channel[c].assign(bufferSize, 0.0);
    }
	 
	// Device information
    /*
    soundStream.listDevices();
	soundStream.setDeviceID(1);         // Some devices are input only and some are output only
    */
    int outputChannels  = 2;
    
    // Setup stream
	soundStream.setup(this, outputChannels, 0, sampleRate, bufferSize, 4);
}

/**
 * Exit
 */
void testApp::exit() {
    printf("Exiting...");
    
    // ----
    
    soundStream.stop();
    soundStream.close();
    
    // ----
    
    printf(" Done.\n");
}

/**
 * Update
 */
void testApp::update() {}

/**
 * Draw
 */
void testApp::draw(){

    // Render labels
	ofSetColor(225);
	ofDrawBitmapString("3D SOUND MIXER", 32, 32);
	ofNoFill();
    
    // ----
	
    // Render audio GUI
    audioGUI(32,60,1024,8);
    
    // ----
    
    // Render user hints (help menu)
	ofSetColor(225);
	string reportString		= "";
	reportString			+= "volume: (" + ofToString(volume, 2) + ") modify with -/+ keys\n";
	reportString			+= "x-axis: (" + ofToString(xaxis, 2) + ") modify with mouse x\n";
	reportString			+= "y-axis: (" + ofToString(yaxis, 2) + ") modify with mouse y\n";
    reportString            += "z-axis: (" + ofToString(zaxis, 2) + ") modify with mouse drag y\n";
	reportString			+= "synthesis: ";
	
	if( !bNoise ){
        reportString += "sample";
		//reportString += "sine wave (" + ofToString(targetFrequency, 2) + "hz) modify with mouse y";
	}else{
		reportString += "noise";
	}
    
    reportString            += "\n\n";
    reportString            += "press 'm' to toggle output modes.";
    
	ofDrawBitmapString(reportString, 32, 579);

}


/**
 * Key press event
 *
 * @param  int  Key
 *
 * @return  void
 */
void testApp::keyPressed  (int key) {
	if ( key == '-' || key == '_' ) {
		volume -= 0.05;
		volume = MAX(volume, 0);
	} else if (key == '+' || key == '=' ){
		volume += 0.05;
		volume = MIN(volume, 1);
	}
	
	if ( key == 's' ) {
		soundStream.start();
	}
	
	if ( key == 'e' ) {
		soundStream.stop();
	}
    
    if ( key == 'm' ) {
        if (bNoise) {
            bNoise = false;
        } else {
            bNoise = true;
        }
    }
}

/**
 * Key release event
 *
 * @param  int  Key
 *
 * @return  void
 */
void testApp::keyReleased  (int key){}

/**
 * Mouse moved event
 *
 * @param  int  X position
 * @param  int  Y position
 *
 * @return  void
 */
void testApp::mouseMoved(int x, int y ){
	// Storage objects
	float width		= (float) ofGetWidth();
	float height	= (float) ofGetHeight();
	
	// Update globals
	xaxis = (float) x / width;
	yaxis = (float) y / height;
}

/**
 * Mouse dragged event
 *
 * @param  int  X position
 * @param  int  Y position
 * @param  int  Mouse button
 *
 * @return  void
 */
void testApp::mouseDragged(int x, int y, int button){
	int height = ofGetHeight();
	zaxis = (float)y / (float)height;
}

/**
 * Mouse pressed event
 *
 * @param  int  X position
 * @param  int  Y position
 * @param  int  Mouse button
 *
 * @return  void
 */
void testApp::mousePressed(int x, int y, int button){}

/**
 * Mouse released event
 *
 * @param  int  X position
 * @param  int  Y position
 * @param  int  Mouse button
 *
 * @return  void
 */
void testApp::mouseReleased(int x, int y, int button){}

/**
 * Window resized event
 *
 * @param  int  Width
 * @param  int  Height
 *
 * @return  void
 */
void testApp::windowResized(int w, int h){}

/**
 * Message event handler.
 *
 * @param  ofMessage  Message
 *
 * @return  void
 */
void testApp::gotMessage(ofMessage msg){}

/**
 * Mouse drag event.
 *
 * @param  ofDragInfo  Drag info
 *
 * @return  void
 */
void testApp::dragEvent(ofDragInfo dragInfo){}

/**
 * Renders audio output GUI to GL context.
 *
 * @param  int  X position
 * @param  int  Y position
 * @param  int  UI width
 * @param  int  Number of channels
 *
 * @return  void
 */
void testApp::audioGUI(int x, int y, int guiw, int nChannels) {
    
    // Iterate
    for (int c = 1; c <= nChannels; c++) {
        
        // Modulus
        // ----------------------------------
        int row         = ( ceil (c / 2) + (c % 2) ) - 1;
        int column      = 0;
        if (c % 2 == 0) {
            column      = 1;
        }
        
        // Calculate offsets
        // ----------------------------------
        int unitw       = guiw / 2 - (x);
        int unith       = 100;
        int ox          = x + (column * unitw);
        int oy          = y + (row * unith);
        
        // Render channel
        // ----------------------------------
        ofPushStyle();
            ofPushMatrix();
        
                ofTranslate(ox, oy, 0);
                
                ofSetColor(225);
                ofDrawBitmapString("Channel " + ofToString(c), 4, 18);
                
                ofSetLineWidth(1);	
                ofRect(0, 0, unitw, unith);
                
                ofSetColor(245, 58, 135);
                ofSetLineWidth(3);
                
                if (bNoise) {
                    ofBeginShape();
                    for (int i = 0; i < channel[c].size(); i++){
                        float x =  ofMap(i, 0, channel[c].size(), 0, unitw, true);
                        ofVertex(x, 50 -channel[c][i]*50.0f);
                    }
                    ofEndShape(false);
                } else {
                    sample.drawWaveForm(ox, oy, unitw, unith, &waveForm);
                }
            
            ofPopMatrix();
        ofPopStyle();
        // ----------------------------------

    }
}

/**
 * Audio output (generator). Routes either a noise or sine generated signal to each output buffer.
 *
 * @param  float  Output
 * @param  int  Buffer size
 * @param  int  Number of channels
 *
 * @return  void
 */
void testApp::audioRequested(float * output, int bufferSize, int nChannels) {	
    
	if ( bNoise == true) {
		// ---------------------- noise --------------
        for (int i = 0; i < bufferSize; i++) {                                         
            // Send to channel buffer
            channel[1][i] = output[i*nChannels + 0] = ofRandom(0, 1) * volume * ( xaxis - 1 ) * ( yaxis - 1 ) * ( zaxis - 1 );
            channel[2][i] = output[i*nChannels + 1] = ofRandom(0, 1) * volume * ( xaxis - 0 ) * ( yaxis - 1 ) * ( zaxis - 1 );
            channel[3][i] = output[i*nChannels + 2] = ofRandom(0, 1) * volume * ( xaxis - 1 ) * ( yaxis - 0 ) * ( zaxis - 1 );
            channel[4][i] = output[i*nChannels + 3] = ofRandom(0, 1) * volume * ( xaxis - 0 ) * ( yaxis - 0 ) * ( zaxis - 1 );
            
            channel[5][i] = output[i*nChannels + 4] = ofRandom(0, 1) * volume * ( xaxis - 1 ) * ( yaxis - 1 ) * ( zaxis - 0 );
            channel[6][i] = output[i*nChannels + 5] = ofRandom(0, 1) * volume * ( xaxis - 0 ) * ( yaxis - 1 ) * ( zaxis - 0 );
            channel[7][i] = output[i*nChannels + 6] = ofRandom(0, 1) * volume * ( xaxis - 1 ) * ( yaxis - 0 ) * ( zaxis - 0 );
            channel[8][i] = output[i*nChannels + 7] = ofRandom(0, 1) * volume * ( xaxis - 0 ) * ( yaxis - 0 ) * ( zaxis - 0 );
        }
    } else {
        // ---------------------- sample -------------
        if (sample.getChannels() == 1 || sample.getChannels() == 2) {
            float smp = sample.update();
            
            /*
            printf("Loaded: %d\n", sample.getIsLoaded());
            printf("Playing: %d\n", sample.getIsPlaying());
            printf("Position: %f\n", sample.getPosition());
            printf("Speed: %f\n", sample.getSpeed());
            */
            
            for (int i = 0; i < bufferSize; i++) {
                // Send to channel buffer
                channel[1][i] = output[i*nChannels + 0] = smp * volume * ( xaxis - 1 ) * ( yaxis - 1 ) * ( zaxis - 1 );
                channel[2][i] = output[i*nChannels + 1] = smp * volume * ( xaxis - 0 ) * ( yaxis - 1 ) * ( zaxis - 1 );
                channel[3][i] = output[i*nChannels + 2] = smp * volume * ( xaxis - 1 ) * ( yaxis - 0 ) * ( zaxis - 1 );
                channel[4][i] = output[i*nChannels + 3] = smp * volume * ( xaxis - 0 ) * ( yaxis - 0 ) * ( zaxis - 1 );
                
                channel[5][i] = output[i*nChannels + 4] = smp * volume * ( xaxis - 1 ) * ( yaxis - 1 ) * ( zaxis - 0 );
                channel[6][i] = output[i*nChannels + 5] = smp * volume * ( xaxis - 0 ) * ( yaxis - 1 ) * ( zaxis - 0 );
                channel[7][i] = output[i*nChannels + 6] = smp * volume * ( xaxis - 1 ) * ( yaxis - 0 ) * ( zaxis - 0 );
                channel[8][i] = output[i*nChannels + 7] = smp * volume * ( xaxis - 0 ) * ( yaxis - 0 ) * ( zaxis - 0 );
            }
        } else {
            for (int i = 0; i < bufferSize; i++) {
                // Send (silence) to channel buffer
                channel[1][i] = output[i*nChannels + 0] = 0.0;
                channel[2][i] = output[i*nChannels + 1] = 0.0;
                channel[3][i] = output[i*nChannels + 2] = 0.0;
                channel[4][i] = output[i*nChannels + 3] = 0.0;
                
                channel[5][i] = output[i*nChannels + 4] = 0.0;
                channel[6][i] = output[i*nChannels + 5] = 0.0;
                channel[7][i] = output[i*nChannels + 6] = 0.0;
                channel[8][i] = output[i*nChannels + 7] = 0.0;
            }
        }
    }
    
}
