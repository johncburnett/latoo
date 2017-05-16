#pragma once

#include "ofMain.h"
#include "ofxTF.h"
#include "ofxGui.h"

#if __APPLE__
    #include "ofxSyphon.h" // mac exclusive
    #define numParticles 3000000 // dGPU in OSX
#else
    #define numParticles 2200000 // iGPU in Linux
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
    
        ofxPanel gui;
        ofParameter<float> a, b, c, d;
        ofParameter<float> da, db, dc, dd;
        ofParameter<float> scale, opacity;
        ofxLabel keys;
        std::string params;
    
        ofxTF tf;
        ofShader renderShader;
        ofEasyCam cam;
        ofImage particleImage;

        void initShaders(void);
        void initGUI(void);
    
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
