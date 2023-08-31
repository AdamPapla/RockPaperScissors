#include <iostream>
#include <string>
#include <map>
#include <random>
using namespace std;

string genRanChoice(void){
    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> distribution(0, 2);
    string options[3] = {"rock", "paper", "scissors"};
    int ranChoice = distribution(rng);
    return options[ranChoice];
}

string whoWins(string player1, string player2){ // Results are from player 1s perspective
    map<string, string> rps {{"rock", "paper"}, {"scissors", "rock"}, {"paper", "scissors"}};
    string result;
    if (player2 == player1) result="draw";
    else result = (player2 == rps[player1]) ? "lose" : "win";
    return result;
}

string rockPaperScissors(){
    string userChoice;
    cout << "Rock, paper or scissors?:" << endl;
    cin >> userChoice;
    string machineChoice = genRanChoice();
    string result = whoWins(userChoice, machineChoice);
    cout << "You chose " << userChoice << ", computer chose " << machineChoice << "\nYou " << result << endl << endl;
    if (result == "draw") result = rockPaperScissors();
    return result;
}
int main(void){
    string userChoice;
    cout << "ROCK PAPER SCISSORS" << endl;
    cout << "Choose mode (draws do not count!):\n1. Best of 1\n2. Best of 3\n3. Best of 5" << endl;
    int gameMode;
    cin >> gameMode;

    if (std::cin.fail()) {
        cout << "Invalid input. Please enter an integer." << std::endl;
        cin.clear(); // Clear the error state
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the buffer
    } 
    else if (gameMode > 3 || gameMode < 0){
        cout << "Invalid game mode entered. Please enter 1, 2 or 3" << endl;
    }
    map<int, int> winCount {{1, 1}, {2, 3}, {3, 5}};
    int userWins = 0;
    int machineWins = 0;
    while (userWins < winCount[gameMode] && machineWins < winCount[gameMode]){
        string result = rockPaperScissors();
        if (result == "win") userWins++;
        else if (result == "lose") machineWins++;
        cout << "\nScore: You: " << userWins << ", Computer: " << machineWins << endl << endl;
    }
    string finalResult = (userWins > machineWins) ? "You win!" : "You lose :(";
    cout << "_______________\n\n" << finalResult << endl << endl;

    return 0;
}