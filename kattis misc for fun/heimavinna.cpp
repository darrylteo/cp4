#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    istringstream iss(s);
    vector<string> tokens;
    while (getline(iss, s, ';')) {
        tokens.push_back(s);
    }
    int homework = 0;
    for (string token : tokens) {
        if (find(token.begin(), token.end(), '-') != token.end()) {
            istringstream iss2(token);
            vector<string> tokens2;
            while (getline(iss2, token, '-')) {
                tokens2.push_back(token);
            }
            int a = stoi(tokens2[0]);
            int b = stoi(tokens2[1]);
            homework += b - a + 1;
        } else {
            homework++;
        }
    }
    cout << homework << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}


