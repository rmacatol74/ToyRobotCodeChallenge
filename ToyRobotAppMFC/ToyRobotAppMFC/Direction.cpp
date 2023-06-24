#include "pch.h"
#include "Direction.h"

#define MIN_INDEX 0
#define MAX_INDEX 3
#define NORTH "NORTH"
#define SOUTH "SOUTH"
#define EAST "EAST"
#define WEST "WEST"

Direction::Direction()
{
	_directionsMap.insert(std::make_pair(NORTH, Direction::Facing::North));
	_directionsMap.insert(std::make_pair(EAST, Direction::Facing::East));
	_directionsMap.insert(std::make_pair(WEST, Direction::Facing::West));
	_directionsMap.insert(std::make_pair(SOUTH, Direction::Facing::South));

	_currentIndex = 0;
}

int Direction::GetDirection()
{
	/// Current index is the value for the enum eFacing
	return _currentIndex; 
}

std::string Direction::GetDirectionString()
{
	for (auto iter = _directionsMap.begin(); iter != _directionsMap.end(); iter++) {
		if (_currentIndex == iter->second) {
			return iter->first;
		}
	}

	return std::string();
}

void Direction::SetDirection(Facing direction)
{
	if (direction < MIN_INDEX || direction > MAX_INDEX)
		return;

	_currentIndex = direction;
}

int Direction::SetDirection(std::string direction)
{
	/// Set the currentIndex based on direction which is in string format
	for (auto iter = _directionsMap.begin(); iter != _directionsMap.end(); iter++) {
		if (direction.compare(iter->first) == 0) {
			_currentIndex = iter->second;		
		}
	}

	return _currentIndex;
}

void Direction::IncreaseIndex()
{
	_currentIndex = ((_currentIndex + 1) > MAX_INDEX) ? MIN_INDEX : _currentIndex + 1 ;
}

void Direction::DecreaseIndex()
{
	_currentIndex = ((_currentIndex - 1) < MIN_INDEX) ? MAX_INDEX : _currentIndex - 1 ;
}



