#include "stdafx.h"
#include <iostream>
#include "Snake.h"
#include "Food.h"
#include "GameManager.h"


int main()
{
	GameManager g(20, 20);
	g.runGame();
	
	return 0;
}
