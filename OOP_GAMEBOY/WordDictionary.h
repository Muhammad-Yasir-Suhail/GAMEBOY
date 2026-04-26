#pragma once

#ifndef WORDDICTIONARY_H
#define WORDDICTIONARY_H

#include<ctime>
#include<cstdlib>

class Dictionary {
private:
    static const int maxWords = 9; 
    static const int wordLen = 5;
    char words[maxWords][wordLen + 1]; 

public:
    Dictionary() {
       
        const char predefinedWords[maxWords][wordLen + 1] = {
            "apple", "grape", "peach", "mango", "berry",
            "lemon", "melon", "plums", "guava"
        };

        for (int i = 0; i < maxWords; ++i) {
            for (int j = 0; j < wordLen + 1; ++j) {
                words[i][j] = predefinedWords[i][j];
            }
        }
    }

    void getRandomWord(char* targetWord);
};
#endif