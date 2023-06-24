#include "pch.h"
#include "CppUnitTest.h"

#include "../ToyRobotAppMFC/TRController.h"
#include "../ToyRobotAppMFC/TRController.cpp"
#include "../ToyRobotAppMFC/ToyRobot.cpp"
#include "../ToyRobotAppMFC/Table.cpp"
#include "../ToyRobotAppMFC/Direction.cpp"

#include <iostream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		/// <summary>
		/// PLACE Command Tests
		/// </summary>
		TEST_METHOD(TRController_ProcessCommand_PLACE)
		{
			TRController trc;
			/// Correct Format, check upper case, and spacing
			/// !!!!!!!!!!!!!! IMPORTANT !!!!!!!!!!!!!!
			/// x & y VALUE are checked by the ToyRobot class not by TRController
			Assert::IsTrue(trc.ProcessCommand("PLACE 0,0,NORTH"));
			Assert::IsTrue(trc.ProcessCommand("PLACE 1,1,SOUTH"));
			Assert::IsTrue(trc.ProcessCommand("PLACE 2,2,EAST"));
			Assert::IsTrue(trc.ProcessCommand("PLACE 3,3,WEST"));
			Assert::IsTrue(trc.ProcessCommand("PLACE 4,4,NORTH"));

			/// Direction is not in Uppercase
			Assert::IsFalse(trc.ProcessCommand("PLACE 0,0,north"));
			Assert::IsFalse(trc.ProcessCommand("PLACE 0,0,East"));
			Assert::IsFalse(trc.ProcessCommand("PLACE 0,0,West"));
			Assert::IsFalse(trc.ProcessCommand("PLACE 0,0,south"));

			/// Spaces in front, back of the command and within
			Assert::IsTrue(trc.ProcessCommand("             PLACE 0,0,NORTH"));
			Assert::IsTrue(trc.ProcessCommand("PLACE 0,0,NORTH             "));
			Assert::IsFalse(trc.ProcessCommand("PLACE 0    ,0,NORTH"));
			Assert::IsFalse(trc.ProcessCommand("PLACE 0,0    ,NORTH"));
			Assert::IsFalse(trc.ProcessCommand("PLACE 0,    0    ,NORTH"));
			Assert::IsFalse(trc.ProcessCommand("PLACE 0,    0,NORTH"));
			Assert::IsFalse(trc.ProcessCommand("PLACE 0,0    ,NORTH"));	
			Assert::IsFalse(trc.ProcessCommand("PLACE            0,0,NORTH"));
		}

		/// <summary>
		/// MOVE Command Tests
		/// </summary>
		TEST_METHOD(TRController_ProcessCommand_MOVE)
		{
			TRController trc;
			/// Trailing & Leading Spaces
			Assert::IsTrue(trc.ProcessCommand("MOVE"));
			Assert::IsTrue(trc.ProcessCommand("MOVE            "));
			Assert::IsTrue(trc.ProcessCommand("            MOVE"));
			
			Assert::IsFalse(trc.ProcessCommand("Move"));
			Assert::IsFalse(trc.ProcessCommand("move"));
			Assert::IsFalse(trc.ProcessCommand("mOVE"));
			Assert::IsFalse(trc.ProcessCommand("M0VE"));
			Assert::IsFalse(trc.ProcessCommand("MoVE"));

		}

		TEST_METHOD(TRController_ProcessCommand_LEFT)
		{
			TRController trc;
			/// Trailing & Leading Spaces
			Assert::IsTrue(trc.ProcessCommand("LEFT"));
			Assert::IsTrue(trc.ProcessCommand("LEFT            "));
			Assert::IsTrue(trc.ProcessCommand("            LEFT"));

			Assert::IsFalse(trc.ProcessCommand("Left"));
			Assert::IsFalse(trc.ProcessCommand("left"));
			Assert::IsFalse(trc.ProcessCommand("lEFT"));
			Assert::IsFalse(trc.ProcessCommand("LEFt"));
			Assert::IsFalse(trc.ProcessCommand("LeFT"));

		}

		TEST_METHOD(TRController_ProcessCommand_RIGHT)
		{
			TRController trc;
			/// Trailing & Leading Spaces
			Assert::IsTrue(trc.ProcessCommand("RIGHT"));
			Assert::IsTrue(trc.ProcessCommand("RIGHT            "));
			Assert::IsTrue(trc.ProcessCommand("            RIGHT"));

			Assert::IsFalse(trc.ProcessCommand("Right"));
			Assert::IsFalse(trc.ProcessCommand("right"));
			Assert::IsFalse(trc.ProcessCommand("rIGHT"));
			Assert::IsFalse(trc.ProcessCommand("RIGHt"));
			Assert::IsFalse(trc.ProcessCommand("RiGHT"));

		}

		TEST_METHOD(TRController_ProcessCommand_REPORT)
		{
			TRController trc;
			/// Trailing & Leading Spaces
			Assert::IsTrue(trc.ProcessCommand("REPORT"));
			Assert::IsTrue(trc.ProcessCommand("REPORT            "));
			Assert::IsTrue(trc.ProcessCommand("            REPORT"));

			Assert::IsFalse(trc.ProcessCommand("Report"));
			Assert::IsFalse(trc.ProcessCommand("report"));
			Assert::IsFalse(trc.ProcessCommand("rEPORT"));
			Assert::IsFalse(trc.ProcessCommand("REPORt"));
			Assert::IsFalse(trc.ProcessCommand("RePORT"));

		}
		
		TEST_METHOD(ToyRobot_Place)
		{
			ToyRobot toyRobot;

			/// Place function test
			Assert::IsTrue(toyRobot.Place(0,0,"NORTH"));
			Assert::IsTrue(toyRobot.Place(1,1,"SOUTH"));
			Assert::IsTrue(toyRobot.Place(2,2,"EAST"));
			Assert::IsTrue(toyRobot.Place(3,3,"WEST"));
			Assert::IsTrue(toyRobot.Place(4,4,"NORTH"));
			
			Assert::IsFalse(toyRobot.Place(5, 5, "NORTH"));
			Assert::IsFalse(toyRobot.Place(-1, -1, "NORTH"));
			Assert::IsFalse(toyRobot.Place(0, -1, "NORTH"));
			Assert::IsFalse(toyRobot.Place(-1, 0, "NORTH"));

			std::string result = toyRobot.Report();
			Assert::AreEqual(std::string("Output: 4,4,NORTH"), result);			
		}

		TEST_METHOD(ToyRobot_Left_Report)
		{
			ToyRobot toyRobot;
						
			Assert::IsTrue(toyRobot.Place(0, 0, "NORTH"));

			/// LEFT & Report function test
			toyRobot.Left();
			std::string result = toyRobot.Report();
			Assert::AreEqual(std::string("Output: 0,0,WEST"), result);

			toyRobot.Left();
			result = toyRobot.Report();
			Assert::AreEqual(std::string("Output: 0,0,SOUTH"), result);

			toyRobot.Left();
			result = toyRobot.Report();
			Assert::AreEqual(std::string("Output: 0,0,EAST"), result);

			toyRobot.Left();
			result = toyRobot.Report();
			Assert::AreEqual(std::string("Output: 0,0,NORTH"), result);
		}

		TEST_METHOD(ToyRobot_Right_Report)
		{
			ToyRobot toyRobot;

			Assert::IsTrue(toyRobot.Place(0, 0, "NORTH"));
			std::string result = toyRobot.Report();
			Assert::AreEqual(std::string("Output: 0,0,NORTH"), result);

			/// Right & Report function test
			toyRobot.Right();
			result = toyRobot.Report();
			Assert::AreEqual(std::string("Output: 0,0,EAST"), result);

			toyRobot.Right();
			result = toyRobot.Report();
			Assert::AreEqual(std::string("Output: 0,0,SOUTH"), result);

			toyRobot.Right();
			result = toyRobot.Report();
			Assert::AreEqual(std::string("Output: 0,0,WEST"), result);

			toyRobot.Right();
			result = toyRobot.Report();
			Assert::AreEqual(std::string("Output: 0,0,NORTH"), result);
		}

		TEST_METHOD(ToyRobot_Move_Report)
		{
			ToyRobot toyRobot;

			Assert::IsTrue(toyRobot.Place(0, 0, "NORTH"));
			std::string result = toyRobot.Report();
			Assert::AreEqual(std::string("Output: 0,0,NORTH"), result);

			/// Move & Report function test
			toyRobot.Move();
			result = toyRobot.Report();
			Assert::AreEqual(std::string("Output: 0,1,NORTH"), result);

			toyRobot.Move();
			result = toyRobot.Report();
			Assert::AreEqual(std::string("Output: 0,2,NORTH"), result);

			toyRobot.Move();
			result = toyRobot.Report();
			Assert::AreEqual(std::string("Output: 0,3,NORTH"), result);

			toyRobot.Move();
			result = toyRobot.Report();
			Assert::AreEqual(std::string("Output: 0,4,NORTH"), result);

			toyRobot.Move();
			result = toyRobot.Report();
			Assert::AreEqual(std::string("Output: 0,4,NORTH"), result);

			toyRobot.Move();
			result = toyRobot.Report();
			Assert::AreEqual(std::string("Output: 0,4,NORTH"), result);

			//------------------------------------------------------------
			Assert::IsTrue(toyRobot.Place(1, 1, "EAST"));
			result = toyRobot.Report();
			Assert::AreEqual(std::string("Output: 1,1,EAST"), result);

			/// Move & Report function test
			toyRobot.Move();
			result = toyRobot.Report();
			Assert::AreEqual(std::string("Output: 2,1,EAST"), result);

			toyRobot.Move();
			result = toyRobot.Report();
			Assert::AreEqual(std::string("Output: 3,1,EAST"), result);

			toyRobot.Move();
			result = toyRobot.Report();
			Assert::AreEqual(std::string("Output: 4,1,EAST"), result);

			toyRobot.Move();
			result = toyRobot.Report();
			Assert::AreEqual(std::string("Output: 4,1,EAST"), result);

			toyRobot.Move();
			result = toyRobot.Report();
			Assert::AreEqual(std::string("Output: 4,1,EAST"), result);

			toyRobot.Move();
			result = toyRobot.Report();
			Assert::AreEqual(std::string("Output: 4,1,EAST"), result);

			//------------------------------------------------------------
			Assert::IsTrue(toyRobot.Place(4, 4, "SOUTH"));
			result = toyRobot.Report();
			Assert::AreEqual(std::string("Output: 4,4,SOUTH"), result);

			/// Move & Report function test
			toyRobot.Move();
			result = toyRobot.Report();
			Assert::AreEqual(std::string("Output: 4,3,SOUTH"), result);

			toyRobot.Move();
			result = toyRobot.Report();
			Assert::AreEqual(std::string("Output: 4,2,SOUTH"), result);

			toyRobot.Move();
			result = toyRobot.Report();
			Assert::AreEqual(std::string("Output: 4,1,SOUTH"), result);

			toyRobot.Move();
			result = toyRobot.Report();
			Assert::AreEqual(std::string("Output: 4,0,SOUTH"), result);

			toyRobot.Move();
			result = toyRobot.Report();
			Assert::AreEqual(std::string("Output: 4,0,SOUTH"), result);

			toyRobot.Move();
			result = toyRobot.Report();
			Assert::AreEqual(std::string("Output: 4,0,SOUTH"), result);

			//------------------------------------------------------------
			Assert::IsTrue(toyRobot.Place(4, 2, "WEST"));
			result = toyRobot.Report();
			Assert::AreEqual(std::string("Output: 4,2,WEST"), result);

			/// Move & Report function test
			toyRobot.Move();
			result = toyRobot.Report();
			Assert::AreEqual(std::string("Output: 3,2,WEST"), result);

			toyRobot.Move();
			result = toyRobot.Report();
			Assert::AreEqual(std::string("Output: 2,2,WEST"), result);

			toyRobot.Move();
			result = toyRobot.Report();
			Assert::AreEqual(std::string("Output: 1,2,WEST"), result);

			toyRobot.Move();
			result = toyRobot.Report();
			Assert::AreEqual(std::string("Output: 0,2,WEST"), result);

			toyRobot.Move();
			result = toyRobot.Report();
			Assert::AreEqual(std::string("Output: 0,2,WEST"), result);

			toyRobot.Move();
			result = toyRobot.Report();
			Assert::AreEqual(std::string("Output: 0,2,WEST"), result);
		}

		TEST_METHOD(Table_IsPosSafe)
		{
			Table table(5,5);
			
			Assert::IsTrue(table.isPosSafe(0,0));
			Assert::IsTrue(table.isPosSafe(0,1));
			Assert::IsTrue(table.isPosSafe(0,2));
			Assert::IsTrue(table.isPosSafe(0,3));
			Assert::IsTrue(table.isPosSafe(0,4));
			Assert::IsFalse(table.isPosSafe(0,5));

			Assert::IsTrue(table.isPosSafe(1, 0));
			Assert::IsTrue(table.isPosSafe(1, 1));
			Assert::IsTrue(table.isPosSafe(1, 2));
			Assert::IsTrue(table.isPosSafe(1, 3));
			Assert::IsTrue(table.isPosSafe(1, 4));
			Assert::IsFalse(table.isPosSafe(1,5));

			Assert::IsTrue(table.isPosSafe(2, 0));
			Assert::IsTrue(table.isPosSafe(2, 1));
			Assert::IsTrue(table.isPosSafe(2, 2));
			Assert::IsTrue(table.isPosSafe(2, 3));
			Assert::IsTrue(table.isPosSafe(2, 4));
			Assert::IsFalse(table.isPosSafe(2, 5));

			Assert::IsTrue(table.isPosSafe(3, 0));
			Assert::IsTrue(table.isPosSafe(3, 1));
			Assert::IsTrue(table.isPosSafe(3, 2));
			Assert::IsTrue(table.isPosSafe(3, 3));
			Assert::IsTrue(table.isPosSafe(3, 4));
			Assert::IsFalse(table.isPosSafe(3,5));

			Assert::IsTrue(table.isPosSafe(4, 0));
			Assert::IsTrue(table.isPosSafe(4, 1));
			Assert::IsTrue(table.isPosSafe(4, 2));
			Assert::IsTrue(table.isPosSafe(4, 3));
			Assert::IsTrue(table.isPosSafe(4, 4));
			Assert::IsFalse(table.isPosSafe(4, 5));

			Assert::IsFalse(table.isPosSafe(5, 0));
			Assert::IsFalse(table.isPosSafe(5, 1));
			Assert::IsFalse(table.isPosSafe(5, 2));
			Assert::IsFalse(table.isPosSafe(5, 3));
			Assert::IsFalse(table.isPosSafe(5, 4));
			Assert::IsFalse(table.isPosSafe(5, 5));


			Assert::IsFalse(table.isPosSafe(-1, 0));
			Assert::IsFalse(table.isPosSafe(-1, 1));
			Assert::IsFalse(table.isPosSafe(-1, 2));
			Assert::IsFalse(table.isPosSafe(-1, 3));
			Assert::IsFalse(table.isPosSafe(-1, 4));

			Assert::IsFalse(table.isPosSafe(0,-1));
			Assert::IsFalse(table.isPosSafe(1, -1));
			Assert::IsFalse(table.isPosSafe(2, -1));
			Assert::IsFalse(table.isPosSafe(3, -1));
			Assert::IsFalse(table.isPosSafe(4, -1));

		}

		TEST_METHOD(Direction_SetDirection_GetDirection_GetDirectionString)
		{
			Direction direction;

			/// SetDirection(Facing direction)
			direction.SetDirection(Direction::North);
			Assert::IsTrue(Direction::North == direction.GetDirection());
			Assert::AreEqual(std::string("NORTH"), direction.GetDirectionString());

			direction.SetDirection(Direction::South);
			Assert::IsTrue(Direction::South == direction.GetDirection());
			Assert::AreEqual(std::string("SOUTH"), direction.GetDirectionString());

			direction.SetDirection(Direction::East);
			Assert::IsTrue(Direction::East == direction.GetDirection());
			Assert::AreEqual(std::string("EAST"), direction.GetDirectionString());

			direction.SetDirection(Direction::West);
			Assert::IsTrue(Direction::West == direction.GetDirection());
			Assert::AreEqual(std::string("WEST"), direction.GetDirectionString());

			//---------------------------------------------------------
			/// SetDirection(std::string direction)
			direction.SetDirection(std::string("NORTH"));
			Assert::IsTrue(Direction::North == direction.GetDirection());
			Assert::AreEqual(std::string("NORTH"), direction.GetDirectionString());

			direction.SetDirection(std::string("SOUTH"));
			Assert::IsTrue(Direction::South == direction.GetDirection());
			Assert::AreEqual(std::string("SOUTH"), direction.GetDirectionString());

			direction.SetDirection(std::string("EAST"));
			Assert::IsTrue(Direction::East == direction.GetDirection());
			Assert::AreEqual(std::string("EAST"), direction.GetDirectionString());

			direction.SetDirection(std::string("WEST"));
			Assert::IsTrue(Direction::West == direction.GetDirection());
			Assert::AreEqual(std::string("WEST"), direction.GetDirectionString());
		}

		TEST_METHOD(Direction_IncreaseIndex_DecreaseIndex)
		{
			Direction direction;

			/// NOTE : 
			/// Index corresponds to enum Facing's value
			/// enum Facing { North =0, East, South, West };

			/// SetDirection(Facing direction)
			direction.SetDirection(Direction::North);

			direction.IncreaseIndex();
			Assert::IsTrue(Direction::East == direction.GetDirection());
			Assert::AreEqual(std::string("EAST"), direction.GetDirectionString());

			direction.IncreaseIndex();
			Assert::IsTrue(Direction::South == direction.GetDirection());
			Assert::AreEqual(std::string("SOUTH"), direction.GetDirectionString());

			direction.IncreaseIndex();
			Assert::IsTrue(Direction::West == direction.GetDirection());
			Assert::AreEqual(std::string("WEST"), direction.GetDirectionString());

			direction.IncreaseIndex();
			Assert::IsTrue(Direction::North == direction.GetDirection());
			Assert::AreEqual(std::string("NORTH"), direction.GetDirectionString());

			//--------------------------------------------
			direction.DecreaseIndex();
			Assert::IsTrue(Direction::West == direction.GetDirection());
			Assert::AreEqual(std::string("WEST"), direction.GetDirectionString());

			direction.DecreaseIndex();
			Assert::IsTrue(Direction::South == direction.GetDirection());
			Assert::AreEqual(std::string("SOUTH"), direction.GetDirectionString());

			direction.DecreaseIndex();
			Assert::IsTrue(Direction::East == direction.GetDirection());
			Assert::AreEqual(std::string("EAST"), direction.GetDirectionString());

			direction.DecreaseIndex();
			Assert::IsTrue(Direction::North == direction.GetDirection());
			Assert::AreEqual(std::string("NORTH"), direction.GetDirectionString());
		}
	};
}
