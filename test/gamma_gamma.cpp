#include <random> 
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <vector>
#include <set>

using namespace std;

const double PI = 3.1415926;
double a, b;

double count0(double y, double sigma) {
	double res;
	res = exp(-1 * pow(y, 2) / (2 * sigma*sigma)) / sqrt(2 * PI*sigma*sigma);
	return res;
}

double count1(double y, double sigma) {
	double res=0;
	res = exp(-1 * pow(y - 1, 2) / (2 * sigma*sigma)) / sqrt(2 * PI*sigma*sigma);
	/*for (double i = 0.01; i <= 30; i += 0.01)
	{
		res += 0.01*exp(-1 * pow(y - i, 2) / (2 * sigma * sigma)) / sqrt(2 * PI * sigma * sigma) * 2 * pow(a * b, (a + b) / 2) * pow(i, (a + b) / 2 - 1) * cyl_bessel_k(a - b, 2 * sqrt(a * b * i)) / (tgamma(a) * tgamma(b));
	}*/
	return res;
}

double GasCount1(double y, double u,double sigma) {
	double res = 0;
	res = exp(-1 * pow(y - u, 2) / (2 * sigma*sigma)) / (sqrt(2 * PI)* sigma);
	/*for (double i = 0.1; i <= 4; i += 0.1)
	{
		res += 0.1 * exp(-1 * pow(y + i, 2) / (2 * sigma * sigma)) / sqrt(2 * PI * sigma * sigma) * 2 * pow(a * b, (a + b) / 2) * pow(i, (a + b) / 2 - 1) * cyl_bessel_k(a - b, 2 * sqrt(a * b * i)) / (tgamma(a) * tgamma(b));
	}*/
	return res;
}

void test1(double EbN0dB)
{
	double times = 100000;
	vector<double> x(times);
	vector<double> y(times);
	vector<double> LLR(times);
	gamma_distribution<double> distrx(a, 1 / a);
	gamma_distribution<double> distry(b, 1 / b);
	double EbN0 = pow(10., EbN0dB / 10.);
	double sigma = sqrt(1 / (2 * 0.5 * EbN0));
	normal_distribution<double> gas(0, sigma);
	default_random_engine d;

#if 0//高斯近似
	double max = 0;
	double pos;
	double tmp;
	double mSigma;
	for (double i = 0; i <= 1; i+=0.001)
	{
		tmp = count1(i, sigma);
		if (tmp>max)
		{
			max = tmp;
			pos = i;
		}
	}
	mSigma = 1 / sqrt(2 * PI) / max;
	cout << pos << " " << mSigma << endl;
	for (double i = -6; i <= 6; i+=0.1)
	{
		cout << GasCount1(i,pos,mSigma) << " ";
	}
#else
	double tmp,p0,p1;
	double errRate = 0;
	double scalar = 1.0 / ((sqrt(2 * PI)) * sigma);
	for (size_t i = 0; i < times; i++)
	{
		//随机生成码元
		x[i] = rand() % 2;
		//经过信道
		tmp = distrx(d) * distry(d);
		y[i] = x[i]*tmp + gas(d);
		p0 = scalar * exp(-1 * pow(y[i] + tmp, 2.0) / (2 * sigma * sigma));
		p1 = scalar * exp(-1 * pow(y[i] - tmp, 2.0) / (2 * sigma * sigma));
		
		if (p0>p1)
		{
			if (x[i]==1)
			{
				errRate++;
			}	
		}
		else
		{
			if (x[i] == 0)
			{
				errRate++;
			}
		}
	}
	cout <<  EbN0dB << "dB:  " << errRate / times << endl;

	//cout << max << "  " << min << endl;
#endif
}


void kPPMmod(vector<double>& x, vector<double>& a, int k)
{
	static int m = log2(k);
	double tmp;
	for (size_t i = 0; i < x.size() / m; i++)
	{
		tmp = 0;
		for (int j = 0; j < m; j++)
		{
			tmp *= 2;
			tmp += x[i * m + j];
		}
		tmp++;
		a[i * k + k - tmp] = 1;
	}
}

void kPPMdemod(vector<double>& x, vector<double>& a, int k)
{
	static int m = log2(k);
	int tmp,pos;
	double max;
	for (size_t i = 0; i < a.size()/k; i++)
	{
		max = a[i*k];
		tmp = k - 1;
		for (int j = 1; j < k; j++)
		{
			if (a[i*k+j]>max)
			{
				tmp=k-j-1;
				break;
			}
		}
		for (size_t j = 0; j < m; j++)
		{
			pos = tmp % 2;
			if (tmp>0)
			{
				tmp /= 2;
			}			
			x[i * m + m-j-1] = pos;
		}
	}
}

