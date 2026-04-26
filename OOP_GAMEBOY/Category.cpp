#include "Category.h"
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;
Category::Category() {}
void Category::loadCategory() {
    srand(time(0));
    string files[] = { "Sprites/movies.txt", "Sprites/food.txt", "Sprites/fruit.txt", "Sprites/countries.txt" };
    int fileNumber = rand() % 4;           //decides which file to open
    ifstream file(files[fileNumber]); //to oprn file
    if (file) {
        string line;
        int wordIndex = rand() % 10;       //decides which word to take from file
        for (int i = 0; getline(file, line); i++) {
            if (i == wordIndex) {
                word = line;
                break;
            }
        }
        file.close();
        hint = "";
        int a = 0;
        int b = 0;
        for (int i = 0; i < files[fileNumber].size(); i++) {  //
            if (files[fileNumber][i] == '/') {
                a = i + 1;
            }
            if (files[fileNumber][i] == '.') {
                b = i;
                break;
            }
        }
        for (int i = a; i < b; i++) {    //To store hint
            hint += files[fileNumber][i];
        }
    }
}
string Category::getHint() {
    return hint;
}
string Category::getWord() {
    return word;
}
