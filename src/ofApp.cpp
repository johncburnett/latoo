#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    
    // init class vars
    xn = yn = zn = 0.5;
    xi = yi = zi = 0.5;
    a = 2; b = 1.526; c = 1.455; d = 1.139;
    da = db = dc = dd = 1;
    scale = 200;
    spacing = 1;

    // init coord buffer
    float * position = new float[numParticles * 3];
    for(int i = 0; i<numParticles; i++){
        for(int j = 0; j < spacing; j++) {
            xn = sin(b*yi) + (c * sin(b*xi));
            zn = sin(a*yi) + (b * sin(a*xi));
            yn = sin(a*xi) + (d * sin(a*yi));
            xi = xn; yi = yn; zi = zn;
        }
        position[i * 3 + 0] = xn;
        position[i * 3 + 1] = yn;
        position[i * 3 + 2] = zn;
    }
    
    // init shaders
    tf.setup(numParticles, "shaders/transformFeedback.vert");
    tf.addBufferObject("inPosition", "outPosition", 3, GL_RGB32F, position);
    tf.generate();
    
    renderShader.load("shaders/render");
    
    // gui
    gui.setup("latoo");
    gui.add(a.set("a", 2.0, -3.0, 3.0));
    gui.add(b.set("b", 1.526, -3.0, 3.0));
    gui.add(c.set("c", 1.455, 0.5, 1.5));
    gui.add(d.set("d", 1.139, 0.5, 1.5));
    gui.add(da.set("da", 1, 0.999, 1.001));
    gui.add(db.set("db", 1, 0.999, 1.001));
    gui.add(dc.set("dc", 1, 0.999, 1.001));
    gui.add(dd.set("dd", 1, 0.999, 1.001));
    gui.add(scale.set("scale", 200, 1, 1000));
    gui.add(opacity.set("opacity", 0.08, 0.0, 0.5));
    gui.add(keys.setup("shortcuts", "\n  's' to modulate coefficients\n  'g' to randomize modulation\n  'b' to reset to coefficients\n  'r' to reset and pause\n  'f' for fullscreen"));
    
    // set camera
    camLoadPos("camPos");
    
    // syphon
#if __APPLE__
    mainOutputSyphonServer.setName("Screen Output");
    mClient.setup();
    mClient.set("","Simple Server");
#endif
}

//--------------------------------------------------------------
void ofApp::update(){
    // modulate params
    a *= da;
    b *= db;
    c *= dc;
    d *= dd;
    
    // run transform feedback
    tf.begin();
    tf.getShader()->setUniform1f("a", a);
    tf.getShader()->setUniform1f("b", b);
    tf.getShader()->setUniform1f("c", c);
    tf.getShader()->setUniform1f("d", d);
    tf.end();
    ofSetWindowTitle(ofToString(ofGetFrameRate()));
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofEnableAlphaBlending();
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    
    // render
    cam.begin();
    renderShader.begin();
    renderShader.setUniform1f("scale", scale);
    renderShader.setUniform1f("opacity", opacity);
    tf.getVbo()->draw(GL_POINTS, 0, numParticles);
    renderShader.end();
    cam.end();
    
    ofDisableAlphaBlending();
    
    // Syphon
#if __APPLE__
    mClient.draw(50, 50);
    mainOutputSyphonServer.publishScreen();
#endif

    gui.draw();
}

//--------------------------------------------------------------

void ofApp::camLoadPos(string _filename){
    ofFile inFile;
    inFile.open(_filename+".mat", ofFile::ReadOnly, true);
    inFile.read((char*) defaultPosition.getPtr(), sizeof(float) * 16);
    inFile.close();
    cam.setTransformMatrix(defaultPosition);
}

void ofApp::camSavePos(string _filename){
    defaultPosition = cam.getGlobalTransformMatrix();
    
    ofFile outFile;
    outFile.open(_filename+".mat", ofFile::WriteOnly, true);
    outFile.write((char*) defaultPosition.getPtr(), sizeof(float) * 16);
    outFile.close();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 's') { da = db = dc = dd = 1.00015; }
    else if(key == 'e') { da = db = dc = dd = 1; }
    else if(key == 'r') {
        xn = yn = zn = 0.5;
        a = 2; b = 1.526; c = 1.455; d = 1.139;
        da = db = dc = dd = 1;
    }
    else if(key == 'b') { a = 2; b = 1.526; c = 1.455; d = 1.139; }
    else if(key == 'g') {
        da = ofRandom(0.999, 1.001);
        db = ofRandom(0.999, 1.001);
        dc = ofRandom(0.999, 1.001);
        dd = ofRandom(0.999, 1.001);
    }
    
    else if(key == 'f') { ofToggleFullscreen(); }
    else if(key == 'f') { ofToggleFullscreen(); camLoadPos("camPos"); }
    else if(key == 'c') { camSavePos("camPos"); }
    else if(key == 'l') { camLoadPos("camPos"); }
    
    else if(key == OF_KEY_UP) {
        da *= 1.0001;
        db *= 1.0001;
        dc *= 1.0001;
        dd *= 1.0001;
    }
    else if(key == OF_KEY_DOWN) {
        da *= 0.9999;
        db *= 0.9999;
        dc *= 0.9999;
        dd *= 0.9999;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){ }
void ofApp::mouseMoved(int x, int y ){ }
void ofApp::mouseDragged(int x, int y, int button){ }
void ofApp::mousePressed(int x, int y, int button){ }
void ofApp::mouseReleased(int x, int y, int button){ }
void ofApp::mouseEntered(int x, int y){ }
void ofApp::mouseExited(int x, int y){ }
void ofApp::windowResized(int w, int h){ }
void ofApp::gotMessage(ofMessage msg){ }
void ofApp::dragEvent(ofDragInfo dragInfo){ }
