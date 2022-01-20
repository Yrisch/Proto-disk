#include"noeud.h"

#include <time.h>
#include <iostream>
#include <sstream>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Window/Event.hpp>


#define LENGTH 500
#define DT 1
#define INT_TIME 1000
#define RAYON  3

float length = 500;
class Pdraw{
public: 
    Particle part;
    sf::CircleShape shape;

    Pdraw(double _x, double _y){
        double dx = (rand() % 201 ) ; //0.05f;
        double dy = (rand() % 201 ) ; //0.05f
        double mass = 10;
        part = Particle(mass,Vect(_x,_y),Vect(dx,dy));
        shape.setPosition((float)_x,(float)_y);
        shape.setFillColor(sf::Color::Green);
        shape.setRadius(RAYON);
    }

};

std::vector<Particle*> initDistribution(){
    std::vector<Particle*> part;
    for (int i=0;i<3;i++){
        double x = (rand() % 201 );
        double y = (rand() % 201 );
        double dx = (rand() % 201 ) ; //0.05f;
        double dy = (rand() % 201 ) ; //0.05f
        part.push_back(new Particle(10.0,Vect(x,y),Vect(dx,dy)));
    }
    return part;
}

int main(){
    noeud root = noeud(nullptr,Vect(0,0),LENGTH);
    std::vector<Particle*> Part = initDistribution();
    for (auto &p :Part){
        root.insert(p);
    }

}