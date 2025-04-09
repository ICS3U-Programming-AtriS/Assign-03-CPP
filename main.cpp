// Copyright (c) 2025 Atri Sarker All rights reserved.
// .
// Created By: Atri S
// Date: Month DayNum, YEAR
// CASINO

#include <iostream>
#include <string>
#include <cstdio>
#include <list>
#include <algorithm>
#include <random>

// Terminal color sequences
const std::string RED = "\033[0;31m";     // Red
const std::string YELLOW = "\033[0;33m";  // Yellow
const std::string BLUE = "\033[0;34m";    // Blue
const std::string PURPLE = "\033[0;35m";  // Purple
const std::string CYAN = "\033[0;36m";    // Cyan
const std::string WHITE = "\033[0;37m";   // White (default)




void print(std::string msg) {
    std::cout << msg;
    printf("\n");
}

// print() but it's red
void red(std::string msg, bool newline = true) {
    // Set the color and print message
    std::cout << RED << msg;
    // Add newline if needed
    if (newline) {
        std::cout << std::endl;
    }
    // Reset Color back to default
    std::cout << WHITE;
}

// print() but it's blue
void blue(std::string msg, bool newline = true) {
    // Set the color and print message
    std::cout << BLUE << msg;
    // Add newline if needed
    if (newline) {
        std::cout << std::endl;
    }
    // Reset Color back to default
    std::cout << WHITE;
}

// print() but it's cyan
void cyan(std::string msg, bool newline = true) {
    // Set the color and print message
    std::cout << CYAN << msg;
    // Add newline if needed
    if (newline) {
        std::cout << std::endl;
    }
    // Reset Color back to default
    std::cout << WHITE;
}

// print() but it's purple
void purple(std::string msg, bool newline = true) {
    // Set the color and print message
    std::cout << PURPLE << msg;
    // Add newline if needed
    if (newline) {
        std::cout << std::endl;
    }
    // Reset Color back to default
    std::cout << WHITE;
}

// print() but it's yellow
void yellow(std::string msg, bool newline = true) {
    // Set the color and print message
    std::cout << YELLOW << msg;
    // Add newline if needed
    if (newline) {
        std::cout << std::endl;
    }
    // Reset Color back to default
    std::cout << WHITE;
}

void lineBreak() {
    yellow("#~#~#~#~#~#~#~#~#~#~#");
}

std::string optionInput(std::string prompt, std::list<std::string> options) {
    lineBreak();
    while (true) {
        // Display available options
        blue("Options: [", false);
        int counter = 1;
        for (std::string option : options) {
            blue('"'+option+'"', false);
            if (counter < options.size()) {
                blue(", ", false);
            }
            counter += 1;
        }
        blue("]");

        // Display prompt
        cyan(prompt, false);
        // Get user's input
        std::string choice;
        std::getline(std::cin, choice);
        // Transform input for case insensitivity
        std::transform(choice.begin(), choice.end(), choice.begin(), ::toupper);
        // Check if user's input is a valid choice
        for (std::string option : options) {
            if (choice == option) {
                lineBreak();
                return choice;
            }
        }
        red("Please enter a valid option from the list");
    }
}

std::string randomChoice(std::list<std::string> options) {
    // RANDOM SEED
    std::random_device seed;
    // MERSENNE TWISTER
    std::mt19937 mt(seed());
    // Distribution that contains index/position for all elements
    std::uniform_int_distribution<int> randIndex(0, options.size() - 1);
    // Get a random number from the list
    int generatedIndex = randIndex(mt);

    // RETURN ELEMENT
    int counter = 0;
    for (std::string option : options) {
        if (counter == generatedIndex) {
            return option;
        }
        counter += 1;
    }
}

// Rock Paper Scissors
void rps() {
    // Display Introduction Message
    print(
        "Welcome to rock paper scissors.\n"
        "Rock beats paper,\n"
        "paper beats scissors,\n"
        "and scissors beats rock.\n"
        "You will be playing Barbable"
        " from Liechtenstein!\n"
        "First to 3 points wins!"
    );

    // Initialize user points
    int userPoints = 0;
    // Initialize program points
    int programPoints = 0;
    // Initialize list for choices
    std::list<std::string> choices = {"ROCK", "PAPER", "SCISSORS"};

    // Game loop for rounds
    while (true) {
        // Initialize user_pick as a string value
        std::string userPick;
        // Initialize program_pick as a string value
        std::string programPick;
        // Check if user is 1 point away from winning
        if (userPoints >= 2) {
            // Get user's pick
            userPick = optionInput("Rock/Paper/Scissors? ", choices);

            // Set Program pick such that it always results in either
            // a draw or a loss
            if (userPick == "ROCK") {
                // program pick is now either "ROCK" or "PAPER"
                programPick = randomChoice({"ROCK", "PAPER"});
            }
            else if (userPick == "PAPER") {
                // program pick is now either "PAPER" or "SCISSORS"
                programPick = randomChoice({ "PAPER", "SCISSORS" });
            }
            // If it's not ROCK or PAPER, it must be SCISSORS;
            else {
                // program pick is now either "SCISSORS" or "ROCK"
                programPick = randomChoice({ "SCISSORS", "ROCK" });
            }

        } else {
            // Get user's pick
            userPick = optionInput("Rock/Paper/Scissors? ", choices);
            // Select a random pick for the program
            programPick = randomChoice(choices);
        }

        // Evaluate the result of the round
        // and award points
        if (userPick == "ROCK") {
            // Rock draws with Rock
            if (programPick == "ROCK") {
                print("DRAW!");
            } else if (programPick == "PAPER") {
                print("LOSS!");
                programPoints += 1;
            } else {
                print("WIN!");
                userPoints += 1;
            }
        }
        else if (userPick == "PAPER") {
            // Paper beats Rock
            if (programPick == "ROCK") {
                print("WIN!");
                userPoints += 1;
            } else if (programPick == "PAPER") {
                print("DRAW!");
            } else {
                print("LOSS!");
                programPoints += 1;
            }
        } else if (userPick == "SCISSORS") {
            // Scissors loses to Rock
            if (programPick == "ROCK") {
                print("LOSS!");
                programPoints += 1;
            } else if (programPick == "PAPER") {
                print("WIN!");
                userPoints += 1;
            } else {
                print("DRAW!");
            }
        }

        // End the game once program reaches 3 points
        if (programPoints >= 3) {
            purple("You lost the set!");
            purple("Barbable spits in your face!");
            break;
        }

        // Display the score
        // at the end of every round
        std::cout << "Your points: " << userPoints;
        std::cout << std::endl;
        std::cout << "Barbable's points: " << programPoints;
        std::cout << std::endl;
    }
}

