#pragma once

#ifndef FOOD_H
#define FOOD_H

#include "stdafx.h"
#include <iostream>

class Food
{
private:
	//food position
	int m_foodX, m_foodY; 

public:
	Food();
	Food(int, int);
	void moveFood();
	
	//used to change coordinates of food
	int randomX, randomY;

	//"Getters" for position of food
	inline int getFoodX() const { return m_foodX; }
	inline int getFoodY() const { return m_foodY; }

};


#endif // !FOOD_H
