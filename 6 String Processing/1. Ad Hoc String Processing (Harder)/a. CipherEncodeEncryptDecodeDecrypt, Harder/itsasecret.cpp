#include <bits/stdc++.h>

using namespace std;

string getUnique(const string &key) {
    string unique;
    for (char c: key) {
        if (c != ' ') {
            c = (char) toupper(c);
            if (c == 'J') c = 'I'; // convert J to I
            if (unique.find(c) == string::npos) {
                unique += c;
            }
        }
    }
    return unique;
}

string removeSpaces(const string &s) {
    string result;
    for (char c: s) {
        if (c != ' ') {
            c = (char) toupper(c);
            if (c == 'J') c = 'I'; // convert J to I
            result += c;
        }
    }
    return result;
}

string processQuery(const string &query) {
    string qCopy = query;
    int idx = 0;
    while (idx < qCopy.size()) {
        char char1, char2;
        char1 = qCopy[idx++];
        char2 = qCopy[idx++];
        if (char1 == char2 || idx == qCopy.size() + 1) {
            char2 = 'X';
            qCopy.insert(idx - 1, 1, char2);
        }
//        if (char1 == char2 && char1 == 'X') {
//            qCopy[--idx] = 'Y';
//            qCopy[--idx] = 'Y';
//        }
    }
    return qCopy;
}

// a little difficult to interpret what they mean by replace with YY... i thought it would be infinite loop since XX -> XX X -> XX XX -> XX XX X ad infinitum
// see the commented code, i think it helps in interpreting the problem statement

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    while (cin >> n >> ws, n) {
        string buf;
        getline(cin, buf);
        string key = getUnique(buf); // and converts j to i
        string letters = "ABCDEFGHIKLMNOPQRSTUVWXYZ"; // except J
        char grid[5][5];
        for (int i = 0; i < key.size(); i++) grid[i / 5][i % 5] = key[i]; // fill with unique letters from key
        for (int i = key.size(); i < 25; i++) { // fill with remaining unique letters
            for (char c: letters) {
                if (key.find(c) == string::npos) {
                    grid[i / 5][i % 5] = c;
                    key += c;
                    break;
                }
            }
        }

        vector<string> queries(n);
        for (int i = 0; i < n; i++) {
            getline(cin, queries[i]);
            queries[i] = removeSpaces(queries[i]); // and converts j to i
        }
        for (string query: queries) {
            query = processQuery(query);
            int idx = 0;
            while (idx < query.size()) {
                char char1 = query[idx++];
                char char2 = query[idx++];
                if (char1 == char2 && char1 == 'X') {
                    cout << "YY";
                    continue;
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
        }
        cout << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

