#ifndef GUARD_Str_h
#define GUARD_Str_h

#include "Vec.h"
#include <algorithm>
#include <istream>
#include <ostream>
#include <iterator>    // back_inserter()

class Str
{
	friend std::istream& operator>>(std::istream&, Str&);

public:
	Str& operator+=(const Str& s) {
		std::copy(s.data.begin(), s.data.end(), std::back_inserter(data));
		return *this;
	}

	typedef Vec<char>::size_type size_type;

	// default constructor
	Str() {}
	
	// create a Str containing n copies of c
	Str(size_type n, char c): data(n, c) {}

	// create a Str from a null-terminated array of char
	Str(const char* p) {
		std::copy(p, p + std::strlen(p), std::back_inserter(data));
	}

	// create a Str from the range denoted by iterators b and e
	template<class In> Str(In b, In e) {
		std::copy(b, e, std::back_inserter(data));
	}

	char& operator[](size_type i) { return data[i]; }
	const char& operator[](size_type i) const { return data[i]; }

	size_type size() const { return data.size(); }

private:
	Vec<char> data;
};

// Overload input operator as non-member function
std::istream& operator>>(std::istream&, Str&);

// Overload output operator as non-member function
std::ostream& operator<<(std::ostream&, const Str&);

Str operator+(const Str&, const Str&);
#endif