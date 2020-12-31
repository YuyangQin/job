#include <random> 
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;
double a, b;

double test(double I) {
	double res;
	res = 2*pow(a*b, (a + b) / 2)*pow(I, (a + b) / 2 - 1)*(a - b, 2 * sqrt(a*b*I)) / (tgamma(a)*tgamma(b));
	return res;
}

int main()
{
	double i = 0;
	a = 17.13;
	b = 16.04;
	/*for ( i = 1; i <= 30; i+=0.01)
	{
		cout << test(i) << endl;
	}*/
	gamma_distribution<double> distrx(a, 1 / a);
	gamma_distribution<double> distry(b, 1/b);
	normal_distribution<double> gas(0, 0.7943);
	random_device d;
#if 0
	double sum = 0;
	for (double i = 0.5; i < 20; i += 0.5)
	{
		cout << test2(i, 9, 2) << endl;
		sum += 0.05*test2(i, b, b);
	}
	cout << sum << endl;
#endif // 0
	double ratio[301] = { 0 };
	double tmp;
	double sum=0;
	for (size_t i = 0; i < 100; i++)
	{
		tmp = distrx(d)*distry(d) + gas(d);
		cout << tmp << " ";
		sum++;
		if (sum == 10)
		{
			cout << endl;
			sum = 0;
		}
		/*for (int i = 300; i >= 0; i--)
		{

			if (tmp >= i*0.1)
			{
				ratio[i]++;
				break;
			}
		}*/
	}	
	/*for (size_t i = 0; i < 301; i++)
	{
		cout << ratio[i] / 1000000 << endl;
	}*/
}