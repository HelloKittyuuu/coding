#include<iostream>
#include<vector>
#include <cassert>
using namespace std;
class Solutions {
public :
    /// <summary>
    /// 最坏情况：当每次划分时，选取的基准值（mid）总是数组中的最大或最小元素，这样每次划分都会将数组分成一个很小的部分和一个很大的部分，
    /// 导致递归深度为 O(n)，每次划分操作又需要 O(n) 时间。因此，最坏情况下时间复杂度为 O(n^2)。
    ///平均情况：在平均情况下，快速排序能够将数组大致划分为两半，递归深度为 O(log n)，
    /// 每次划分操作仍需要 O(n) 时间。因此，平均时间复杂度为 O(n log n)。
    /// </summary>
    /// <param name="left"></param>
    /// <param name="right"></param>
    /// <param name="sorces"></param>
    void quicksort(int left, int right, vector<int>& sorces,int jizhun) {
        if (left >= right)return;
        int m_left = left + 1;
        int m_right = right;
        int mid = sorces[left];
        while (m_left <= m_right) {
            while (m_left <= m_right && sorces[m_left] > mid) {
                m_left++;

            }
            while (m_left <= m_right && sorces[m_right] < mid) {
                m_right--;
            }

            if (m_left <= m_right) {
                swap(sorces[m_left], sorces[m_right]);m_left++;m_right--;
            }
        }
        swap(sorces[left], sorces[m_right]);
        if (jizhun - 1 >m_right)
        quicksort(m_left, right, sorces, jizhun);
        quicksort(left, m_right - 1, sorces, jizhun);
    }
    /// <summary>
    /// GetTopScores 函数的时间复杂度
    ///GetTopScores 函数主要由两部分组成：
    ///快速排序：对输入数组 sorces 进行快速排序，这部分的平均时间复杂度为 O(n log n)，其中 n 是数组的长度。
    /// 提取前 m 个元素：在数组排序完成后，从数组中提取前 m 个元素，时间复杂度为 O(m)。由于 m 最大为 n，因此可以视为 O(n)。
    /// </summary>
    /// <param name="sorces"></param>
    /// <param name="m"></param>
    /// <returns></returns>
    vector<int> GetTopScores(vector<int>& sorces, int m) {
        vector<int>res;
        if (m ==0|| sorces.size()==0)return res ;
        int length = sorces.size();
       
        quicksort(0, length - 1, sorces,m);
        m = length < m ? length : m;
        for (int i = 0;i < m;i++) {
            res.push_back(sorces[i]);
        }
        return res;
    }

        
};

/// <summary>
/// 测试函数
/// </summary>
void testQuicksortAndGetTopScores() {
    Solutions s;
    std::vector<int> input1 = { 5, 3, 8, 2, 7 };
    vector<int>res;
    res = s.GetTopScores(input1, 6);
    std::vector<int> expectedSorted1 = { 8,7,5 };
    for (int i = 0; i < expectedSorted1.size(); i++) {
        assert(res[i] == expectedSorted1[i]);

    }

    std::vector<int> input2 = { 10, 6, 4, 9, 1 };
    res = s.GetTopScores(input2, 6);
    std::vector<int> expectedSorted2 = { 10,9,6,4,1 };
    for (int i = 0; i < expectedSorted2.size(); i++) {
        cout << res[i] << "!=" << expectedSorted2[i];

        assert(res[i] == expectedSorted2[i]);
    }

    std::vector<int> inputForTopScores = { 5, 3, 8, 2, 7 };
    std::vector<int> topScores = s.GetTopScores(inputForTopScores, 3);
    std::vector<int> expectedTopScores = { 8,7,5 };
    for (int i = 0; i < topScores.size(); i++) {
        assert(topScores[i] == expectedTopScores[i]);
    }
}

//int main() {
//    testQuicksortAndGetTopScores();
//    std::cout << "All tests passed." << std::endl;
//    return 0;
//}
///--------------------------------------------------------------
/*
* 前k名，当基数太大了的时候，构建最小堆，k相较于几百万人较小如前2000，人数不足k，直接插入，人数大于2000，判断是否大于最小数直接替换最小值
* 但是如果k相较于几百万较大时，或者同时在线实时提交的新数据特别多的时候，还在直接用上面的方法进行快速选择排序，


*/