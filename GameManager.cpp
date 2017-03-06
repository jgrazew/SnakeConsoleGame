#include "stdafx.h"
#include <iostream>
#include "GameManager.h"
#include <random>

GameManager::GameManager(int height, int width) : m_height(height), m_width(width)
{
	m_score = 0;

	m_up = 'w';
	m_down = 's';
	m_left = 'a';
	m_right = 'd';

	m_quitGame = false;

	//set initial position of snake to the middle and initital food position to random
	m_theSnake= std::shared_ptr<Snake>(new Snake(width / 2, height / 2)); 											                                             
	m_theFood = std::shared_ptr<Food>(new Food(randomNumber(width), randomNumber(height)));

	//tail has max length of 75
	m_tailX = std::make_shared<std::vector<int>>(75);
	m_tailY = std::make_shared<std::vector<int>>(75);
	m_tailLength = 0;
}

void GameManager::draw()
{
	system("cls"); 

	//top wall
	for (int i = 0; i != m_width; i++)	
		std::cout << "#";
	std::cout << std::endl;

	for (int i = 0; i != m_height; i++)
	{
		for (int j = 0; j != m_width; j++)
		{
			int snakeX = m_theSnake->getHeadX();
			int snakeY = m_theSnake->getHeadY();
			int foodX = m_theFood->getFoodX();
			int foodY = m_theFood->getFoodY();

			//first element of each row will be wall
			if (j == 0)					
				std::cout << "#";

			//if x and y coordinates equal to that of snake print head
			else if (i == snakeY && j == snakeX)
				std::cout << "O";
			//if x and y cordinates equal to that of food print it 
			else if (i == foodY && j == foodX)	
				std::cout << "f";
			//last elemnt of each row will be wall
			else if (j == m_width - 1)
				std::cout << "#";
			//draw tail or print space
			else  
			{
				bool print = false;			
				for (int k = 0; k != m_tailLength; k++)
				{
					if ((*m_tailX)[k] == j && (*m_tailY)[k] == i)
					{
						std::cout << "o";
						print = true;

					}

				}
				if (print == false)	
					std::cout << " ";
			}
		}	
		std::cout << std::endl;
	}
	for (int i = 0; i != m_width; i++)	//bottom wall
		std::cout << "#";
	std::cout << std::endl;
	std::cout << m_score << std::endl;

}

void GameManager::input()
{
	if (_kbhit()) 
	{
		char key = _getch();

		if (key == m_up)
		{
			m_theSnake->changeDirection(UP);
		}
		if (key == m_down)
		{
			m_theSnake->changeDirection(DOWN);
		}
		if (key == m_right)
		{
			m_theSnake->changeDirection(RIGHT);
		}
		if (key == m_left)
		{
			m_theSnake->changeDirection(LEFT);
		}
		if (key == 'x')
			m_quitGame = true;
	}

}

void GameManager::logic()
{
	int snakeX = m_theSnake->getHeadX();
	int snakeY = m_theSnake->getHeadY();
	int foodX = m_theFood->getFoodX();
	int foodY = m_theFood->getFoodY();

	//Logic for tail
	int prevX = (*m_tailX)[0]; 
	int prevY = (*m_tailY)[0];
	(*m_tailX)[0] = snakeX; 
	(*m_tailY)[0] = snakeY;
	int currentLoopX, currentLoopY;

	if (m_tailLength > 0)
	{
		for (int i = 1; i != m_tailLength; i++)	
		{
			currentLoopX = (*m_tailX)[i];
			currentLoopY = (*m_tailY)[i];
			(*m_tailX)[i] = prevX; 
			(*m_tailY)[i] = prevY;
			prevX = currentLoopX;
			prevY = currentLoopY;
		}
	}

	//after we move the snake we need to get the cordinates before running the logic
	m_theSnake->moveDirection();
	snakeX = m_theSnake->getHeadX(); 
	snakeY = m_theSnake->getHeadY();

	//terminate game if we hit the walls
	if (snakeX > m_width - 2 || snakeX<1 || snakeY>m_height - 1 || snakeY < 0)	
																				
		m_quitGame = true;

	//if tail hits head- game over
	for (int i = 1; i < m_tailLength; i++)			
		if ((*m_tailX)[i] == snakeX && (*m_tailY)[i] == snakeY)	
			m_quitGame = true;

	//when snake eats food get a new random number for food and increase tail length
	if (snakeX == foodX && snakeY == foodY)
	{
		m_score += 10;
		m_theFood->randomX = randomNumber(m_width);		
		m_theFood->randomY = randomNumber(m_height);

		m_theFood->moveFood();
		m_tailLength = m_tailLength + 1; 

	}

}

void GameManager::runGame()
{
	while (!m_quitGame)
	{
		draw();
		input();
		logic();
	}
}

int GameManager::randomNumber(int y) 
{
	//obtain a random number; set seed generator; define the range
	std::random_device rand; 
	std::mt19937 eng(rand()); 
	std::uniform_int<> dist(1, y - 2);
	return dist(eng);
}
