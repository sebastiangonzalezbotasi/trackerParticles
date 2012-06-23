//
//  Pelota.h
//  trackerParticles
//
//  Created by Sebastian Gonzalez Botasi on 22/06/12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#ifndef PELOTA  // recordemos que esto previene declarar la misma clase
#define PELOTA  // dos veces

#include "ofMain.h" // Aqui agregamos los métodos y clases de oF

class Pelota {
public:         // Todos los métodos aquí son públicos por los que cualquiera puede
    // verlos y acceder a ellos.
     Pelota();
    
    void agregarFuerza(ofVec2f fuerza);
    void agregarNoise(float _angulo, float _turbulencia);   //agregará un movimiento aleatorio suave
    
    void agregarAlphaFade(bool _fadeOut);   // hará que se desvanezcan
    void agregarScaleFade(bool _melt);      // hará que se achiquen
    void matar();
    
    bool pasoElBorde();
    bool estaViva();                        // esta función chequea si esta viva
    
    void update(float _limiteDeVelocidad);  // el update quitará vida y limitará el movimiento
    
    void draw();
    void draw(ofImage* _imagen);
    
    ofColor color;
    
    ofVec2f pos, vel, acc;
    float alphaF, escalaF;
    int vida,vidaInicial, tamanio;
};
#endif