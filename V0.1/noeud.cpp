#include "noeud.h"

noeud::noeud(Particle *_p){
    nodeP = _p;


 } 
noeud::noeud(Particle *_p,Vect _pos, float _length){
    if (nodeP == nullptr){
        nodeP = _p;
    }
    ori = _pos;
    length = _length;
    childP.reserve(20);
    box.setOutlineThickness(1.f);
    box.setOutlineColor(sf::Color::Black);
    box.setSize(sf::Vector2f((float)length,(float)length));
    box.setPosition((float)ori.get_X(),(float)ori.get_Y());
    box.setFillColor(sf::Color(242,242,242));
}

void noeud::insert(Particle *_p){
    if (nodeP == nullptr && isLeaf){
        nodeP = _p;
    }
    else if (!isLeaf){
        nodeP = nullptr;
        childP.push_back(_p);
        noeud* child = getChild(_p);
        child->insert(_p);

    }
    else{
        subdivise();
        insert(nodeP);
        insert(_p);
    }

}

noeud* noeud::getChild(Particle *_p){
    Vect tpos = _p->pos;
    bool left = tpos.get_X() < ori.get_X();
    bool right = tpos.get_X() > ori.get_X();
    if (tpos.get_Y()>ori.get_Y()){
        if(right) return child[0];
        if(left)  return child[1];
    }
    else{
        if(right) return child[2];
        if(left)  return child[3];
    }
    return nullptr;
}

void noeud::subdivise(){
    isLeaf = false;
    float newLength = length/2;
    float x=0,y = 0;
    for (int i=0;i<4;i++){
        switch (i)
        {
        case 0:x = ori.get_X()+newLength;y = ori.get_Y()+newLength;;break;
        case 1:x = ori.get_X()-newLength;y = ori.get_Y()+newLength;;break;
        case 2:x = ori.get_X()+newLength;y = ori.get_Y()-newLength;;break;
        case 3:x = ori.get_X()-newLength;y = ori.get_Y()-newLength;;break;
        }
        Vect tempPos = Vect(x,y);
        
        child[i] = new noeud(nullptr,tempPos,newLength);
        child[i]->parent = this;
    }
}

void noeud::compForce(Particle *_p){
    if (_p==nodeP||nodeP==nullptr){
        return;
    }
    else if (isLeaf){
        _p->compForce(*nodeP);
    }
    else{
        float d = _p->pos.distance(nodeP->pos);
        if (length/d<0.5){
            _p->compForceCOM(childP);
        }
        else{
            child[0]->compForce(_p);
            child[1]->compForce(_p);
            child[2]->compForce(_p);
            child[3]->compForce(_p);
        }
    }
}

void noeud::draw(sf::RenderTarget &window){
    box.setFillColor(sf::Color::White);
    window.draw(box);
    if(!isLeaf){
        for (noeud *c : child){
            c->draw(window);
        }
    }

}