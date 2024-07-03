#include <bits/stdc++.h>

using namespace std;

double evaluateHand(vector<string> v) {
    vector<pair<char, int>> hand = {{'A', 0},
                                    {'2', 0},
                                    {'3', 0},
                                    {'4', 0},
                                    {'5', 0},
                                    {'6', 0},
                                    {'7', 0},
                                    {'8', 0},
                                    {'9', 0},
                                    {'T', 0},
                                    {'J', 0},
                                    {'Q', 0},
                                    {'K', 0}};
    // count number of each card
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 13; j++) {
            if (v[i][0] == hand[j].first) hand[j].second++;
        }
    }
    // check for longest consecutive cards... check up to 17 since can be K A 2 3 4
    int consecutive1 = 0, consecutive2 = 0, longest1 = 0, longest2 = 0, remove[13] = {};
    for (int i = 0; i < 17; i++) {
        if (hand[i % 13].second > 0) {
            consecutive1++;
            remove[i % 13] = 1;
        } else consecutive1 = 0;
        if (consecutive1 > longest1) longest1 = consecutive1;
    }
    // remove these consecutive cards from hand
    consecutive1 = 0;
    for (int i = 0; i < 17; i++) {
        if (remove[i % 13] == 1) {
            consecutive1++;
        } else consecutive1 = 0;
        if (consecutive1 == longest1) {
            for (int j = 0; j < consecutive1; j++){
                hand[(i - j) % 13].second--;
            }
            break; // only remove once! especially if 2 consecutive x2
        }
    }

    // check twice cuz can 2 pairs
    for (int i = 0; i < 17; i++) {
        if (hand[i % 13].second > 0) {
            consecutive2++;
            remove[i % 13] = 1;
        } else consecutive2 = 0;
        if (consecutive2 > longest2) longest2 = consecutive2;
    }

    if (longest1 == 5) return 100;
    else if (longest1 == 4) return 10;
    else if (longest1 == 3 && longest2 == 2) return 5;
    else if (longest1 == 3) return 3;
    else if (longest1 == 2 && longest2 == 2) return 1;
    else return 0;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    string a, b, c, d, e;
    while (cin >> a >> b >> c >> d >> e) {
        vector<string> vOriginal, v;
        double score[6] = {};
        vOriginal.push_back(a);
        vOriginal.push_back(b);
        vOriginal.push_back(c);
        vOriginal.push_back(d);
        vOriginal.push_back(e);

        score[0] = evaluateHand(vOriginal);
        // check all possible replacements
        // all start with 4 suits A 2 3 4 5 6 7 8 9 T J Q K
        map<char, int> deck = {{'A', 4},
                               {'2', 4},
                               {'3', 4},
                               {'4', 4},
                               {'5', 4},
                               {'6', 4},
                               {'7', 4},
                               {'8', 4},
                               {'9', 4},
                               {'T', 4},
                               {'J', 4},
                               {'Q', 4},
                               {'K', 4}};
        for (int i = 0; i < 5; i++) {
            deck[vOriginal[i][0]]--;
        }

        // replace A... -1 cuz need pay to exchange
        for (auto &&item: deck) {
            v = vOriginal; // we will modify v
            if (item.second == 0) continue;
            else (v[0][0] = item.first);
            score[1] += (evaluateHand(v) - 1) * item.second / 47;
        }

        // replace B
        for (auto &&item: deck) {
            v = vOriginal; // we will modify v
            if (item.second == 0) continue;
            else (v[1][0] = item.first);
            score[2] += (evaluateHand(v) - 1) * item.second / 47;
        }

        // replace C
        for (auto &&item: deck) {
            v = vOriginal; // we will modify v
            if (item.second == 0) continue;
            else (v[2][0] = item.first);
            score[3] += (evaluateHand(v) - 1) * item.second / 47;
        }

        // replace D
        for (auto &&item: deck) {
            v = vOriginal; // we will modify v
            if (item.second == 0) continue;
            else (v[3][0] = item.first);
            score[4] += (evaluateHand(v) - 1) * item.second / 47;
        }

        // replace E
        for (auto &&item: deck) {
            v = vOriginal; // we will modify v
            if (item.second == 0) continue;
            else (v[4][0] = item.first);
            score[5] += (evaluateHand(v) - 1) * item.second / 47;
        }

        // decide if exchange or not
        double best = *max_element(score, score + 6);
        if (score[0] == best) cout << "Stay" << endl;
        else if (score[1] == best) cout << "Exchange " << vOriginal[0] << endl;
        else if (score[2] == best) cout << "Exchange " << vOriginal[1] << endl;
        else if (score[3] == best) cout << "Exchange " << vOriginal[2] << endl;
        else if (score[4] == best) cout << "Exchange " << vOriginal[3] << endl;
        else if (score[5] == best) cout << "Exchange " << vOriginal[4] << endl;

    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

