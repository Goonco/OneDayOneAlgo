/*
    [BOJ16234_인구_이동] - 23.01.12
    * 복잡한 구현 문제이다. 와중에 문제를 잘못읽어서 해결이 오래걸렸다.
    * 포인트는 벽을 따로 생각하지 않고 type이라는 구조체 변수를 통해 연합중인 국가들을 관리하는 것이다.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

struct country {
    int population;
    int type;
};

int typeIncr = 0;
country initCountry(int pop) {
    country newCountry = { pop, typeIncr++ };
    return newCountry;
}

int BOARD_N, BOUND_L, BOUND_R;
vector<vector<country>> board;

// 상하좌우
int moveY[4] = { -1, 1, 0, 0 };
int moveX[4] = { 0,0,-1,1 };
bool changed;
void recBreakWall(int i, int j, int befI, int befJ) {
    int dif = (int)abs(board[i][j].population - board[befI][befJ].population);
   
    if (!(i == befI && j == befJ) && BOUND_L <= dif && dif <= BOUND_R) {
        board[i][j].type = board[befI][befJ].type;
        changed = true;
    }

    int nextI, nextJ;
    for (int mv = 0; mv < 4; mv++) {
        nextI = i + moveY[mv];
        nextJ = j + moveX[mv];

        if (nextI < 0 || nextJ < 0 || nextI >= BOARD_N || nextJ >= BOARD_N) continue;

        int dif = (int)abs(board[i][j].population - board[nextI][nextJ].population);
        if (BOUND_L <= dif && dif <= BOUND_R) {
            if (board[nextI][nextJ].type != board[i][j].type) {
                recBreakWall(nextI, nextJ, i, j);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> BOARD_N >> BOUND_L >> BOUND_R;
    board.resize(BOARD_N, vector<country>(0));

    int pop;
    for (vector<country>& it : board) {
        for (int i = 0; i < BOARD_N; i++) {
            cin >> pop;
            it.push_back(initCountry(pop));
        }
    }

    int count = 0;
    while (true) {
        changed = false;
        for (int i = 0; i < BOARD_N; i++) {
            for (int j = 0; j < BOARD_N; j++)
                recBreakWall(i, j, i, j);
        }

        if (!changed) break;

        vector<pair<int, int>> groups(BOARD_N * BOARD_N, make_pair(0, 0)); // type i -> popsum, countysum
        for (int i = 0; i < BOARD_N; i++) {
            for (int j = 0; j < BOARD_N; j++) {
                groups[board[i][j].type].first += board[i][j].population;
                groups[board[i][j].type].second++;
            }
        }

        for (int i = 0; i < BOARD_N; i++) {
            for (int j = 0; j < BOARD_N; j++)
                board[i][j].population = (int)(groups[board[i][j].type].first / groups[board[i][j].type].second);
        }

        for (int i = 0; i < BOARD_N; i++) {
            for (int j = 0; j < BOARD_N; j++)
                board[i][j].type = i * BOARD_N + j;
        }

        count++;
    }

    cout << count;
    ;   return 0;
}
