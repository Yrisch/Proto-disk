#include "Particle.h"

#define G 6.67e-11


Particle::Particle(){
    m=0;
    pos = Vect();
    vel = Vect();
}

Particle::Particle(double _m,Vect _pos,Vect _vel){
    m = _m;
    pos = _pos;
    vel = _vel;
}

void Particle::stepUp(float dt){
    pos = pos+vel*dt;
}

void Particle::compVel(float dt){
    vel = vel+force*(dt);
}
void Particle::compForce(Particle &otherP){
    double dx = otherP.pos.get_X()-pos.get_X();
    double dy = otherP.pos.get_Y()-pos.get_Y();
    double r = sqrt(dx*dx-dy*dy);
    double softParam = 5.0f;
    double precompForce = (G*otherP.m)/(pow(r,3)+softParam*softParam);
    force.set_X(force.get_X()+(precompForce*dx));
    force.set_Y(force.get_Y()+(precompForce*dy));
}
void Particle::compForceCOM(std::vector<Particle*> ComP){
    Vect Com_pos = Vect();
    double Com_m = 0;
    for(auto && part: ComP){
        Com_pos = Com_pos + part->pos*part->m;
        Com_m += part->m;
    }
    Particle Com_part = Particle(Com_m,Com_pos,Vect());
    compForce(Com_part);

}