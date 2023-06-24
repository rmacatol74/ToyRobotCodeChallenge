#pragma once
#include <map>

class Direction
{
public :
	/// <summary>
	/// Facing value will also act as an index for the Directions Mapping
	/// </summary>
	enum Facing { North =0, East, South, West };

	Direction();
	virtual ~Direction() = default;

	int GetDirection();
	void SetDirection(Facing face);
	int SetDirection(std::string direction);

	void IncreaseIndex();
	void DecreaseIndex();

	std::string GetDirectionString();

private:
	int _currentIndex;
	std::map<std::string, Facing> _directionsMap;

};

