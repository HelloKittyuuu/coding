#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    double FindMedianTalentIndex(vector<int>& fireAbility, vector<int>& iceAbility) {
        if (fireAbility.size() == 0 && iceAbility.size() == 0)return 0;
        int times = (iceAbility.size() + fireAbility.size())/2-2;
        int temp = times%2;
        int left=0;
        int left2=0;
        double res = 0;
        while (times > 0) {
            if (fireAbility.size() - 1 >= left) {
                left2++;
            }
            else if (iceAbility.size() - 1 >= left2) {
                left++;

            }
            else {
                if (fireAbility[left] > iceAbility[left2]) {
                    left2++;
                }
                else {
                    left++;
                }
            }
           
            times--;
        }
        if (fireAbility.size() > 0 && iceAbility.size())
            res = max(fireAbility[left], iceAbility[left2]);
        else if (fireAbility.size() == 0)res = iceAbility[left2];
        else {
            res = fireAbility[left];
        }
        if (temp == 0) {
            if (left >= fireAbility.size()) {
                res += iceAbility[left2 + 1];
            }
            else if (left2 >= iceAbility.size()) {
                res += fireAbility[left + 1];
            }
            else {
                res += max(fireAbility[left + 1], iceAbility[left2 + 1]);
            }
            return res/2;
        }
        else {
            return res;
        }
       

        
    }
};
int main() {
    Solution a;
    vector<int> b{};
    vector<int> c{ 1,2,3,4,6,8,8 ,10,10};
    cout<<a.FindMedianTalentIndex(b, c);
    return 1;

}
///_____________________________________________________________________
/*����ʵʱ���¸Ľ���
ʹ����������ά�����ݣ�һ��С���Ѵ洢�ϴ��һ�룬��һ������Ѵ洢��С��һ�롣
���������� O(log n) ��ʱ�临�Ӷ��ڿ��ٲ����ɾ��Ԫ�أ����ҿ����� O(1) ��ʱ���ڻ����λ����
+������������������������������������������������������������


*/