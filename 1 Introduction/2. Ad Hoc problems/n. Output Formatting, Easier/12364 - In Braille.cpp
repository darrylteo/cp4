#include <bits/stdc++.h>

using namespace std;

string decodeOne(const vector<string> &v) {
    if (v[0] == "*." && v[1] == ".." && v[2] == "..") return "1";
    else if (v[0] == "*." && v[1] == "*." && v[2] == "..") return "2";
    else if (v[0] == "**" && v[1] == ".." && v[2] == "..") return "3";
    else if (v[0] == "**" && v[1] == ".*" && v[2] == "..") return "4";
    else if (v[0] == "*." && v[1] == ".*" && v[2] == "..") return "5";
    else if (v[0] == "**" && v[1] == "*." && v[2] == "..") return "6";
    else if (v[0] == "**" && v[1] == "**" && v[2] == "..") return "7";
    else if (v[0] == "*." && v[1] == "**" && v[2] == "..") return "8";
    else if (v[0] == ".*" && v[1] == "*." && v[2] == "..") return "9";
    else if (v[0] == ".*" && v[1] == "**" && v[2] == "..") return "0";
    else return "-";

}

string decodeAll(const vector<string> &v) {
    string ans;
    int size = v[0].size() / 3 + 1;
    for (int i = 0; i < size; ++i) {
        vector<string> v1;
        for (int j = 0; j < 3; ++j) {
            v1.push_back(v[j].substr(i * 3, 2));
        }
        ans += decodeOne(v1);
    }
    return ans;
}

string encodeAll(string s) {
    string line1, line2, line3;
    for (char i: s) {
        if (i == '1') {
            line1 += "*. ";
            line2 += ".. ";
            line3 += ".. ";
        } else if (i == '2') {
            line1 += "*. ";
            line2 += "*. ";
            line3 += ".. ";
        } else if (i == '3') {
            line1 += "** ";
            line2 += ".. ";
            line3 += ".. ";
        } else if (i == '4') {
            line1 += "** ";
            line2 += ".* ";
            line3 += ".. ";
        } else if (i == '5') {
            line1 += "*. ";
            line2 += ".* ";
            line3 += ".. ";
        } else if (i == '6') {
            line1 += "** ";
            line2 += "*. ";
            line3 += ".. ";
        } else if (i == '7') {
            line1 += "** ";
            line2 += "** ";
            line3 += ".. ";
        } else if (i == '8') {
            line1 += "*. ";
            line2 += "** ";
            line3 += ".. ";
        } else if (i == '9') {
            line1 += ".* ";
            line2 += "*. ";
            line3 += ".. ";
        } else if (i == '0') {
            line1 += ".* ";
            line2 += "** ";
            line3 += ".. ";
        }
    }
    line1.pop_back();
    line2.pop_back();
    line3.pop_back();
    return line1 + "\n" + line2 + "\n" + line3 + "\n";
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    int n;
    while (cin >> n, n) {
        string s, ans;
        cin >> s;
        if (s == "S") {
            cin >> s;
            cout << encodeAll(s);
        } else {
            string buf;
            vector<string> v;
            for (int i = 0; i < 3; ++i) {
                getline(cin >> ws, buf);
                v.push_back(buf);
            }
            cout << decodeAll(v) << endl;
        }
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}