#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    while (n--) {
        int B, SG, SB;
        cin >> B >> SG >> SB;
        priority_queue<int> green, blue;
        for (int i = 0; i < SG; ++i) {
            int x;
            cin >> x;
            green.push(x);
        }
        for (int i = 0; i < SB; ++i) {
            int x;
            cin >> x;
            blue.push(x);
        }
        while (!green.empty() && !blue.empty()) {
            vector<int> g, b;
            for (int i = 0; i < B; ++i) {
                if (green.empty() || blue.empty()) break;
                int x = green.top();
                green.pop();
                int y = blue.top();
                blue.pop();
                if (x > y) g.push_back(x - y);
                else if (x < y) b.push_back(y - x);
            }
            for (auto &x : g) green.push(x);
            for (auto &x : b) blue.push(x);
        }
        if (green.empty() && blue.empty()) cout << "green and blue died\n";
        else if (green.empty()) {
            cout << "blue wins\n";
            while (!blue.empty()) {
                cout << blue.top() << '\n';
                blue.pop();
            }
        } else {
            cout << "green wins\n";
            while (!green.empty()) {
                cout << green.top() << '\n';
                green.pop();
            }
        }
        if (n) cout << '\n';
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

