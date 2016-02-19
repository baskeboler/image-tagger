#ifndef MINIVIEW_H
#define MINIVIEW_H
#include "ofMain.h"

#define MINIVIEW_MAX_WIDTH 128.0
#define MINIVIEW_MAX_HEIGHT 128.0
class MiniView
{
public:
    MiniView();
    void loadImage(ofImage im);
    void draw();
    void move(ofVec2f& vec);
    void updateScale(float s);
    void updatePosition(ofPoint& p);
    float scale;
    float zoom;
    ofImage image;
    ofRectangle viewPort;
    int width;
    int height;
    bool ready;
    int getHeight() const;
    void setHeight(int value);
    int getWidth() const;
    void setWidth(int value);
    bool isReady() const;
    void setReady(bool value);
};

#endif // MINIVIEW_H
