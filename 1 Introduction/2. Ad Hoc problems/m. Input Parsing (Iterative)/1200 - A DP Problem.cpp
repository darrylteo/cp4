#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    string buf, word, num;
    vector<string> words;
    int n;
    cin >> n;
    while (n--) {
        getline(cin>>ws, buf);
        int xLeft = 0, xRight = 0, numLeft = 0, numRight = 0, pastEqual = 0, sign = 1;
        for (int i = 0; i < buf.size(); i++) {
            // if it is not symbol, keep adding to the word
            // here, word is just a string of numbers and x at end or just numbers
            if (buf[i] == '=') {
                sign = 1;
                pastEqual = 1;
            }
            if (buf[i] == '-') sign = -1;
            if (buf[i] == '+') sign = 1;
            if (isalnum(buf[i])) {
                while (isalnum(buf[i])) {
                    word += buf[i];
                    i++;
                }
                i--; // to compensate for the increment in the while loop

                if (word == "x" && sign == 1) {
                    if (!pastEqual) xLeft++;
                    else xRight++;
                } else if (word == "x" && sign == -1) {
                    if (!pastEqual) xLeft--;
                    else xRight--;
                } else if (!word.empty() && sign == 1) {
                    if (!pastEqual && word[word.size() - 1] == 'x') xLeft += stoi(word.substr(0, word.size() - 1));
                    else if (!pastEqual) numLeft += stoi(word);
                    else if (word[word.size() - 1] == 'x') xRight += stoi(word.substr(0, word.size() - 1));
                    else numRight += stoi(word);
                } else if (!word.empty() && sign == -1) {
                    if (!pastEqual && word[word.size() - 1] == 'x') xLeft -= stoi(word.substr(0, word.size() - 1));
                    else if (!pastEqual) numLeft -= stoi(word);
                    else if (word[word.size() - 1] == 'x') xRight -= stoi(word.substr(0, word.size() - 1));
                    else numRight -= stoi(word);
                }
                word = "";
            }
        }
        // finally we can come up with the answer to three cases
        if (xLeft == xRight && numLeft == numRight) cout << "IDENTITY" << endl;
        else if (xLeft == xRight && numLeft != numRight) cout << "IMPOSSIBLE" << endl;
        else {
            int ans = floor(((double)numRight - numLeft) / (xLeft - xRight));
            cout << ans << endl;
        }
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}