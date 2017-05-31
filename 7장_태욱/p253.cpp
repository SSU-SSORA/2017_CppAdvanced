#include <iostream>
#include <string>
using namespace std;

template <typename T>
struct my_map {
	my_map(T t) : data(t) {}
	T GetData() {
		return data;
	}
private:
	T data;
};

template<typename K,  typename V, template<typename A> typename C = my_map>
class Map {
public:
	Map(K k, V v) :key(k), value(v) {}
	K GetKey() {
		return key.GetData();
	}
	V GetValue() {
		return value.GetData();
	}

private:
	C<K> key;
	C<V> value;
};

int main(void) {
	Map<int, string, my_map> map(1000, "ÅÛÇÃ¸´ ÅÛÇÃ¸´ ÀÎ¼ö");
	cout << "Map(" << map.GetKey() << ", " << map.GetValue().c_str() << ")\n";

}