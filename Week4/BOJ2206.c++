/*
    [BOJ2206_벽_부수고_이동하기] - 23.01.26
    * 달빛 여우 문제의 dijkstra 제거 버전!
    * bfs로 최단 경로를 구하지만 두 가지 케이스를 고려하는 것이 관건
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef vector<pair<int, int>> vp;

int N, M;
vector<vector<bool>> board;
vector<vp> dp;

int movex[4] = { -1,1,0,0 };
int movey[4] = { 0,0,-1,1 };
void bfs() {
    dp[0][0].first = 0;
    queue<pair<int, int>> q;
    q.push({ 0,0 });

    pair<int, int> cur;
    while (!q.empty()) {
        cur = q.front();
        q.pop();

        int curX = cur.first, curY = cur.second;
        int nextX, nextY;
        for (int i = 0; i < 4; i++) {
            nextX = curX + movex[i];
            nextY = curY + movey[i];
            if (nextX < 0 || nextY < 0 || nextX >= N || nextY >= M) continue;

            if (board[nextX][nextY]) {
                // wall
                if (dp[nextX][nextY].second > dp[curX][curY].first + 1) {
                    dp[nextX][nextY].second = dp[curX][curY].first + 1;
                    q.push({ nextX, nextY });
                }

            }
            else {
                // nonwall
                bool flag = false;
                if (dp[nextX][nextY].first > dp[curX][curY].first + 1) {
                    flag = true;
                    dp[nextX][nextY].first = dp[curX][curY].first + 1;
                }

                if (dp[nextX][nextY].second > dp[curX][curY].second + 1) {
                    flag = true;
                    dp[nextX][nextY].second = dp[curX][curY].second + 1;
                }

                if (flag) q.push({ nextX, nextY });
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    board.resize(N, vector<bool>(M, false));
    dp.resize(N, vp(M, { 999999, 999999 }));

    char c;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> c;
            if (c == '1') board[i][j] = true;
            else board[i][j] = false;
        }
    }

    bfs();
    int minAns = min(dp[N - 1][M - 1].first, dp[N - 1][M - 1].second);
    if (minAns == 999999) minAns = -1;
    else minAns++;
    cout << minAns;

    return 0;
}