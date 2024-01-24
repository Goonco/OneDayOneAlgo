/*
    [BOJ7562_나이트의_이동] - 23.01.24
    * 부등호와 등호의 차이로 하나는 메모리 초과 하나는 성공하는 경우가 있다?!
*/

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <utility>
#include <algorithm>

using namespace std;
int BOARD_LEN;
int fromx, fromy;
int tox, toy;

vector<vector<int>> board;

int movex[8] = { -2,-1,1,2,2,1,-1,-2 };
int movey[8] = { -1,-2,-2,-1,1,2,2,1 };
void moveNight() {
    board[fromx][fromy] = 0;

    queue<pair<int, int>> q;
    q.push({ fromx, fromy });

    pair<int, int> cur;
    while (!q.empty()) {
        cur = q.front();
        q.pop();

        if (cur.first == tox && cur.second == toy) break;

        if (board[cur.first][cur.second] >= board[tox][toy]) continue;
        for (int i = 0; i < 8; i++) {
            int nextx = cur.first + movex[i];
            int nexty = cur.second + movey[i];

            if (nextx < 0 || nexty < 0 || nextx >= board.size() || nexty >= board[0].size()) continue;

            if (board[nextx][nexty] > board[cur.first][cur.second] + 1) {
                board[nextx][nexty] = board[cur.first][cur.second] + 1;
                q.push({ nextx, nexty });
            }

        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int TEST_CASE;
    cin >> TEST_CASE;

    while (TEST_CASE--) {
        cin >> BOARD_LEN;
        cin >> fromx >> fromy;
        cin >> tox >> toy;

        board.clear();
        board.resize(BOARD_LEN, vector<int>(BOARD_LEN, INT_MAX));
        moveNight();

        cout << board[tox][toy] << "\n";
    }

    return 0;
}