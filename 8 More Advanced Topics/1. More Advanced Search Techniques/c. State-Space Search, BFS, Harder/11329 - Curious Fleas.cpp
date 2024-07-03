#include <bits/stdc++.h>

using namespace std;

// EWSN
vector<int> dirx = {0, 0, 1, -1};
vector<int> diry = {1, -1, 0, 0};

// returns the current die after moving in the given direction
// no add or remove fleas
bitset<6> roll(bitset<6> die, int dir) {
    bitset<6> new_die = die;
    // die: bottom, top, left, front, right, back
    switch (dir) {
        case 0: // east. front (3) and back (5) no change
            new_die[0] = die[4];
            new_die[2] = die[0];
            new_die[1] = die[2];
            new_die[4] = die[1];
            break;
        case 1: // west. front (3) and back (5) no change
            new_die[0] = die[2];
            new_die[2] = die[1];
            new_die[1] = die[4];
            new_die[4] = die[0];
            break;
        case 2: // south. left (2) and right (4) no change
            new_die[0] = die[3];
            new_die[3] = die[1];
            new_die[1] = die[5];
            new_die[5] = die[0];
            break;
        case 3: // north. left (2) and right (4) no change
            new_die[0] = die[5];
            new_die[3] = die[0];
            new_die[1] = die[3];
            new_die[5] = die[1];
            break;
        default:
            break;
    }
    return new_die;
}

struct hashh {
    size_t operator()(const tuple<int, int, bitset<6>, bitset<16>> &t) const {
        size_t h = 0;
        h ^= hash<int>()(get<0>(t)) + 0x9e3779b9 + (h << 6) + (h >> 2);
        h ^= hash<int>()(get<1>(t)) + 0x9e3779b9 + (h << 6) + (h >> 2);
        h ^= hash<bitset<6>>()(get<2>(t)) + 0x9e3779b9 + (h << 6) + (h >> 2);
        h ^= hash<bitset<16>>()(get<3>(t)) + 0x9e3779b9 + (h << 6) + (h >> 2);
        return h;
    }
};

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        vector<string> board;
        for (int i = 0; i < 4; i++) {
            string s;
            cin >> s;
            board.push_back(s);
        }
        int x, y; // pos of die
        bitset<6> die; // start with 0 fleas on the die
        bitset<16> fleas; // initial pos of fleas
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (board[i][j] == 'D') {
                    x = i;
                    y = j;
                }
                if (board[i][j] == 'X') fleas[i * 4 + j] = true;
            }
        }

        // the state of the system may be uniquely determined by (x, y, die, fleas)
        unordered_map<tuple<int, int, bitset<6>, bitset<16>>, int, hashh> dist;
        queue<tuple<int, int, bitset<6>, bitset<16>>> q;
        q.emplace(x, y, die, fleas);
        dist[{x, y, die, fleas}] = 0;
        int found = 0;
        while (!q.empty()) {
            auto [x, y, die, fleas] = q.front();
            if (fleas == 0) {
                cout << dist[{x, y, die, fleas}] << endl;
                found = 1;
                break;
            }
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x + dirx[i];
                int ny = y + diry[i];
                if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4) continue;
                bitset<6> new_die = roll(die, i);
                bitset<16> new_fleas = fleas;
                int die_flea = new_die[0], floor_flea = new_fleas[nx * 4 + ny];
                if (die_flea && floor_flea) { // die to floor and floor to die
                    // IMPORTANT DO NOTHING HERE. I PUT CONTINUE AND SPENT 1H DEBUGGING
                } else if (die_flea) { // die to floor
                    new_die[0] = false;
                    new_fleas[nx * 4 + ny] = true;
                } else if (floor_flea) { // floor to die
                    new_die[0] = true;
                    new_fleas[nx * 4 + ny] = false;
                }
                if (dist.find({nx, ny, new_die, new_fleas}) == dist.end()) {
                    dist[{nx, ny, new_die, new_fleas}] = dist[{x, y, die, fleas}] + 1;
                    q.emplace(nx, ny, new_die, new_fleas);
                }
            }
        }
        if (!found) {
            cout << "impossible" << endl;
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}