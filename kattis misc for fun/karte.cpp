#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int cards[5][15]{}; // PKHT, 1-13
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i += 3) {
        char sub1 = s[i];
        string sub2 = s.substr(i + 1, 2);
        int suit = -1, rank = -1;
        if (sub1 == 'P') suit = 0;
        else if (sub1 == 'K') suit = 1;
        else if (sub1 == 'H') suit = 2;
        else suit = 3;
        rank = stoi(sub2);
        if (cards[suit][rank]) { // duplicate
            cout << "GRESKA";
            return 0;
        }
        cards[suit][rank] = 1;
    }
    for (int i = 0; i < 4; i++) {
        int cnt = 0;
        for (int j = 1; j <= 13; j++) {
            if (!cards[i][j]) cnt++;
        }
        cout << cnt << " ";
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}