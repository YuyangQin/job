#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

void buildTree(vector<int>& nums, vector<int>&value, int pos, int left, int right)
{
	if (left == right)
	{
		value[pos] = nums[left];
		return;
	}
	int mid = (left + right) >> 1;
	buildTree(nums, value, 2 * pos + 1, left, mid);
	buildTree(nums, value, 2 * pos + 2, mid + 1, right);
	value[pos] = value[2 * pos + 1] + value[2 * pos + 2];
}
int rangeSum(vector<int>&value, int pos, int left, int right, int qleft, int qright)
{
	if (left>qright || right<qleft)
	{
		return 0;
	}
	if (left >= qleft&&right <= qright)
	{
		return value[pos];
	}
	int mid = (left + right) >> 1;
	return rangeSum(value, 2 * pos + 1, left, mid, qleft, qright) + rangeSum(value, 2 * pos + 2, mid + 1, right, qleft, qright);
}
void updateTree(vector<int>&value, int pos, int left, int right, int index, int newvalue)
{
	if (left == right&&left == index)
	{
		value[pos] = newvalue;
		return;
	}
	int mid = (left + right) >> 1;
	if (index <= mid)
	{
		updateTree(value, 2 * pos + 1, left, mid, index, newvalue);
	}
	else
	{
		updateTree(value, 2 * pos + 2, mid + 1, right, index, newvalue);
	}
	value[pos] = value[2 * pos + 1] + value[2 * pos + 2];
}
class NumArray {
public:
	NumArray(vector<int>& nums) {
		_right_end = nums.size();
		if (_right_end==0)
		{
			return;
		}
		_value.assign(4 * _right_end, 0);
		_right_end--;
		buildTree(nums, _value, 0, 0, _right_end);
	}

	void update(int i, int val) {
		updateTree(_value, 0, 0, _right_end, i, val);
	}

	int sumRange(int i, int j) {
		return rangeSum(_value, 0, 0, _right_end, i, j);
	}
private:
	vector<int> _value;
	int _right_end;
};


int main()
{

	return 0;
}
