#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    int n, t, m;
    cin >> n >> t >> m;
    int time, teamID;
    string problem, verdict;
    // problem[0][0] = time for problem A, problem[0][1] = teamID for problem A
    vector<vector<int>> problems(n, vector<int>(2, -1));
    vector<vector<int>> solved(t, vector<int>(n, 0));
    while (m--) {
        cin >> time >> teamID >> problem >> verdict;
        if (verdict == "Yes" && problem[0] - 'A' < n) { // ignore problems that are not in the contest
            if (solved[teamID - 1][problem[0] - 'A'] == 0) {
                problems[problem[0] - 'A'][0] = time;
                problems[problem[0] - 'A'][1] = teamID;
                solved[teamID - 1][problem[0] - 'A'] = 1;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (problems[i][0] == -1) {
            cout << char(i + 'A') << " - -" << endl;
        } else {
            cout << char(i + 'A') << " " << problems[i][0] << " " << problems[i][1] << endl;
        }
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
