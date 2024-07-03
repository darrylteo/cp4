#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    int n, k;
    cin >> n >> k;
    stack<int> prevCommands;
    for (int i = 0; i < k; i++) {
        string command;
        cin >> command;
        if (command == "undo") {
            int x;
            cin >> x;
            for (int j = 0; j < x; j++) {
                prevCommands.pop();
            }
        } else {
            int x = stoi(command);
            prevCommands.push(x);
        }
    }
    int sum = 0;
    while (!prevCommands.empty()) {
        sum += prevCommands.top();
        prevCommands.pop();
    }
    cout << (sum + 1000 * n) % n << endl; // just some constants to mod negative numbers

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