void kPPMmod2(vector<double>& x, vector<double>& a, int k)
{
	static int m = log2(k);
	double tmp;
	for (size_t i = 0; i < x.size() / m; i++)
	{
		tmp = 0;
		for (int j = 0; j < m; j++)
		{
			tmp += pow(2, j) * x[i * m + j];
		}
		a[i * k + tmp] = 1;
	}
}

//简化软判
void kPPMdemod2(vector<double>& y, vector<double>& a, vector<double>& prob0, vector<double>& prob1, int k)
{
	static int m = log2(k);
	int  pos,tmp;
	double sum,rate;
	for (size_t i = 0; i < a.size() / k; i++)
	{
		sum = 0;
		rate = 0;
		for (int j = 0; j < k; j++)
		{
			sum += abs(a[i * k + j]);
		}
		for (int j = 0; j < k; j++)
		{
			rate = abs(a[i * k + j]) / sum;
			tmp = j;
			for (size_t l = 0; l < m; l++)
			{
				pos = tmp % 2;
				if (tmp > 0)
				{
					tmp /= 2;
				}
				if (pos==0)
				{
					prob0[i * m + l] += rate;
				}
				else
				{
					prob1[i * m + l] += rate;
				}
			}
		}		
	}
	for (size_t i = 0; i < y.size(); i++)
	{
		if (log(prob0[i]/prob1[i])>0)
		{
			y[i] = 0;
		}
		else
		{
			y[i] = 1;
		}
	}
}

//My软判
void kPPMdemod3(vector<double>& y, vector<double>& a, vector<double>& prob0, vector<double>& prob1, int k,double sigma)
{
	static int m = log2(k);
	static vector<double> mProb0(k);
	static vector<double> mProb1(k);
	static vector<double> Probk(k);
	int  pos, tmp;
	double sum, rate;
	for (size_t i = 0; i < a.size() / k; i++)
	{
		for (int j = 0; j < k; j++)
		{
			Probk[j] = 1;
		}
		sum = 0;
		for (int j = 0; j < k; j++)
		{
			mProb0[j] = count0(a[i * k + j], sigma);
			mProb1[j] = count1(a[i * k + j],sigma);
		}
		for (int j = 0; j < k; j++)
		{
			tmp = j;
			for (size_t l = 0; l < k; l++)
			{
				if (l==j)
				{
					Probk[j] *= mProb1[l];
				}
				else
				{
					Probk[j] *= mProb0[l];
				}
			}
			sum += Probk[j];
		}
		for (int j = 0; j < k; j++)
		{
			Probk[j] /= sum;
			tmp = j;
			for (size_t l = 0; l < m; l++)
			{
				pos = tmp % 2;
				if (tmp > 0)
				{
					tmp /= 2;
				}
				if (pos == 0)
				{
					prob0[i * m + l] += Probk[j];
				}
				else
				{
					prob1[i * m + l] += Probk[j];
				}
			}
		}
	}
	for (size_t i = 0; i < y.size(); i++)
	{
		if (log(prob0[i] / prob1[i]) > 0)
		{
			y[i] = 0;
		}
		else
		{
			y[i] = 1;
		}
	}
}

void test3(double EbN0dB)
{
	double times = 100000;
	int k = 4;
	int m = log2(k);
	vector<double> x(times);
	vector<double> mod(times * k / log2(k));
	vector<double> y(times);
	gamma_distribution<double> distrx(a, 1 / a);
	gamma_distribution<double> distry(b, 1 / b);
	double EbN0 = pow(10., EbN0dB / 10.);
	double sigma = sqrt(1 / (2 * 0.5 * EbN0));
	normal_distribution<double> gas(0, sigma);
	default_random_engine d;

	for (int i = 0; i < x.size(); i++)
	{
		x[i] = rand() % 2;	
	}
	kPPMmod(x, mod, k);
	for (int i = 0; i < mod.size(); i++)
	{
		mod[i] = distrx(d) * distry(d) * mod[i] + gas(d);
	}
	kPPMdemod(y, mod, k);
	double count = 0;
	for (int i = 0; i < times; i++)
	{
		if (x[i] != y[i])
			count++;
	}
	cout << count / times << endl;
}
void test4(double EbN0dB)
{
	double times = 2;
	int k = 4;
	int m = log2(k);
	vector<double> x(times);
	vector<double> mod(times * k / log2(k));
	vector<double> y(times);
	vector<double> prob0(times);
	vector<double> prob1(times);
	gamma_distribution<double> distrx(a, 1 / a);
	gamma_distribution<double> distry(b, 1 / b);
	double EbN0 = pow(10., EbN0dB / 10.);
	double sigma = sqrt(1 / (2 * 0.5 * EbN0));
	normal_distribution<double> gas(0, sigma);
	default_random_engine d;

	for (int i = 0; i < x.size(); i++)
	{
		x[i] = rand() % 2;
	}
	kPPMmod2(x, mod, k);
	for (int i = 0; i < mod.size(); i++)
	{
		mod[i] = distrx(d) * distry(d) * mod[i] + gas(d);
	}
	kPPMdemod3(y, mod, prob0, prob1, k,sigma);
	double count = 0;
	for (int i = 0; i < times; i++)
	{
		if (x[i] != y[i])
			count++;
	}
	cout << count / times << endl;
}

