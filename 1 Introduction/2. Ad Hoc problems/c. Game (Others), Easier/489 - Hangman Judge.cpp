#include <bits/stdc++.h>

using namespace std;

int n;


int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    cin >> n;
    while (n != -1) {
        cout << "Round " << n << endl;

        map<char, int> word, guess;
        string w, g;
        cin >> w >> g;
        for (char i: w) {
            word[i] = 0;
        }
        for (char i: g) {
            guess[i] = 0;
        }

        int correct = 0, wrong = 0;
        for (char i: g) {
            if (word.find(i) != word.end()) {
                if (word[i] == 0) { // not used yet then count as correct
                    correct++;
                    word[i] = 1;
                }
            } else {
                if (guess[i] == 0) { // not used yet then count as wrong
                    wrong++;
                    guess[i] = 1;
                }
            }
            if (wrong == 7 || correct == word.size()) break;
        }


        if (correct == word.size()) cout << "You win." << endl;
        else if (wrong == 7) cout << "You lose." << endl;
        else cout << "You chickened out." << endl;

        cin >> n;
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

