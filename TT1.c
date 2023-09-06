#include <stdio.h>
#include <string.h>

// Structure to store each question and its options
struct Question {
    char question[100];
    char options[4][50];
    int correctOption;
};

// Function to display a question and get user's answer
int askQuestion(struct Question q) {
    int userAnswer;

    printf("%s\n", q.question);
    for (int i = 0; i < 4; i++) {
        printf("%d) %s\n", i + 1, q.options[i]);
    }
    printf("Your answer: ");
    scanf("%d", &userAnswer);

    return userAnswer;
}

int main() {
    // Initialize player's name and score
    char playerName[50];
    int totalScore = 0;
    	printf("\n\n\n\n\n\n");
		printf("\n\t   +-------+                          ___       ___                             ");
		printf("\n\t   |       |      |         |            |                /                              ");
		printf("\n\t   |       |      |         |            |               /                               ");
		printf("\n\t   |       |      |         |            |              /                                ");
		printf("\n\t   |    // |      |         |            |             /                                 ");
		printf("\n\t   |   //  |      |         |            |            /                                  ");
		printf("\n\t   +--//---+      |___|         _|_        /___                          ");

    printf("Welcome to the Quiz Game!\n");
    printf("Enter your name: ");
    scanf("%s", playerName);

    // Array of questions for each round
    struct Question round1Questions[5] = {
        {"What is the capital city of Brazil?", {"Rio de Janeiro", "Sao Paulo", " Brasilia", " Salvador"}, 3},
         {"Which ocean is the largest in the world?", {"Atlantic Ocean", "Pacific Ocean", " Indian Ocean", "  Arctic Ocean"}, 2},
          {"The Renaissance period originated in which country?", {"Italy", " France", " Spain", " England"}, 1},
           {" Which ancient wonder was located in Egypt and is the only one still standing today?", {"Hanging Gardens of Babylon", " Statue of Zeus at Olympia", "Great Pyramid of Giza", " Temple of Artemis at Ephesus"}, 3},
            {"Which gas do plants release during photosynthesis?", {"Oxygen", "Carbon Dioxide", "  Nitrogen", "  Helium"}, 1}
        // Add more questions for round 1
    };

    struct Question round2Questions[5] = {
        {"What is the smallest unit of life?", {"Cell", "Atom", "Molecule", "Proton"}, 1},
        {"What is the process by which water vapor turns directly into ice without passing through the liquid state called?", {"Melting", "Sublimation", "Evaporation", "Condensation"}, 2},
        {" Which gas do plants use for photosynthesis?", {"Nitrogen", " Oxygen", "Carbon Dioxide", "Hydrogen"}, 3},
        {"What is the chemical symbol for gold?", {"Ag", "Au", " Fe", "Pb"}, 2},
        {"Who painted the Mona Lisa?", {" Vincent van Gogh", " Leonardo da Vinci", "Pablo Picasso", "Michelangelo"}, 2},
        // Add more questions for round 2
    };

    struct Question round3Questions[5] = {
        {" In which year did the Titanic sink?", {"1912", "1923", "1905", " 1931"}, 1},
         {" What is the largest organ in the human body?", {" Brain", " Liver", " Heart", " Skin"}, 3},
          {" What is the tallest mountain in the world?", {"Mount Kilimanjaro", "Mount Fuji", "Mount Everest", " Mount McKinley"}, 3},
           {"  What is the largest planet in our solar system?", {"Mars", "Earth", "Saturn", " Jupiter"}, 4},
            {" Who wrote the play Romeo and Juliet?", {"William Shakespeare", "Jane Austen", "Charles Dickens", " Mark Twain"}, 1},
        // Add more questions for round 3
    };

    // Play each round
    struct Question *currentRound;
    for (int round = 0; round < 3; round++) {
        if (round == 0) currentRound = round1Questions;
        else if (round == 1) currentRound = round2Questions;
        else currentRound = round3Questions;

        printf("\nRound %d:\n", round + 1);

        int roundScore = 0;
        for (int q = 0; q < 5; q++) {
            int userAnswer = askQuestion(currentRound[q]);
            if (userAnswer == currentRound[q].correctOption) {
                printf("Correct!\n");
                roundScore++;
            } else {
                printf("Wrong!\n");
            }
        }

        totalScore += roundScore;
        printf("Round %d Summary:\n", round + 1);
        printf("- Name: %s\n", playerName);
        printf("- Score: %d\n", roundScore);

        if (roundScore >= 3 && round < 2) {
            printf("\nCongratulations! You've qualified for the next round.\n");
        } else if (round < 2) {
            printf("\nUnfortunately, you did not qualify for the next round. Better luck next time!\n");
            break;
        }
    }

    printf("\nGame Over\n");
    printf("- Final Score: %d\n", totalScore);
    printf("Thank you for playing!\n");

    return 0;
}
