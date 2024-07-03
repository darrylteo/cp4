#include <bits/stdc++.h>

using namespace std;

// model the cursor as in between the top of both stacks

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    string s;
    cin >> s;
    stack<char> left, right;
    for (char c : s) {
        if (c == 'L') {
            if (!left.empty()) {
                right.push(left.top());
                left.pop();
            }
        } else if (c == 'R') {
            if (!right.empty()) {
                left.push(right.top());
                right.pop();
            }
        } else if (c == 'B') {
            if (!left.empty()) {
                left.pop();
            }
        } else {
            left.push(c);
        }
    }
    while (!left.empty()) {
        right.push(left.top());
        left.pop();
    }
    string ans;
    while (!right.empty()) {
        ans += right.top();
        right.pop();
    }
    cout << ans << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}


