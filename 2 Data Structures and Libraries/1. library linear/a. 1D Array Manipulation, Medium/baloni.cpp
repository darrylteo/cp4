#include <bits/stdc++.h>

using namespace std;

// if throw dart at ballon x1 at height n, if a later ballon xn at height n-1 exists
// it is counted within same throw and we propagate the dart to height n-1 and remove from height n
// finally we count the number of "darts" at each height

// note this is just a quick way to count the naive strategy of throwing a dart at next ballon from left
// fortunately it is the optimal strategy

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    int N;
    cin >> N;
    vector<int> heights;
    heights.assign(1000005, 0);

    for (int i = 0; i < N; i++) {
        int n;
        cin >> n;
        if (heights[n] > 0){
            heights[n]--;
        }
        heights[n-1]++; // propagate dart to lower height
    }

    cout << accumulate(heights.begin(), heights.end(), 0) << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}



// p.s. ballon is a reference to a pokemon youtuber haydunn
// https://www.youtube.com/watch?v=06u2Cb7kmlA