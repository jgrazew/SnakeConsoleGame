#pragma once

#ifndef SNAKE_H
#define SNAKE_H

#include "stdafx.h"
#include <iostream>
#include"enumDirection.h"

class Snake
{
private:
	//head position of snake
	int headX, headY;
	//starting positin of snake
	int originalX, originalY; 
	e_direction direction;


public:
	Snake(int, int);
	void reset();
	//"setter" for member variable direction
	void changeDirection(e_direction); 
	void moveDirection();

	//"Getters" for position of head and direction
	inline int getHeadX() const { return headX; }
	inline int getHeadY() const { return headY; }
	inline e_direction getDirection() { return direction; }

};

#endif // !SNAKE_H
