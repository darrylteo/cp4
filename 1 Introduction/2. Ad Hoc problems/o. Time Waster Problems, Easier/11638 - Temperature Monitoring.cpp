#include <bits/stdc++.h>

using namespace std;

bool checkActive(const vector<int> &reading, int threshold, int trigger) {
    for (int i: reading) {
        if ((i < threshold && !trigger) || (i > threshold && trigger)) {
            return true;
        }
    }
    return false;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        cout << "Case " << i + 1 << ": ";
        // read data
        int M, S, threshold[4], C, K, active[4], trigger[4], time[100], temp[100];
        string CBin;
        cin >> M >> S >> threshold[0] >> threshold[1] >> threshold[2] >> threshold[3] >> C >> K;
        for (int j = 0; j < K; ++j) {
            cin >> time[j] >> temp[j];
        }
        // convert C to binary and get active and trigger
        CBin = bitset<32>(C).to_string();
        for (int j = 0; j < 4; ++j) {
            active[j] = CBin[CBin.size() - 1 - j] - '0';
            trigger[j] = CBin[CBin.size() - 1 - j - 4] - '0';
        }
        // get temperature readings by sensor based on M, S, time and temp
        // this is the most important. the temp periods useless
        int tmp = 0, currTime = S, maxTime = accumulate(time, time + K, 0);
        vector<int> reading, cumTime;
        for (int j = 0; j < K; ++j) {
            cumTime.push_back(tmp);
            tmp += time[j];
        }
        cumTime.push_back(tmp); // we have K + 1 "intervals"
        cumTime.push_back(maxTime + 1); // to make sure we get the last reading
        while (currTime <= maxTime) {
            // check which interval currTime is in
            int interval = 0;
            while (currTime > cumTime[interval]) {
                interval++;
            }
            // get reading
            if (interval == 0) reading.push_back(temp[0]);
            else reading.push_back(temp[interval - 1]);
            currTime += M;
        }
        // if sensor is active check if reading is within threshold
        string ans;
        for (int j = 0; j < 4; ++j) {
            if (active[j]) {
                if (checkActive(reading, threshold[j], trigger[j])) ans += "yes ";
                else ans += "no ";
            } else {
                ans += "no ";
            }
        }
        ans.pop_back();
        cout << ans << endl;
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}