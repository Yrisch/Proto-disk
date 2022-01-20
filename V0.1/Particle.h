#include "Vect.h"
#include <vector>
#include<cmath>


class Particle{

public:
    double m;
    Vect pos;
    Vect vel;
    Vect force = Vect();
    /**!
     *
     * @param _pos
     * @param _vel
     * @param _m
     */
    Particle(double _m,Vect _pos,Vect _vel);
    Particle();
    void stepUp(float dt);
    void compVel(float dt);
    void compForce(Particle &otherP);
    void compForceCOM(std::vector<Particle*> ComP);
    inline void resetforce(){force = Vect();};


};