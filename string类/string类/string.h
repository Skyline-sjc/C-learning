#pragma once
#include<assert.h>
namespace Skyline {
	class string {
	public:
		typedef char* iterator;
		typedef const char* const_iterator;
		iterator begin(){
			return _str;
		}
		const_iterator begin() const 
		{
			return _str;
		}
		iterator end() {
			return _str + _size;
		}
		const_iterator end() const
		{
			return _str + _size;
		}
		void swap(string& s)
		{
			::swap(_str, s._str);
			::swap(_size, s._size);
			::swap(_capacity, s._capacity);
		}
		string(const char* str = "")
		{
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}

		/*string(const string& str)
		:_str(new char[strlen(str._str) + 1])
		{
			strcpy(_str, str._str);
		}*/
		string(const string& str)
			:_str(nullptr), _size(0), _capacity(0)
		{
			string temp(str._str);
			/*::swap(temp._str,_str);
			::swap(temp._size, _size);
			::swap(temp._capacity, _capacity);*/
			swap(temp);
		}


		/*string& operator=(const string& s) {
			if (s._str != _str) {
				delete[] _str;
				_str = new char[strlen(s._str) + 1];
				strcpy(_str, s._str);
			}
		}*/
		string& operator=(string s) {
			swap(s);
			return *this;
		}


		~string() {
			delete[] _str;
			_str = nullptr;
			_size = 0;
			_capacity = 0;
		}
		

		
		const char& operator[](size_t n) const
		{
			assert(n < _size);
			return _str[n];
		}
		
		char& operator[](size_t n)
		{
			assert(n < _size);
			return _str[n];
		}
		
		size_t size() const
		{
			return _size;
		}
		
		
	const char* c_str() const
		{
			return _str;
		}
		void reserve(size_t n) {
			if (n > _capacity) {
				char* temp = new char[n + 1];
				strncpy(temp, _str,_size);
				delete[] _str;
				_str = temp;
				_capacity = n;
			}

		}//开空间，扩展capacity
	void resize(size_t n,const char val='\0') {
		if (n >= _size) {
			reserve(n);
			for (size_t i = _size; i < n; i++) {
				_str[i] = val;
			}
		}
		if (n < _size) {
			for (size_t i = n; i < _size; i++) {
				_str[i] = val;
			}
			_size = n;
			_str[_size] = '\0';
		}
		}//开空间初始化，扩展capacity，同时_size也要动
		void push_back(char ch) {
			if (_size == _capacity) {
				size_t new_size = _capacity == 0 ? 4 : _capacity * 2;
				reserve(new_size);
			}
			_str[_size] = ch;
			_str[_size + 1] = '\0';
			++_size;
			
		}
		void append(const char* str) {
			size_t len = _size + strlen(str);
			if (len > _capacity) {
				reserve(len);
			}
			strcpy(_str + _size, str);
			_size = len;
		}
		string& operator+=(char ch) {
			push_back(ch);
			return *this;
		}
		string& operator+=(const char* str) {
			append(str);
			return *this;
		}
		string& insert(size_t pos,const char ch) {
			assert(pos <= _size);
			if (_size == _capacity) {
				size_t new_size = _capacity == 0 ? 4 : _capacity * 2;
				reserve(new_size);
			}
			size_t end = _size+1;
			while (end > pos) {
				_str[end] = _str[end-1];
				end--;
			}
			_str[pos] = ch;
			_size++;
			return *this;
		}
		string& insert(size_t pos, const char* str) {
			assert(pos <= _size);
			size_t len = strlen(str);
			if (len+_size > _capacity) {
				reserve(len+_size);
			}
			char* end = _str + _size;
			while (end >=_str+pos) {
				*(end + len) = *end;
				end--;
			}
			strncpy(_str + pos, str, len);
			_size += len;
			return *this;
		}
		string& erase(size_t pos, size_t len=npos) {
			assert(pos <= _size);
			size_t leftlen = _size - pos;
			if (leftlen < len) {
				_str[pos] = '\0';
				_size = pos;
			}
			else {
				strcpy(_str + pos, _str + pos + len);
				_size -= len;
			}
			return *this;
		}
		size_t find(const char ch,size_t pos=0) {
			assert(pos <= _size);
			for (size_t i = pos; i < _size; i++) {
				if (_str[i] == ch) {
					return i;
				}
			}
			return npos;
		}
		size_t find(const char* str, size_t pos = 0) {
			assert(pos <= _size);
			const char *temp= strstr(_str+pos, str);
			if (temp != nullptr) {
				return temp - _str;
			}
			else {
				return npos;
			}
		}
		size_t rfind(const char ch, size_t pos = 0) {
			assert(pos <= _size);
			for (size_t i = _size-1; i >=pos; i--) {
				if (_str[i] == ch) {
					return i;
				}
			}
			return npos;
		}
		size_t rfind(const char* str, size_t pos = 0) {
			assert(pos <= _size);
			string temp;
			const char* end = _str + _size-1;
			while (end >= _str + pos) {
				temp += *end;
				end--;
			}
			string find_temp;
			for (int i = strlen(str) - 1; i >= 0; i--) {
				find_temp += str[i];
			}
			const char* t = strstr(temp._str, find_temp._str);
			if (t != nullptr) {
				return _size-(t+strlen(str)-temp._str);
			}
			else {
				return npos;
			}
		}
    inline bool operator<(const string& s) {
			if (strcmp(_str, s._str) < 0) {
				return true;
			}
			return false;
		}
    inline bool operator>(const string& s) {
			return !(*this < s);
		}
	inline bool operator<=(const string& s) {
			return (*this < s) || (*this == s);
		}
	inline bool operator>=(const string& s) {
			return (*this > s) || (*this == s);
		}
	inline bool operator==(const string& s) {
			return !(strcmp(_str, s._str));
		}
	inline bool operator!=(const string& s) {
			return !(*this == s);
		}
	void clear() {
		_size = 0;
		_str[0] = '\0';
	}

	private:
		char* _str;
		size_t _size;
		size_t _capacity;
		static const size_t npos;
	};
	const size_t string::npos = 1;
	ostream& operator<<(ostream& out, const string& s1) {
		for (auto ch : s1) {
			out << ch;
		}
		return out;
	}
	istream& operator>>(istream& in, string& s1) {
		s1.clear();
		char ch=in.get();
		while (ch != ' ' && ch != '\n') {
			s1 += ch;
			ch = in.get();
		}
		return in;
	}
	istream& getline(istream& in, string& s1) {
		s1.clear();
		char ch = in.get();
		while (ch != '\n') {
			s1 += ch;
			ch = in.get();
		}
		return in;
	}
	void test_string_s() {
		string s1("hello hello");
		cout << s1.rfind("ello") << endl;
	}
	//void test_string3()
	//{
	//	string s1("hello world");
	//	string::iterator it = s1.begin();
	//	while (it != s1.end())
	//	{
	//		cout << *it << " ";
	//		++it;
	//	}
	//	cout << endl;

	//	// 看起来很神奇，但是原理很简单，这个范围for会被编译器替换成迭代器形式
	//	// 也就是说范围for是有迭代器支持的
	//	for (auto ch : s1)
	//	{
	//		cout << ch << " ";
	//	}
	//	cout << endl;
	//}
}


