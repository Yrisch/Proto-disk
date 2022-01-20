#include "Vect.h"
#include <cmath>
Vect::Vect(double X, double Y) {// constructeur
	x = X;
	y = Y;
}
Vect::Vect() {// construteur
	x =  0;
	y =  0;
}
Vect::~Vect() {//destructeur

}
Vect::Vect(const Vect &other) {// construteur
	x = other.x;
	y = other.y;
}

double Vect::norme() { // calcule la norme du vecteur
	return sqrt(x * x + y * y);
}

double Vect::distance(const Vect &other){
	return sqrt((x * x-other.x*other.x) + (y * y-other.y*other.y));
}
double Vect::distanceSquared(const Vect &other){
	return (x * x-other.x*other.x) + (y * y-other.y*other.y);
}
bool Vect::operator==(const Vect v) {//surcharge d'opérateur ==
	bool result;
	result = (x == v.x) && (y == v.y);
	return result;
}
bool Vect::operator!=(const Vect v){//surcharge d'opérateur !=
	bool result;
	result = (x != v.x) || (y != v.y);
	return result;
}
Vect Vect::operator-(Vect v) {//surcharge d'opérateur -
	Vect diff;
	diff.set_X(x - v.get_X());
	diff.set_Y(y - v.get_Y());
	return diff;
}
Vect Vect::operator+(Vect v) {//surcharge d'opérateur +
	Vect somme;
	somme.set_X(x + v.get_X());
	somme.set_Y(y + v.get_Y());
	return somme;
}
Vect Vect::operator*(int i) {//surcharge d'opérateur * pour un scalaire int
	Vect produit;
	produit.set_X(x*i);
	produit.set_Y(y*i);
	return produit;
}
Vect Vect::operator*(long i) {//surcharge d'opérateur * pour un scalaire long
	Vect produit;
	produit.set_X(x * i);
	produit.set_Y(y * i);
	return produit;
}
Vect Vect::operator*(double i) {//surcharge d'opérateur pour un scalaire double
	Vect produit;
	produit.set_X(x * i);
	produit.set_Y(y * i);
	return produit;
}