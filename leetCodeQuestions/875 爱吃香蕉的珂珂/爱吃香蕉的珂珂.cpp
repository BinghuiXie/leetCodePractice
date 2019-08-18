/*
����ϲ�����㽶�������� N ���㽶���� i ������ piles[i] ���㽶�������Ѿ��뿪�ˣ�����HСʱ�������

������Ծ��������㽶���ٶ� K ����λ����/Сʱ����ÿ��Сʱ��������ѡ��һ���㽶�����гԵ� K ����
�������㽶���� K ���������Ե���ѵ������㽶��Ȼ����һСʱ�ڲ����ٳԸ�����㽶��

����ϲ�������ԣ�����Ȼ���ھ�������ǰ�Ե����е��㽶��

������������ H Сʱ�ڳԵ������㽶����С�ٶ� K��K Ϊ��������

	1 <= piles.length <= 10^4
	piles.length <= H <= 10^9
	1 <= piles[i] <= 10^9

*/
#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

class Solution {
public:
    int maxNum(vector<int>& piles) {
		int maxIndex = 0;
		for (unsigned int i = 0; i < piles.size(); i++) {
			maxIndex = piles[i] > piles[maxIndex] ? i : maxIndex;
		}
		return piles[maxIndex];
	}
    int minEatingSpeed(vector<int>& piles, int H) {
    	int maxSpeed = 1;
    	double sum = 0;
    	double temp = H;
        if (H == piles.size()) {
        	return maxNum(piles);
		}
		for(unsigned int i = 0; i < piles.size(); i++) {
			sum += piles[i];
		}
		// �ȼ���һ����ƽ���ٶ��£�Ҳ����ÿ��Сʱ����һ�����㽶���õ�ʱ��( �㽶���� / H ) 
		maxSpeed = sum / H + 1;
		while(true){
			temp = H;
			for(unsigned int i = 0; i < piles.size(); i++) {
				temp -= piles[i] % maxSpeed == 0 ? piles[i] / maxSpeed : (piles[i] / maxSpeed + 1);
                if (temp < 0) {
                    maxSpeed++;
                    break;
                }
            }
			if (temp >= 0) {
				break; 
			}
		}
		return maxSpeed;
    }
};
//[312884470]
//968709470

int main () {
	Solution sol;
	vector<int> piles;
	int backHour;
	int num;
	cout << "Type in banana piles��end with -1: ";
	cin >> num;
	while (num != -1) {
		piles.push_back(num);
		cin >> num;
	}
	cout << "Type in hours: ";
	cin >> backHour;
	unsigned const int speed = sol.minEatingSpeed(piles, backHour);
	cout << speed << endl;
	return 0;
}
// 30 11 23 4 20 -1
// 6

// 332484035 524908576 855865114 632922376 222257295 690155293 112677673 679580077 337406589 290818316 877337160 901728858 679284947 688210097 692137887 718203285 629455728 941802184
// 823855818






























