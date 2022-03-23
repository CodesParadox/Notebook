
#include "Notebook.hpp"
#include "Direction.hpp"
#include <iostream>
#include <stdexcept>
#include <unordered_map>
#include <algorithm>

using ariel::Direction;
using namespace std;

namespace ariel {
    Notebook::Notebook(){} 

    void Notebook::write (int page,int row,int colum,Direction direction,string st){}

    string Notebook::read ( int page,int row, int colum,Direction direction, int len) {
        return "k";
    }
    void Notebook::erase (int page,int row, int colum,Direction direction,int len) {}

    void Notebook::show (int page){}


};