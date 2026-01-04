#include <algorithm>
#include <iostream>
using namespace std;

// 用來找出對於某個直徑的所需基地台
int needStations(int minDist, int *pos, int n) {
    int lastInd = 0; // 最後選擇基地台的左側座標位址
    int count = 1;   // 已選擇的基地台數目
    for (int x = 1; x < n; ++x) {
        // 如果這個基地台超出覆蓋範圍
        if (pos[x] > pos[lastInd] + minDist) {
            count++;     // 新增一個基地台
            lastInd = x; // 設定基地台左側座標
        }
    }
    return count;
}

int main() {
    int n; // 服務點數量
    int k; // 基地台數量
    cin >> n >> k;

    int pos[n];
    // 依序讀取服務點位置
    for (int i = 0; i < n; ++i) {
        cin >> pos[i];
    }
    // 將服務點座標由小到大排序
    sort(pos, pos + n);

    // 使用二分搜尋法，找出可行直徑的最小值
    int left = 0;                    // 最大的不可行直徑
    int right = pos[n - 1] - pos[0]; // 最小的可行直徑
    int mid;                         // 中間值

    // 重複直到找到真正最小的可行直徑
    //->最大的不可行直徑+1=最小的可行直徑
    while (left + 1 < right) {
        mid = (left + right) / 2; // 設定中間值做為測試點
        if (needStations(mid, pos, n) <= k) {
            // 對於某個直徑 如果我需要的站點數 <= 我可用的站點數 ->這個直徑是可行的
            right = mid;
        } else {
            // 反之這個直徑是不可行的
            left = mid;
        }
    }

    // 輸出我們找到的最小可行直徑
    cout << right << endl;
    return 0;
}
