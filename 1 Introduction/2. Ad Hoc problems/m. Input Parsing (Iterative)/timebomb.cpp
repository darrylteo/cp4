#include <bits/stdc++.h>

using namespace std;

string decodeOne (const vector<string> &v) {
    if (v[0] == "***" && v[1] == "* *" && v[2] == "* *" && v[3] == "* *" && v[4] == "***") return "0";
    else if (v[0] == "  *" && v[1] == "  *" && v[2] == "  *" && v[3] == "  *" && v[4] == "  *") return "1";
    else if (v[0] == "***" && v[1] == "  *" && v[2] == "***" && v[3] == "*  " && v[4] == "***") return "2";
    else if (v[0] == "***" && v[1] == "  *" && v[2] == "***" && v[3] == "  *" && v[4] == "***") return "3";
    else if (v[0] == "* *" && v[1] == "* *" && v[2] == "***" && v[3] == "  *" && v[4] == "  *") return "4";
    else if (v[0] == "***" && v[1] == "*  " && v[2] == "***" && v[3] == "  *" && v[4] == "***") return "5";
    else if (v[0] == "***" && v[1] == "*  " && v[2] == "***" && v[3] == "* *" && v[4] == "***") return "6";
    else if (v[0] == "***" && v[1] == "  *" && v[2] == "  *" && v[3] == "  *" && v[4] == "  *") return "7";
    else if (v[0] == "***" && v[1] == "* *" && v[2] == "***" && v[3] == "* *" && v[4] == "***") return "8";
    else if (v[0] == "***" && v[1] == "* *" && v[2] == "***" && v[3] == "  *" && v[4] == "***") return "9";
    else return "-"; // boom

}

string decodeAll(const vector<string> &v) {
    string ans;
    int size = v[0].size() / 4 + 1;
    for (int i = 0; i < size; ++i) {
        vector<string> v1;
        for (int j = 0; j < 5; ++j){
            v1.push_back(v[j].substr(i * 4, 3));
        }
        ans += decodeOne(v1);
    }
    return ans;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    string buf;
    vector<string> v;
    for (int i = 0; i < 5; ++i) {
        getline(cin, buf);
        v.push_back(buf);
    }
    string ans = decodeAll(v);
    if (ans.find('-') != string::npos) cout << "BOOM!!" << endl;
    else if (stoi(ans) % 6 == 0) cout << "BEER!!" << endl;
    else cout << "BOOM!!" << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}