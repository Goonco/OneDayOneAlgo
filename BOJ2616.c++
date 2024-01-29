/*
    [BOJ2616_소형기관차] - 23.01.29
    * Dynamic Proramming이지만 case에 따라 다르게 전파해 나가는 문제
    * 보다 빠른 풀이 존재
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <iomanip>

using namespace std;

// startI, sum
bool sortBy(pair<int, int> bef, pair<int, int> aft) {
    return bef.second > aft.second;
}

void printTest(vector<vector<int>> dp) {
    for (int p2 = 0; p2 < 3; p2++) {
        for (int p1 = 0; p1 < dp.size(); p1++) {
 
            cout << setw(3) << dp[p1][p2] << " ";
        }
        cout << "\n";
    }
    cout << "\n\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int trainLen, subMax;
    cin >> trainLen;
    vector<int> train(trainLen);

    for (int i = 0; i < trainLen; i++)
        cin >> train[i];

    cin >> subMax;
    vector<int> arr(trainLen - subMax + 1);

    int i;
    queue<int> q;
    int sum = 0;
    for (i = 0; i < subMax; i++) {
        q.push(train[i]);
        sum += train[i];
    }
    
    int idx = 0;
    arr[idx++] = sum;
    for (i; i < trainLen; i++) {
        sum -= q.front();
        q.pop();
        sum += train[i];
        q.push(train[i]);

        arr[idx++] = sum;
    }

    vector<vector<int>> dp(arr.size(), vector<int>(3,0));
    for (int i = 0; i < arr.size(); i++) {
        int lv1 = arr[i];
        int lv2 = i - subMax >= 0 ? dp[i - subMax][0] + lv1 : 0;
        int lv3 = i - subMax >= 0 && dp[i - subMax][1] ? dp[i - subMax][1] + lv1 : 0;

        //j < i + subMax &&
        for (int j = i;  j < i + subMax &&  j < arr.size(); j++) {
            if (!j) {
                dp[j][0] = max(dp[j][0], lv1);
                dp[j][1] = max(dp[j][1], lv2);
                dp[j][2] = max(dp[j][2], lv3);
            }
            else {
                dp[j][0] = max(max(dp[j][0], lv1), dp[j-1][0]);
                dp[j][1] = max(max(dp[j][1], lv2), dp[j-1][1]);
                dp[j][2] = max(max(dp[j][2], lv3), dp[j-1][2]);
            }
        }

        //printTest(dp);
    }

    cout << dp[arr.size() - 1][2];
    return 0;
}