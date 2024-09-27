#include <iostream>
#include<vector>
#include<algorithm>
#include <cassert>
using namespace std;
class Solution {
public:
	/// <summary>
	/// ʱ�临�Ӷ�o(n)
	/// �ռ临��o(n)
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
ħ��Կ��:
int maxTreasureWithMagicKey(vector<int>& treasure) {
    int n = treasure.size();
    if (n == 0) return 0;
    if (n == 1) return treasure[0];
    vector<vector<int>> dp(n, vector<int>(2, 0));//(δ/�Ѿ�)ʹ�ù�һ��ħ��Կ�׵������ֵ��
    dp[0][0] = treasure[0];
    dp[0][1] = treasure[0];
    dp[1][0] = max(treasure[0], treasure[1]);
    dp[1][1] = treasure[0] + treasure[1];
    // ��̬�滮����
    for (int i = 2; i < n; i++) {
        dp[i][0] = max(dp[i-1][0], dp[i-2][0] + treasure[i]);
        dp[i][1] = max({dp[i-1][1], dp[i-2][1] + treasure[i], dp[i-2][0] + treasure[i] + treasure[i-1]});
    }
    // �������ս��
    return max(dp[n-1][0], dp[n-1][1]);
}

�ͷ����䣺
����ʹ�ö�̬�滮��
	dp[i] = max(dp[i - 2] + nums[i - 1], dp[i - 1]��0);
*/
/*
һ����ϡ�������Ӧ���͡������֡����ƵĲ�����������Ϸ����Ϊ����ṩʹ��һ�Ρ�ħ��Կ�ס������ڱ���Ļ��ᡣ
�����ǰ�������ڲ����������ǰ���£���󻯵÷ֺͽ�����ͬʱ�������������Ӧ���ơ�����������㷨����Ϸ��ƵĻ���������

������һ���ɱ�����ɵ����̣�ÿ��������ܰ�������ֵ������ֵ���������塣�����ڵ���������ᴥ�����壬������ʧ���ռ��ı��
����ҿ���ʹ��һ�Ρ�ħ��Կ�ס�����ȫ�ش��������ڵı�������������塣���仹����������Ӧ���ԣ�����������ͬ���͵ı���
����ͬ��ֵ�����ʵı��䣩���γ������������Ӷ��������ߵĽ�����
�����������������������ѡ����󻯵÷֣����ⴥ�����壬���ڱ�Ҫʱ����ʹ�á�ħ��Կ�ס���*/