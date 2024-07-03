#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    string buf;
    int caseNo = 1;
    while (cin >> buf, buf != "end") {
        cout << "Case " << caseNo++ << ": ";
        vector<stack<char>> stacks;
        // for each char, check all stacks and push it onto the one with a letter larger or equal to it
        for (char c: buf) {
            bool pushed = false;
            for (auto &stack: stacks) {
                if (stack.empty() || stack.top() >= c) {
                    stack.push(c);
                    pushed = true;
                    break;
                }
            }
            if (!pushed) {
                stacks.emplace_back();
                stacks.back().push(c);
            }
        }
        cout << stacks.size() << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
