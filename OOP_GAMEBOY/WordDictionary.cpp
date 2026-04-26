#include "WordDictionary.h"


void Dictionary::getRandomWord(char* targetWord){
    srand(time(0)); // Seed the random number generator
    int randomIndex = rand() % maxWords;
    for (int i = 0; i < wordLen + 1; ++i) {
        targetWord[i] = words[randomIndex][i];
    }
}