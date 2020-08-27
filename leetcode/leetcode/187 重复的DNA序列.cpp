#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>


using namespace std;

class Solution {
		vector<string> findRepeatedDnaSequences(string s) {
		int L = 10, n = s.length();
		if (n <= L) return{};

		// rolling hash parameters: base a
		int a = 4, aL = (int)pow(a, L);

		// convert string to array of integers
		int toInt[128] = { 0 };
		toInt['A'] = 0;
		toInt['C'] = 1;
		toInt['G'] = 2;
		toInt['T'] = 3;
		vector<int> nums(n);
		for (int i = 0; i < n; ++i) 
			nums[i] = toInt[s[i]];

		int bitmask = 0;
		unordered_map<int,int> seen;
		vector<string> output;
		// iterate over all sequences of length L
		for (int start = 0; start < n - L + 1; ++start) {
			// compute bitmask of the current sequence in O(1) time
			if (start != 0) {
				// left shift to free the last 2 bit
				bitmask <<= 2;
				// add a new 2-bits number in the last two bits
				bitmask |= nums[start + L - 1];
				// unset first two bits: 2L-bit and (2L + 1)-bit
				bitmask &= ~(3 << 2 * L);
			}
			// compute hash of the first sequence in O(L) time
			else {
				for (int i = 0; i < L; ++i) {
					bitmask <<= 2;
					bitmask |= nums[i];
				}
			}
			// update output and hashset of seen sequences
			if (seen[bitmask]==1) 
				output.push_back(s.substr(start, L));
			seen[bitmask]++;
		}
		return output;
	}
}



string trans(int DNA)
{
	const char DNA_CHAR[] = { 'A','C','G','T' };
	string str;
	for (size_t i = 0; i < 10; i++)
	{
		str += DNA_CHAR[DNA & 3];
		DNA = DNA >> 2;
	}
	return str;
}

class Solution {
public:
	vector<string> findRepeatedDnaSequences(string s) {
		vector<string> res;
		unordered_map<int, int> g_map;
		if (s.size()<10)
		{
			return res;
		}
		int char_map[128] = { 0 };
		char_map['A'] = 0;
		char_map['C'] = 1;
		char_map['G'] = 2;
		char_map['T'] = 3;
		int key = 0;
		for (size_t i = 9; i >= 0; i--)
		{
			key = (key *4) + char_map[s[i]];
		}
		g_map[key] = 1;
		for (size_t i = 10; i < s.size(); i++)
		{
			key = key >> 2;
			key = key | (char_map[s[i]] << 18);
			g_map[key]++;
		}
		for (auto& it:g_map)
		{
			if (it.second > 1)
			{
				res.push_back(trans(it.first));
			}
		}
		return res;
	}
};

//¹þÏ£±í
class Solution1 {
public:
	vector<string> findRepeatedDnaSequences(string s) {
		vector<string> res;
		unordered_map<string, int> umap;

		for (int i = 0; i <= s.size()-10; i++)
		{
			umap[s.substr(i, 10)]++;
		}
		for (auto& it : umap)
		{
			if (it.second>1)
			{
				res.push_back(it.first);
			}
		}
		return res;
	}
};

int main()
{
	string s = "ACGTACGTACGT";
	Solution sol;
	sol.findRepeatedDnaSequences(s);

	return 0;
}
