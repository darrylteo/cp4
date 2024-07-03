#include <bits/stdc++.h>

using namespace std;

bool checkSet(string &card1, string &card2, string &card3) {
    for (int i = 0; i < 4; ++i) {
        if ((card1[i] == card2[i] && card2[i] == card3[i]) ||
            (card1[i] != card2[i] && card2[i] != card3[i] && card1[i] != card3[i])) {
            continue;
        } else {
            return false;
        }
    }
    return true;
}


int main() {

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> cards;
    for (int i = 0; i < 12; i++) {
        string card;
        cin >> card;
        cards.push_back(card);
    }

    bool flag = false;
    for (int i1 = 0; i1 < 12; ++i1) {
        for (int i2 = i1 + 1; i2 < 12; ++i2) {
            for (int i3 = i2 + 1; i3 < 12; ++i3) {
                if (checkSet(cards[i1], cards[i2], cards[i3])) {
                    cout << i1 + 1 << " " << i2 + 1 << " " << i3 + 1 << endl;
                    flag = true;
                }
            }
        }
    }
    if (!flag) {
        cout << "no sets" << endl;
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}
