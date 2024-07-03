#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    int p;
    cin >> p;
    while (p--) {
        next:
        deque<string> dq;
        string command;
        cin >> command;
        int n;
        cin >> n;
        string buf, s;
        cin >> buf;
        for (int i = 1; i < buf.size(); ++i) { // 1 to skip [
            if (buf[i] == ',' || buf[i] == ']') {
                dq.push_back(s);
                s = "";
                continue;
            }
            s += buf[i];
        }
        if (dq.back() == "") dq.pop_back(); // if empty
        bool forward = true;
        bool end = false;
        for (int i = 0; i < command.size(); ++i) {
            if (command[i] == 'R') {
                forward = !forward;
            } else {
                if (dq.empty()) {
                    cout << "error\n";
                    end = true;
                    break;
                }
                if (forward) dq.pop_front();
                else dq.pop_back();
            }
        }
        if (end) continue;
        cout << "[";
        if (forward) {
            while (!dq.empty()) {
                cout << dq.front();
                dq.pop_front();
                if (!dq.empty()) cout << ",";
            }
        } else {
            while (!dq.empty()) {
                cout << dq.back();
                dq.pop_back();
                if (!dq.empty()) cout << ",";
            }
        }
        cout << "]\n";

    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
