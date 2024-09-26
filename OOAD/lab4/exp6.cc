#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int generateRandomNumber() {
    return rand() % 9 + 1;
}

bool generateQuestion() {
    int num1 = generateRandomNumber();
    int num2 = generateRandomNumber();

    int correctAnswer = num1 + num2;

    cout << "How much is " << num1 << " plus " << num2 << "? ";
    
    int userAnswer;
    cin >> userAnswer;

    if (userAnswer == correctAnswer) {
        switch (rand() % 4 + 1) {
            case 1:
                cout << "Great job!" << endl;
                break;
            case 2:
                cout << "Fantastic!" << endl;
                break;
            case 3:
                cout << "Awesome!" << endl;
                break;
            case 4:
                cout << "You're a math whiz!" << endl;
                break;
        }
        return true;
    } else {
        switch (rand() % 4 + 1) {
            case 1:
                cout << "Oops. Try again." << endl;
                break;
            case 2:
                cout << "Not quite right. Give it another shot." << endl;
                break;
            case 3:
                cout << "Don't worry, you'll get it next time." << endl;
                break;
            case 4:
                cout << "Incorrect. Keep trying." << endl;
                break;
        }
        return false;
    }
}

int main() {
    srand(time(0));

    cout << "Welcome to the Math Quiz Game!" << endl;

    generateQuestion();

    char playAgain;
    do {
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
        if (playAgain == 'y' || playAgain == 'Y') {
            generateQuestion();
        }
    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing! Goodbye." << endl;

    return 0;
}
