#include <bits/stdc++.h>

using namespace std;

// 1. gather all words in vector, unique in unordered_set
// 2. have 2 pointers, start and end. dynamic size sliding window
// 3. move end pointer until all words are covered
// 4. move start pointer until 1 word is removed
// 5. if this is less than current min, replace p and q by start and end
// 6. repeat 3-5 until end pointer reaches end of vector

// close to TLE

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string buf;
    getline(cin, buf);
    n = stoi(buf);
    for (int i = 1; i <= n; i++) {
        cout << "Document " << i << ": ";
        int p, q, min = INT_MAX, start = 0, end = 0;
        vector<string> words;
        words.reserve(100000);
        unordered_set<string> unique;
        string s;
        while (getline(cin, s)) {
            if (s == "END") break;
            std::regex re("[^a-z]");
            std::sregex_token_iterator first{s.begin(), s.end(), re, -1}, last;//the '-1' is what makes the regex split (-1 := what was not matched)
            std::vector<std::string> tokens{first, last};
            for (auto &token : tokens) {
                if (token.empty()) continue;
                words.push_back(token);
                unique.insert(token);
            }
        }

        if (unique.size() == 0) {
            cout << "0 0" << endl;
            continue;
        }

        unordered_map<string, int> freq;
        int uniqueCnt = unique.size(), cnt = 0;
        while (start < words.size() && end < words.size()) {
            while (end < words.size() && cnt < uniqueCnt) {
                if (freq[words[end]] == 0) cnt++; // keep shifting end ptr right until all words are covered
                freq[words[end]]++;
                end++;
            }
            while (start < words.size() && cnt == uniqueCnt) {
                if (freq[words[start]] == 1) cnt--; // keep shifting start ptr right until 1 word is removed
                freq[words[start]]--;
                start++;
            }
            if (end - start + 1 < min) {
                min = end - start + 1;
                p = start;
                q = end;
            }
        }
        cout << p << " " << q << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}