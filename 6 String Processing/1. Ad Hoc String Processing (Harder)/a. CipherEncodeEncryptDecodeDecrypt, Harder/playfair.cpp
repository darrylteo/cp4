#include <bits/stdc++.h>

using namespace std;

string getUnique(const string& key) {
    string unique;
    for (char c : key) {
        if (unique.find(c) == string::npos && c != ' ') {
            unique += c;
        }
    }
    return unique;
}

string removeSpaces(const string& s) {
    string result;
    for (char c : s) {
        if (c != ' ') {
            result += c;
        }
    }
    return result;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    string buf;
    getline(cin, buf);
    string key = getUnique(buf);
    string letters = "abcdefghijklmnoprstuvwxyz"; // except q
    char grid[5][5];
    for (int i = 0; i < key.size(); i++) grid[i / 5][i % 5] = key[i]; // fill with unique letters
    for (int i = key.size(); i < 25; i++) { // fill with remaining unique letters
        for (char c : letters) {
            if (key.find(c) == string::npos) {
                grid[i / 5][i % 5] = c;
                key += c;
                break;
            }
        }
    }
    getline(cin, buf);
    string cipher = removeSpaces(buf);
    int idx = 0;
    while (idx < cipher.size()) {
        char char1, char2;
        char1 = cipher[idx++];
        char2 = cipher[idx++];
        if (char1 == char2 || idx == cipher.size() + 1) {
            char2 = 'x';
            idx--;
        }
        int r1, c1, r2, c2;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (grid[i][j] == char1) {
                    r1 = i;
                    c1 = j;
                }
                if (grid[i][j] == char2) {
                    r2 = i;
                    c2 = j;
                }
            }
        }
        if (r1 == r2) {
            cout << (char) toupper(grid[r1][(c1 + 1) % 5]) << (char) toupper(grid[r2][(c2 + 1) % 5]);
        } else if (c1 == c2) {
            cout << (char) toupper(grid[(r1 + 1) % 5][c1]) << (char) toupper(grid[(r2 + 1) % 5][c2]);
        } else {
            cout << (char) toupper(grid[r1][c2]) << (char) toupper(grid[r2][c1]);
        }
    }
    cout << '\n';

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