double rate1(double y, double sigma, double h)
{
	double res;
	res = exp(-1 * pow(y-h, 2) / (2 * sigma * sigma)) / sqrt(2 * PI * sigma * sigma);
	return res;
}
void mysort(vector<double>& data, vector<double>& p1)
{
	for (int j = 0; j < data.size()-1; j++)
		for (int i = 0; i < data.size() - 1 - j; i++) {
			if (data[i] > data[i + 1]) {
				swap(data[i], data[i + 1]);
				swap(p1[i], p1[i + 1]);
			}
		}
}
void test5(double EbN0dB)
{
	double times = 10000;
	vector<double> x(times);
	vector<double> y(times);
	vector<double> h(times);
	vector<double> p0(times);
	vector<double> p1(times);
	gamma_distribution<double> distrx(a, 1 / a);
	gamma_distribution<double> distry(b, 1 / b);
	double EbN0 = pow(10., EbN0dB / 10.);
	double sigma = sqrt(1 / (2 * 0.5 * EbN0));
	normal_distribution<double> gas(0, sigma);
	double tmp;
	int count=0;
	default_random_engine d;
	for (size_t i = 0; i < times; i++)
	{
		x[i] = rand() % 2;
		h[i] = distrx(d) * distry(d);
		y[i] = h[i] * x[i] + gas(d);
		p0[i] = count0(y[i],sigma);
		p1[i] = rate1(y[i], sigma, h[i]);
		if ((p0[i]>p1[i])&&x[i]==1)
		{
			count++;
		}
		else if(x[i]==0)
		{
			count++;
		}
	}
	cout << count / times << endl;
}

//
//My软判
void kPPMdemod4(vector<double>& y, vector<double>& a, vector<double>& h,vector<double>& prob0, vector<double>& prob1, int k, double sigma)
{
	static int m = log2(k);
	static vector<double> mProb0(k);
	static vector<double> mProb1(k);
	static vector<double> Probk(k);
	int  pos, tmp;
	double sum, rate;
	for (size_t i = 0; i < a.size() / k; i++)
	{
		for (int j = 0; j < k; j++)
		{
			Probk[j] = 1;
		}
		sum = 0;
		for (int j = 0; j < k; j++)
		{
			mProb0[j] = count0(a[i * k + j], sigma);
			mProb1[j] = rate1(a[i * k + j], sigma, h[i * k + j]);
		}
		for (int j = 0; j < k; j++)
		{
			tmp = j;
			for (size_t l = 0; l < k; l++)
			{
				if (l == j)
				{
					Probk[j] *= mProb1[l];
				}
				else
				{
					Probk[j] *= mProb0[l];
				}
			}
			sum += Probk[j];
		}
		for (int j = 0; j < k; j++)
		{
			Probk[j] /= sum;
			tmp = j;
			for (size_t l = 0; l < m; l++)
			{
				pos = tmp % 2;
				if (tmp > 0)
				{
					tmp /= 2;
				}
				if (pos == 0)
				{
					prob0[i * m + l] += Probk[j];
				}
				else
				{
					prob1[i * m + l] += Probk[j];
				}
			}
		}
	}
	for (size_t i = 0; i < y.size(); i++)
	{
		if (log(prob0[i] / prob1[i]) > 0)
		{
			y[i] = 0;
		}
		else
		{
			y[i] = 1;
		}
	}
}
//高斯软判算PPM误码率，概率校正
void test6(double EbN0dB)
{
	double times = 1000000;
	int k = 16;
	double m = log2(k);
	vector<double> x(times);
	vector<double> mod(times * k / log2(k));
	vector<double> h(times * k / log2(k));
	vector<double> y(times);
	vector<double> prob0(times);
	vector<double> prob1(times);
	gamma_distribution<double> distrx(a, 1 / a);
	gamma_distribution<double> distry(b, 1 / b);
	double EbN0 = pow(10., EbN0dB / 10.);
	double sigma = sqrt(1 / (2 * 0.5 * EbN0));
	normal_distribution<double> gas(0, sigma);
	default_random_engine d;

	for (int i = 0; i < x.size(); i++)
	{
		x[i] = 0;
	}
	kPPMmod2(x, mod, k);
	for (int i = 0; i < mod.size(); i++)
	{
		h[i] = distrx(d) * distry(d);
		mod[i] = h[i] * mod[i] + gas(d);
	}
	kPPMdemod4(y, mod, h, prob0, prob1, k, sigma);
	double count = 0;
	for (int i = 0; i < times; i++)
	{
		if (x[i] != y[i])
			count++;
	}
	cout << count / times << endl;
}

