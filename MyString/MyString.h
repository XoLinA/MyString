#pragma once
class MyString
{
private: //для s1.MyStrCmp(s1.str, s2.str) нужен public;
	char* str;
	int length;

public:

	MyString();
	MyString(int length);
	MyString(const char* s);
	~MyString();
	void Input();
	void MyStrcpy(MyString& obj);
	bool MyStrStr(const char* str);
	int MyChr(char c);
	int MyStrLen();
	void MyStrCat(MyString& b);
	int MyStrCmp(const char* s1, const char* s2);

	char& operator[](int index);
	//void operator()();
	MyString operator+(char c) const;
	friend MyString operator+(char c, const MyString& obj);
	friend MyString operator+(int n, const MyString& obj);
	MyString operator+(int n) const;
	MyString operator++(int);
	MyString operator++();


	void MyDelChr(char c);

	void Print();
};