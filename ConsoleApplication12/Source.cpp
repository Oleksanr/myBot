#include  <iostream>
#include  <ctime>
using namespace std;

int main()
{
	cout << "My new project" << endl;
	int a = clock();

	cout << a << endl;
	cout << ((float)a / CLOCKS_PER_SEC) << endl;
	system("pause");
	system("pause");
	system("pause");

	return  0;
}