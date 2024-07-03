#include <bits/stdc++.h>

using namespace std;

int main() {

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int M, Q;
    cin >> M >> Q;
    vector<string> movies(M), queries(Q);
    for (int i = 0; i < M; ++i) {
        cin >> movies[i];
    }
    for (int i = 0; i < Q; ++i) {
        cin >> queries[i];
    }

    for (const string& query: queries) {
        vector<int> similarityScore;
        for (const string& movie: movies) {
            if (query.size() > movie.size()) {
                similarityScore.push_back(0);
                continue;
            }
            int bestScore = 0, displacements = movie.size() - query.size();
            for (int i = 0; i <= displacements; ++i) {
                int score = 0;
                // we push query to the right by comparing to the right of movie
                for (int j = 0; j < query.size(); ++j) {
                    if (query[j] == movie[i + j]) {
                        score++;
                    }
                }
                bestScore = max(bestScore, score);
            }
            similarityScore.push_back(bestScore);
        }
        int maxScore = *max_element(similarityScore.begin(), similarityScore.end());
        for (int i = 0; i < similarityScore.size(); ++i) {
            if (similarityScore[i] == maxScore) {
                cout << i + 1 << '\n';
                break;
            }
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}
