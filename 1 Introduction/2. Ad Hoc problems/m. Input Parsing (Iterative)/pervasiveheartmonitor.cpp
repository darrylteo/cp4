#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    string buf, s;
    while (getline(cin, buf)) {
        string name;
        vector<double> v;
        stringstream ss(buf);
        while (ss >> s) {
            if (isalpha(s[0])) name += s + " ";
            else v.push_back(stod(s));;
        }

        cout << fixed << setprecision(6) << accumulate(v.begin(), v.end(), 0.0) / v.size() << " ";

        name = name.substr(0, name.size() - 1);
        cout << name << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}