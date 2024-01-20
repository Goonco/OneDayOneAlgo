/*
    [BOJ14719_빗물] - 23.01.14
    * 직접 보드를 구현하는 문제로 항상 높이를 첫 index로 둘지 넓이를 첫 index로 둘지 고민된다.
    * 좌측아래를 [0][0]으로 잡고 위로 올라가면 [1][0] 오른쪽으로 가면 [0][1]의 방식으로 구현했다.
    * 구현 자체는 어렵지 않아 따로 언급할 점은 없다.
*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int H, W;
    cin >> H >> W;

    vector<vector<bool>> board(H, vector<bool>(W, false));

    int height;
    for (int i = 0; i < W; i++) {
        cin >> height;

        for (int j = 0; j < height; j++)
            board[j][i] = true;
    }

    int rainCount = 0;

    for (vector<bool> line : board) {
        int tmpCount = 0;
        bool flag = false;

        for (bool wall : line) {
            if (flag) {
                if (wall) {
                    rainCount += tmpCount;
                    tmpCount = 0;
                }
                else {
                    tmpCount++;
                }
            }
            
            if (wall) flag = true;
        }

    }

    cout << rainCount;

    return 0;
}
