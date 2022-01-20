#pragma once
class Vect
{
	double x;
	double y;

public:
	Vect(double , double );
	Vect();
	virtual ~Vect();
	Vect(const Vect& other);
	inline double get_X() { return x; };
	inline double get_Y() { return y; };
	double norme();
	double distance(const Vect& other);
	double distanceSquared(const Vect& other);
	inline void set_X(double X) { x = X; };
	inline void set_Y(double Y) { y = Y; };
	bool operator==(const Vect v);
	bool operator!=(const Vect v);
	Vect operator-(Vect v);
	Vect operator+(Vect v);
	Vect operator*(int i);
	Vect operator*(long i);
	Vect operator*(double i);
};

