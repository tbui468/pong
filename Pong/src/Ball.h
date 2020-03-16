#pragma once
#include "Entity.h"

class Ball : public Entity
{
private:
public:
	Ball(double x, double y, double width, double height) : Entity(x, y, width, height) {};
};

