#include <bits/stdc++.h>

using namespace std;

string wordToPig(string word) {
    if (word[0] == 'A' || word[0] == 'E' || word[0] == 'I' || word[0] == 'O' || word[0] == 'U' ||
        word[0] == 'a' || word[0] == 'e' || word[0] == 'i' || word[0] == 'o' || word[0] == 'u') {
        word += "ay";
    } else {
        word = word.substr(1, word.length() - 1) + word[0] + "ay";
    }
    for (int i = 0; i < word.length(); i++) {
        if (!isalpha(word[i])) {
            word = word.substr(0, i) + word.substr(i + 1, word.length() - i - 1) + word[i];
        }
    }
    return word;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    string buf, word, num;
    vector<string> words;
    set<string> s; // just to detect if a word is already in the vector
    while (getline(cin, buf)) {
        for (int i = 0; i < buf.size(); i++) {
            // if it is a letter, keep adding to the word
            if (isalpha(buf[i])) {
                while (isalpha(buf[i])) {
                    word += buf[i];
                    i++;
                }
                i--; // to compensate for the increment in the while loop
                word = wordToPig(word);
                cout << word;
                word = "";
            } else {
                cout << buf[i];
            }
            
        }
        cout << endl;
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}