void kPPMde5(vector<double>& y, vector<double>& prob0, vector<double>& prob1, vector<double>& I, int N, int k, double sigma)
// fill y with mean= -1 and variance sigma^2 Gaussian
// This corresponds to the all-zero vector
{
	int  pos, tmp;
	double sum, rate;
	static int mm = log2(k);
	static double* mProb0 = new double[k];
	static double* mProb1 = new double[k];
	static double* Probk = new double[k];

	for (size_t i = 0; i < N; i++)
	{
		prob0[i] = 0;
		prob1[i] = 0;
	}
	for (size_t i = 0; i < N * mm / k; i++)
	{
		for (int j = 0; j < k; j++)
		{
			Probk[j] = 1;
		}
		sum = 0;
		for (int j = 0; j < k; j++)
		{
			mProb0[j] = exp(-1 * pow(y[i * k + j], 2) / (2 * sigma * sigma)) / sqrt(2 * PI * sigma * sigma);
			mProb1[j] = exp(-1 * pow(y[i * k + j] - I[i * k + j], 2) / (2 * sigma * sigma)) / (sqrt(2 * PI) * sigma);
			//Probk[j] = pow(y[i * k + j], 2);
			//sum += Probk[j];
		}
		for (int j = 0; j < k; j++)
		{
			tmp = j;
			for (size_t l = 0; l < k; l++)
			{
				if (l == j)
				{
					Probk[j] *= mProb1[l];
				}
				else
				{
					Probk[j] *= mProb0[l];
				}
			}
			sum += Probk[j];
		}
		for (int j = 0; j < k; j++)
		{
			Probk[j] /= sum;
			tmp = j;
			for (size_t l = 0; l < mm; l++)
			{
				pos = tmp % 2;
				if (tmp > 0)
				{
					tmp /= 2;
				}
				if (pos == 0)
				{
					prob0[i * mm + l] += Probk[j];
				}
				else
				{
					prob1[i * mm + l] += Probk[j];
				}
			}
		}
	}
}
static int graniset = 0;
static double grangset;

double gran(void)
{
	double rsq, v1, v2, fac;

	if (!graniset) {
		graniset = 1;
		do {
			v1 = 2 * (rand() / (double)RAND_MAX) - 1;
			v2 = 2 * (rand() / (double)RAND_MAX) - 1;
			rsq = v1 * v1 + v2 * v2;
		} while (rsq > 1 || rsq == 0);
		fac = sqrt(-2 * log(rsq) / rsq);
		grangset = v1 * fac;
		return v2 * fac;
	}
	else {
		graniset = 0;
		return grangset;
	}
}
void randvec(vector<double>& y, vector<double>& mod, vector<double>& I, int N, double sigma)
// fill y with mean= -1 and variance sigma^2 Gaussian
// This corresponds to the all-zero vector
{
	static double a = 17.13, b = 16.04;//alpha,beta
	static gamma_distribution<double> distra(a, 1 / a);
	static gamma_distribution<double> distrb(b, 1 / b);
	static default_random_engine d;
	int i;
	for (i = 0; i < N; i++) {
		I[i] = distra(d) * distrb(d);
		y[i] = mod[i] * I[i] + sigma * gran();
	}
}
void kPPM7(vector<double>& mod, int N, int k)
// This corresponds to the all-zero vector
{
	for (size_t i = 0; i < N; i++)
	{
		mod[i] = 0;
	}
	for (size_t i = 0; i < N / k; i++)
	{
		mod[i * k] = 1;
	}
}
//LDPC译码测试
void test7(double EbN0dB)
{
	double times = 2304;
	int k = 4;
	double m = log2(k);
	vector<double> x(times);
	vector<double> mod(times * k / log2(k));
	vector<double> I(times * k / log2(k));
	vector<double> y(times * k / log2(k));
	vector<double> prob0(times);
	vector<double> prob1(times);
	vector<double> p(times);
	gamma_distribution<double> distrx(a, 1 / a);
	gamma_distribution<double> distry(b, 1 / b);
	double EbN0 = pow(10., EbN0dB / 10.);
	double sigma = sqrt(1 / (2 * 0.5 * EbN0) / (k / 2));
	normal_distribution<double> gas(0, sigma);
	default_random_engine d;

	for (int i = 0; i < x.size(); i++)
	{
		x[i] = 0;
	}
	kPPMmod2(x,mod, k);
	//randvec(y, mod, I, times * k / m, sigma);
	for (int i = 0; i < y.size(); i++) {
		I[i] = distrx(d) * distry(d);
		y[i] = mod[i] * I[i] + sigma * gran();
	}
	kPPMde5(y, prob0, prob1, I, times, k, sigma);
	double count = 0;
	for (int i = 0; i < times; i++)
	{
		p[i] = prob1[i] / (prob0[i] + prob1[i]);
		if (p[i]<0.5)
		{
			count++;
		} 
	}
	cout << count/times << endl;
}

