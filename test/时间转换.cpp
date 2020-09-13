#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <time.h>
#include <vector>
#include <algorithm>
#include <memory>

using namespace std;


//main()函数的定义
void main(void)
{
	tm info;
	info.tm_year = 2019 - 1900;
	info.tm_mon = 8;
	info.tm_mday = 11;
	info.tm_hour = 0;
	info.tm_min = 0;
	info.tm_sec = 0;
	info.tm_wday = 0;
	time_t tmptime = mktime(&info);
	tmptime += 365 * 24 * 60*60;
	//转换time_t类型的时间字符串并显示
	char *timep = ctime(&tmptime);
	cout << "ctime(&current_time):" << endl;
	cout << timep;
}
