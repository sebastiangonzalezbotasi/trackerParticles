#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofEnableAlphaBlending();
    ofSetFrameRate(60);
    
    bola.loadImage( "bola.png" );
    logo.loadImage( "BIONIMIOGoogle.png" );
    
    vidGrabber.setVerbose(true);
    vidGrabber.initGrabber(320,240);
    
    
    //Escala Color
    colorImg.allocate(320,240);
	
    //Escalas de grises
    grayImage.allocate(320,240);
	grayBg.allocate(320,240);
	grayDiff.allocate(320,240);
    
	bLearnBakground = true;
	threshold = 80;
    activoPanel = false;
    
    for(int i = 0; i < TOTAL; i++){
        p[i].pos.set( ofRandom(ofGetWindowWidth()), ofRandom(ofGetWindowHeight()));
    }
    tiempo = 0;
    
}

//--------------------------------------------------------------
void testApp::update(){
    ofBackground(100,100,100);
    
    vidGrabber.update();
    
    if (vidGrabber.isFrameNew()){
        
        colorImg.setFromPixels(vidGrabber.getPixels(), 320,240);
        
        grayImage = colorImg;
        
		if (bLearnBakground == true){
			grayBg = grayImage;
			bLearnBakground = false;
		}
        
		grayDiff.absDiff(grayBg, grayImage);
		grayDiff.threshold(threshold);
		
        contourFinder.findContours(grayDiff, 20, (340*240)/3, 1, false);	// find holes
	}
    
    for (int i = 0; i < contourFinder.nBlobs; i++){
        //optimizar, cuenta rara para escalar
        posX = ( (contourFinder.blobs[i].centroid.x - 20) * 3) + 64; 
        posY = ( (contourFinder.blobs[i].centroid.y - 20) * 3) + 48;
    }
    
    
    
    
    for(int i = 0; i < TOTAL; i++){
        p[i].agregarFuerza(ofVec2f(0,0.00098));
        p[i].agregarNoise(2.7, 0.76);
        p[i].agregarAlphaFade(false);
        p[i].agregarScaleFade(false);
        p[i].update(1);
        
        
        if (p[i].pasoElBorde() || !p[i].estaViva() ){
            p[i] = Pelota();
            p[i].color.setHue( (tiempo%3000)*0.1 );
            p[i].pos.set(posX,posY);
        }
    }
    
    tiempo++;
    
}



//--------------------------------------------------------------
void testApp::draw(){
    
    if( activoPanel ){
        ofSetHexColor(0xffffff);
        colorImg.draw(20,20);
        grayDiff.draw(360,20);
        
        ofFill();
        ofSetHexColor(0x333333);
        ofRect(700,20,320,240);
        ofSetHexColor(0xffffff);
        
        for (int i = 0; i < contourFinder.nBlobs; i++){
            contourFinder.blobs[i].draw(700,20);
        }
        
        ofFill();
        ofSetHexColor(0x000000);
        ofRect(20,280,1000,80);
        
        ofSetHexColor(0xffffff);
        char reportStr[1024];
        sprintf(reportStr, "bg subtraction and blob detection\npress ' ' to capture bg\nthreshold %i (press: +/-)\nnum blobs found %i, fps: %f", threshold, contourFinder.nBlobs, ofGetFrameRate());
        ofDrawBitmapString(reportStr, 30, 300);
        
        logo.draw( 843 ,290 );    
        
    }else{
        
        ofPopStyle();
        colorImg.draw(0,0,ofGetWindowWidth() , ofGetWindowHeight());
        ofPopStyle();
        
        for(int i = 0; i < TOTAL; i++){
            p[i].draw(&bola);   // Le pasa la direcci—n en memoria
        }
        
        
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    switch (key){
		case ' ':
			bLearnBakground = true;
			break;
		case '+':
			threshold ++;
			if (threshold > 255) threshold = 255;
			break;
		case '-':
			threshold --;
			if (threshold < 0) threshold = 0;
			break;
        case '1':
            activoPanel = true;
            break;
        case '2':
            activoPanel = false;
            break;    
	}
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 
    
}