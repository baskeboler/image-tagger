#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    imageLoaded = false;
    zoomFactor = 1.0;
    moveVector = ofVec2f::zero();
#ifdef DEBUG
    ofSetLogLevel (OF_LOG_VERBOSE);
#endif
    gui.assign (new ofxDatGui());

    gui->addHeader ("Tools");
    ofxDatGuiButton * openFileButton = gui->addButton ("Open File");
    openFileButton->onButtonEvent (this, &ofApp::onOpenFile);
    gui->addButton ("Exit")->onButtonEvent (this, &ofApp::onExit);


    ofxDatGuiFolder * navFolder = gui->addFolder ("Nav");
    ofxDatGuiSlider *zoomSlider = navFolder->addSlider ("Zoom", 0.1, 3, 1.0);
    zoomSlider->bind(zoomFactor);
    gui->addFRM();
    gui->addFooter();
 //   gui->
}

//--------------------------------------------------------------
void ofApp::update() {
    if (miniView.isReady()) {
        miniView.updateScale(zoomFactor);
        ofPoint pos(-moveVector.x, -moveVector.y);
        miniView.updatePosition(pos);
    }
}

//--------------------------------------------------------------
void ofApp::draw() {
    if (imageLoaded) {
        ofPushMatrix();
        ofScale(zoomFactor, zoomFactor);
        ofTranslate(moveVector + (finishDrag-startDrag));
        workingImage.draw (0,0);

        ofPopMatrix();
        drawMiniView();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed (int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased (int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved (int x, int y ) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged (int x, int y, int button) {
    finishDrag = ofPoint(x, y);
}

//--------------------------------------------------------------
void ofApp::mousePressed (int x, int y, int button) {
    startDrag = ofPoint(x,y);
    finishDrag = startDrag;
}

//--------------------------------------------------------------
void ofApp::mouseReleased (int x, int y, int button) {
    moveVector += (finishDrag - startDrag);
    startDrag = ofPoint::zero();
    finishDrag = startDrag;
}

//--------------------------------------------------------------
void ofApp::mouseEntered (int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited (int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized (int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage (ofMessage msg) {

}

void ofApp::onOpenFile (ofxDatGuiButtonEvent event) {
    ofLog (OF_LOG_VERBOSE) << "Open file button pushed";
    ofFileDialogResult openFileResult = ofSystemLoadDialog ("Open Image File");

    if (openFileResult.bSuccess) {
        workingImage.load(openFileResult.filePath);
        miniView.loadImage(workingImage);
        imageLoaded = true;
        ofLog (OF_LOG_VERBOSE) << openFileResult.filePath << " loaded.";
    }
}

void ofApp::onExit (ofxDatGuiButtonEvent event) {
    ofExit();
}

void ofApp::drawMiniView()
{
    ofPushMatrix();
    int miniViewWidth = miniView.getWidth();
    int windowWidth = ofGetWindowWidth();
    ofTranslate(windowWidth-miniViewWidth, 0);
    if (miniView.isReady()) {
        miniView.draw();
    }
    ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::dragEvent (ofDragInfo dragInfo) {

}
