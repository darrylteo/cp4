#include <bits/stdc++.h>

using namespace std;

int N;

// cant find a closed form for this, so just use a loop
// iterate over all numbers that have the same number of digits as n
// remember colors are 1-9, so 0 is not a valid digit
// definitely not optimized but under time limit

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    cin >> N;
    while (N--) {
        char guess[10] = {}, ans[10] = {}, tmp[10] = {};
        int correct, halfCorrect, ansInt, matches = 0;
        cin >> guess >> correct >> halfCorrect;
        strcpy(tmp, guess); // save a copy of guess
        ansInt = static_cast<int>(pow(10, strlen(guess) - 1));
        while (ansInt < static_cast<int>(pow(10, strlen(guess)))) {
            strcpy(guess, tmp); // reset guess
            sprintf(ans, "%d", ansInt);

            // check if ans contains 0 (only 9 colors 1-9)
            int containsZero = 0;
            for (int i = 0; i < strlen(ans); i++) {
                if (ans[i] == '0') {
                    containsZero = 1;
                    break;
                }
            }
            if (containsZero) {
                ansInt++;
                continue;
            }

            int correctCount = 0, halfCorrectCount = 0;
            // check for correct placing and remove these (just for this loop)
            // since if used for correct match, cannot use for wrong match
            for (int i = 0; i < strlen(guess); i++) {
                if (guess[i] == ans[i]) {
                    correctCount++;
                    guess[i] = 'x';
                    ans[i] = 'x';
                }
            }

            // check for half correct placing
            for (int i = 0; i < strlen(guess); i++) {
                for (int j = 0; j < strlen(ans); j++) {
                    if (!isalpha(guess[i]) && !isalpha(ans[j]) && guess[i] == ans[j]) {
                        halfCorrectCount++;
                        guess[i] = 'x';
                        ans[j] = 'x';
                    }
                }
            }

            if (correctCount == correct && halfCorrectCount == halfCorrect) {
                matches++;
            }
            ansInt++;
        }
        cout << matches << endl;

    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

