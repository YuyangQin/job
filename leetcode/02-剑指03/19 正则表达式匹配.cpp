#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool isMatch(string s, string p) {
		// ����ַ�������Ϊ0����Ҫ���������
		if (s.size() == 0) {
			// ������򴮳���Ϊ�������ض���ƥ�䣬���� "."��"ab*",������ a*b*������ʽ��*������λ��
			if (p.length() % 2 != 0) return false;
			int i = 1;
			while (i < p.length()) {
				if (p[i] != '*') return false;
				i += 2;
			}
			return true;
		}
		// ����ַ������Ȳ�Ϊ0����������û�ˣ�return false
		if (p.length() == 0) return false;
		// c1 �� c2 �ֱ����������ĵ�ǰλ��c3�����򴮵�ǰλ�ĺ�һλ��������ڵĻ����͸���һ��
		char c1 = s[0], c2 = p[0], c3 = 'a';
		if (p.length() > 1) {
			c3 = p[1];
		}
		// ��dpһ������һλ��Ϊ�� '*' �Ͳ��� '*' �������
		if (c3 != '*') {
			// �����λ�ַ�һ�����������򴮸�λ�� '.',Ҳ������ƥ�������ַ����Ϳ���������
			if (c1 == c2 || c2 == '.') {
				return isMatch(s.substr(1), p.substr(1));
			}
			else {
				// ����ƥ��
				return false;
			}
		}
		else {
			// �����λ�ַ�һ�����������򴮸�λ�� '.'����dpһ�����п��Ͳ����������
			if (c1 == c2 || c2 == '.') {
				return isMatch(s.substr(1), p) || isMatch(s, p.substr(2));
			}
			else {
				// ��һ������ô��������λ�ͷ��ˣ�ֱ��������
				return isMatch(s, p.substr(2));
			}
		}
	}
};

void main()
{
	Solution s;
}