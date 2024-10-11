#include <iostream>
#include <cstdlib>  // for rand() and srand()
#include <ctime>    // for time()
#include <algorithm> // for transform

using namespace std;

string getComputerChoice() {
    int randomChoice = rand() % 3;  // Random number between 0 and 2
    if (randomChoice == 0)
        return "Rock";
    else if (randomChoice == 1)
        return "Paper";
    else
        return "Scissors";
}

string getUserChoice() {
    string choice;
    cout << "Enter your choice (Rock, Paper, Scissors): ";
    cin >> choice;

    // Convert to lowercase for case-insensitive comparison
    transform(choice.begin(), choice.end(), choice.begin(), ::tolower);

    // Map lowercase input back to proper format
    if (choice == "rock") return "Rock";
    else if (choice == "paper") return "Paper";
    else if (choice == "scissors") return "Scissors";
    else {
        cout << "Invalid choice! Please enter Rock, Paper, or Scissors." << endl;
        return getUserChoice(); // Re-prompt for valid input
    }
}

void showGraphic(string choice) {
    if (choice == "Rock") {
        cout << "    _______" << endl;
        cout << "---'   ____)" << endl;
        cout << "      (_____)" << endl;
        cout << "      (_____)" << endl;
        cout << "      (____)" << endl;
        cout << "---.__(___)" << endl;
    } else if (choice == "Paper") {
        cout << "    _______" << endl;
        cout << "---'   ____)____" << endl;
        cout << "          ______)" << endl;
        cout << "          _______)" << endl;
        cout << "         _______)" << endl;
        cout << "---.__________)" << endl;
    } else if (choice == "Scissors") {
        cout << "    _______" << endl;
        cout << "---'   ____)____" << endl;
        cout << "          ______)" << endl;
        cout << "       __________)" << endl;
        cout << "      (____)" << endl;
        cout << "---.__(___)" << endl;
    }
}

void determineWinner(string userChoice, string computerChoice) {
    cout << "Computer chose: " << computerChoice << endl;
    showGraphic(computerChoice);

    if (userChoice == computerChoice) {
        cout << "It's a draw!" << endl;
    } else if ((userChoice == "Rock" && computerChoice == "Scissors") ||
               (userChoice == "Paper" && computerChoice == "Rock") ||
               (userChoice == "Scissors" && computerChoice == "Paper")) {
        cout << "You win!" << endl;
    } else {
        cout << "Computer wins!" << endl;
    }
}

int main() {
    srand(time(0));  // Seed the random number generator

    string userChoice, playAgain;
    do {
        userChoice = getUserChoice();
        cout << "You chose: " << userChoice << endl;
        showGraphic(userChoice);

        string computerChoice = getComputerChoice(); // Generate computer choice
        determineWinner(userChoice, computerChoice);

        cout << "Do you want to play again? (yes/no): ";
        cin >> playAgain;
    } while (playAgain == "yes");

    cout << "Thanks for playing!" << endl;

    return 0;
}
