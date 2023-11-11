#include "function.h"
#include <Windows.h>
int main() {
    SetConsoleOutputCP(1251);
    vector<string> words = loadWordsFromFile("words.txt");

    if (words.empty()) {
        cout << "Файл не содержит слов. Пожалуйста, добавьте английские слова в файл 'words.txt'." << endl;
        return 1;
    }

    string guessedWord = getRandomWord(words);
    string displayedWord(guessedWord.length(), '_');
    string guessedLetters;
    int attempts = 6;

    cout << "Добро пожаловать в игру 'Виселица'!" << endl;

    while (attempts > 0) {
        cout << "Угаданное слово: " << displayedWord << endl;
        cout << "Угаданные буквы: " << guessedLetters << endl;
        cout << "Осталось попыток: " << attempts << endl;

        string guess;
        cout << "Введите букву или попробуйте угадать слово целиком: ";
        cin >> guess;

        if (guess.length() == 1) {
            char letter = tolower(guess[0]);

            if (!isalpha(letter)) {
                cout << "Пожалуйста, введите только букву." << endl;
                continue;
            }

            if (isAlreadyGuessed(letter, guessedLetters)) {
                cout << "Вы уже угадывали эту букву." << endl;
                continue;
            }

            if (isLetterGuessed(letter, guessedWord, displayedWord)) {
                if (isGameOver(displayedWord)) {
                    cout << "Поздравляем! Вы угадали слово: " << guessedWord << endl;
                    break;
                }
            }
            else {
                attempts--;
            }

            guessedLetters += letter;
        }
        else if (guess.length() == guessedWord.length() && guess == guessedWord) {
            cout << "Поздравляем! Вы угадали слово: " << guessedWord << endl;
            break;
        }
        else {
            cout << "Неверное слово." << endl;
            attempts--;
        }
    }

    if (attempts == 0) {
        cout << "У вас закончились попытки. Загаданное слово было: " << guessedWord << endl;
    }

    return 0;
}