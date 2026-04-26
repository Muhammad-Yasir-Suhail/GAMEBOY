#ifndef CATEGORY_H
#define CATEGORY_H
#include <iostream>
using namespace std;
#include <string>
class Category {
    string word;
    string hint;
public:
    Category();
    void loadCategory();
    string getHint();
    string getWord();
};

#endif
