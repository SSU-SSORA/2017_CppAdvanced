#ifndef Array_hpp
#define Array_hpp

#include <exception>
#include <iterator>
#include <initializer_list>

template <typename Type>
class Array {
public:
	typedef std::size_t size_type;

	

	class iterator {
	public:
		typedef Type value_type;
		typedef Type& reference;
		typedef Type* pointer;

		
		//�ݺ��� ī�װ��� �Ʒ��� ���� ������ �־�� ��
		typedef std::random_access_iterator_tag iterator_category;

		//difference_type�� �޸� �ּҸ� ������ ������ ������ �����
		//�迭�� ���� ����Ѵ�. ��ü�� int
		typedef std::ptrdiff_t difference_type;


		//������/����Ʈ ������ ����
		iterator() :_ptr(nullptr) {}
		iterator(Type *rhs) :_ptr(rhs) {}
		iterator(const iterator &rhs) : _ptr(rhs._ptr) {}

		inline iterator& operator=(Type *rhs) { _ptr = rhs; return *this; }
		inline iterator& operator=(const Type& rhs) { _ptr = rhs; return *this; }
		inline iterator& operator+=(difference_type *rhs) { _ptr += rhs; return *this; }
		inline iterator& operator-=(difference_type *rhs) { _ptr -= rhs; return *this; }


		inline Type& operator*() const { return *_ptr; }
		inline Type* operator->() const { return _ptr; }
		inline Type& operator[](difference_type rhs) const { return _ptr[rhs]; }
		

		inline iterator& operator++() { ++_ptr; return *this; }
		inline iterator& operator--() { --_ptr; return *this; }
		inline iterator operator++(int) { iterator temp(*this); ++_ptr; return temp; }
		inline iterator operator--(int) { iterator temp(*this); --_ptr; return temp; }
		
		inline iterator operator+(difference_type rhs) const {
			return iterator(_ptr + rhs);
		}
		inline iterator operator-(difference_type rhs) const {
			return iterator(_ptr - rhs);
		}

		inline difference_type operator+(const iterator& rhs) const {
			return (_ptr + rhs._ptr);
		}
		inline difference_type operator-(const iterator& rhs) const {
			return (_ptr - rhs._ptr);
		}

		friend inline iterator operator+(difference_type lhs, const iterator& rhs) {
			return iterator(lhs + rhs._ptr);
		}
		friend inline iterator operator-(difference_type lhs, const iterator& rhs) {
			return iterator(lhs - rhs._ptr);
		}

		//� �� �����ڴ� Ư�� ��ġ���� �ľ��ϱ� ���� ����Ѵ�.
		
		inline bool operator==(const iterator& rhs) const { return _ptr == rhs._ptr; }
		inline bool operator!=(const iterator& rhs) const { return _ptr != rhs._ptr; }

		//��� �� �������ڴ� ���� �Ǵ� ��ġ�� ������ �ľ��ϱ� ���� ����Ѵ�.
		inline bool operator>(const iterator& rhs) const { return _ptr > rhs._ptr; }
		inline bool operator<(const iterator& rhs) const { return _ptr < rhs._ptr; }
		inline bool operator>=(const iterator& rhs) const { return _ptr >= rhs._ptr; }
		inline bool operator<=(const iterator& rhs) const { return _ptr <= rhs._ptr; }

	private:
		Type* _ptr;
	};

	Array(size_type size = 0) :_size(size) {
		if (0 == size) _data = nullptr;
		else _data = new Type[_size]();//�迭 ������ �Բ� �ʱ�ȭ
	}
	
	template<typename _InputIterator>
	Array(_InputIterator _first, _InputIterator _last) {
		size_type size = _last - _first;
		_data = new Type[size];

		std::copy(_first, _last, _data);
		_size = size;
	}

	Array(std::initializer_list<Type> init) : _size(init.size()) {
		_data = new Type[_size];
		std::copy(init.begin(), init.end(), _data);
	}//�迭�� �ʱ�ȭ

	~Array() {
		if (_data) {
			delete[] _data;
			_size = 0;
		}
	}

	inline size_type size() const { return _size; }

	inline void push_back(Type t) {
		size_type size = _size + 1;
		Type *temp = new Type[size];
		std::copy(_data, _data + _size, temp);

		temp[_size] = t;
		delete[] _data;
		_data = temp;
		_size = size;
	}

	inline Type pop_back() {
		if (0 == _size)
			throw std::runtime_error("Array : ����ֽ��ϴ�.");
		--_size;
		return _data[_size];
	}


	inline Type& operator[](size_type idx) {
		if (idx >= _size || idx < 0)
			throw std::runtime_error("idx�� �߸��Ǿ����ϴ�.");
		return _data[idx];
	}

	inline const Type& operator[](size_type idx) const {
		if (idx >= size || idx < 0)
			throw std::runtime_error("idx�� �߸��Ǿ����ϴ�.");
		return _data[idx];
	}

	iterator begin() {
		return iterator(_data);
	}

	iterator end() {
		return iterator(_data + _size);
	}

	
private:
	Type * _data;
	size_type _size;
};
#endif

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

