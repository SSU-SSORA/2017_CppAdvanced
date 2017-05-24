/*
 * test.cpp
 *
 *  Created on: 2017. 5. 17.
 *      Author: TaeWook
 */


#include <iostream>

int main(){
	unsigned char value = 10;

	int bits = ~value;
	std::cout << ~value << ", " <<bits << std::endl;
	std::cin.get();
	return 0;
}
