#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string roman = "";
        int a[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string b[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int i = 0;
        while(num){
        	if (num >= a[i] && i < 13) {
        		roman += b[i];
        		num -= a[i];
			} else {
				i++;
			}
		}
		return roman;
    }
};

int main () {
	Solution sol;
	int num;
	string result;
	cout << "Type in the number(1 - 3999) needs to be transformed in to roman: ";
	cin >> num;
	result = sol.intToRoman(num);
	cout << result;
}
