#include <bits/stdc++.h>

using namespace std;

struct record{
    string dateTime;
    int hour, enter, distance;
};

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string buf;
    getline(cin, buf);
    n = stoi(buf);
    getline(cin, buf);
    while (n--) {
        vector<int> cost(24);
        map<string, vector<record>> records;
        getline(cin, buf);
        stringstream ss(buf);
        for (int i = 0; i < 24; i++) {
            int x;
            ss >> x;
            cost[i] = x;
        }
        string car;
        while (getline(cin, buf) && buf != "") {
            stringstream ss(buf);
            record r;
            ss >> car >> r.dateTime;
            string s;
            ss >> s;
            if (s == "enter") {
                r.enter = 1;
            } else {
                r.enter = 0;
            }
            ss >> r.distance;
            r.hour = stoi(r.dateTime.substr(6, 2));
            records[car].push_back(r);
        }
        for(auto &i: records){
            sort(i.second.begin(), i.second.end(), [](record a, record b){
                return a.dateTime < b.dateTime;
            });
        }
        for(auto &i: records){
            bool used = false;
            int bill = 200; // everyone has to pay this if use road
            for(int j = 0; j < i.second.size(); j++){
                if(i.second[j].enter == 1 && j + 1 < i.second.size() && i.second[j + 1].enter == 0){
                    bill += 100; // per trip cost
                    bill += abs(i.second[j + 1].distance - i.second[j].distance) * cost[i.second[j].hour]; // charged rate of entry time
                    used = true;
                }
            }
            if(used){
                cout << i.first << " $" << bill / 100 << "." << setw(2) << setfill('0') << bill % 100 << endl;
            }
        }
        if(n != 0){
            cout << endl;
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}