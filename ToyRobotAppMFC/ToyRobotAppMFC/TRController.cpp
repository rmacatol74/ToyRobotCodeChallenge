#include "pch.h"
#include "TRController.h"
#include <stdio.h>

/// STRICT FORMAT : "PLACE X,Y,F"
#define PLACE_REGEX   "^\\s*(PLACE)\\s([0-9]),([0-9]),(NORTH|EAST|WEST|SOUTH)\\s*$"
#define MOVE_REGEX    "^\\s*(MOVE)\\s*$"
#define LEFT_REGEX    "^\\s*(LEFT)\\s*$"
#define RIGHT_REGEX   "^\\s*(RIGHT)\\s*$"
#define REPORT_REGEX  "^\\s*(REPORT)\\s*$"

static ToyRobot _toyRobot;
bool _isPlacementOK;

TRController::TRController()
{
	_isPlacementOK = false;
	InitializeMapCommands();
}

bool TRController::ProcessCommand(std::string input)
{
	CommandType allCommands = GetCommands();

	for (auto iter = allCommands.begin(); iter != allCommands.end(); iter++)
	{
		std::regex regx(iter->first); /// case sensitive 
		std::smatch found;
		if (iter->second && std::regex_match(input, found, regx))
		{
			iter->second(found);
			return true;
		}
	}

	return false;
}

CommandType TRController::GetCommands()
{
	return _mapCommands;
}

void TRController::InitializeMapCommands()
{
	/// Add all ToyRobot's command (PLACE, MOVE, LEFT, RIGHT, REPORT)
	/// 

	/// 1. Add PLACE command 
	/// STRICT FORMAT : "PLACE X,Y,F"
	_mapCommands.insert(std::make_pair(PLACE_REGEX,
		    /// Lambda begin
			[](std::smatch found) 
			{
				// 0. found[0] is the whole input
				// 1. Get position starting with index 2 for x, index 3 for y
				int x = stoi(found[2]);
				int y = stoi(found[3]);

				// 2. Get the Direction string
				std::string direction = found[4];

				// 3. Process command
				_isPlacementOK = _toyRobot.Place(x, y, direction);
				return _isPlacementOK;

			}
			/// Lambda end
		));

	/// 2. Add MOVE command
	_mapCommands.insert(std::make_pair(MOVE_REGEX,
		/// Lambda begin
		[](std::smatch found)
		{
			if (_isPlacementOK) // if the robot is already placed
			{
				_toyRobot.Move();
			}
		}
		/// Lambda end
	));

	/// 3. Add LEFT command
	_mapCommands.insert(std::make_pair(LEFT_REGEX,
		/// Lambda begin
		[](std::smatch found)
		{
			if (_isPlacementOK) // if the robot is already placed
			{
				_toyRobot.Left();
			}
		}
		/// Lambda end
	));

	/// 4. Add RIGHT command
	_mapCommands.insert(std::make_pair(RIGHT_REGEX,
		/// Lambda begin
		[](std::smatch found)
		{
			if (_isPlacementOK) // if the robot is already placed
			{
				_toyRobot.Right();
			}
		}
		/// Lambda end
	));

	/// 5. Add REPORT command
	_mapCommands.insert(std::make_pair(REPORT_REGEX,
		/// Lambda begin
		[](std::smatch found)
		{
			if (_isPlacementOK) // if the robot is already placed
			{
				_toyRobot.Report();
			}
		}
		/// Lambda end
	));

}
