#include <bits/stdc++.h>

using namespace std;

int N, K;
map<string, int> cards;


int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    cin >> N >> K;
    int card1pos, card2pos, usedpos[1005] = {};
    string card1, card2;
    int matches = 0, alreadyMatched = 0;
    while (K--) {
        cin >> card1pos >> card2pos >> card1 >> card2;
        usedpos[card1pos] = 1;
        usedpos[card2pos] = 1;

        // dont add match since its enemy matched (minus ur match too)
        if (strcmp(card1.c_str(), card2.c_str()) == 0) {
            if (cards[card1] == -1){
                matches--;
            }
            cards[card1] = -1;
            alreadyMatched++;
            continue;
        }
        // if not found, add to map
        if (cards.find(card1) == cards.end()) {
            cards[card1] = card1pos;
            // else if found in new position and not matched before, match!
        } else if (cards[card1] != card1pos && cards[card1] != -1) {
            matches++;
            cards[card1] = -1;
        }
        // if not found, add to map
        if (cards.find(card2) == cards.end()) {
            cards[card2] = card2pos;
            // else if found in new position and not matched before, match!
        } else if (cards[card2] != card2pos && cards[card2] != -1) {
            matches++;
            cards[card2] = -1;
        }
    }

    int noOfOpenedCards = 0, noOfUnopenedCards = 0, noOfUnmatchedCards = 0;
    for (int i = 1; i <= N; i++) {
        if (usedpos[i] != 0) {
            noOfOpenedCards++;
        }
    }
    noOfUnopenedCards = N - noOfOpenedCards;
    noOfUnmatchedCards = noOfOpenedCards - alreadyMatched * 2 - matches * 2;
    // if all remaining cards are different, you can match all remaining cards
    // OR also ok if only 2 cards remaining and both same (need add since noOfUnmatchedCards = 0)
    if (noOfUnmatchedCards == noOfUnopenedCards || noOfUnopenedCards == 2 ){
        matches = N/2 - alreadyMatched;
    }


    cout << matches << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}


