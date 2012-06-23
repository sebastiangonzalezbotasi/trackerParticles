#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofEnableAlphaBlending();
    ofSetFrameRate(60);
    bola.loadImage( "bola.png" );
    
    for(int i = 0; i < TOTAL; i++){
        p[i].pos.set( ofRandom(ofGetWindowWidth()), ofRandom(ofGetWindowHeight()));
    }
    tiempo = 0;
}

//--------------------------------------------------------------
void testApp::update(){
 
        for(int i = 0; i < TOTAL; i++){
            p[i].agregarFuerza(ofVec2f(0,0.00098));
            p[i].agregarNoise(2.7, 0.76);
            p[i].agregarAlphaFade(false);
            p[i].agregarScaleFade(false);
            p[i].update(1);
            
            
            if (p[i].pasoElBorde() || !p[i].estaViva() ){
                p[i] = Pelota();
                p[i].color.setHue( (tiempo%3000)*0.1 );
                p[i].pos.set(mouseX,mouseY);
            }
        }
        
        tiempo++;
    
    
}



//--------------------------------------------------------------
void testApp::draw(){
    ofBackground(0);

    for(int i = 0; i < TOTAL; i++){
        p[i].draw(&bola);   // Le pasa la direcci—n en memoria
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
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