#include <bits/stdc++.h>

using namespace std;

string line1, line2, line3, line4, line5, line6, line7;

void encodeOne(char i) {
    if (i == '0') {
        line1 += "xxxxx.";
        line2 += "x...x.";
        line3 += "x...x.";
        line4 += "x...x.";
        line5 += "x...x.";
        line6 += "x...x.";
        line7 += "xxxxx.";
    } else if (i == '1') {
        line1 += "....x.";
        line2 += "....x.";
        line3 += "....x.";
        line4 += "....x.";
        line5 += "....x.";
        line6 += "....x.";
        line7 += "....x.";
    } else if (i == '2') {
        line1 += "xxxxx.";
        line2 += "....x.";
        line3 += "....x.";
        line4 += "xxxxx.";
        line5 += "x.....";
        line6 += "x.....";
        line7 += "xxxxx.";
    } else if (i == '3') {
        line1 += "xxxxx.";
        line2 += "....x.";
        line3 += "....x.";
        line4 += "xxxxx.";
        line5 += "....x.";
        line6 += "....x.";
        line7 += "xxxxx.";
    } else if (i == '4') {
        line1 += "x...x.";
        line2 += "x...x.";
        line3 += "x...x.";
        line4 += "xxxxx.";
        line5 += "....x.";
        line6 += "....x.";
        line7 += "....x.";
    } else if (i == '5') {
        line1 += "xxxxx.";
        line2 += "x.....";
        line3 += "x.....";
        line4 += "xxxxx.";
        line5 += "....x.";
        line6 += "....x.";
        line7 += "xxxxx.";
    } else if (i == '6') {
        line1 += "xxxxx.";
        line2 += "x.....";
        line3 += "x.....";
        line4 += "xxxxx.";
        line5 += "x...x.";
        line6 += "x...x.";
        line7 += "xxxxx.";
    } else if (i == '7') {
        line1 += "xxxxx.";
        line2 += "....x.";
        line3 += "....x.";
        line4 += "....x.";
        line5 += "....x.";
        line6 += "....x.";
        line7 += "....x.";
    } else if (i == '8') {
        line1 += "xxxxx.";
        line2 += "x...x.";
        line3 += "x...x.";
        line4 += "xxxxx.";
        line5 += "x...x.";
        line6 += "x...x.";
        line7 += "xxxxx.";
    } else if (i == '9') {
        line1 += "xxxxx.";
        line2 += "x...x.";
        line3 += "x...x.";
        line4 += "xxxxx.";
        line5 += "....x.";
        line6 += "....x.";
        line7 += "xxxxx.";
    }
}

string encodeAll(string s) {
    string tmp, ansString;
    int ansInt=0;
    for (int i = 0; i < s.size(); i++) {
        tmp += s[i];
        if (s[i] == '+') {
            ansInt = stoi(tmp.substr(0, tmp.size() - 1));
            tmp = "";
        }
    }
    ansInt += stoi(tmp);
    ansString = to_string(ansInt);
    for (int i = 0; i < s.size(); i++) {
        encodeOne(ansString[i]);
    }
    line1.pop_back();
    line2.pop_back();
    line3.pop_back();
    line4.pop_back();
    line5.pop_back();
    line6.pop_back();
    line7.pop_back();
    return line1 + "\n" + line2 + "\n" + line3 + "\n" + line4 + "\n" + line5 + "\n" + line6 + "\n" + line7 + "\n";
}

string decodeOne (const vector<string> &v) {
    if (v[0] == "xxxxx" && v[1] == "x...x" && v[2] == "x...x" && v[3] == "x...x" && v[4] == "x...x" && v[5] == "x...x" && v[6] == "xxxxx") return "0";
    if (v[0] == "....x" && v[1] == "....x" && v[2] == "....x" && v[3] == "....x" && v[4] == "....x" && v[5] == "....x" && v[6] == "....x") return "1";
    if (v[0] == "xxxxx" && v[1] == "....x" && v[2] == "....x" && v[3] == "xxxxx" && v[4] == "x...." && v[5] == "x...." && v[6] == "xxxxx") return "2";
    if (v[0] == "xxxxx" && v[1] == "....x" && v[2] == "....x" && v[3] == "xxxxx" && v[4] == "....x" && v[5] == "....x" && v[6] == "xxxxx") return "3";
    if (v[0] == "x...x" && v[1] == "x...x" && v[2] == "x...x" && v[3] == "xxxxx" && v[4] == "....x" && v[5] == "....x" && v[6] == "....x") return "4";
    if (v[0] == "xxxxx" && v[1] == "x...." && v[2] == "x...." && v[3] == "xxxxx" && v[4] == "....x" && v[5] == "....x" && v[6] == "xxxxx") return "5";
    if (v[0] == "xxxxx" && v[1] == "x...." && v[2] == "x...." && v[3] == "xxxxx" && v[4] == "x...x" && v[5] == "x...x" && v[6] == "xxxxx") return "6";
    if (v[0] == "xxxxx" && v[1] == "....x" && v[2] == "....x" && v[3] == "....x" && v[4] == "....x" && v[5] == "....x" && v[6] == "....x") return "7";
    if (v[0] == "xxxxx" && v[1] == "x...x" && v[2] == "x...x" && v[3] == "xxxxx" && v[4] == "x...x" && v[5] == "x...x" && v[6] == "xxxxx") return "8";
    if (v[0] == "xxxxx" && v[1] == "x...x" && v[2] == "x...x" && v[3] == "xxxxx" && v[4] == "....x" && v[5] == "....x" && v[6] == "xxxxx") return "9";
    else return "+";

}

string decodeAll(const vector<string> &v) {
    string ans;
    int size = v[0].size() / 6 + 1;
    for (int i = 0; i < size; ++i) {
        vector<string> v1;
        for (int j = 0; j < 7; ++j){
            v1.push_back(v[j].substr(i * 6, 5));
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
    for (int i = 0; i < 7; ++i) {
        getline(cin, buf);
        v.push_back(buf);
    }
    string ans = decodeAll(v);
    cout << encodeAll(ans);

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}