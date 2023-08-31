// Adam Graham
// 31/08/2023
// Main file of rock paper scissors game

#include <iostream>
#include <string>
#include <map>
#include <random>
#include "func.h"
using namespace std;



int main(void){
    string userChoice;
    cout << "ROCK PAPER SCISSORS" << endl;

    // Setting up game mode
    cout << "Choose mode (draws do not count!):\n1. Best of 1\n2. Best of 3\n3. Best of 5" << endl;
    int gameMode;
    cin >> gameMode;
    // Error checking user input for game mode
    if (std::cin.fail()) {
        cout << "Invalid input. Please enter an integer." << std::endl;
        cin.clear(); // Clear the error state
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the buffer
    } 
    else if (gameMode > 3 || gameMode < 0){
        cout << "Invalid game mode entered. Please enter 1, 2 or 3" << endl;
    }

    map<int, int> winCount {{1, 1}, {2, 2}, {3, 3}};    // Map game mode to required wins
    int userWins = 0;
    int machineWins = 0;
    while (userWins < winCount[gameMode] && machineWins < winCount[gameMode]){  // Continue until a player satisfies win count
        string result = rockPaperScissors();
        if (result == "err"){   // If user entered incorrect input, skip iteration 
            continue;
        }
        if (result == "win") userWins++;    // Update win record
        else if (result == "lose") machineWins++;
        cout << "\nScore: You: " << userWins << ", Computer: " << machineWins << endl << endl;
    }
    string finalResult = (userWins > machineWins) ? "You win!" : "You lose :(";
    cout << "_______________\n\n" << finalResult << endl << endl;

    return 0;
}