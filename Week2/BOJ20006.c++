/*
    [BOJ20006_랭킹전_대기열] - 23.01.10
    * 단순 구현 문제. 언급할 점 없음
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

bool myCompare(pair<int, string>& bef, pair<int, string>& next) {
    return bef.second < next.second;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int PLAYER_NUM, ROOM_MAX;
    cin >> PLAYER_NUM >> ROOM_MAX;

    vector<vector<pair<int,string>>> rooms;

    int num;
    string name;
    for (int i = 0; i < PLAYER_NUM; i++) {
        cin >> num >> name;

        bool flag = true;
        for (vector<pair<int, string>>& room : rooms) {
            if (room.size() < ROOM_MAX && room[0].first - 10 <= num && num <= room[0].first + 10) {
                flag = false;
                room.push_back(make_pair(num, name));
                break;
            }
        }

        if (flag) {
            vector<pair<int, string>> newRoom;
            newRoom.push_back(make_pair(num, name));
            rooms.push_back(newRoom);
        }
    }

    for (vector<pair<int, string>> room : rooms) {
        if (room.size() == ROOM_MAX) cout << "Started!\n";
        else cout << "Waiting!\n";

        sort(room.begin(), room.end(), myCompare);
        for (pair<int, string> p : room)
            cout << p.first << " " << p.second << "\n";
    }

    return 0;
}
