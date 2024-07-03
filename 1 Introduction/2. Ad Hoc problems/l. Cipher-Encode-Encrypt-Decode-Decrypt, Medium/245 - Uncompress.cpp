#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    string buf, word, num;
    vector<string> words;
    set<string> s; // just to detect if a word is already in the vector
    while (getline(cin, buf), buf != "0") {
        for (int i = 0; i < buf.size(); i++) {
            // if it is a letter, keep adding to the word
            if (isalpha(buf[i])) {
                while (isalpha(buf[i])) {
                    word += buf[i];
                    i++;
                }
                i--; // to compensate for the increment in the while loop

                if (s.insert(word).second) { // if not in set this returns true
                    words.push_back(word);
                } else {
                    words.erase(find(words.begin(), words.end(), word));
                    words.push_back(word);
                }
                cout << word;
                word = "";
            } else if (isdigit(buf[i])) {
                num = "";
                while (isdigit(buf[i])) { // keep checking until we get full number
                    num += buf[i];
                    i++;
                }
                i--; // to compensate for the increment in the while loop
                string wordToReplace = words[words.size() - stoi(num)];
                words.erase(words.end() - stoi(num));
                words.push_back(wordToReplace);
                cout << wordToReplace;
            } else {
                cout << buf[i];
            }
        }
        cout << endl;
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}