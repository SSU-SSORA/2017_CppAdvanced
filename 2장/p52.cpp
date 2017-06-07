//C와 C++의 호환을 위해 사용함
//책에는 없지만, 윈도우용 외부 라이브러리(DLL)을 작성하기 위해선 필수적인 지식이다.


extern int x;
//extern C++ int x;와 같다
//컴파일러에게 외부 C++내 변수임을 알림->초기화 불가


extern "C" int y;
//C 언어로 제작된 외부 오브젝트 모듈 내 변수임을 선언한다.
//extern "C" {extern int y;}와 같다

extern "C" {int z; }
//이렇게 하면 선언과 함께 정의된 변수로 외부에서 역으로 사용할 수 있다. export용