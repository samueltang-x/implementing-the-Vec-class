#include "Str.h"
#include <istream>
#include <ostream>
#include <iostream>
#include <cctype>    // isspace

using std::istream;
using std::ostream;
using std::cout;
using std::endl;
using std::isspace;

ostream& operator<<(ostream& os, const Str& s) {
	for (Str::size_type i = 0; i != s.size(); ++i)
		os << s[i];
	return os;
}

istream& operator>>(istream& is, Str& s) {
	s.data.clear();

	char c;
	while (is.get(c) && isspace(c))
		;

	if (is) {
		do s.data.push_back(c);
		while (is.get(c) && !isspace(c));

		if (is)
			is.unget();
	}

	return is;
}

Str operator+(const Str& s, const Str& t) {
	Str r = s;
	r += t;
	return r;
}
