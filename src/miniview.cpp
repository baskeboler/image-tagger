#include "miniview.h"

MiniView::MiniView(): ready (false) {

}

void MiniView::loadImage (ofImage im) {
    image = im;
    float imW = im.getWidth();
    float imH = im.getHeight();

    if (imW >= imH) {
        scale = MINIVIEW_MAX_WIDTH / imW;

    } else {
        scale = MINIVIEW_MAX_HEIGHT / imH;
    }

    image.resize (imW*scale, imH*scale);
    width = image.getWidth();
    height = image.getHeight();
    viewPort.setPosition (0,0);
    viewPort.setSize (ofGetWindowWidth()*scale, ofGetWindowHeight()*scale);
    ready = true;
}

void MiniView::draw() {
    ofPushMatrix();
    ofPushStyle();
    ofTranslate (-5, 5);
    image.draw (0,0);
    ofSetColor (ofColor::red);
    ofSetLineWidth (5);
    ofNoFill();
    ofDrawRectangle (viewPort);
    ofPopStyle();
    ofPopMatrix();
}

void MiniView::updateScale (float s) {
    zoom = s;
    float newScaleFactor = scale * (1.0/zoom);
    viewPort.setSize (ofGetWindowWidth()*newScaleFactor, ofGetWindowHeight()*newScaleFactor);
}



void MiniView::updatePosition (ofPoint & p) {
    viewPort.setPosition (p*scale);
}

bool MiniView::isReady() const {
    return ready;
}

void MiniView::setReady (bool value) {
    ready = value;
}

int MiniView::getWidth() const {
    return width;
}

void MiniView::setWidth (int value) {
    width = value;
}

int MiniView::getHeight() const {
    return height;
}

void MiniView::setHeight (int value) {
    height = value;
}
