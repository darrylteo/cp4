#include <bits/stdc++.h>

using namespace std;

// for x and y,
// green will be from 2x TO 2x+(x-5) AND 2y TO 2y+(y-5) etc.
// for the smallest element, check each second from 2x TO 2x+(x-5) against all other elements green time
// print first green time that matches all other elements green time
// we do this by "shrinking" the set to just the intersection of all green times

void printScenario(vector<int> v) {
    std::sort(v.begin(), v.end());
    int currTime = v[0] * 2; // start after first cycle

    while (currTime <= 5 * 60 * 60) {
        vector<int> match(v[0] - 5, 1);
        for (int i = 1; i < v.size(); i++) {
            // find the latest start time of the green light of v[i] that is before currTime.
            // we check from currTime to currTime + v[0] - 5
            // but find the pattern from latestStartTime for v[i]
            int latestStartTime = 0;
            while (latestStartTime < currTime - 2 * v[i]) {
                latestStartTime += 2 * v[i];
            }

            for (int j = currTime; j < currTime + v[0] - 5; j++) {
                // if all elements of match == 0, continue to next currTime
                if (std::all_of(match.begin(), match.end(), [](int i) { return i == 0; })) {
                    break;
                }
                // always check 2 cycles (not more since v[i] > v[0])
                // for each second in currTime to currTime + v[0] - 5, check if it is in the green light of v[i] (2 cycles)
                if ((j >= latestStartTime && j < latestStartTime + v[i] - 5 ||
                    j >= latestStartTime + 2 * v[i] && j < latestStartTime + 2 * v[i] + v[i] - 5) &&
                    match[j - currTime] == 1) {
                    match[j - currTime] = 1;
                } else {
                    match[j - currTime] = 0;
                }
            }
        }
        // check which of matches == 1, if found, print results and return
        for (int j = 0; j < match.size(); j++) {
            if (match[j] == 1) {
                currTime += j;
                cout << setfill('0') << setw(2) << currTime / 3600 << ":"
                     << setfill('0') << setw(2) << (currTime % 3600) / 60 << ":"
                     << setfill('0') << setw(2) << currTime % 60 << endl;
                return;
            }
        }

        currTime += v[0] * 2;
    }
    cout << "Signals fail to synchronise in 5 hours" << endl;

}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    vector<int> v;
    int n;
    while (cin >> n) {
        // if meet 0, compute scenario data
        if (n == 0) {
            printScenario(v);
            // clear vector and check next element
            v.clear();
            cin >> n;
            if (n == 0) break;
            else v.push_back(n);
        } else v.push_back(n);
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
