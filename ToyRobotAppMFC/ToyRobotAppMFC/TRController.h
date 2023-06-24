#pragma once

#include "ToyRobot.h"
#include <functional>
#include <regex>
#include <map>

typedef std::map<std::string, std::function<void(std::smatch match)>> CommandType;

class TRController
{
public : 
	TRController();
	virtual ~TRController() = default;

	bool ProcessCommand(std::string input);

private : 	
	/// <summary>
	/// Map the input string to the commands using regex & lambda function
	/// </summary>
	CommandType _mapCommands;

	void InitializeMapCommands();
	CommandType GetCommands();
};

