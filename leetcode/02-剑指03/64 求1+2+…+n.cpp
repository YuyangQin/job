#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

class Solution {
public:
	//方法二：位运算
	int sumNums(int n) {
		int ans = 0, A = n, B = n + 1;

		(B & 1) && (ans += A);
		A <<= 1;
		B >>= 1;

		(B & 1) && (ans += A);
		A <<= 1;
		B >>= 1;

		(B & 1) && (ans += A);
		A <<= 1;
		B >>= 1;

		(B & 1) && (ans += A);
		A <<= 1;
		B >>= 1;

		(B & 1) && (ans += A);
		A <<= 1;
		B >>= 1;

		(B & 1) && (ans += A);
		A <<= 1;
		B >>= 1;

		(B & 1) && (ans += A);
		A <<= 1;
		B >>= 1;

		(B & 1) && (ans += A);
		A <<= 1;
		B >>= 1;

		(B & 1) && (ans += A);
		A <<= 1;
		B >>= 1;

		(B & 1) && (ans += A);
		A <<= 1;
		B >>= 1;

		(B & 1) && (ans += A);
		A <<= 1;
		B >>= 1;

		(B & 1) && (ans += A);
		A <<= 1;
		B >>= 1;

		(B & 1) && (ans += A);
		A <<= 1;
		B >>= 1;

		(B & 1) && (ans += A);
		A <<= 1;
		B >>= 1;

		return ans >> 1;
	}
	class Solution {
public:
    int sumNums(int n) {
        int ans = 0, A = n, B = n + 1;

        (B & 1) && (ans += A);
        A <<= 1;
        B >>= 1;

        (B & 1) && (ans += A);
        A <<= 1;
        B >>= 1;

        (B & 1) && (ans += A);
        A <<= 1;
        B >>= 1;

        (B & 1) && (ans += A);
        A <<= 1;
        B >>= 1;

        (B & 1) && (ans += A);
        A <<= 1;
        B >>= 1;

        (B & 1) && (ans += A);
        A <<= 1;
        B >>= 1;

        (B & 1) && (ans += A);
        A <<= 1;
        B >>= 1;

        (B & 1) && (ans += A);
        A <<= 1;
        B >>= 1;

        (B & 1) && (ans += A);
        A <<= 1;
        B >>= 1;

        (B & 1) && (ans += A);
        A <<= 1;
        B >>= 1;

        (B & 1) && (ans += A);
        A <<= 1;
        B >>= 1;

        (B & 1) && (ans += A);
        A <<= 1;
        B >>= 1;

        (B & 1) && (ans += A);
        A <<= 1;
        B >>= 1;

        (B & 1) && (ans += A);
        A <<= 1;
        B >>= 1;

        return ans >> 1;
    }
	//方法一：逻辑运算符的短路
	int sumNums(int n) {
		n && (n += (n - 1));
		return n;
	}
};
};

int main()
{

	return 0;
}
