/* 最长公共前缀 */
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<string> str;
	
    string longestCommonPrefix(vector<string>& strs) {
    	int size = strs.size();
    	string res;
    	if(size == 1) {
    		return strs[0];
		}
		if(size == 0) {
			return "";
		}
		for (int i = 0; i < strs.size() ; i++) {
			if(strs[i] == "") {
				return "";
			}
		}
    	int mid = size / 2;
    	vector<string> L, R;
    	
    	for(int i = 0; i < mid; i++) L.push_back(strs[i]);;
    	for(int i = mid; i < size; i++) R.push_back(strs[i]);
    	
    	longestCommonPrefix(L);
    	longestCommonPrefix(R);
    	res = upfindlongestCommonPrefix(L, R, mid, size - mid);
    	
    	releaseVector(L);
    	releaseVector(R);
    	return res;
    }
    string upfindlongestCommonPrefix(vector<string>& L, vector<string>& R, int leftSize, int rightSize) {
    	int i = 0, j = 0;
    	string res;
    	while(i < leftSize && j < rightSize) {
    		res = findLongerPrefix(L[i], R[j++]);
    		str.push_back(res);
    		PrintVector(str, "str");
    		if (str.size() == 2) {
    			res = findLongerPrefix(str[0], str[1]);
    			releaseVector(str);
    			str.push_back(res);
			}
			if (j == rightSize - 1) {
				j = 0;
				i++;
			}
		}
		return res;
	}
	string findLongerPrefix(string s1, string s2) {
		cout << "s1: " << s1 << " " << "s2: " << s2 << endl; 
		int i = 0;
		int len = s1.length() < s2.length() ? s1.length() : s2.length();
		string res;
		while (i < len) {
			cout << s1[i] << " " << s2[i] << endl;
			if(s1[i] == s2[i]) {
				res += s1[i];
				i++;
			} else {
				break;
			}
		}
		return res;
	}
	void PrintVector(vector<string>& strs, string name){
		cout << name << ": ";
		for(int i = 0; i < strs.size(); i++) {
			cout << strs[i] <<" ";
		}
		cout << endl;
	}
	void releaseVector (vector<string>& v) {
		v.clear();
    	vector<string>().swap(v);
	}
};

int main() {
	Solution sol;
	string item, commonPrefix;
	vector<string> strs;
	unsigned int len, i = 0;
	cout << "Type in the length of the vector: ";
	cin >> len;
	cout << "Type in the strings: ";
	while (i < len) {
		cin >> item;
		strs.push_back(item);
		i++;
	}
	commonPrefix = sol.longestCommonPrefix(strs);
	cout << commonPrefix;
}
