#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

vector<string> loadWordsFromFile(string filename) {
    vector<string> words;
    ifstream file(filename);

    if (file.is_open()) {
        string word;
        while (getline(file, word)) {
            words.push_back(word);
        }
        file.close();
    }

    return words;
}

string getRandomWord(const vector<string>& words) {
    srand(time(0));
    return words[rand() % words.size()];
}

bool isLetterGuessed(char letter, const string& guessedWord, string& displayedWord) {
    bool found = false;
    for (int i = 0; i < guessedWord.length(); i++) {
        if (guessedWord[i] == letter) {
            displayedWord[i] = letter;
            found = true;
        }
    }
    return found;
}

bool isGameOver(const string& displayedWord) {
    return displayedWord.find('_') == string::npos;
}

bool isAlreadyGuessed(char letter, const string& guessedLetters) {
    return guessedLetters.find(letter) != string::npos;
}