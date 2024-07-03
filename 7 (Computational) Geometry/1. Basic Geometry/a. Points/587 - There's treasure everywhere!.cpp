#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    string s;
    int cases = 1;
    while (cin >> s) {
        if (s == "END") break;
        vector<string> cmd;
        stringstream ss(s);
        string word;
        while (getline(ss, word, ',')) {
            cmd.push_back(word);
        }
        cmd.back().pop_back(); // remove the full stop
        double x = 0, y = 0;
        for (string &c : cmd) {
            string tmp, dir;
            int dist;
            for (char &ch : c) {
                if (isdigit(ch)) tmp.push_back(ch);
                else dir.push_back(ch);
            }
            dist = stoi(tmp);
            if (dir == "N") y += dist;
            else if (dir == "S") y -= dist;
            else if (dir == "E") x += dist;
            else if (dir == "W") x -= dist;
            else if (dir == "NE") {
                x += dist * sqrt(2) / 2;
                y += dist * sqrt(2) / 2;
            } else if (dir == "NW") {
                x -= dist * sqrt(2) / 2;
                y += dist * sqrt(2) / 2;
            } else if (dir == "SE") {
                x += dist * sqrt(2) / 2;
                y -= dist * sqrt(2) / 2;
            } else if (dir == "SW") {
                x -= dist * sqrt(2) / 2;
                y -= dist * sqrt(2) / 2;
            }
        }
        cout << "Map #" << cases++ << endl;
        cout << "The treasure is located at (" << fixed << setprecision(3) << x << "," << y << ")." << endl;
        cout << "The distance to the treasure is " << fixed << setprecision(3) << sqrt(x * x + y * y) << "." << endl;
        cout << endl;
    }



    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}