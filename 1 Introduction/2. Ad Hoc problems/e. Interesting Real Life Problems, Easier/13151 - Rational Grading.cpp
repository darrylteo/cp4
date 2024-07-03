#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    int t;
    char ival[50];
    cin >> ival >> t;
    while (t) {
        int score = 0, studentAnswer, curr;
        string cmd;

        // convert to decimal
        if (ival[0] == '0' && ival[1] == 'x') sscanf(ival, "%x", &curr);
        else if (ival[0] == '0') sscanf(ival, "%o", &curr);
        else sscanf(ival, "%d", &curr);


        for (int i = 0; i < t; i++) {
            cin >> cmd >> studentAnswer;
            if (cmd == "i") {
                if (studentAnswer == curr) score++;
                else curr = studentAnswer;
            } else if (cmd == "i++") {
                if (studentAnswer == curr) {
                    score++;
                    curr++;
                } else curr = studentAnswer + 1;
            } else if (cmd == "++i") {
                if (studentAnswer == curr + 1) {
                    score++;
                    curr++;
                } else curr = studentAnswer;
            } else if (cmd == "i--") {
                if (studentAnswer == curr) {
                    score++;
                    curr--;
                } else curr = studentAnswer - 1;
            } else if (cmd == "--i") {
                if (studentAnswer == curr - 1) {
                    score++;
                    curr--;
                } else curr = studentAnswer;
            }
        }

        cout << score << endl;
        cin >> ival >> t;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

