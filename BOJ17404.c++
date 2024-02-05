/*
    [BOJ17404_RGB거리_2] - 23.02.05
    * 딱봐도 dp에 점화식까지 쉽게 나온다. 그러나 dp의 구현 과정이 굉장히 신박했다.
    * 솔직히 답지를 봤고 계속 생각해도 못풀었을 것 같다. 좀더 쉽게 직관적으로 생각하자.
*/

#include <iostream>
#include <vector>

using namespace std;

#define INF 987654321

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int HOUSE_N;
    cin >> HOUSE_N;

    vector<vector<int>> colors(HOUSE_N, vector<int>(3));
    for (int i = 0; i < HOUSE_N; i++) {
        cin >> colors[i][0] >> colors[i][1] >> colors[i][2];
    }

    int MINANS = INF;

    vector<vector<int>> dp(HOUSE_N, vector<int>(3));
    for (int c = 0; c < 3; c++) {
        for (int i = 0; i < 3; i++)
            dp[0][i] = INF;
        dp[0][c] = colors[0][c];

        for (int i = 1; i < HOUSE_N; i++) {
            dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + colors[i][0];
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + colors[i][1];
            dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + colors[i][2];
        }

        for (int i = 0; i < 3; i++) {
            if (i == c) continue;
            MINANS = min(dp[dp.size() - 1][i], MINANS);
        }
    }   

    cout << MINANS;

    return 0;
}