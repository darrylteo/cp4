#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    string s;
    vi num1, num2;
    cin >> s;
    for (char i: s) {
        num1.push_back(i - '0');
    }
    cin >> s;
    for (char i: s) {
        num2.push_back(i - '0');
    }
    for (int i = 0; i < min(num1.size(), num2.size()); i++) {
        int idx1 = num1.size() - i - 1;
        int idx2 = num2.size() - i - 1;
        if (num1[idx1] < num2[idx2]) {
            num1[idx1] = -1;
        }
        if (num1[idx1] > num2[idx2]) {
            num2[idx2] = -1;
        }
    }
    // check if yoda
    bool yoda = true;
    for (int i: num1) {
        if (i != -1) {
            yoda = false;
            break;
        }
    }
    if (yoda) {
        cout << "YODA" << endl;
    } else {
        string ans;
        for (int i: num1) {
            if (i != -1) {
                ans += to_string(i);
            }
        }
        cout << stoi(ans) << endl;
    }
    // check if yoda
    yoda = true;
    for (int i: num2) {
        if (i != -1) {
            yoda = false;
            break;
        }
    }
    if (yoda) {
        cout << "YODA" << endl;
    } else {
        string ans;
        for (int i: num2) {
            if (i != -1) {
                ans += to_string(i);
            }
        }
        cout << stoi(ans) << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}

