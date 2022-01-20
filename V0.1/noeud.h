#include"Particle.h"
#include <vector>
#include <algorithm>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>

class noeud {
private: 
    bool isLeaf = true;
    Particle* nodeP = nullptr;
    Vect ori;
    float length;
    noeud* parent = nullptr;
    noeud* child[4] = {nullptr,nullptr,nullptr,nullptr};
    std::vector<Particle*> childP;
    sf::RectangleShape box;


    void subdivise();

public:

    noeud(Particle* p);
    noeud(Particle* _p,Vect pos, float length);
    void insert(Particle *_p);
    noeud* getChild(Particle*_p);
    void compForce(Particle *_p);
    void draw(sf::RenderTarget &window);




};