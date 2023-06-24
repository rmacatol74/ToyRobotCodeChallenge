#include "pch.h"
#include "ToyRobot.h"
#include <string>


ToyRobot::ToyRobot()
	: _tableDim(TABLE_LENGTH_DEFAULT, TABLE_WIDTH_DEFAULT)
{
	_xPos = DEFAULT_POSITION;
	_yPos = DEFAULT_POSITION;
	_iStep = 0;
	_direction.SetDirection(Direction::North);
}

bool ToyRobot::Place(int x, int y, std::string direction)
{
	if (_tableDim.isPosSafe(x, y))
	{
		/// Safe to place the robot in the table
		_xPos = x;
		_yPos = y;
		_direction.SetDirection(direction);
		return true;
	}

	/// Must return TRUE if placement successful or the toyRobot is already on the table 
	/// otherwise return FALSE
	return (_tableDim.isPosSafe(x, y) ? true : false);
}

void ToyRobot::Move()
{
	int newXpos = _xPos;
	int newYpos = _yPos;

	SetStep();

	Direction::Facing direction = (Direction::Facing)_direction.GetDirection();
	switch (direction)
	{
		case Direction::North:
		case Direction::South:
			newYpos = _yPos + _iStep;
			break;
		case Direction::East:
		case Direction::West:
			newXpos = _xPos + _iStep;
			break;
		default:
			return;
	}

	if (_tableDim.isPosSafe(newXpos, newYpos))
	{
		/// if safe then set the toy robot to the new position
		_xPos = newXpos;
		_yPos = newYpos;
	}
}

void ToyRobot::Left()
{
	/// Index based for Facing enum
	/// Index Values : 
	///      NORTH = 0, EAST = 1 , SOUTH = 2, WEST = 3
	/// Behavior : 
	///     LEFT decreases the index and will loop back again to 3 from 0
	
	_direction.DecreaseIndex();


}

void ToyRobot::Right()
{
	/// Index based for Facing enum
	/// Index Values : 
	///      NORTH = 0, EAST = 1 , SOUTH = 2, WEST = 3
	/// Behavior : 
	///     RIGHT increases the index and will loop back again to 0 from 3

	_direction.IncreaseIndex();
}

std::string ToyRobot::Report()
{
	std::string report = "Output: " + std::to_string(_xPos) + "," + std::to_string(_yPos) + "," + _direction.GetDirectionString() + "\0";
	printf(report.c_str());
	return report;
}

void ToyRobot::SetStep()
{
	Direction::Facing direction = (Direction::Facing)_direction.GetDirection();
	switch (direction)
	{
		case Direction::North :
		case Direction::East  :
			_iStep = 1; /// positive if moving up (north) or right (east)
			break;
		case Direction::South:
		case Direction::West:
			_iStep = -1; /// negative step if moving left (west) or down (south)
			break;
		default : 
			_iStep = 0;
			return;
	}
}



