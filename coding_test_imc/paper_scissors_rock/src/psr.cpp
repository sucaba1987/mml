#include <iostream>
#include <random>
#include <string>
using namespace std;
int main()
{
    const string player_symbols[3]   = {"Paper   ", "Rock    ", "Scissors"};
    const string computer_symbols[3] = {"Paper   ", "Scissors", "Rock    "};
    const string results[3] = {"Draw", "You loss!", "You win!"};
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0,2);
    int num_plays(0);
    int round(1);
    int player_idx(-1);
    int computer_idx(-1);
    char symbol;

    cout << "Welcome to Paper Scissors Rock Game" << endl;
    cout << "Please enter how many times you want to play: ";
    cin >> num_plays;
    while (num_plays <= 0) {
        cout << "Please enter positive number: ";
        cin >> num_plays;
    }
    cout << "The following characters represent the symbol:" << endl;
    cout << "p = Paper, r = Rock, s = Scissors, e = End game now" << endl;
    cout << "---------------------------------------------------" << endl;
    while (round <= num_plays) {
        player_idx = -1;
        cout << "Round " << round << ":" << endl;
        while (player_idx < 0) {
            cin >> symbol;
            switch (symbol) {
              case 'e':
                  player_idx = 3;
                  break;
              case 'p':
                  player_idx = 0;
                  break;
              case 'r':
                  player_idx = 1;
                  break;
              case 's':
                  player_idx = 2;
                  break;
              default:
                  break;
            }
        }
        if (player_idx >= 3)
            break;
        computer_idx = dis(gen);
        cout << "You: " << player_symbols[player_idx]
             << " Computer: " << computer_symbols[computer_idx]
             << " Result: " << results[(player_idx + computer_idx) % 3]
             << endl;
        ++round;
    }
    return 0;
}