// Coin Flipping Game
void coinFlip() {
    // Get user's guess for whether a coin will result in
    // "HEADS" or "TAILS"
    std::string guess = optionInput("Heads/Tails? ", {"HEADS", "TAILS"});

    if (guess == "HEADS") {
        // If the user guessed "HEADS", the result is "TAILS"
        purple("The coin was tails, unfortunately.");
    } else /* If guess is not "HEADS", it must be "TAILS" */ {
        // If the user guessed "TAILS", the result is "HEADS"
        purple("The coin was heads, unfortunately.");
    }
}

// Number Guessing Game
void numGuess() {
    // Get the user's guess as a string
    std::string userInput;
    cyan("Enter a number (0-9): ", false);
    std::getline(std::cin, userInput);

    try {
        // # Convert the user's guess to an integer
        int userNum = std::stoi(userInput);

        // Check if user's guess is within the guessing boundaries
        if (0 <= userNum && userNum <= 9) {
            // Generate a random number between 0 and 9,
            // excluding the user's guess
            // RANDOM SEED
            std::random_device seed;
            // MERSENNE TWISTER
            std::mt19937 mt(seed());
            // Distribution that contains numbers from 1 to 9
            std::uniform_int_distribution<int> randOffset(1, 9);
            // Generate the number
            int correctNum = (userNum + randOffset(mt)) % 10;

            // Tell the user that they guessed wrong
            // Also tell them the correct answer
            purple("Wrong the correct answer was ", false);
            purple(std::to_string(correctNum) + ".");
        } else {
            purple("Wrong! Hint: The number is between 0 and 9");
        }
    } catch (std::invalid_argument) {
        // Tell the user that their input wasn't an integer
        red(userInput, false);
        red(" is not an integer.");
    }
}

void hangman() {
    /*    
    # List of 3-letter words
    # Carefully engineered so that no sequence of 5 characters
    # will empty out the list
    */
    std::list<std::string> wordList = {
        "BAT",
        "BAR",
        "BTW",
        "BAN",
        "BIN",
        "CAR",
        "CAT",
        "CAP",
        "CAN",
        "DOG",
        "FAN",
        "FAT",
        "FIN",
        "FUN",
        "GAP",
        "GUN",
        "HUT",
        "HMM",
        "JET",
        "JOB",
        "JOY",
        "KIT",
        "LOG",
        "MAN",
        "MAP",
        "NAP",
        "NET",
        "PEN",
        "PET",
        "PIN",
        "POT",
        "PRY",
        "RAT",
        "SUN",
        "SPY",
        "SSH",
        "VAN",
        "WIT",
        "WHY",
        "YES",
        "ZAP",
    };

    
}

int main() {
    // Introduction message
    print("Welcome to THE CASINO!");

    // List of available games
    std::list<std::string> gameList = {"RPS", "COIN", "NUMBER", "HANGMAN", "EXIT"};

    // Game Selection Loop
    while (true) {
        // Ask user what game they want to play
        std::string selectedGame;
        selectedGame = optionInput("What Game do you want to play?: ", gameList);

        // Take the user to the game they want to play
        if (selectedGame == "RPS") {
            // Rock Paper Scissors
            rps();
        } else if (selectedGame == "COIN") {
            // Coin Flipping Game
            coinFlip();
        } else if (selectedGame == "NUMBER") {
            // Number Guessing Game
            numGuess();
        } else if (selectedGame == "HANGMAN") {
            // Hangman Game
            hangman();
        } else if (selectedGame == "EXIT") {
            // Provide the user with factual knowledge
            // \u0025 is the unicode sequence for "%"
            purple("FACT: 99\u0025 of gamblers quit before they win big!");
            purple("Be sure to come back!");
            // Exit loop, consequently ending the program
            break;
        }
    }

}
