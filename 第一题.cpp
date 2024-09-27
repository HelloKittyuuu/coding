#include<iostream>
#include<vector>
#include <cassert>
using namespace std;
class Solutions {
public :
    /// <summary>
    /// ��������ÿ�λ���ʱ��ѡȡ�Ļ�׼ֵ��mid�����������е�������СԪ�أ�����ÿ�λ��ֶ��Ὣ����ֳ�һ����С�Ĳ��ֺ�һ���ܴ�Ĳ��֣�
    /// ���µݹ����Ϊ O(n)��ÿ�λ��ֲ�������Ҫ O(n) ʱ�䡣��ˣ�������ʱ�临�Ӷ�Ϊ O(n^2)��
    ///ƽ���������ƽ������£����������ܹ���������»���Ϊ���룬�ݹ����Ϊ O(log n)��
    /// ÿ�λ��ֲ�������Ҫ O(n) ʱ�䡣��ˣ�ƽ��ʱ�临�Ӷ�Ϊ O(n log n)��
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
    /// GetTopScores ������ʱ�临�Ӷ�
    ///GetTopScores ������Ҫ����������ɣ�
    ///�������򣺶��������� sorces ���п��������ⲿ�ֵ�ƽ��ʱ�临�Ӷ�Ϊ O(n log n)������ n ������ĳ��ȡ�
    /// ��ȡǰ m ��Ԫ�أ�������������ɺ󣬴���������ȡǰ m ��Ԫ�أ�ʱ�临�Ӷ�Ϊ O(m)������ m ���Ϊ n����˿�����Ϊ O(n)��
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
/// ���Ժ���
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
* ǰk����������̫���˵�ʱ�򣬹�����С�ѣ�k����ڼ������˽�С��ǰ2000����������k��ֱ�Ӳ��룬��������2000���ж��Ƿ������С��ֱ���滻��Сֵ
* �������k����ڼ�����ϴ�ʱ������ͬʱ����ʵʱ�ύ���������ر���ʱ�򣬻���ֱ��������ķ������п���ѡ������


*/