/*
    [BOJ13460_구슬_탈출_2] - 23.02.11
    * 까다로운 구현 문제. 그와중에 문제를 똑바로 안읽어 정말 해멘 문제.
    * 가장자리에는 항상 '#'이 오며, 10번 초과 움직일 시 -1로 출력해야 하는 것도 정확히 작성해야 함
*/


#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
#include <algorithm>

using namespace std;

enum blockstate {
    wall, path, hole
};

struct position {
    int x;
    int y;
};

struct Node {
    position red;
    position blue;
    int count;
};

int BOARD_X, BOARD_Y;

vector<vector<blockstate>> board;

int dirx[] = {-1,1,0,0};
int diry[] = {0,0,-1,1};

int bfs(position startRed, position startBlue) {
    int ans = -1;

    // visited[x][y] : red가 x, y에 있을 때 blue의 position
    vector<vector<vector<position>>> visited(BOARD_X, vector<vector<position>>(BOARD_Y, vector<position>()));
    queue<Node> q;

    q.push({startRed, startBlue, 0});
    visited[startRed.x][startRed.y].push_back(startBlue);

    while (!q.empty()) {
        Node cur = q.front();
        q.pop();

        if (cur.count >= 10) continue;
        if (ans != -1 && cur.count >= ans) continue;

        for (int dir = 0; dir < 4; dir++) {
            int nextRX = cur.red.x;
            int nextRY = cur.red.y;
            int nextBX = cur.blue.x;
            int nextBY = cur.blue.y;

            // R, B 밀기
            while (board[nextRX][nextRY] == path) {
                nextRX += dirx[dir];
                nextRY += diry[dir];
            }
            while (board[nextBX][nextBY] == path) {
                nextBX += dirx[dir];
                nextBY += diry[dir];
            }
            if (board[nextRX][nextRY] == wall) {
                nextRX -= dirx[dir];
                nextRY -= diry[dir];
            }
            if (board[nextBX][nextBY] == wall) {
                nextBX -= dirx[dir];
                nextBY -= diry[dir];
            }

            if (board[nextBX][nextBY] == hole) continue;

            // R, B 둘 다 같은 위치인 경우 보정
            if (nextRX == nextBX && nextRY == nextBY) {
                int difR = abs(cur.red.x - nextRX) + abs(cur.red.y - nextRY);
                int difB = abs(cur.blue.x - nextBX) + abs(cur.blue.y - nextBY);

                if (difR < difB) {
                    nextBX -= dirx[dir];
                    nextBY -= diry[dir];
                }
                else {
                    nextRX -= dirx[dir];
                    nextRY -= diry[dir];
                }
            }

            // 이미 도달한 위치
            bool flag = false;
            for (position blue : visited[nextRX][nextRY]) {
                if (blue.x == nextBX && blue.y == nextBY) {
                    flag = true;
                    break;
                }
            }
            if (flag) continue;

            if (board[nextRX][nextRY] == hole) {
                if (ans != -1) ans = min(ans, cur.count + 1);
                else ans = cur.count + 1;
            }
            else if (board[nextBX][nextBY] == hole) {
                // none
            }
            else {
                q.push({ {nextRX, nextRY}, {nextBX, nextBY}, cur.count + 1 });
                visited[nextRX][nextRY].push_back({ nextBX, nextBY });
            }
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> BOARD_X >> BOARD_Y;
    board.resize(BOARD_X, vector<blockstate>(BOARD_Y, path));

    position startRed;
    position startBlue;

    char c;
    for (int x = 0; x < BOARD_X; x++) {
        for (int y = 0; y < BOARD_Y; y++) {
            cin >> c;
            switch (c) {
            case '#': board[x][y] = wall; break;
            case 'O': board[x][y] = hole; break;
            case 'R': startRed = { x,y }; break;
            case 'B': startBlue = { x,y }; break;
            }
        }
    }

    cout << bfs(startRed, startBlue);

    return 0;
}