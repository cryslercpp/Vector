#pragma once


#define MAX_SIZE  100000

template <typename T>
class Vector {
public:

	Vector(){
		this->value = new T[this->_capacity];
	}
	Vector(size_t n) {
		 
		this->_capacity = n << 2;
		this->value = new T[this->_capacity];
		for (size_t i = 0; i < n; ++i)
			this->value[i] = T();
		this->count = n;
	}
	Vector(const Vector<T> &other) {
		 
		this->_capacity = other._capacity;
		this->value = new T[this->_capacity];
		for (size_t i = 0; i < other.size(); ++i)
			this->value[i] = other.value[i];
		this->count = other.size();
	}
	~Vector() {
		delete[] this->value;
	}

	T * data() {
		return this->value;
	}
	const T * data() const{
		return this->value;
	}

	bool   empty() const {
		return (this->count == 0);
	}
	size_t size() const {
		return this->count;
	}
	size_t max_size() const {
		return MAX_SIZE;
	}
	size_t capacity() const {
		return this->_capacity;
	}

	void   push_back(const T &val) {
		if (this->count == this->_capacity) {
			this->_capacity <<= 2;
			reallocate();
		}
		this->value[this->count] = val;
		++this->count;
	}

	void   clear() {
		for (size_t i = 0; i < this->count; ++i)
			this->value[i].~T();
		this->count = 0;
	}

	void   resize(size_t val) {
		if (val > this->count) {
			if (val > this->_capacity) {
				this->_capacity = val;
				reallocate();
			}
		}
		else {	 
			for (size_t i = this->count; i < val; ++i)
				this->value[i].~T();
		}
		this->count = val;
	}
	void   reserve(size_t val) {
		if (val > this->_capacity) {
			this->_capacity = val;
			reallocate();
		}
	}

	T & operator [](size_t idx) {
		return this->value[idx];
	}	
	T & at(size_t idx) {
		return this->value[idx];
	}	
	T & front() {
		return this->value[0];
	}	
	T & back() {
		return this->value[this->count - 1];
	}
	


	const T & operator [](size_t idx) const {
		return this->value[idx];
	}
	const T & at(size_t idx) const {
		return this->value[idx];
	}
	const T & front() const {
		return this->value[0];
	}
	const T & back() const {
		return this->value[this->count - 1];
	}


private:
	T * value;
	size_t count;
	size_t _capacity = 4;


	inline void reallocate() {
		T *tmp = new T[this->_capacity];
		memcpy(tmp, this->value, this->count * sizeof(T));
		delete[] this->value;
		this->value = tmp;
	}
	inline void copy(const Vector<T>& other) {
		this->count = other.count;
		this->capacity = other.capacity;
		this->value = new T[other.capacity];
		for (size_t i = 0; i < this->count; i++)
			this->value[i] = other.value[i];
	}

};