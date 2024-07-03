#include <bits/stdc++.h>

using namespace std;

// strategy:
// if currHeight is less than top of stack, this is a candidate mountain
// collect best candidate and if u get match, update currMax
// the min resets when u finish matching all current mountains (mountain i match everything before i)
// seems like need to do this twice, once from left and once from right
// example: 5 1 9 2 5... from left is 4, from right is 3
// there are bimodal run times in kattis, probably similar method but some 1 loop some double like me
// maybe can do 1 loop if u start from tallest mountain and go left and right

int solveLeft(const vector<int>& heights){
    int overallMax = 0, currHeight, currMin;
    stack<int> s;
    for (int i = 0; i < heights.size(); i++) {
        currHeight = heights[i];
        if (s.empty() || currHeight >= s.top()) { // match
            while (!s.empty() && currHeight >= s.top()) {
                overallMax = max(overallMax, s.top() - currMin);
                s.pop();
            }
            if (s.empty()) {
                currMin = currHeight;
            }
            s.push(currHeight);
        } else { // no match (too short)
            currMin = min(currMin, currHeight);
            s.push(currHeight);
        }
    }
    return overallMax;
}

int solveRight(vector<int> heights){
    int overallMax = 0, currHeight, currMin;
    stack<int> s;
    for (int i = heights.size() - 1; i >= 0; i--) {
        currHeight = heights[i];
        if (s.empty() || currHeight >= s.top()) { // match
            while (!s.empty() && currHeight >= s.top()) {
                overallMax = max(overallMax, s.top() - currMin);
                s.pop();
            }
            if (s.empty()) {
                currMin = currHeight;
            }
            s.push(currHeight);
        } else { // no match (too short)
            currMin = min(currMin, currHeight);
            s.push(currHeight);
        }
    }
    return overallMax;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    int n;
    cin >> n;
    vector<int> heights(n);
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }

    cout << max(solveLeft(heights), solveRight(heights)) << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
