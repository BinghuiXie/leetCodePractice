/* 罗马数字转整数 */
#include<iostream>
#include<string.h>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
    	int integer = 0;
        int a[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string b[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int i = s.length();
        while(i >= 0) {
        	int j = i - 1;
        	switch(s[i]){
        		case 'I':
        			integer += 1;
        			break;
        		case 'V':
        			if(s[j] == 'I'){
        				integer += 4;
        				i--;
					} else {
						integer += 5;
					}
        			break;
				case 'X':
					if(s[j] == 'I') {
						integer += 9;
						i--;
					} else {
						integer += 10;
					}
        			break;
        		case 'L':
        			if(s[j] == 'X') {
        				integer += 40;
        				i--;
					} else {
						integer += 50;
					}
        			break;
				case 'C':
					if(s[j] == 'X') {
						integer += 90;
						i--;
					} else {
						integer += 100;
					}
        			break;
        		case 'D':
        			if(s[j] == 'C') {
        				integer += 400;
        				i--;
					} else {
						integer += 500;
					}
        			break;
        		case 'M':
        			if(s[j] == 'C') {
        				integer += 900;
        				i--;
					} else {
						integer += 1000;
					}
        			break;
			}
			i--;
		}
		return integer;
    }
};

int main () {
	Solution sol;
	string s;
	cout << "Type in the string needs to be transfered to integer: ";
	cin >> s;
	int result = sol.romanToInt(s);
	cout << result << endl;
	return 0;
}
