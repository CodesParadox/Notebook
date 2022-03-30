#pragma once
#include <iostream>
#include "Direction.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <limits>
using namespace std;

#define ROW_MAX 100
const uint INF = std::numeric_limits<uint>::max();

// Defult values in map of char
struct noChar
{
	char ch = '_'; // defult char
};

namespace ariel
{
	class Notebook
	{
		/*  a map of maps of chars. contains the posted chars.
		Min_Col, Max_Col, Min_Raw, Max_Raw -> marking the borders of the whole notebook to keeping it small */
	private:
		map<unsigned int, map<unsigned int, noChar>> notebook;
		unsigned int Min_Col, Max_Col, Min_Raw, Max_Raw;

	public:
		Notebook() // Creating new empty notebook -> constructor
		{
			Max_Col = 100;
			Min_Col = Min_Raw = 0;   //Max col and row -> set initially to 0
			Max_Raw = INF; // Max col and row -> set initially to max value of uint.
		}
		~Notebook() {} // destructor -> create notebook as it come out of context
		void write(int page, u_int row, u_int column, Direction direction, string msg);

		string read(int page, u_int row, u_int column, Direction direction, u_int length);

		void show(int page);
		void erase(int page, u_int row, u_int col, Direction direction, int len);
	};
}