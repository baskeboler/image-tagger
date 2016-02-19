#pragma once

#include "ofxDatGui.h"
#include "ofMain.h"
#include <Poco/SharedPtr.h>
#include "miniview.h"



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

        void onOpenFile(ofxDatGuiButtonEvent event);
        void onExit(ofxDatGuiButtonEvent event);
protected:
        void drawMiniView();
private:
        Poco::SharedPtr<ofxDatGui> gui;
        ofImage original;
        ofImage workingImage;
        bool imageLoaded;
        float zoomFactor;
        ofVec2f moveVector;

        ofPoint startDrag;
        ofPoint finishDrag;

        MiniView miniView;
};
