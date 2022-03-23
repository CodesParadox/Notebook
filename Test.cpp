#include <unordered_map>
#include <algorithm>
#include <string>
#include "Notebook.hpp"
#include <iostream>
#include "doctest.h"
#include <stdexcept>
#include "Direction.hpp"

#define ROW_MAX 100

using namespace ariel;

TEST_CASE("good inputs"){
    Notebook note;
    note.write(0,0,0,Direction::Horizontal,"galbraymok");
    note.write(0,1,0,Direction::Vertical,"heyhey");
    CHECK(note.read(0,5,0,Direction::Vertical,5)=="braym");
    CHECK(note.read(0,0,5,Direction::Horizontal,5)=="braym");
    note.erase(0,0,2,Direction::Horizontal,3);
    CHECK(note.read(0,0,0,Direction::Horizontal,10)=="ga~~~aymok");
    note.erase(0,5,0,Direction::Vertical,5);
    CHECK(note.read(0,0,0,Direction::Vertical,10)=="galbr~~~~~");
    note.write(0,0,0,Direction::Horizontal,"hey");
    note.write(0,0,4,Direction::Horizontal,"everyone");
    CHECK(note.read(0,0,0,Direction::Horizontal,12)=="hey_everyone");

}


TEST_CASE("bad inputs"){
    Notebook note;
    CHECK_THROWS(note.write(-1,0,0,Direction::Horizontal,"error 404 - cant use something that doesnt exist"));
    CHECK_THROWS(note.write(-1,0,0,Direction::Vertical,"error 404 - cant use something that doesnt exist"));
    CHECK_THROWS(note.read(-1,0,0,Direction::Horizontal,6));
    CHECK_THROWS(note.write(10,0,-3,Direction::Horizontal,"error 404 - cant use something that doesnt exist"));
    CHECK_THROWS(note.write(20,0,-20,Direction::Vertical,"error 404 - cant use something that doesnt exist"));
    CHECK_THROWS(note.write(1,-1,0,Direction::Vertical,"error 404 - cant use something that doesnt exist"));
    CHECK_THROWS(note.erase(2,4,-2,Direction::Horizontal,0));
    CHECK_THROWS(note.write(0,-7,1000,Direction::Horizontal,"error 404 - cant use something that doesnt exist"));
    CHECK_THROWS(note.read(-1,0,0,Direction::Vertical,3));
    CHECK_THROWS(note.read(1,-5,0,Direction::Horizontal,10));
    CHECK_THROWS(note.erase(-1,0,0,Direction::Vertical,10));
    CHECK_THROWS(note.write(1,-3,-9,Direction::Horizontal,"error 404 - cant use something that doesnt exist"));
    CHECK_THROWS(note.erase(1,0,-9,Direction::Vertical,7));
    note.write(0,0,0,Direction::Horizontal,"hello");
    CHECK_THROWS(note.write(0,0,0,Direction::Vertical,"olleh"));
    CHECK_THROWS(note.read(-1,100,0,Direction::Vertical,2));
    CHECK_THROWS(note.read(2,4,-3,Direction::Horizontal,2));
    CHECK_THROWS(note.read(12,6,-3,Direction::Vertical,20));

    

}