#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

	ofBackground(34, 34, 34);

	// 8 output channels,
	// 0 input channels
	// 22050 samples per second
	// 512 samples per buffer
	// 4 num buffers (latency)
	
	int bufferSize		= 512;
	sampleRate 			= 44100;
	phase 				= 0;
	phaseAdder 			= 0.0f;
	phaseAdderTarget 	= 0.0f;
	volume				= 0.1f;
	bNoise 				= true;
	
	c1Audio.assign(bufferSize, 0.0);
	c2Audio.assign(bufferSize, 0.0);
	c3Audio.assign(bufferSize, 0.0);
	c4Audio.assign(bufferSize, 0.0);
	c5Audio.assign(bufferSize, 0.0);
	c6Audio.assign(bufferSize, 0.0);
	c7Audio.assign(bufferSize, 0.0);
	c8Audio.assign(bufferSize, 0.0);
	
	soundStream.listDevices();
	
	//if you want to set the device id to be different than the default
	//soundStream.setDeviceID(1); 	//note some devices are input only and some are output only 

	soundStream.setup(this, 2, 0, sampleRate, bufferSize, 4);

	ofSetFrameRate(60);
}


//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){

	ofSetColor(225);
	ofDrawBitmapString("3D SOUND - FRONT", 32, 32);
	ofDrawBitmapString("3D SOUND - REAR", 32, 292);
	//ofDrawBitmapString("press 's' to unpause the audio\npress 'e' to pause the audio", 31, 92);
	
	ofNoFill();
	
	// draw channel 1:
	ofPushStyle();
		ofPushMatrix();
		ofTranslate(32, 60, 0);
			
		ofSetColor(225);
		ofDrawBitmapString("Channel 1", 4, 18);
		
		ofSetLineWidth(1);	
		ofRect(0, 0, 480, 100);

		ofSetColor(245, 58, 135);
		ofSetLineWidth(3);
					
			ofBeginShape();
			for (int i = 0; i < c1Audio.size(); i++){
				float x =  ofMap(i, 0, c1Audio.size(), 0, 480, true);
				ofVertex(x, 50 -c1Audio[i]*50.0f);
			}
			ofEndShape(false);
			
		ofPopMatrix();
	ofPopStyle();

	// draw channel 2:
	ofPushStyle();
		ofPushMatrix();
		ofTranslate(512, 60, 0);
			
		ofSetColor(225);
		ofDrawBitmapString("Channel 2", 4, 18);
		
		ofSetLineWidth(1);	
		ofRect(0, 0, 480, 100);

		ofSetColor(245, 58, 135);
		ofSetLineWidth(3);
					
			ofBeginShape();
			for (int i = 0; i < c2Audio.size(); i++){
				float x =  ofMap(i, 0, c2Audio.size(), 0, 480, true);
				ofVertex(x, 50 -c2Audio[i]*50.0f);
			}
			ofEndShape(false);
			
		ofPopMatrix();
	ofPopStyle();
	
	// draw channel 3:
	ofPushStyle();
		ofPushMatrix();
		ofTranslate(32, 160, 0);
		
		ofSetColor(225);
		ofDrawBitmapString("Channel 3", 4, 18);
		
		ofSetLineWidth(1);	
		ofRect(0, 0, 480, 100);
		
		ofSetColor(245, 58, 135);
		ofSetLineWidth(3);
		
			ofBeginShape();
			for (int i = 0; i < c3Audio.size(); i++){
				float x =  ofMap(i, 0, c3Audio.size(), 0, 480, true);
				ofVertex(x, 50 -c3Audio[i]*50.0f);
			}
			ofEndShape(false);
		
		ofPopMatrix();
	ofPopStyle();
	
	// draw channel 4:
	ofPushStyle();
		ofPushMatrix();
		ofTranslate(512, 160, 0);
		
		ofSetColor(225);
		ofDrawBitmapString("Channel 4", 4, 18);
		
		ofSetLineWidth(1);	
		ofRect(0, 0, 480, 100);
		
		ofSetColor(245, 58, 135);
		ofSetLineWidth(3);
		
			ofBeginShape();
			for (int i = 0; i < c4Audio.size(); i++){
				float x =  ofMap(i, 0, c4Audio.size(), 0, 480, true);
				ofVertex(x, 50 -c4Audio[i]*50.0f);
			}
			ofEndShape(false);
		
		ofPopMatrix();
	ofPopStyle();
	
	// -----
	// -----
	
	// draw channel 5:
	ofPushStyle();
		ofPushMatrix();
		ofTranslate(32, 322, 0);
		
		ofSetColor(225);
		ofDrawBitmapString("Channel 5", 4, 18);
		
		ofSetLineWidth(1);	
		ofRect(0, 0, 480, 100);
		
		ofSetColor(245, 58, 135);
		ofSetLineWidth(3);
		
			ofBeginShape();
			for (int i = 0; i < c5Audio.size(); i++){
				float x =  ofMap(i, 0, c5Audio.size(), 0, 480, true);
				ofVertex(x, 50 -c5Audio[i]*50.0f);
			}
			ofEndShape(false);
		
		ofPopMatrix();
	ofPopStyle();
	
	// draw channel 6:
	ofPushStyle();
		ofPushMatrix();
		ofTranslate(512, 322, 0);
		
		ofSetColor(225);
		ofDrawBitmapString("Channel 6", 4, 18);
		
		ofSetLineWidth(1);	
		ofRect(0, 0, 480, 100);
		
		ofSetColor(245, 58, 135);
		ofSetLineWidth(3);
		
			ofBeginShape();
			for (int i = 0; i < c6Audio.size(); i++){
				float x =  ofMap(i, 0, c6Audio.size(), 0, 480, true);
				ofVertex(x, 50 -c6Audio[i]*50.0f);
			}
			ofEndShape(false);
		
		ofPopMatrix();
	ofPopStyle();
	
	// draw channel 7:
	ofPushStyle();
		ofPushMatrix();
		ofTranslate(32, 422, 0);
		
		ofSetColor(225);
		ofDrawBitmapString("Channel 7", 4, 18);
		
		ofSetLineWidth(1);	
		ofRect(0, 0, 480, 100);
		
		ofSetColor(245, 58, 135);
		ofSetLineWidth(3);
		
			ofBeginShape();
			for (int i = 0; i < c7Audio.size(); i++){
				float x =  ofMap(i, 0, c7Audio.size(), 0, 480, true);
				ofVertex(x, 50 -c7Audio[i]*50.0f);
			}
			ofEndShape(false);
		
		ofPopMatrix();
	ofPopStyle();
	
	// draw channel 8:
	ofPushStyle();
	ofPushMatrix();
	ofTranslate(512, 422, 0);
	
	ofSetColor(225);
	ofDrawBitmapString("Channel 8", 4, 18);
	
	ofSetLineWidth(1);	
	ofRect(0, 0, 480, 100);
	
	ofSetColor(245, 58, 135);
	ofSetLineWidth(3);
	
	ofBeginShape();
	for (int i = 0; i < c8Audio.size(); i++){
		float x =  ofMap(i, 0, c8Audio.size(), 0, 480, true);
		ofVertex(x, 50 -c8Audio[i]*50.0f);
	}
	ofEndShape(false);
	
	ofPopMatrix();
	ofPopStyle();
	
	// -------------------------
	ofSetColor(225);
	string reportString		= "";
	reportString			+= "volume: ("+ofToString(volume, 2)+") modify with -/+ keys\n";
	reportString			+= "pan:    ("+ofToString(pan, 2)+") modify with mouse x\n";
	reportString			+= "tilt:   ("+ofToString(tilt, 2)+") modify with mouse y\n";
	reportString			+= "synthesis: ";
	
	if( !bNoise ){
		reportString += "sine wave (" + ofToString(targetFrequency, 2) + "hz) modify with mouse y";
	}else{
		reportString += "noise";	
	}
	ofDrawBitmapString(reportString, 32, 579);

}


