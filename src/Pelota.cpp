//
//  Pelota.cpp
//  trackerParticles
//
//  Created by Sebastian Gonzalez Botasi on 22/06/12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#include "Pelota.h"     // Referencia al header donde los siguientes métodos están 

Pelota::Pelota(){
    tamanio = ofRandom(20);
    color.set(ofRandom(255),ofRandom(255),ofRandom(255));
    
    pos.set( ofGetWindowWidth()*0.5 , ofGetWindowHeight()*0.5 );
    vel.set( ofRandom(-1,1),ofRandom(-1,1));
    acc.set( ofRandom(-1,1),ofRandom(-1,1));
    
    alphaF  = 1;
    escalaF = 1;
    
    vida = vidaInicial = ofRandom(200,1000);
}

void Pelota::update(float _limiteDeVelocidad = 0.0){
    vel += acc; // Suma la aceleración a la velocidad
    
    if (_limiteDeVelocidad != 0)
        vel.limit(_limiteDeVelocidad);          
    pos += vel; // Suma la velocidad a la posición
    acc *= 0;   // Vuelve a cero la aceleración
    
    vida--;
}

void Pelota::agregarFuerza(ofVec2f fuerza){
    acc += fuerza;
}

void Pelota::agregarNoise(float _angulo, float _turbulencia){
    float angulo = ofSignedNoise(pos.x * 0.005f, pos.y *0.005f) * angulo;
    ofVec2f noiseVector( cos( angulo ), sin( angulo ) );
    acc += noiseVector * _turbulencia * (1.0 - ofNormalize(vida, 0, vidaInicial));
}

void Pelota::agregarAlphaFade(bool _fadeOut = true){
    if (_fadeOut)
        alphaF = 1.0f-ofNormalize(vida, 0,vidaInicial);
    else 
        alphaF = ofNormalize(vida, 0,vidaInicial);
}

void Pelota::agregarScaleFade(bool _melt = true){
    if (_melt)
        escalaF = 1.0f-ofNormalize(vida, 0,vidaInicial);
    else 
        escalaF = ofNormalize(vida, 0,vidaInicial);
}

void Pelota::draw(){
    ofSetColor(color, color.a * alphaF );
    ofCircle(pos.x, pos.y, tamanio * escalaF );
}

void Pelota::draw(ofImage* _imagen){ // espera un puntero de tipo ofImage
    ofSetColor(color, color.a * alphaF );
    _imagen->draw(  pos.x - _imagen->getWidth() * escalaF, 
                  pos.y - _imagen->getHeight() * escalaF, 
                  _imagen->getWidth() * escalaF, 
                  _imagen->getHeight() * escalaF);
}

void Pelota::matar(){
    vida = 0;
}

bool Pelota::pasoElBorde(){
    bool rta = false;
    
    if ( pos.x < 0 || pos.y < 0 || pos.x > ofGetWindowWidth() || pos.y > ofGetWindowHeight()){
        rta = true;
    }
        return rta;
}

bool Pelota::estaViva(){
    bool rta = true;
    
    if (vida <= 0)
        rta = false;
    
    return rta;
}