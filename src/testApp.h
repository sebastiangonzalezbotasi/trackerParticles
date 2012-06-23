#pragma once

#include "ofMain.h"
#include "Pelota.h"
#include "ofxOpenCv.h"

#define TOTAL 100       // Esta bueno explorar hasta que nœmero puede llegar


class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    Pelota  p[TOTAL];
    int tiempo;
 
    ofImage bola;
    ofImage logo;
    
    
    ofVideoGrabber 		    vidGrabber;
    
    ofxCvColorImage			colorImg;
    
    ofxCvGrayscaleImage 	grayImage;
    ofxCvGrayscaleImage 	grayBg;
    ofxCvGrayscaleImage 	grayDiff;
    
    ofxCvContourFinder 	    contourFinder;
    
    int 				threshold;
    bool				bLearnBakground;
    bool activoPanel;
    
    int posX;
    int posY;

  		
};
