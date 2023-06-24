#include "pch.h"
#include "Table.h"

Table::Table(int length, int width)
{
	_length = length;
	_width = width;
}

Table::~Table()
{
}

bool Table::isPosSafe(int x, int y)
{
	return (x >= MIN_POSITION && y >= MIN_POSITION && x < _width && y < _length);
}