#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
    	unsigned const int len = height.size();
		unsigned int res = 0;
        unsigned int i = 0, j = len - 1;
        res = (j - i) * min(height[i], height[j]);
        while (i < j) {
        	const int area = (j - i) * min(height[i], height[j]);
        	res = area > res ? area : res;
        	if (height[i] <= height[j]) {
        		i++;
			} else {
				j--;
			}
		}
		return res;
    }
};

int main () {
	Solution sol;
	vector<int> bottleHeights;
	int height;
	cout << "Type in bottle heights (end with -1): ";
	cin >> height;
	while (height != -1) {
		bottleHeights.push_back(height);
		cin >> height;
	}
	unsigned const int maxArea = sol.maxArea(bottleHeights);
	
	cout << maxArea;
	cout << endl;
}
