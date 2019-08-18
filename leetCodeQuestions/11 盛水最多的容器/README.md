# 盛水最多的容器
来源：（LeetCode）](https://leetcode-cn.com/problems/container-with-most-water)

### 题目描述
给定 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

> 输入样例： 1 8 6 2 5 4 8 3 7 (vector)
    输出：49
<img src="https://aliyun-lc-upload.oss-cn-hangzhou.aliyuncs.com/aliyun-lc-upload/uploads/2018/07/25/question_11.jpg" alt="示例" />

### 题解
一开始使用的暴力法，然后最后一个测试样例超时了。。。

**双指针（下标）法**
原理：
题意是求围成的最大面积，根据题意可以得出的求面积的公式是：<i>area=(j - i)*min(hi, hj)</i>。（j 和 i 是横坐标，假设 j > i）。
初始的时候设置 i= 0， j = len - 1，其中 len = vector.size();同时计算此时的面积<i>area</i>，然后比较 i 和 j 对应的纵坐标的大小，纵坐标小的那个对应的横坐标向内收一个单位（如果 hi < hj，那么i++，否则 j--）。每次 i 或者 j 更新的时候都计算一次 <i>area</i>，同时把当前的 <i>area</i> 与之前的<i>area</i>比较，取较大的一个，直到 i == j 的时候结束循环。
移动短边的原因(以 i 对应的边为短边举例)：
在(i, j)范围内，首先，不管移动哪一边，这样宽度在减小，其次，因为高度由两个边中短的一个决定，而这个更新后的短的边（i + p， 或者 j - q）只能是小于或者等于最初的短边( i )，所以在（i, j)之间的所有的面积是一定小于(i, j)围成的面积，其次，如果每次更新长边（j--）的话，那么矩形的边的高度不可能再变大。而移动短边的话，同理还是因为高度都短的哪个边决定，如果后面的边大于当前的边，那么虽然宽度减小，但是高度还有可能变大，所以移动短的一边。
代码如下：
```
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
```