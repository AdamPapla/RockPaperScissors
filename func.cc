// Adam Graham
// 31/08/2023
// Function file of rock paper scissors game
#include <iostream>
#include <string>
#include <map>
#include <random>
using namespace std;

// Generate a random choice for the computer out of rock, paper and scissors
string genRanChoice(void){
    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> distribution(0, 2);  // Set up random distribution
    string options[3] = {"rock", "paper", "scissors"};
    int ranChoice = distribution(rng);
    return options[ranChoice];  // Return random choice
}

// Given the user and machine choices, calculate who wins the round
string whoWins(string player1, string player2){ // Results are from player 1s perspective
    map<string, string> rps {{"rock", "paper"}, {"scissors", "rock"}, {"paper", "scissors"}};   // Map of choice to choice that defeats it
    string result;
    if (player2 == player1) result="draw";  // If both are the same - draw
    else result = (player2 == rps[player1]) ? "lose" : "win";   // If opposition's choice is the choice that defeats player1s, player1 loses
    return result;
}

// Run the rock paper scissors game until one player wins the round
string rockPaperScissors(){
    string userChoice;
    cout << "Rock, paper or scissors?:" << endl;
    cin >> userChoice;  // Read user input
    for (char &c : userChoice)  // Convert to lower case
        c = tolower(c);
    // Error handling
    if (userChoice != "rock" && userChoice != "scissors" && userChoice != "paper"){
        cout << "\nInvalid choice entered. Please enter rock, paper or scissors\n" << endl;
        return "err";
    }
    string machineChoice = genRanChoice();
    string result = whoWins(userChoice, machineChoice);
    cout << "You chose " << userChoice << ", computer chose " << machineChoice << "\nYou " << result << endl << endl;
    if (result == "draw") 
        result = rockPaperScissors();   	// If a draw, run again until win/loss is obtained
    return result;
}