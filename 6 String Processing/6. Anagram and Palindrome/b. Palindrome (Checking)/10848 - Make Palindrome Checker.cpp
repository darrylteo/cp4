#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(string s) {
    for (int i = 0; i < s.size() / 2; i++) {
        if (s[i] != s[s.size() - i - 1]) {
            return false;
        }
    }
    return true;
}

bool allIsDigit(string s) {
    if (s.empty() || s.size() > 1e8) return false; // important bug. else stoi(aa) will runtime error
    for (char i: s) {
        if (!isdigit(i)) return false;
    }
    return true;
}

bool allIsLower(string s) {
    for (char i: s) {
        if (i < 'a' || i > 'z') return false;
    }
    return true;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    string s1, s2, buf, aa;
    int a;
    while (getline(cin, buf)) {
        // property 1
        s1 = s2 = aa = "";
        a = -1;
        int z = 0;
        string ans;
        for (char i: buf) {
            if (i == ' ') {
                z++;
            } else {
                if (z == 0) s1 += i;
                if (z == 1) aa += i;
                if (z == 2) s2 += i;
            }
        }
        if (allIsDigit(aa) && aa.size() < 5) a = stoi(aa);
        if (z != 2 || a < 0 || a > 1000 || s1.size() > 1000 || s2.size() > 2000 || !allIsLower(s1) || !allIsLower(s2)) {
            cout << "FFFFFFF The solution is not accepted\n";
            continue;
        } else {
            ans += 'T';
        }

        // property 2
        if (isPalindrome(s2)) ans += 'T';
        else ans += 'F';

        // property 3
        vector<int> s1_freq(26, 0), s2_freq(26, 0);
        for (char i: s1) s1_freq[i - 'a']++;
        for (char i: s2) s2_freq[i - 'a']++;
        bool flag = true;
        for (int i = 0; i < 26; i++) {
            if (s1_freq[i] && !s2_freq[i]) {
                flag = false;
                break;
            }
        }
        if (flag) ans += 'T';
        else ans += 'F';

        // property 4
        flag = true;
        for (int i = 0; i < 26; i++) {
            if (s1_freq[i] > s2_freq[i]) {
                flag = false;
                break;
            }
        }
        if (flag) ans += 'T';
        else ans += 'F';

        // property 5
        int j = 0, fail = 0;
        for (char c: s1) {
            while (j < s2.size() && s2[j] != c) j++;
            if (j == s2.size()) {
                ans += 'F';
                fail = 1;
                break;
            }
            j++;
        }
        if (!fail) ans += 'T';

        // property 6
        if (s1.size() + a == s2.size()) ans += 'T';
        else ans += 'F';

        // property 7
        if (a < s1.size()) ans += 'T';
        else ans += 'F';

        if (ans == "TTTTTTT") cout << "TTTTTTT The solution is accepted\n";
        else cout << ans << " The solution is not accepted\n";
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}
