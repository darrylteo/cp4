#include <bits/stdc++.h>

using namespace std;

// if you look at the table in terms of 0s and 1s its clearly binary
// it starts from bottom up... e.g. 1st letter is 01001100 = 76 = L
//    0100010110100110100101101010110101001
//    0000001000010101000000100100001010000
//    1001111000110011011001001100100010110
//    1001100100010000111000000100100001110
//    0000011000000101000000101000001010000
//    0010000001001000000010010001000000000
//    1101111110110111111101101110111111111
//    0000000000000000000000000000000000000
string matrixToMessage(vector<string> matrix) {
    string message = "";
    for (int i = 0; i < matrix[0].size(); i++) {
        int num = 0;
        for (int j = 7; j >= 0; j--) {
            num += (matrix[j][i] - '0') * pow(2, j);
        }
        message += (char) num;
    }
    return message;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    int n;
    cin >> n;
    while (n--) {
        vector<string> matrix;
        string s;
        cin >> s;
        for (int i = 0; i < 8; i++) {
            cin >> s;
            s = s.substr(1, s.size() - 2);
            for (int j = 0; j < s.size(); j++) {
                if (s[j] == '/') {
                    s[j] = '0';
                } else {
                    s[j] = '1';
                }
            }
            matrix.push_back(s);
        }

        cout << matrixToMessage(matrix);
        cout << endl;

        cin >> s; // clear newline
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}


