#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int cases;
    cin >> cases;
    while (cases--) {
        // i always forget to put maps inside ._. (but i end up wasting 15min to realize this)
        map<string, vector<string>> drivers;
        unordered_map<string, vector<int>> cars;
        int n, m;
        cin >> n >> m;
        for (int _ = 0; _ < n; _++) {
            string s;
            cin >> s;
            cars[s] = vector<int>(3); // catalog, pick up cost, cost per km
            int tmp1, tmp2, tmp3;
            cin >> tmp1 >> tmp2 >> tmp3;
            cars[s][0] = tmp1;
            cars[s][1] = tmp2;
            cars[s][2] = tmp3;
        }
        // i don't think time is used here. anyway get all commands for each driver
        for (int _ = 0; _ < m; _++) {
            string s;
            cin >> s >> s; // don't use time
            string tmp1, tmp2;
            cin >> tmp1 >> tmp2;
            drivers[s].push_back(tmp1 + tmp2);
        }
        // check if valid commands
        for (auto &driver: drivers) {
            cout << driver.first << " ";
            string status; // empty string means he can pick up a car. if is car name means can accident or return
            int cost = 0;
            bool valid = true;
            for (auto &command: driver.second) {
                if (command[0] == 'p') {
                    if (status.empty()) {
                        status = command.substr(1);
                        cost += cars[status][1];
                    } else { // already has a car
                        cout << "INCONSISTENT" << endl;
                        valid = false;
                        break; // don't need check further commands. already problem
                    }
                } else if (command[0] == 'a') {
                    if (status.empty()) { // no car to crash
                        cout << "INCONSISTENT" << endl;
                        valid = false;
                        break;
                    } else { // else find cost to pay
                        cost += ceil(stoi(command.substr(1)) * cars[status][0] / 100.0);
                    }
                } else if (command[0] == 'r') {
                    if (status.empty()) { // no car to return
                        cout << "INCONSISTENT" << endl;
                        valid = false;
                        break;
                    } else {
                        cost += stoi(command.substr(1)) * cars[status][2];
                        status = "";
                    }
                }
            }
            if (!valid) continue;
            if (!status.empty()) { // if still has a car
                cout << "INCONSISTENT" << endl;
            } else {
                cout << cost << endl;
            }
        }
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
