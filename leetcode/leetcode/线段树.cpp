#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

class SegmentTree
{
public:
	SegmentTree();
	~SegmentTree();
	void buildTree(vector<int>& nums, vector<int>&value, int pos, int left, int right)
	{
		if (left==right)
		{
			value[pos] = nums[left];
			return;
		}
		int mid = (left + right) >> 1;
		buildTree(nums, value, 2 * pos + 1, left, mid);
		buildTree(nums, value, 2 * pos + 2, mid + 1, right);
		value[pos] = value[2 * pos + 1] + value[2 * pos + 2];
	}
	int rangeSum(vector<int>& nums, vector<int>&value, int pos, int left, int right, int qleft, int qright)
	{
		if (left>qright||right<qleft)
		{
			return 0;
		}
		if (left>=qleft&&right<=qright)
		{
			return value[pos];
		}
		int mid = (left + right) >> 1;
		return rangeSum(nums, value, 2 * pos + 1, left, mid,qleft,qright)+ rangeSum(nums, value, 2 * pos + 2, mid + 1, right, qleft, qright);
	}
	void updateTree(vector<int>& nums, vector<int>&value, int pos, int left, int right, int index, int newvalue)
	{
		if (left==right&&left==index)
		{
			value[pos] = newvalue;
			return;
		}
		int mid = (left + right) >> 1;
		if (index<=mid)
		{
			updateTree(nums, value, 2 * pos + 1, left, mid,index,newvalue);
		}
		else
		{
			updateTree(nums, value, 2 * pos + 2, mid + 1, right, index, newvalue);
		}
		value[pos] = value[2 * pos + 1] + value[2 * pos + 2];
	}

private:

};

SegmentTree::SegmentTree()
{
}

SegmentTree::~SegmentTree()
{
}

int main()
{

	return 0;
}
