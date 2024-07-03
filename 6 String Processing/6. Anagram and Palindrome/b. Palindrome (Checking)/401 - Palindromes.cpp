#include <bits/stdc++.h>

using namespace std;

map<char, char> mirror = {
    {'A', 'A'}, {'E', '3'}, {'H', 'H'}, {'I', 'I'}, {'J', 'L'}, {'L', 'J'},
    {'M', 'M'}, {'O', 'O'}, {'S', '2'}, {'T', 'T'}, {'U', 'U'}, {'V', 'V'},
    {'W', 'W'}, {'X', 'X'}, {'Y', 'Y'}, {'Z', '5'}, {'1', '1'}, {'2', 'S'},
    {'3', 'E'}, {'5', 'Z'}, {'8', '8'}
};

bool isPalindrome(string s) {
    for (int i = 0; i < s.size() / 2; i++) {
        if (s[i] != s[s.size() - i - 1]) {
            return false;
        }
    }
    return true;
}

bool isMirrored(string s) {
    for (int i = 0; i < s.size(); i++) {
        if (mirror.find(s[i]) == mirror.end() || mirror[s[i]] != s[s.size() - i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    string s;
    while (cin >> s) {
        bool palindrome = isPalindrome(s);
        bool mirrored = isMirrored(s);

        cout << s << " -- is ";
        if (!palindrome && !mirrored) {
            cout << "not a palindrome.\n";
        } else if (palindrome && !mirrored) {
            cout << "a regular palindrome.\n";
        } else if (!palindrome && mirrored) {
            cout << "a mirrored string.\n";
        } else {
            cout << "a mirrored palindrome.\n";
        }
        cout << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}
