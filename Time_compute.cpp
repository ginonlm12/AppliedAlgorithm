#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> day_stt_1;
string day_stt_2[1001];
string Day, Time;
int total, duration;

void input() {
    total = 0;
    while (1) {
        cin >> Day;
        if (Day == "*") {
            break;
        }
        total++;
        day_stt_1[Day] = total;
        day_stt_2[total] = Day;
    }
}

void Date_compute(string st, int STT, int Duration) {
    int stime = stoi(st.substr(0, 2)) * 3600 + stoi(st.substr(3, 2)) * 60 + stoi(st.substr(6, 2));
    int a = (stime + Duration) % 86400; // Chenh lech thoi gian
    int b = (stime + Duration - a) / 86400; // Chenh lech ngay
    cout << day_stt_2[(STT + b) % total] << " ";

    int h = a / 3600;
    int m = (a - h * 3600) / 60;
    int s = a - h * 3600 - m * 60;

    printf("%02d:%02d:%02d\n", h, m, s);
}

void SOLVE() {
    while (1) {
        cin >> Day;
        if (Day == "***") {
            break;
        }
        cin >> Time;
        cin >> duration;
        Date_compute(Time, day_stt_1[Day], duration);
    }
}

int main() {
    freopen("inp.inp", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    input();
    SOLVE();
    return 0;
}
