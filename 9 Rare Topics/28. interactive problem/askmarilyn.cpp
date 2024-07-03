#include <bits/stdc++.h>

using namespace std;

std::random_device rd;  // Will be used to obtain a seed for the random number engine
std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
std::uniform_real_distribution<> dis(0, 1);

// direct implementation of monty hall problem. only tricky part is generating which random door to start.

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int tc = 0;
    int replyInt;
    char replyChar;
    while (tc < 1000) {
        vector<bool> used(3, false);
        double roll = dis(gen);
        if (roll > 0.67) used[0] = true;
        else if (roll > 0.33) used[1] = true;
        else used[2] = true;
        int start;
        for (int i = 0; i < 3; i++) {
            if (used[i]) start = i;
        }
        cout << (char) (start + 'A') << flush;
        cin >> replyChar >> replyInt;
        if (replyInt) cout << replyChar << flush;
        else {
            used[replyChar - 'A'] = true;
            char nextChar;
            for (int i = 0; i < 3; i++) {
                if (!used[i]) nextChar = (char) ('A' + i);
            }
            cout << nextChar << flush;
        }
        cin >> replyInt >> replyChar;
        tc++;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
