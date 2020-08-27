#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	int findNthDigit(int n) {
		if (n < 10)
			return n;
		int bit=1;//λ��
		int pre;//ǰһλ������󳤶�
		long length=9;//��λ������󳤶�
		int nth;//��¼Ϊ��λ���µĵڼ�λ��		
		int num;//��¼Ϊ��״̬�µĵڼ�λ���Ķ���λ
		int number;//���շ��ص���

		while (n>length)
		{
			bit++;
			pre = length;
			length += (9 * pow(10, bit - 1)*bit);
		}
		nth = (n-1 - pre) / bit;
		num = (n-1 - pre) % bit;
		number = pow(10, bit-1) + nth;

		return getNum(number, num, bit);
	}
	int getNum(int number, int num,int bit)
	{
		string a = to_string(number);
		return a[num]-'0';
	}

};


void main()
{
	Solution s;
	cout << pow(2, 31) << endl;

	cout<<s.findNthDigit(190);
}
