/*
    [BOJ20437_문자열_게임_2] - 23.01.11
    * 슬라이딩 윈도우라고 명시되어 있으나, 그보다 문제의 #3과 #4 규칙이 결론적으로 무엇을 의미하는지 파악하는 것과 데이터를 어떤 식으로 저장할지 결정하는 것이 더욱 중요해 보임.
    * 알파벳 별로 index를 저장하기 위해 2차원 벡터를 사용했으며, vector<vector<int>>와 같은 긴 자료형은 typedef로 처리하는 것이 굉장히 편리함.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<vector<int>> dv;

dv analyzeString(string s) {
    dv board(26, vector<int>(0));

    for (int i = 0; i < s.size(); i++) {
        board[s[i] - 'a'].push_back(i);
    }

    return board;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int TEST_CASE, K;
    cin >> TEST_CASE;

    string s;
    while (TEST_CASE--) {
        cin >> s >> K;

        dv board = analyzeString(s);

        int three = 999999, four = -1;
        for (vector<int> iter : board) {
            if (iter.size() >= K) {
                
                for (int i = 0; i <= iter.size() - K; i++) {
                    int dif = iter[i + K - 1] - iter[i] + 1;
                    three = min(three, dif);
                    four = max(four, dif);
                }
            }
        }

        if (four != -1) cout << three << " " << four << "\n";
        else cout << -1 << "\n";
    }

    return 0;
}
