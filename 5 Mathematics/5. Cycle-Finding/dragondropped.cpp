#include <bits/stdc++.h>

using namespace std;

// worst case if cycle is ~6000. approximately?:
// 1st step use 6000 + 6000 * 2 commands
// 2nd step use 1 + 6000 + 6000 commands
// 3rd step use 6000 commands... already more than 30000 commands.

int main() {
    int N, s, e, x = 0;
    cin >> N;
    // 1st part: finding k*mu, hare h’s speed is 2x tortoise t’s
    while (true) {
        x++;
        // move tortoise 1x
        cout << "NEXT SPIKE\n";
        cout.flush();
        cin >> s >> e;
        if (s == 0) {
            cout << "ASK SPIKE\n"; // spike reached end of shift
            cout.flush();
            return 0;
        }
        // move hare 2x
        cout << "NEXT GABBY\n";
        cout.flush();
        cin >> s >> e;
        if (s == 0) {
            cout << "ASK GABBY\n"; // gabby reached end of shift
            cout.flush();
            return 0;
        }
        cout << "NEXT GABBY\n";
        cout.flush();
        cin >> s >> e;
        if (s == 0) {
            cout << "ASK GABBY\n"; // gabby reached end of shift
            cout.flush();
            return 0;
        }
        // check if tortoise and hare met
        if (e == 1) break;
    }

    // 3rd part: finding lambda, hare h moves, tortoise t stays
    int lambda = 0;
    while (true) {
        ++lambda;
        // move hare 1x
        cout << "NEXT GABBY\n";
        cout.flush();
        cin >> s >> e;
        if (s == 0) {
            cout << "ASK GABBY\n"; // gabby reached end of shift
            cout.flush();
            return 0;
        }
        // check if tortoise and hare met
        if (e == 1) break;
    }
//    cout << "lambda: " << lambda << "\n";
//    cout.flush();

    int steps = (N - x) % lambda;
//    cout << "steps: " << steps << "\n";
//    cout.flush();
    for (int i = 0; i < steps; ++i) {
        cout << "NEXT SPIKE\n";
        cout.flush();
        cin >> s >> e;
        if (s == 0) {
            cout << "ASK SPIKE\n"; // spike reached end of shift
            cout.flush();
            return 0;
        }
    }
    cout << "ASK SPIKE\n";
    cout.flush();

    return 0;
}