/*
    [BOJ18405_경쟁적_전염] - 23.01.25
    * DFS 문제 맞나..? priority queue 이용
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct virus {
    int type;
    int x;
    int y;
};

struct cmp {
    bool operator()(virus bef, virus aft) {
        return bef.type > aft.type;
    }
};

int BOARD_LEN, VIRUS_TYPE;
vector<vector<int>> board;

int movex[4] = { -1,1,0,0 };
int movey[4] = { 0, 0, -1,1 };

void expandVirus(int x, int y, priority_queue <virus, vector<virus>, cmp>& tmp) {
    for (int i = 0; i < 4; i++) {
        int nextx = x + movex[i];
        int nexty = y + movey[i];
        if (nextx < 0 || nexty < 0 || nextx >= BOARD_LEN || nexty >= BOARD_LEN) continue;
        if (board[nextx][nexty]) continue;
        board[nextx][nexty] = board[x][y];
        tmp.push({ board[nextx][nexty], nextx, nexty });
    }       
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> BOARD_LEN >> VIRUS_TYPE;
    board.resize(BOARD_LEN, vector<int>(BOARD_LEN, 0));

    priority_queue <virus, vector<virus>, cmp> pq;
    for (int i = 0; i < BOARD_LEN; i++) {
        for (int j = 0; j < BOARD_LEN; j++) {
            cin >> board[i][j];
            if(board[i][j])
                pq.push({ board[i][j], i , j });
        }
    }

    int S, X, Y;
    cin >> S >> X >> Y;

    for (int i = 0; i < S; i++) {
        priority_queue <virus, vector<virus>, cmp> tmp;

        virus cur;
        while (!pq.empty()) {
            cur = pq.top();
            pq.pop();

            expandVirus(cur.x, cur.y, tmp);
        }

        pq = tmp;
    }

    cout << board[X-1][Y-1];

    return 0;
}