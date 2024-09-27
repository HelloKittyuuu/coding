#include <iostream>
#include<vector>
#include<algorithm>
#include <cassert>
using namespace std;
class Solution {
public:
	/// <summary>
	/// 时间复杂度o(n)
	/// 空间复杂o(n)
	/// </summary>
	/// <param name="nums"></param>
	/// <returns></returns>
	int rob(vector<int>& nums) {
		if (nums.empty()) return 0;  
		if (nums.size() == 1) return nums[0]; 


		vector<int> dp(nums.size() + 1, 0);
		dp[1] = nums[0];

		for (int i = 2; i <= nums.size(); i++) {
			dp[i] = max(dp[i - 2] + nums[i - 1], dp[i - 1]);
		}

		return dp[nums.size()];  
	}
};


//int main() {
//	 vector<int> emptyVec;
//	Solution solution;
//	int result1 = solution.rob(emptyVec);
//	assert(result1==0);
//	std::cout<< "Result for empty vector: " << result1 <<  endl;
//	 vector<int> singleVec = { 5 };
//	int result2 = solution.rob(singleVec);
//	assert(result2 == 5);
//	std::cout << "Result for single element vector: " << result2 <<  endl;
//	 vector<int> normalVec = { 1, 2, 3, 1 };
//	int result3 = solution.rob(normalVec);
//	assert(result3 == 4);
//	std::cout << "Result for normal vector: " << result3 <<  endl;
//	return 0;
//
//}
///------------------------------------------------------------------------------
/*
魔法钥匙:
int maxTreasureWithMagicKey(vector<int>& treasure) {
    int n = treasure.size();
    if (n == 0) return 0;
    if (n == 1) return treasure[0];
    vector<vector<int>> dp(n, vector<int>(2, 0));//(未/已经)使用过一次魔法钥匙的最大宝物值。
    dp[0][0] = treasure[0];
    dp[0][1] = treasure[0];
    dp[1][0] = max(treasure[0], treasure[1]);
    dp[1][1] = treasure[0] + treasure[1];
    // 动态规划计算
    for (int i = 2; i < n; i++) {
        dp[i][0] = max(dp[i-1][0], dp[i-2][0] + treasure[i]);
        dp[i][1] = max({dp[i-1][1], dp[i-2][1] + treasure[i], dp[i-2][0] + treasure[i] + treasure[i-1]});
    }
    // 返回最终结果
    return max(dp[n-1][0], dp[n-1][1]);
}

惩罚宝箱：
依旧使用动态规划，
	dp[i] = max(dp[i - 2] + nums[i - 1], dp[i - 1]，0);
*/
/*
一个结合“连锁反应”和“消消乐”机制的策略类益智游戏，并为玩家提供使用一次“魔法钥匙”打开相邻宝箱的机会。
核心是帮助玩家在不触发陷阱的前提下，最大化得分和奖励，同时充分利用连锁反应机制。以下是这个算法和游戏设计的基本方案。

玩家面对一个由宝箱组成的棋盘，每个宝箱可能包含正分值、负分值、或是陷阱。打开相邻的两个宝箱会触发陷阱，导致损失已收集的宝物，
但玩家可以使用一次“魔法钥匙”来安全地打开两个相邻的宝箱而不触发陷阱。宝箱还具有连锁反应属性，即连续打开相同类型的宝箱
（相同分值或性质的宝箱）会形成连锁消除，从而产生更高的奖励。
帮助玩家在棋盘上做出最优选择，最大化得分，避免触发陷阱，并在必要时合理使用“魔法钥匙”。*/