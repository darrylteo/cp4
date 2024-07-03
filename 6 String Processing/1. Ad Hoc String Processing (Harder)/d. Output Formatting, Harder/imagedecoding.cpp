#include <bits/stdc++.h>

using namespace std;

int printLine(const string& s) {
    int sum = 0, charType = 0;
    stringstream ss(s);
    string token;
    ss >> token;
    if (token == "#") charType = 1;
    while (ss >> token) {
        cout << string(stoi(token), (charType ? '#' : '.'));
        sum += stoi(token);
        charType = !charType;
    }
    cout << '\n';
    return sum;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, start = 1;
    while (cin >> n, n) {
        if (start) start = 0;
        else cout << '\n';

        int error = 0, sumFirst = 0, sumCurrent = 0;
        string s;
        cin.ignore();
        getline(cin, s);
        sumFirst = printLine(s);
        for (int i = 1; i < n; i++) {
            getline(cin, s);
            sumCurrent = printLine(s);
            if (sumFirst != sumCurrent) error = 1;
        }
        if (error) cout << "Error decoding image\n";
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

