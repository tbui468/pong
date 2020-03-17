#pragma once
#include "Entity.h"

class Paddle : public Entity
{
private:
	
public:
	Paddle(double x, double y) :Entity(x, y, 25, 100) {};
};

