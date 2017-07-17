#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cassert>
#include <initializer_list>

template <typename Type>
class Array {
public:
	typedef int size_type;
	class iterator {
	public:
		typedef Type value_type;
		typedef Type& reference;
		typedef Type * pointer;

		//�ݺ��� ī�ױ� ���� �ݵ�� ������ �־�� �Ѥ�, �ƴϸ� �������� �߻��Ѵ�.
		typedef std::forward_iterator_tag iterator_category;
		typedef std::ptrdiff_t difference_type;

		//���� Ŭ������ ������/����Ʈ �����ڸ� �����
		iterator(pointer ptr = nullptr) :_ptr(ptr) {}

		//���� ����/���� �����ڸ� ����
		iterator operator++() { ++_ptr; return *this; }
		iterator operator++(int) { iterator tmp(*this); ++_ptr; return tmp; }
	
		reference operator*() { return *_ptr; }
		pointer operator->() { return _ptr; }

		bool operator==(const iterator& rhs) {
			return (_ptr == rhs._ptr);
		}
		bool operator!=(const iterator& rhs) {
			return  (_ptr!= rhs._ptr);
		}
	private:
		Type* _ptr;
	};

	Array(size_type size = 0) :_size(size) {
		if (0 == size) _data = nullptr;
		else _data = new Type[_size]();//�迭 ������ �Բ� �ʱ�ȭ
	}

	Array(std::initializer_list<Type> init) : _size(init.size()) {
		_data = new Type[_size];
		std::copy(init.begin(), init.end(), _data);
	}//�迭�� �ʱ�ȭ

	template<typename _InputIterator>
	inline Array(_InputIterator _first, _InputIterator _last) {
		size_type size = _last - _first;
		_data = new Type[size];

		std::copy(_first, _last, _data);
		_size = size;
	}

	~Array() {
		if (_data) {
			delete[] _data;
			_size = 0;
		}
	}

	inline size_type size() const { return _size; }

	Type& operator[](size_type idx) {
		assert(idx < _size);
		return _data[idx];
	}

	const Type& operator[](size_type idx) const {
		assert(idx < _size);
		return _data[idx];
	}

	iterator begin() {
		return iterator(_data);
	}

	iterator end() {
		return iterator( _data + _size);
	}

private:
	Type * _data;
	size_type _size;
};


struct Account {
	Account() = default;
	Account(const char * id, const char * name, int bal) {
		strcpy(this->account, id);
		strcpy(this->name, name);
		this->balance = bal;
	}
	char account[20];
	char name[20];
	int balance;
};

int main() {
	Array<double> array = { 2.3, 3.2, 4.3, 16.78, 9.4, 3.14 };
	for (Array<double>::iterator i = array.begin();
		i != array.end(); ++i)
		std::cout << *i << " ";

	Array<Account> list = {
		{"120-345-129099","ȫ�浿",60000},
		{"120-345-223011","��ȫ��",10000},
		{"210-545-144011","�Ż��Ӵ�",50000}
	};

	for (auto& i : list) {
		printf("�� �� : %s, ������ : %s", i.account, i.name);
		printf(", �ܾ� : %i\n", i.balance);
	}

	std::vector<double> vec;
	std::copy(array.begin(), array.end(), std::back_inserter(vec));

	for (std::vector<double>::iterator i = vec.begin();
		i != vec.end(); ++i) {
		std::cout << *i << " ";
	}
	std::cout << std::endl;
	return 0;

}