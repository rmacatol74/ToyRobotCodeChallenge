# Toy Robot Code Challenge 
### Description: 
The application is a simulation of a toy robot moving on a square table top, of dimensions 5 units x 5 units. There are no other obstructions on the table surface. The robot is free to roam around the surface of the table, but must be prevented from falling to destruction. Any movement that would result in the robot falling from the table must be prevented, however further valid movement commands must still be allowed. 

### Requirements:
Create a **console application** that can read in commands of the following form

```
    PLACE X,Y,F 
    MOVE 
    LEFT 
    RIGHT 
    REPORT
```

**PLACE** will put the toy robot on the table in position X,Y and facing NORTH, SOUTH, EAST or WEST. The origin (0,0) can be considered to be the SOUTH WEST most corner. It is required that the first command to the robot is a PLACE command, after that, any sequence of commands may be issued, in any order, including another PLACE command. The application should discard all commands in the sequence until a valid PLACE command has been executed. 

**MOVE** will move the toy robot one unit forward in the direction it is currently facing. 

**LEFT** and **RIGHT** will rotate the robot 90 degrees in the specified direction without changing the position of the robot. REPORT will announce the X,Y and F of the robot. This can be in any form, but standard output is sufficient. A robot that is not on the table can choose to ignore the MOVE, LEFT, RIGHT and REPORT commands. Input can be from a file, or from standard input, as the developer chooses. 

### Constraints: 
The toy robot must not fall off the table during movement. This also includes the initial placement of the toy robot. Any move that would cause the robot to fall must be ignored.
Example Input and Output: 

```
    PLACE 0,0,NORTH 
    MOVE 
    REPORT 
    Output: 0,1,NORTH 

    PLACE 0,0,NORTH 
    LEFT 
    REPORT 
    Output: 0,0,WEST 

    PLACE 1,2,EAST 
    MOVE 
    MOVE 
    LEFT 
    MOVE 
    REPORT 
    Output: 3,3,NORTH
```

## About the project

**ToyRobotAppMFC** project is a Console Windows application with Precomplied header and MFC header option enabled during creation. This project is created using Visual Studio 2022. 

### Prerequisites
Must have Visual Studio with the **Desktop development with C++ workload** installed and running on your computer. If it's not installed yet, follow the steps in Install C++ support in Visual Studio. **https://learn.microsoft.com/en-us/cpp/build/vscpp-step-0-installation?view=msvc-170**

### Repo:

```

git clone https://github.com/rmacatol74/ToyRobotCodeChallenge.git

```

### Building the solution
1. Open the solution or the project file using Visual Studio : 

```
\ToyRobotAppMFC\ToyRobotAppMFC.sln

or

\ToyRobotAppMFC\ToyRobotAppMFC\ToyRobotAppMFC.vcxproj

```

2. To build the  project, choose **Build Solution** from the **Build** menu
3. To run the code, on the menu bar, choose **Debug, Start without debugging**.

### Running the Unit Test

1. Open **Test Explorer**. To open the Test Explorer, choose **Test > Test Explorer** from the top menu bar (or **press Ctrl + E, T**).

2. Run the unit tests by clicking **Run All** (or **press Ctrl + R, V**).
