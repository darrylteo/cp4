#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    int n;
    cin >> n;
    while (n--) {
        int start, end;
        vector<pair<int, int>> startEnd;
        while (cin >> start >> end, start || end) {
            startEnd.emplace_back(start, end);
        }
        // sort so can just compare sequentially by keeping track of time previous meeting ended
        sort(startEnd.begin(), startEnd.end());

        int maxMeetings = 0;
        for (int i = 0; i < 1 << startEnd.size(); i++) {
            bitset<25> meetings(i);
            bool valid = true;
            int prevEnd = 0;
            for (int j = 0; j < startEnd.size(); j++) {
                if (meetings[j]) {
                    if (startEnd[j].first < prevEnd) {
                        valid = false;
                        break;
                    }
                    prevEnd = startEnd[j].second;
                }
            }
            if (valid) {
                maxMeetings = max(maxMeetings, (int) meetings.count());
            }
        }
        cout << maxMeetings << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}