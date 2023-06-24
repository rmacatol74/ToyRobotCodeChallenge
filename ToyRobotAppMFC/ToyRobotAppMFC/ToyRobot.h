#pragma once
#include "Direction.h"
#include "Table.h"


#define TABLE_LENGTH_DEFAULT 5
#define TABLE_WIDTH_DEFAULT 5

class ToyRobot
{
private:
	int _xPos;
	int _yPos;
	int _iStep;
	Direction _direction;
	Table _tableDim;

	void SetStep();
public:
	ToyRobot();
	ToyRobot(int x, int y, std::string sDirection);
	ToyRobot(int x, int y, Direction::Facing face);
	virtual ~ToyRobot() = default;

	bool Place(int x, int y, std::string sDirection);
	void Move();
	void Left();
	void Right();
	std::string Report();

};

