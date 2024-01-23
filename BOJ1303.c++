/*
    [BOJ1303_전쟁_-_전투] - 23.01.23
    * DFS
    * 문제를 똑바로 읽자.. board 입력 받을 때 N * N이 입력 예시일 경우 가로 세로 조심..!
*/


#include <iostream>
#include <vector>

using namespace std;

int W = 0;
int B = 0;
vector<vector<char>>board;
vector<vector<bool>>visited;

int moveX[4] = { -1,1,0,0 };
int moveY[4] = { 0,0,-1,1 };
int dfs(int x, int y) {
    if (visited[x][y]) return 0;
    visited[x][y] = true;

    int sum = 1;
    for (int i = 0; i < 4; i++) {
        int nextX = x + moveX[i];
        int nextY = y + moveY[i];
        if (nextX < 0 || nextY < 0 || nextX >= board.size() || nextY >= board[0].size()) continue;
        if (board[x][y] != board[nextX][nextY]) continue;

        sum += dfs(nextX, nextY);
    }

    return sum;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int BOARD_X, BOARD_Y;
    cin >> BOARD_Y >> BOARD_X ;

    board.resize(BOARD_X, vector<char>(BOARD_Y));
    visited.resize(BOARD_X, vector<bool>(BOARD_Y, false));
    for (int i = 0; i < BOARD_X; i++) {
        for (int j = 0; j < BOARD_Y; j++)
            cin >> board[i][j];
    }

    for (int i = 0; i < BOARD_X; i++) {
        for (int j = 0; j < BOARD_Y; j++) {
            if (visited[i][j]) continue;
            int tmp = dfs(i, j);
            if (board[i][j] == 'W') W += tmp * tmp;
            else B += tmp * tmp;
        }
    }

    cout << W << " " << B;
    return 0;
}