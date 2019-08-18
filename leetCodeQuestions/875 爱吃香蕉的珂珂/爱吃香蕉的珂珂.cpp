/*
珂珂喜欢吃香蕉。这里有 N 堆香蕉，第 i 堆中有 piles[i] 根香蕉。警卫已经离开了，将在H小时后回来。

珂珂可以决定她吃香蕉的速度 K （单位：根/小时）。每个小时，她将会选择一堆香蕉，从中吃掉 K 根。
如果这堆香蕉少于 K 根，她将吃掉这堆的所有香蕉，然后这一小时内不会再吃更多的香蕉。

珂珂喜欢慢慢吃，但仍然想在警卫回来前吃掉所有的香蕉。

返回她可以在 H 小时内吃掉所有香蕉的最小速度 K（K 为整数）。

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
		// 先计算一下在平均速度下，也就是每个小时都吃一样的香蕉所用的时间( 香蕉总数 / H ) 
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
	cout << "Type in banana piles，end with -1: ";
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






























