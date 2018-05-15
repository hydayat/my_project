// Your code here
#include<cstring>
#include<iostream>
using namespace std;
class mybool {
public:
	bool cnmb;
};
mybool mb;
class MyString {
public:
	friend ostream &operator<<(ostream &os, const MyString &mystr);

	MyString();
	MyString(const char* p1);
	MyString(const MyString& mystr);
	~MyString();
	int size()const;
	char& operator[](int x) const {
		return *(p_begin + x);
	}
	friend mybool& operator==(const MyString& mystr1, const MyString& mystr2);
	friend mybool& operator<(const MyString& mystr1, const MyString& mystr2);
	friend mybool& operator<=(const MyString& mystr1, const MyString& mystr2);
	void append(const char* p);
	void append(const MyString& mystr);


private:
	char *p_begin;
	char *p_end;
	int len;
};

MyString::MyString() {
	p_begin = 0;
	p_end = 0;
	len = 0;
}
MyString::MyString(const char* p1) {
	p_begin = new char[strlen(p1)];
	for (int i = 0;i != strlen(p1);i++) {
		*(p_begin + i) = *(p1 + i);
	}
	len = strlen(p1);
	p_end = p_begin + len;
}
MyString::MyString(const MyString& mystr) {
	p_begin = new char[mystr.len];
	for (int i = 0;i != mystr.len;i++) {
		*(p_begin + i) = *(mystr.p_begin + i);
	}
	len = mystr.len;
	p_end = p_begin + len;
}
MyString::~MyString() {
	delete p_begin;
}
int MyString::size() const {
	return len;
};
ostream &operator<<(ostream &os, const MyString &mystr)
{
	for (char* p = mystr.p_begin;p != mystr.p_end;p++)
		os << *p;
	return os;
}
void MyString::append(const char* p) {
	int len_last = len;
	len += strlen(p);
	char* p_last_begin = p_begin;
	char* p_last_end = p_end;
	p_begin = new char[len];
	for (int i = 0;i != len_last;i++)
		*(p_begin + i) = *(p_last_begin + i);
	for (int j = 0;j != strlen(p);j++)
		*(p_begin + len_last + j) = *(p + j);
	delete p_last_begin;
	p_end = p_begin + len;
}
void MyString::append(const MyString& mystr) {
	int len_last = len;
	len += mystr.len;
	char* p_last_begin = p_begin;
	char* p_last_end = p_end;
	p_begin = new char[len];
	for (int i = 0;i != len_last;i++)
		*(p_begin + i) = *(p_last_begin + i);
	for (int j = 0;j != mystr.len;j++)
		*(p_begin + len_last + j) = *(mystr.p_begin + j);
	p_end = p_begin + len;
}
mybool& operator==(const MyString& mystr1, const MyString& mystr2) {

	if (mystr1.len == mystr2.len) {
		for (int i = 0;i != mystr1.len;i++) {
			if (*(mystr1.p_begin + i) != *(mystr2.p_begin + i)) {
				mb.cnmb = 0;
				return mb;
			}
		}
		mb.cnmb = 1;
		return mb;
	}
	else {
		mb.cnmb = 0;
		return mb;
	}
}
ostream& operator<<(ostream &os, mybool &mb) {
	if (mb.cnmb == 1)
		os << "true";
	else
		os << "false";
	return os;
}
mybool& operator!=(const MyString& mystr1, const MyString& mystr2) {
	if ((mystr1 == mystr2).cnmb == 0) {
		mb.cnmb = 1;
		return mb;
	}
	else {
		mb.cnmb = 0;
		return mb;
	}
}
mybool& operator<(const MyString& mystr1, const MyString& mystr2) {
	int len_min = (mystr1.len <= mystr2.len ? mystr1.len : mystr2.len);
	for (int i = 0;i != len_min;i++) {
		if (*(mystr1.p_begin + i) > *(mystr2.p_begin + i)) {
			mb.cnmb = 0;
			return mb;
		}
		else if (*(mystr1.p_begin + i) < *(mystr2.p_begin + i)) {
			mb.cnmb = 1;
			return mb;
		}
	}
	if (mystr1.len < mystr2.len) {
		mb.cnmb = 1;
		return mb;
	}
	else {
		mb.cnmb = 0;
		return mb;
	}
}
mybool& operator<=(const MyString& mystr1, const MyString& mystr2) {
	if ((mystr1 == mystr2).cnmb == 1 || (mystr1 < mystr2).cnmb == 1) {
		mb.cnmb = 1;
		return mb;
	}
	else {
		mb.cnmb = 0;
		return mb;
	}
}
mybool& operator>(const MyString& mystr1, const MyString& mystr2) {
	if ((mystr1 == mystr2).cnmb == 0 && (mystr1 < mystr2).cnmb == 0) {
		mb.cnmb = 1;
		return mb;
	}
	else {
		mb.cnmb = 0;
		return mb;
	}
}
mybool& operator>=(const MyString& mystr1, const MyString& mystr2) {
	if ((mystr1 == mystr2).cnmb == 1 || (mystr1 > mystr2).cnmb == 1) {
		mb.cnmb = 1;
		return mb;
	}
	else {
		mb.cnmb = 0;
		return mb;
	}
}

