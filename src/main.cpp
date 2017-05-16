#include "ofMain.h"
#include "ofApp.h"

#define WIDTH 1920
#define HEIGHT 1080

//========================================================================
int main( ){
    ofGLWindowSettings settings;
    settings.setGLVersion(3, 2);
    settings.width = WIDTH;
    settings.height = HEIGHT;
    ofCreateWindow(settings);
    ofRunApp(new ofApp());
}
