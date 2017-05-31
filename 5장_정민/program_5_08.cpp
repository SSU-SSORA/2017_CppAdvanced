#include<iostream>
#include<string>

int general(int i){
	return i >= 0 ? i : -i;
}

#define unsafe(i)( (i) >= 0 ? (i) : (-i) ) //메크로 함수

//인라인 함수
inline int safe(int i) {
	return i >= 0 ? i : -i;
}

//싱수표현식
constexpr int expr(int i) {
	return i >= 0 ? i : -i;
}

int main()
{
	int ans, x = 0;

	// 1. 일반 함수를 호출하여 실행시킨 예
	ans = general(x++);
	std::cout << "general(x++) = " << ans << ", " << x << std::endl;


	// 2. 메크로 실행
	x = 0;
	ans = unsafe(x++);
	std::cout << " unsafe(x++) = " << ans << ", " << x << std::endl;
	x = 0;

	// 3. 인라인 함수 실행
	ans = safe(x++);
	std::cout << " safe(x++) = " << ans << ", " << x << std::endl;
	x = 0;


	// 4. 상수표현식 실행
	x = 0;
	ans = expr(x++);
	std::cout << " expr(x++) = " << ans << ", " << x << std::endl;
	return 0;
}


