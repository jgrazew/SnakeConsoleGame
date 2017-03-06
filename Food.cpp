#include "stdafx.h"
#include <iostream>
#include "Food.h"

Food::Food() : m_foodX(0), m_foodY(0)
{

}

Food::Food(int foodCorX, int foodCorY) : m_foodX(foodCorX), m_foodY(foodCorY),
randomX(foodCorX), randomY(foodCorY)
{

}

void Food::moveFood()
{
	m_foodX = randomX;
	m_foodY = randomY;
}
