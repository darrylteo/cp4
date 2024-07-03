#include <bits/stdc++.h>

using namespace std;

int getDistance(char c1, char c2) {
    string keys = "qwertyuiopasdfghjkl;zxcvbnm,./"; // 10 chars per line
    int row1, col1, row2, col2;
    for (int i = 0; i < keys.size(); i++) {
        if (keys[i] == c1) {
            row1 = i / 10;
            col1 = i % 10;
        }
        if (keys[i] == c2) {
            row2 = i / 10;
            col2 = i % 10;
        }
    }
    return abs(row1 - row2) + abs(col1 - col2);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    int n;
    cin >> n;
    while (n--) {
        vector<pair<string,int>> words;
        string original, tmp;
        int m;
        cin >> original >> m;
        while (m--) {
            cin >> tmp;
            words.emplace_back(tmp, 0);
        }
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words[i].first.size(); j++) {
                words[i].second += getDistance(original[j], words[i].first[j]);
            }
        }
        sort(words.begin(), words.end(), [](pair<string,int> a, pair<string,int> b) {
            if (a.second == b.second) {
                return a.first < b.first;
            }
            return a.second < b.second;
        });
        for (pair<string,int> word : words) {
            cout << word.first << " " << word.second << endl;
        }


    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
