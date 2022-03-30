#include <iostream>
#include "Notebook.hpp"
#include <map>
#include <algorithm>
#include <stdexcept>
#include <sstream>
#include "Direction.hpp"
#include <string>
using namespace std;

namespace ariel
{
	/* Posting a string type method on the notebook, by given coordinates, direction and the string of the write */

	void Notebook::write(int page, u_int row, u_int col, Direction direction, std::string msg)
	{

		if(page < 0 || row < 0 || col < 0 ){
        	throw invalid_argument("Error - Invalid Inputs");
		}

			if(page < 0 || row < 0 || col < 0 || col > 99 || msg.length() < 0 ){
        	throw invalid_argument("Error - Invalid Inputs");
		}

		if(col >=100){
			throw invalid_argument("Error - stackoverflow");
		}

		if (direction == Direction::Horizontal && (col + msg.length()) > 100){
			throw invalid_argument("Error - stackoverflow for horizontal length");
		}
		

		/* gvulot from what i have to what i get */
		this->Max_Raw = max(this->Max_Raw, row);
		this->Max_Col = max(this->Max_Col, col);
		this->Min_Raw = min(this->Min_Raw, row);
		this->Min_Col = min(this->Min_Col, col);

		// for( int i=0; i< msg.length(); i++){
		// 	this->notebook[row][col].ch = msg.at(i);
		// 	if (direction == Direction::Vertical)
		// 	{
		// 		row++;
		// 	}
		// 	else
		// 	{
		// 		col++;
		// 	}
		// }
		
		//Check if the char '~' is in the string
		if(msg == "~"){
					throw invalid_argument("ERROR 404 -Cant use this '~' Input ");}
		if (msg.length() >= 1) // check if the string is empty
		{

			for (char chr : msg) // posting -> check each char
			{
				
				//marking the direction using a boolean for easy redirection
				if (direction == Direction::Vertical) // if its vertical move row otherwise col
				{
					this->notebook[row][col].ch = chr;
					row++;
					
				}
				else{
					this->notebook[row][col].ch = chr;
					col++;}
			}
		}
	}

	/* Reading from the notebook by coordinates, direction and length */
	string Notebook::read(int page ,unsigned int row, unsigned int col, Direction direction, unsigned int length)
	{
		//Check if the input in valid
		if(page < 0 || row < 0 || col < 0 || col > 99 || length < 0 ){
        	throw invalid_argument("Error - Invalid Inputs");
		}

		if(col >=100){
			throw invalid_argument("Error - stackoverflow");
		}

		if (direction == Direction::Horizontal && (col + length) > 100){
			throw invalid_argument("Error - stackoverflow for horizontal length");
		}

		//if(notebook.count(page) != 0)

		string str;
		if (length == 0)
		{return str;}
		else{
			for (unsigned int i = 0; i < length; i++) // move on the input length
			{
				str = str + this->notebook[row][col].ch; // hashmap in hashmap
				if (direction == Direction::Vertical)
				{row++;
				}	else{col++;}
			}
			return str;
		}
	}

	/**
     * Converts the map notebook to an output on screen including row numbers on the left side of the notebook itself.
     * Print the notebook while empty cell is "_"
     * */
	void Notebook::show(int page)
	{
		if(page <0){
			throw invalid_argument("Invalid negative page");
		}

		for (unsigned int i = this->Min_Raw; i <= this->Max_Raw; i++) // move from the min char to the max
		{
			for (unsigned int j = this->Min_Col; j <= this->Max_Col; j++)
			{
				cout << this->notebook[i][j].ch << " "; // put space after finish
			}
			cout << "\n\n";
		}
	}

	void Notebook::erase(int page, u_int row, u_int col, Direction direction, int len){
	
			//Check if the input in valid
		if(page < 0 || row < 0 || col < 0 || col > 99 || len < 0 ){
        	throw invalid_argument("Error - Invalid Inputs");
		}

		if(col >=100){
			throw invalid_argument("Error - stackoverflow");
		}

		if (direction == Direction::Horizontal && (col + len) > 100){
			throw invalid_argument("Error - stackoverflow for horizontal length");
		}

		this->Max_Raw = max(this->Max_Raw, row);
		this->Max_Col = max(this->Max_Col, col);
		this->Min_Raw = min(this->Min_Raw, row);
		this->Min_Col = min(this->Min_Col, col);

		string msg = "~";

			for (char chr : msg) // posting -> check each char
			{
				this->notebook[row][col].ch = chr;
				//marking the direction using a boolean for easy redirection
				if (direction == Direction::Vertical) // if its vertical move row otherwise col
				{
					row++;
				}
				else
				{
					col++;
				}
			}
			
	}

}


// void showMenu(){
// 	cout << "***********Menu**********" <<endl;
// 	cout << "1. read write" << endl;
// 	cout << "2. Post" << endl;
// 	cout << "3. Show Post" << endl;
// 	cout << "*************************" << endl;
// }
// int main(){
//	do{
// 	int choice;
// 	int row, col;
// 	string str="";
// 	showMenu();
// 	cout <<"Pick your choice: ";
// 	cin >> choice;
//	}
// 	switch(choice){
// 		case 1:
// 		string Notebook::read();
// 		break;
// 		case 2: cout<< "Posting: ";
// 		cin>> row;
// 		cin >> col;
// 		cin>> str;
// 		break;
// 		case 3:
// 		show();
// 		break;
//		case 0:
//			break;
//

// 	}while(choice !=0){
//};
// 	system("pause>0");

// }