/*
    [BOJ10942_팰린드롬?] - 23.02.04
    * 상당히 신박한 dp 문제. dp table을 채워나가는 방식이 약간 특이했음.
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<bool>> dp;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;

    dp.resize(N, vector<bool>(N, false));
    vector<int> arr(N);
    queue < pair<int, int>> bfs;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        dp[i][i] = true;
        bfs.push({ i,i });

        if (i > 0 && arr[i] == arr[i - 1]) {
            dp[i - 1][i] = true;
            bfs.push({ i - 1,i });
        }
    }

    pair<int, int> cur;
    while (!bfs.empty()) {
        cur = bfs.front();
        bfs.pop();

        int nextX = cur.first - 1;
        int nextY = cur.second + 1;

        if (nextX < 0 || nextY >= N) continue;
        if (dp[nextX][nextY]) continue;
        
        if (arr[nextX] == arr[nextY]) {
            bfs.push({ nextX, nextY });
            dp[nextX][nextY] = true;
        }
    }

    int M;
    cin >> M;

    int from, to;
    for (int i = 0; i < M; i++) {
        cin >> from >> to;
        cout << (dp[from-1][to - 1] ? 1 : 0) << "\n";
    }

    return 0;
}