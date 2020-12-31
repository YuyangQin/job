#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool isMatch(string s, string p) {
		// 如果字符串长度为0，需要检测下正则串
		if (s.size() == 0) {
			// 如果正则串长度为奇数，必定不匹配，比如 "."、"ab*",必须是 a*b*这种形式，*在奇数位上
			if (p.length() % 2 != 0) return false;
			int i = 1;
			while (i < p.length()) {
				if (p[i] != '*') return false;
				i += 2;
			}
			return true;
		}
		// 如果字符串长度不为0，但是正则串没了，return false
		if (p.length() == 0) return false;
		// c1 和 c2 分别是两个串的当前位，c3是正则串当前位的后一位，如果存在的话，就更新一下
		char c1 = s[0], c2 = p[0], c3 = 'a';
		if (p.length() > 1) {
			c3 = p[1];
		}
		// 和dp一样，后一位分为是 '*' 和不是 '*' 两种情况
		if (c3 != '*') {
			// 如果该位字符一样，或是正则串该位是 '.',也就是能匹配任意字符，就可以往后走
			if (c1 == c2 || c2 == '.') {
				return isMatch(s.substr(1), p.substr(1));
			}
			else {
				// 否则不匹配
				return false;
			}
		}
		else {
			// 如果该位字符一样，或是正则串该位是 '.'，和dp一样，有看和不看两种情况
			if (c1 == c2 || c2 == '.') {
				return isMatch(s.substr(1), p) || isMatch(s, p.substr(2));
			}
			else {
				// 不一样，那么正则串这两位就废了，直接往后走
				return isMatch(s, p.substr(2));
			}
		}
	}
};

void main()
{
	Solution s;
}