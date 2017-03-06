#include "stdafx.h"
#include <iostream>
#include "Snake.h"

Snake::Snake(int corX, int corY) : originalX(corX), originalY(corY), headX(corX), headY(corY), direction(STOP)
{

}

void Snake::reset()
{
	headX = originalX;
	headY = originalY;
	direction = STOP;
}

void Snake::changeDirection(e_direction dir)
{
	direction = dir;
}

void Snake::moveDirection()
{
	switch (direction)
	{
	case STOP:
		break;
	case LEFT:
		headX--;
		break;
	case RIGHT:
		headX++;
		break;
	case UP:
		headY--;	
		break;
	case DOWN:
		headY++;
		break;
	default:
		break;
	}
}
