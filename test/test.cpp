#include	<iostream>
using namespace	std;
struct	A {
	int	data;
};
int	main(void)
{

	const	A	a = { 200 };
	/*A	a1 = const_cast<A>(a);
	a1.data = 300;*/
	A	&a2 = const_cast<A&>(a);
	a2.data = 300;
	cout << a.data << a2.data << endl;
	A	*a3 = const_cast<A*>(&a);
	a3->data = 400;
	cout << a.data << a3->data << endl;

	const int	x = 3;

	int	&x1 = const_cast<int&>(x);
	x1 = 300;
	cout << x << x1 << endl;

	int	*x2 = const_cast<int*>(&x);
	*x2 = 400;
	cout << x << *x2 << endl;

	return 0;
}