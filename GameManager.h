#pragma once

#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <time.h>
#include <Windows.h>
#include <memory>
#include <vector>
#include "Snake.h"
#include"Food.h"

class GameManager
{
private:
	//for level of game
	int m_width, m_height; 
	int m_score;
	//used to control players
	char m_up, m_down, m_left, m_right;	
	bool m_quitGame;
	//Pointer to Snake object
	std::shared_ptr<Snake> m_theSnake;
	//Pointer to food object	
	std::shared_ptr<Food> m_theFood;
	
	//Pointers to the tail, cordinates are held in vectors
	std::shared_ptr<std::vector<int>> m_tailX; 
	std::shared_ptr<std::vector<int>> m_tailY;
	int m_tailLength;

public:
	GameManager(int, int);

	//function draws field, snake and food
	void draw();
	//takes input and changes the snakes direction
	void input();	
	//logic of game
	void logic();
	int randomNumber(int);
	void runGame();
};
#endif // !GAMEMANAGER_H

