#include <iostream>
using namespace std;

int main(void){
	int x = 23, n = 1;
	int y = x<<n;
	std::cout << x << " << " << n << " = " << y << std::endl;

	y = x >> n;
	std::cout << x << " >> " << n << " = " << y << std::endl;

	x = -105;
	y = x << n;
	std::cout << x << " << " << n << " = " << y << std::endl;

	y = x >> n;
	std::cout << x << " >> " << n << " = " << y << std::endl;


	cin.get();
	return 0;
}
