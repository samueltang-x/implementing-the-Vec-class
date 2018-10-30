#include "test.h"
#include "Vec.h"
#include "Str.h"

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;


int test_Vec_int() {
	cout << endl << "Testing Vec<int> class: " << endl;
	Vec<int> vi(2, 3);
	cout << "Before push back: " << endl;
	for (Vec<int>::const_iterator i = vi.begin(); i != vi.end(); ++i) {
		cout << *i << endl;
	}
	vi.push_back(4);
	cout << "After push back: " << endl;
	for (Vec<int>::const_iterator i = vi.begin(); i != vi.end(); ++i) {
		cout << *i << endl;
	}
	return 0;
}

int test_Vec_char() {

	cout << endl << "Testing Vec<char> class: " << endl;
	Vec<char> vi(2, 'X');
	cout << "Before push back: " << endl;
	for (Vec<char>::const_iterator i = vi.begin(); i != vi.end(); ++i) {
		cout << *i << endl;
	}
	vi.push_back('T');
	cout << "After push back: " << endl;
	for (Vec<char>::const_iterator i = vi.begin(); i != vi.end(); ++i) {
		cout << *i << endl;
	}
	return 0;
}

int test_Vec_string() {
	cout << endl << "Testing Vec<string> class: " << endl;
	Vec<string> vi(2, "Samuel");
	cout << "Before push back: " << endl;
	for (Vec<string>::const_iterator i = vi.begin(); i != vi.end(); ++i) {
		cout << *i << endl;
	}
	vi.push_back(" Tang");
	cout << "After push back: " << endl;
	for (Vec<string>::const_iterator i = vi.begin(); i != vi.end(); ++i) {
		cout << *i << endl;
	}
	return 0;
}

int test_Str() {
  cout << endl << "Testing Str<char> class: " << endl;
  Str s("Cool, all bugs fixed now!");
  cout << s << endl;
  return 0;
}