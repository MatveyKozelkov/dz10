#include "function.h"
#include <Windows.h>
int main() {
    SetConsoleOutputCP(1251);
    vector<string> words = loadWordsFromFile("words.txt");

    if (words.empty()) {
        cout << "���� �� �������� ����. ����������, �������� ���������� ����� � ���� 'words.txt'." << endl;
        return 1;
    }

    string guessedWord = getRandomWord(words);
    string displayedWord(guessedWord.length(), '_');
    string guessedLetters;
    int attempts = 6;

    cout << "����� ���������� � ���� '��������'!" << endl;

    while (attempts > 0) {
        cout << "��������� �����: " << displayedWord << endl;
        cout << "��������� �����: " << guessedLetters << endl;
        cout << "�������� �������: " << attempts << endl;

        string guess;
        cout << "������� ����� ��� ���������� ������� ����� �������: ";
        cin >> guess;

        if (guess.length() == 1) {
            char letter = tolower(guess[0]);

            if (!isalpha(letter)) {
                cout << "����������, ������� ������ �����." << endl;
                continue;
            }

            if (isAlreadyGuessed(letter, guessedLetters)) {
                cout << "�� ��� ��������� ��� �����." << endl;
                continue;
            }

            if (isLetterGuessed(letter, guessedWord, displayedWord)) {
                if (isGameOver(displayedWord)) {
                    cout << "�����������! �� ������� �����: " << guessedWord << endl;
                    break;
                }
            }
            else {
                attempts--;
            }

            guessedLetters += letter;
        }
        else if (guess.length() == guessedWord.length() && guess == guessedWord) {
            cout << "�����������! �� ������� �����: " << guessedWord << endl;
            break;
        }
        else {
            cout << "�������� �����." << endl;
            attempts--;
        }
    }

    if (attempts == 0) {
        cout << "� ��� ����������� �������. ���������� ����� ����: " << guessedWord << endl;
    }

    return 0;
}