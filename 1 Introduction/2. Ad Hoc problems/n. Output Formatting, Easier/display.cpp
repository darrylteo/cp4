#include <bits/stdc++.h>

using namespace std;

string line1, line2, line3, line4, line5, line6, line7;

void reset() {
    line1 = "";
    line2 = "";
    line3 = "";
    line4 = "";
    line5 = "";
    line6 = "";
    line7 = "";
}

void encodeOne(char i) {
    if (i == '0') {
        line1 += "+---+  ";
        line2 += "|   |  ";
        line3 += "|   |  ";
        line4 += "+   +  ";
        line5 += "|   |  ";
        line6 += "|   |  ";
        line7 += "+---+  ";
    } else if (i == '1') {
        line1 += "    +  ";
        line2 += "    |  ";
        line3 += "    |  ";
        line4 += "    +  ";
        line5 += "    |  ";
        line6 += "    |  ";
        line7 += "    +  ";
    } else if (i == '2') {
        line1 += "+---+  ";
        line2 += "    |  ";
        line3 += "    |  ";
        line4 += "+---+  ";
        line5 += "|      ";
        line6 += "|      ";
        line7 += "+---+  ";
    } else if (i == '3') {
        line1 += "+---+  ";
        line2 += "    |  ";
        line3 += "    |  ";
        line4 += "+---+  ";
        line5 += "    |  ";
        line6 += "    |  ";
        line7 += "+---+  ";
    } else if (i == '4') {
        line1 += "+   +  ";
        line2 += "|   |  ";
        line3 += "|   |  ";
        line4 += "+---+  ";
        line5 += "    |  ";
        line6 += "    |  ";
        line7 += "    +  ";
    } else if (i == '5') {
        line1 += "+---+  ";
        line2 += "|      ";
        line3 += "|      ";
        line4 += "+---+  ";
        line5 += "    |  ";
        line6 += "    |  ";
        line7 += "+---+  ";
    } else if (i == '6') {
        line1 += "+---+  ";
        line2 += "|      ";
        line3 += "|      ";
        line4 += "+---+  ";
        line5 += "|   |  ";
        line6 += "|   |  ";
        line7 += "+---+  ";
    } else if (i == '7') {
        line1 += "+---+  ";
        line2 += "    |  ";
        line3 += "    |  ";
        line4 += "    +  ";
        line5 += "    |  ";
        line6 += "    |  ";
        line7 += "    +  ";
    } else if (i == '8') {
        line1 += "+---+  ";
        line2 += "|   |  ";
        line3 += "|   |  ";
        line4 += "+---+  ";
        line5 += "|   |  ";
        line6 += "|   |  ";
        line7 += "+---+  ";
    } else if (i == '9') {
        line1 += "+---+  ";
        line2 += "|   |  ";
        line3 += "|   |  ";
        line4 += "+---+  ";
        line5 += "    |  ";
        line6 += "    |  ";
        line7 += "+---+  ";
    }
}

string encodeAll(string s) {
    reset();
    for (int i = 0; i < s.size(); i++) {
        encodeOne(s[i]);
        if (i == 2) {
            line1 += "   ";
            line2 += "   ";
            line3 += "o  ";
            line4 += "   ";
            line5 += "o  ";
            line6 += "   ";
            line7 += "   ";
        }
    }
    line1.pop_back();
    line2.pop_back();
    line3.pop_back();
    line4.pop_back();
    line5.pop_back();
    line6.pop_back();
    line7.pop_back();
    line1.pop_back();
    line2.pop_back();
    line3.pop_back();
    line4.pop_back();
    line5.pop_back();
    line6.pop_back();
    line7.pop_back();
    return line1 + "\n" + line2 + "\n" + line3 + "\n" + line4 + "\n" + line5 + "\n" + line6 + "\n" + line7 + "\n";
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    string s;
    int first = 1;
    while (cin >> s) {
        if (first != 1) cout << endl << endl;
        first = 0;
        if (s == "end") {
            break;
        }
        cout << encodeAll(s);
    }
    cout << "end" << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}