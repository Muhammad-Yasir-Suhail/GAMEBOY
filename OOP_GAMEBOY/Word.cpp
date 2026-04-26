#include "Word.h"
void Word::setWord(const char* newWord) {
    for (int i = 0; i < 5; ++i) {
        word[i] = newWord[i];
    }
    word[5] = '\0'; // Null-terminate
}
char* Word::getWord() {
    return word;
}
void Word::addLetter(char letter) {
    for (int i = 0; i < 5; ++i) {
        if (word[i] == '\0') {
            word[i] = letter;
            word[i + 1] = '\0'; // Null-terminate
            break;
        }
    }
}
void Word::reset() {
    for (int i = 0; i < 6; ++i) {
        word[i] = '\0'; // Reset word
    }
}
bool Word::isComplete(){
    for (int i = 0; i < 5; ++i) {
        if (word[i] == '\0') {
            return false;
        }
    }
    return true;
}