#pragma once

#include "ofMain.h"
#include "ofxTF.h"
#include "ofxGui.h"

// syphon is mac exclusive
#if __APPLE__
    #include "ofxSyphon.h"
#endif

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
		
    private:
        float xi, yi, zi;
        float xn, yn, zn;
        const int spacing;
    
        ofxPanel gui;
        ofParameter<float> a, b, c, d;
        ofParameter<float> da, db, dc, dd;
        ofParameter<float> scale, opacity;
        ofxLabel keys;
    
        ofxTF tf;
        const int numParticles = 1500000;
        ofShader renderShader;
        ofEasyCam cam;
        ofImage particleImage;
    
        // save camera perspectives
        void camLoadPos(string);
        void camSavePos(string);
        ofMatrix4x4 defaultPosition;
    
        // Syphon
    #if __APPLE__
        ofxSyphonServer mainOutputSyphonServer;
        ofxSyphonClient mClient;
    #endif
};
