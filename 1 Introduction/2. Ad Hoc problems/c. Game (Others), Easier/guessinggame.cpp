#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    int guess, guesses[11] = {};
    string response;
    while (cin >> guess, guess != 0) {
        cin >> response >> response; // only 2nd word matters
        // any impossible "right on" guess is marked as -1
        // my guesses array is 1-indexed
        if (response == "high") {
            for (int i = guess; i < 11; i++) {
                guesses[i] = -1;
            }
        } else if (response == "low") {
            for (int i = 1; i <= guess; i++) {
                guesses[i] = -1;
            }
        } else {
            if (guesses[guess] == 0) {
                cout << "Stan may be honest" << endl;
            } else {
                cout << "Stan is dishonest" << endl;
            }
            fill(guesses, guesses + 11, 0);
        }
    }



    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

