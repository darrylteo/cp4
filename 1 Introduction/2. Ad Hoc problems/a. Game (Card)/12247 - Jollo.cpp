#include <bits/stdc++.h>

using namespace std;

vector<int> cardsPrincess, cardsPrince;

//basically permutation of X and Y, win win, lose lose, win lose, lose win//

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    do {
        for (int i = 0; i < 3; i++) {
            int x;
            cin >> x;
            cardsPrincess.push_back(x);
        }
        for (int i = 0; i < 2; i++) {
            int x;
            cin >> x;
            cardsPrince.push_back(x);
        }
        sort(cardsPrincess.begin(), cardsPrincess.end());
        sort(cardsPrince.begin(), cardsPrince.end());

        // case 1 (return smallest card in deck) (win win)
        if (cardsPrince[0] > cardsPrincess[2]) {
            for (int i = 1; i < 53; i++) {
                // == end means not in vector
                if (find(cardsPrince.begin(), cardsPrince.end(), i) == cardsPrince.end() &&
                    find(cardsPrincess.begin(), cardsPrincess.end(), i) == cardsPrincess.end()) {
                    cout << i << endl;
                    break;
                }
            }
        }

            // case 2 (lose lose)
        else if (cardsPrince[0] < cardsPrincess[1] && cardsPrince[1] < cardsPrincess[2]) {
            cout << -1 << endl;
        }

            // case 3 (return card that bigger than princess middle) (win lose)
        else if (cardsPrince[0] > cardsPrincess[1] && cardsPrince[1] < cardsPrincess[2]) {
            for (int i = cardsPrincess[1] + 1; i < 53; i++) {
                if (find(cardsPrince.begin(), cardsPrince.end(), i) == cardsPrince.end() &&
                    find(cardsPrincess.begin(), cardsPrincess.end(), i) == cardsPrincess.end()) {
                    cout << i << endl;
                    break;
                }
                if (i == 52) cout << -1 << endl;
            }
        }

            // case 4 (return card that bigger than princess middle) (semi-lose win)
        else if (cardsPrince[0] > cardsPrincess[1] && cardsPrince[1] > cardsPrincess[2]) {
            for (int i = cardsPrincess[1] + 1; i < 53; i++) {
                if (find(cardsPrince.begin(), cardsPrince.end(), i) == cardsPrince.end() &&
                    find(cardsPrincess.begin(), cardsPrincess.end(), i) == cardsPrincess.end()) {
                    cout << i << endl;
                    break;
                }
                if (i == 52) cout << -1 << endl;
            }
        }

        // case 5 (return card that bigger than princess max) (mega-lose win)
        else if (cardsPrince[0] < cardsPrincess[1] && cardsPrince[1] > cardsPrincess[2]) {
            for (int i = cardsPrincess[2] + 1; i < 53; i++) {
                if (find(cardsPrince.begin(), cardsPrince.end(), i) == cardsPrince.end() &&
                    find(cardsPrincess.begin(), cardsPrincess.end(), i) == cardsPrincess.end()) {
                    cout << i << endl;
                    break;
                }
                if (i == 52) cout << -1 << endl;
            }
        }

        // reset deck
        cardsPrincess.clear();
        cardsPrince.clear();
    } while (cardsPrince[0] != 0);


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}