void test8(double EbN0dB)
{
	double times = 10000000;
	vector<double> x(times);
	vector<double> y(times);
	vector<double> I(times);
	vector<double> p0(times);
	vector<double> p1(times);
	vector<double> LLR(times);
	gamma_distribution<double> distrx(a, 1 / a);
	gamma_distribution<double> distry(b, 1 / b);
	double EbN0 = pow(10., EbN0dB / 10.);
	double sigma = sqrt(1 / (2 * 0.5 * EbN0));
	normal_distribution<double> gas(0, sigma);
	default_random_engine d;

	double tmp = 0;
	double errRate = 0;
	double max = 0, min = 0;
	for (size_t i = 0; i < times; i++)
	{
		//随机生成码元
		x[i] = rand() % 2;
		//经过信道
		I[i] = distrx(d) * distry(d);
#if 1	//bpsk
		if (x[i]==0)
		{
			y[i] = (-1) * I[i] + sigma * gran();
		}
		else
		{
			y[i] =  I[i] + sigma * gran();
		}
		
		////判决
		p0[i] = exp(-1 * pow(y[i] + I[i], 2) / (2 * sigma * sigma)) / (sqrt(2 * PI) * sigma);
		p1[i] = exp(-1 * pow(y[i] - I[i], 2) / (2 * sigma * sigma)) / (sqrt(2 * PI) * sigma);
#elif	//ook
		y[i] = x[i] * I[i] + sigma * gran();
		////判决
		p0[i] = exp(-1 * pow(y[i], 2) / (2 * sigma * sigma)) / sqrt(2 * PI * sigma * sigma);
		p1[i] = exp(-1 * pow(y[i] - I[i], 2) / (2 * sigma * sigma)) / (sqrt(2 * PI) * sigma);
		
#endif // 0

		tmp = p0[i] > p1[i] ? 0 : 1;
		if (tmp != x[i])
		{
			errRate++;
		}
	}
	cout << errRate / times << endl;

	//cout << max << "  " << min << endl;
}

void test2(double EbN0dB)
{
	double times = 100000;
	
	vector<double> count(50,0);
	gamma_distribution<double> distrx(a, 1 / a);
	gamma_distribution<double> distry(b, 1 / b);
	default_random_engine d;

	double tmp;
	int pos;
	for (size_t i = 0; i < times; i++)
	{
		tmp = distrx(d) * distry(d);
		pos = tmp * 10;
		if (pos>49)
		{
			continue;
		}
		count[pos]++;
	}
	for (size_t i = 0; i < 50; i++)
	{
		cout << count[i] << endl;
	}
}

void test_3()
{
	double tmp, tmpPos;
	for (size_t i = 0; i < 50; i++)
	{
		tmpPos = i * 0.1;
		tmp = 0;
		for (size_t j = 0; j < 10; j++)
		{
			tmpPos += 0.01;
			tmp += 2 * pow(a * b, (a + b) / 2) * pow(tmpPos, (a + b) / 2 - 1) * cyl_bessel_k(a - b, 2 * sqrt(a * b * tmpPos)) / (tgamma(a) * tgamma(b));;
		}
		cout << tmp*0.01<< endl;
	}
}

int main()
{
	a = 17.13;
	b = 16.04;
	//test2(15);
	//test2();
	for (size_t i = 0; i <= 20; i++)
	{
		test8(i);
	}
	system("pause");
}