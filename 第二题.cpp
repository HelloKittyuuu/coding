#include <iostream>
#include <vector>
#include <cassert>
using namespace std;
/// <summary>
/// 时间o(n)
/// 空间o(1)
/// </summary>
/// <param name="heights"></param>
/// <returns></returns>
double MaxEnergyField(const vector<int>& heights) {
    int n = heights.size();
    if (n < 2) return 0;
    int left = 0, right = n - 1;
    double max_area = 0;
    while (left < right) {
        double area = 0.5f*(right - left) * (heights[left] + heights[right]);
        max_area = max(max_area, area);
        if (heights[left] < heights[right]) {
            left++;
        }
        else {
            right--;
        }
    }
    return max_area;
}
//int main() {
//    vector< pair< vector<int>, double>> testCases = {
//    {{2, 4}, 3},
//    {{1, 3, 5}, 6},
//    {{3, 2, 4}, 7},
//    {{4, 3, 2, 1}, 7.5f},
//    {{5, 4, 3, 2, 1}, 12},
//    {{1, 2, 3, 2, 1}, 4.5},
//    {{2, 3, 4, 3, 2}, 8},
//    {{1, 5, 3, 4}, 9},
//    {{6, 4, 5, 3}, 13.5},
//    {{3, 7, 5, 4}, 11}
//    };
//
//    for (const auto& testCase : testCases) {
//        double result = MaxEnergyField(testCase.first);
//        cout << "Test passed for input: ";
//        for (int height : testCase.first) {
//            cout << height << " ";
//        }
//        assert(result == testCase.second);
//       
//        cout << endl;
//    }
//
//    return 0;
//
//}
/*
如果我们允许玩家使⽤魔法道具来临时增加某个位置的塔的⾼度，你会如何修改你的算法？:
保存临时修改前的最大值以及位置，增加完位置后，重计算一边获取新的最大值是否大于以前的最值，如果大于则修改。

在游戏的⾼级模式中，某些位置可能有建筑限制（⾼度为0）。你的算法如何处理这种情况？
如果为0按照原算法的逻辑已经包括了处理方式就是直接将为零的指针，或者更进一步为0直接进行指针移动，需要
*/