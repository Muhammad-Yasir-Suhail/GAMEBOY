#ifndef WORD_H
#define WORD_H
class Word {
private:
   // static const int wordLen = 5;
    char word[6];
public:
    Word() {
        for (int i = 0; i < 6; ++i) {
            word[i] = '\0'; // Initialize word as empty
        }
    }
    void setWord(const char* newWord);
    char* getWord();
    void addLetter(char letter);
    void reset();
    bool isComplete();
};

#endif