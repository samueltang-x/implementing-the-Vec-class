#ifndef GUARD_Vec_h
#define GUARD_Vec_h

#include <memory>
#include <algorithm>
#include <cstddef>

template <class T> class Vec {
public:
	typedef T* iterator;
	typedef const T* const_iterator;
	typedef std::size_t size_type;
	typedef T value_type;

	// default constructor
	Vec() { create(); }
	// explict constructor
	explicit Vec(size_type n, const T& t = T()) { create(n, t); }
	// copy constructor
	Vec(const Vec& v) { create(v.begin(), v.end()); }
	// destructor
	~Vec() { uncreate(); }

	size_type size() const { return avail - data; }

	// indexing operators
	T& operator[](size_type i) { return data[i]; }
	const T& operator[](size_type i) const { return data[i]; }

	// assignment operator
	Vec& operator=(const Vec&);

	iterator begin() { return data; }
	const_iterator begin() const { return data; }

	iterator end() { return avail; }
	const_iterator end() const { return avail; }

	void push_back(const T& val) {
		if (avail == limit)
			grow();
		uncheck_append(val);
	}

	void clear() { uncreate(); }

	void erase(iterator it) {

	}

private:
	iterator data;
	iterator avail;
	iterator limit;

	std::allocator<T> alloc;

	void create();
	void create(size_type, const T&);
	void create(const_iterator, const_iterator);

	void uncreate();

	void grow();
	void uncheck_append(const T&);
};

template <class T> void Vec<T>::create() {
	data = avail = limit = 0;
}

template <class T> void Vec<T>::create(size_type n, const T& t) {
	data = alloc.allocate(n);
	avail = limit = data + n;
	std::uninitialized_fill(data, limit, t);
}

template <class T> void Vec<T>::create(const_iterator b, const_iterator e) {
	data = alloc.allocate(e - b);
	limit = avail = std::uninitialized_copy(b, e, data);
}

template <class T> void Vec<T>::uncreate() {
	if (data) {
		// destroy all elements
		iterator it = avail;
		while (it != data)
			alloc.destroy(--it);

		// return memory
		alloc.deallocate(data, limit - data);
	}
	data = avail = limit = 0;
}

template <class T>
Vec<T>& Vec<T>::operator=(const Vec& rhs) {
	// Check for self-assignment
	if (&rhs != this) {
		uncreate();
		create(rhs.begin(), rhs.end());
	}
	return *this;
}

template <class T> void Vec<T>::grow() {
	size_type new_size = std::max(2* (limit - data), ptrdiff_t(1));

	iterator new_data = alloc.allocate(new_size);
	iterator new_avail = std::uninitialized_copy(data, avail, new_data);

	uncreate();

	data = new_data;
	avail = new_avail;
	limit = data + new_size;
}

template <class T> void Vec<T>::uncheck_append(const T& t) {
	alloc.construct(avail++, t);
}

#endif