//--------------------------------------------------------------
void testApp::keyPressed  (int key){
	if (key == '-' || key == '_' ){
		volume -= 0.05;
		volume = MAX(volume, 0);
	} else if (key == '+' || key == '=' ){
		volume += 0.05;
		volume = MIN(volume, 1);
	}
	
	if( key == 's' ){
		soundStream.start();
	}
	
	if( key == 'e' ){
		soundStream.stop();
	}
	
}

//--------------------------------------------------------------
void testApp::keyReleased  (int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
	int width = ofGetWidth();
	pan = (float)x / (float)width;
	float height = (float)ofGetHeight();
	tilt = (float)y / (float)height;
	float heightPct = ((height-y) / height);
	targetFrequency = 2000.0f * heightPct;
	phaseAdderTarget = (targetFrequency / (float) sampleRate) * TWO_PI;
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
	int width = ofGetWidth();
	pan = (float)x / (float)width;
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	//bNoise = true;
}


//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
	//bNoise = false;
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::audioOut(float * output, int bufferSize, int nChannels){	
	//pan = 0.5f;
	float leftScale = 1 - pan;
	float rightScale = pan;

	// sin (n) seems to have trouble when n is very large, so we
	// keep phase in the range of 0-TWO_PI like this:
	while (phase > TWO_PI){
		phase -= TWO_PI;
	}

	if ( bNoise == true){
		// ---------------------- noise --------------
		for (int i = 0; i < bufferSize; i++){
			c1Audio[i] = output[i*nChannels    ] = ofRandom(0, 1) * volume * leftScale;
			c2Audio[i] = output[i*nChannels + 1] = ofRandom(0, 1) * volume * rightScale;
			c3Audio[i] = output[i*nChannels + 2] = ofRandom(0, 1) * volume * rightScale;
			c4Audio[i] = output[i*nChannels + 3] = ofRandom(0, 1) * volume * rightScale;
			
			c5Audio[i] = output[i*nChannels + 4] = ofRandom(0, 1) * volume * rightScale;
			c6Audio[i] = output[i*nChannels + 5] = ofRandom(0, 1) * volume * rightScale;
			c7Audio[i] = output[i*nChannels + 6] = ofRandom(0, 1) * volume * rightScale;
			c8Audio[i] = output[i*nChannels + 7] = ofRandom(0, 1) * volume * rightScale;
		}
	} else {
		// ---------------------- sine wave --------------
		phaseAdder = 0.95f * phaseAdder + 0.05f * phaseAdderTarget;
		for (int i = 0; i < bufferSize; i++){
			phase += phaseAdder;
			float sample = sin(phase);
			c1Audio[i] = output[i*nChannels    ] = sample * volume * leftScale;
			c2Audio[i] = output[i*nChannels + 1] = sample * volume * rightScale;
		}
	}

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
