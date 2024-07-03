#include <bits/stdc++.h>

using namespace std;

struct contestant {
    int id;
    int solved;
    int penalty;
    bool submitted;
    bool correct[10];
    int wrong[10];
};

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    string s;
    int T;
    getline(cin, s);
    T = stoi(s);
    getline(cin, s); // clear first blank line
    while (T--) {
        // intialize contestants
        vector<contestant> contestants(101);
        for (int i = 1; i <= 100; i++) {
            contestants[i].id = i;
            contestants[i].solved = 0;
            contestants[i].penalty = 0;
            contestants[i].submitted = false;
            for (int j = 0; j < 10; j++) {
                contestants[i].correct[j] = false;
            }
            for (int j = 0; j < 10; j++) {
                contestants[i].wrong[j] = 0;
            }
        }
        while (true) {
            getline(cin, s); // should not be blank on "first" getline of each test case
            if (s.empty()) { // go to next test case
                break;
            }
            stringstream ss(s);
            int contestant, problem, time;
            char L;
            ss >> contestant >> problem >> time >> L;
            contestants[contestant].submitted = true; // need print even if they didn't solve any problem
            if (L != 'C' && L != 'I') {
                continue;
            }
            if (L == 'C') {
                if (contestants[contestant].correct[problem]) { // already solved
                    continue;
                }
                contestants[contestant].correct[problem] = true;
                contestants[contestant].solved++;
                contestants[contestant].penalty += time;
                contestants[contestant].penalty += contestants[contestant].wrong[problem] * 20;
            } else {
                if (contestants[contestant].correct[problem]) { // already solved
                    continue;
                }
                contestants[contestant].wrong[problem]++; // wrong submission (add up only if solved)
            }
        }
        sort(contestants.begin(), contestants.end(), [](contestant a, contestant b) {
            if (a.penalty == b.penalty) {
                return a.id < b.id;
            } else if (a.solved == b.solved) {
                return a.penalty < b.penalty;
            }
            return a.solved > b.solved;
        });
        for (contestant c: contestants) {
            if (c.submitted) {
                cout << c.id << " " << c.solved << " " << c.penalty << endl;
            }
        }
        if (T) {
            cout << endl;
        }
    }
    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
