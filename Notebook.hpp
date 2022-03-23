
#include "Direction.hpp"
#include <algorithm>
#include <map>
#include <string>
#include <iostream>
#include <unordered_map>
#include <stdexcept> 

using namespace std;
#define ROW_MAX 100
namespace ariel{
    class Notebook{
    private:
        unordered_map<int,int> _notebook;
    public:
        Notebook();
        void write(int page,int row,int column,Direction direc,string str);
        string read(int page,int row,int column,Direction direc,int length);
        void erase(int page,int row,int column,Direction direc,int length);
        void show(int page);

    };

}