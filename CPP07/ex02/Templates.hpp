#ifndef TEMPLATES_HPP
#define TEMPLATES_HPP

#include <exception>
#include <iostream>
#include <stdexcept>

template <typename T>
class Array {
   private:
	T *_array;
	unsigned int _len;

   public:
	// ORTHODOX
	Array() : _array(NULL), _len(0) {}
	Array(unsigned int len) : _len(len) {
		_array = new T[len];
		for (int cnt = 0; cnt < len; cnt++) {
			_array[cnt] = T();
		}
	}

	Array(const Array<T> &idk) : _array(NULL), _len(idk._len) {
		_array = new T[idk._len];
		for (int cnt = 0; cnt < idk._len; cnt++) {
			_array[cnt] = idk._array[cnt];
		}
	}

	T &operator=(const Array<T> &idk) {
		if (this == &idk) return *this;
		delete[] _array;
		_array = new T[_len];
		for (int cnt = 0; cnt < _len; cnt++) {
			_array[cnt] = idk._array[cnt];
		}
		return *this;
	}

	~Array() { delete[] _array; }
	// ADDITIONAL FUNCTIONS
	T &operator[](unsigned int id) {
		if (id >= _len) throw std::logic_error("Hasta la vista, baby");
		return _array[id];
	}

	unsigned int getLen() const { return _len; }
};
#endif