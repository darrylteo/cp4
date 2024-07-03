#include <bits/stdc++.h>

using namespace std;

int N;


int cardValue(string card) {
    if (card[0] == 'A' || card[0] == 'T' || card[0] == 'J' || card[0] == 'Q' || card[0] == 'K') {
        return 10;
    } else {
        return card[0] - '0';
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    scanf("%d", &N);
    for (int n = 0; n < N; n++) {
        vector<string> cards;
        string tmp;
        for (int i = 0; i < 52; i++) {
            cin >> tmp;
            cards.push_back(tmp);
        }
        std::reverse(cards.begin(), cards.end()); // oops didn't read it is bottom to top
        int Y = 0;
        for (int i = 0; i < 3; i++) {
            int X = cardValue(cards[25]);
            Y += X;
            int discard = 10 - X + 1;
            for (int j = 0; j < discard; j++) {
                cards.erase(cards.begin() + 25);
            }
        }
        cout << "Case " << n + 1 << ": " << cards[cards.size() - Y] << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

