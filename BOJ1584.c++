/*
    [BOJ1584_게임] - 23.01.15
    * 2차원 Dijkstra 구현
*/

#include <iostream>
#include <vector>
#include <queue>

enum Area {
    safe = 0,
    danger = 1,
    dead = 99999,
};

int MAGIC_NUMBER = dead;

struct Node {
    int x;
    int y;
    int dist;
};

struct cmp {
    bool operator()(Node bef, Node aft) {
        return bef.dist > aft.dist;
    }
};

using namespace std;

vector<vector<Area>> board(501, vector<Area>(501, safe));
vector<vector<int>> dij(501, vector<int>(501, MAGIC_NUMBER));
priority_queue<Node, vector<Node>, cmp> pq;

void fillBoard(int x1, int y1, int x2, int y2, Area type) {
    int fromX = min(x1, x2);
    int toX = max(x1, x2);
    int fromY = min(y1, y2);
    int toY = max(y1, y2);

    for (int i = fromX; i <= toX; i++) {
        for (int j = fromY; j <= toY; j++)
            board[i][j] = type;
    }
}

int moveX[4] = { -1,1,0,0 };
int moveY[4] = { 0,0,-1,1 };

void dijkstra() {
    dij[0][0] = 0;
    pq.push({ 0,0,0 });
    
    Node cur;
    while (!pq.empty()) {
        cur = pq.top();
        pq.pop();

        if (cur.x == 500 && cur.y == 500) return;
        if (dij[cur.x][cur.y] < cur.dist) continue;

        for (int i = 0; i < 4; i++) {
            int nextX = cur.x + moveX[i];
            int nextY = cur.y + moveY[i];

            if (nextX < 0 || nextY < 0 || nextX > 500 || nextY > 500) continue;

            int nextDis = dij[cur.x][cur.y] + board[nextX][nextY];

            if (nextDis < dij[nextX][nextY]) {
                dij[nextX][nextY] = nextDis;
                pq.push({ nextX, nextY, nextDis });
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int x1, y1, x2, y2;
    int dangerAreaNum, deathAreaNum;
    
    cin >> dangerAreaNum;
    while (dangerAreaNum--) {
        cin >> x1 >> y1 >> x2 >> y2;
        fillBoard(x1, y1, x2, y2, danger);
    }

    cin >> deathAreaNum;
    while (deathAreaNum--) {
        cin >> x1 >> y1 >> x2 >> y2;
        fillBoard(x1, y1, x2, y2, dead);
    }

    dijkstra();

    if (dij[500][500] == MAGIC_NUMBER) cout << -1;
    else cout << dij[500][500];

    return 0;
}
