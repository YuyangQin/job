#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<fstream>
#include<sstream>
#include <vector>
#include <string>

using namespace std;

 vector< string> split(const  string& s, char delimiter)
{
	 vector< string> tokens;
	 string token;
	 istringstream tokenStream(s);
	while ( getline(tokenStream, token, delimiter))
	{
		tokens.push_back(token);
	}
	return tokens;
}


int main()
{	split("1 2 3 4 5", ' ');
	return 0;
}
