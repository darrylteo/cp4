#include <bits/stdc++.h>

using namespace std;

int firstVowel (string word) {
    for (int i = 0; i < word.length(); i++) {
        if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' ||
            word[i] == 'o' || word[i] == 'u' || word[i] == 'y') {
            return i;
        }
    }
    return -1;
}

string wordToPig (string word) {
    string pigWord = word;
    if (word[0] == 'a' || word[0] == 'e' || word[0] == 'i' ||
        word[0] == 'o' || word[0] == 'u' || word[0] == 'y') {
        pigWord += "yay";
    } else {
        int first = firstVowel(word);
        pigWord = word.substr(first, word.length() - first) + word.substr(0, first) + "ay";
    }
    return pigWord;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    string s;
    while (getline(cin, s)) {
        istringstream iss(s);
        string word;
        while (iss >> word) {
            cout << wordToPig(word) << " ";
        }
        cout << endl;
    }

}


