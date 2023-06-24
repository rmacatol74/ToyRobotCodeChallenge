#pragma once

#define MIN_POSITION 0
#define DEFAULT_POSITION -1

class Table
{
public:
	Table(int length, int width);
	~Table();

	bool isPosSafe(int x, int y);

private:
	int _length;
	int _width;
};

