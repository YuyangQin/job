#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

class Solution {
public:
	//��������λ����
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
	//����һ���߼�������Ķ�·
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
