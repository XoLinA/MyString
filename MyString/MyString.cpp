#include "MyString.h"
#include <iostream>
using namespace std;

MyString::MyString(int length)
{
	this->length = 0;
	this->str = nullptr;
	if (length > 0)
	{
		this->length = length;
		this->str = new char[length + 1];
		this->str[0] = '\0';
		cout << "Length: " << length << endl;
	}
	else
	{
		cout << "Error/////////";
	}
}
MyString::MyString()
{
	length = 80;
	str = new char[length + 1];
	str[0] = '\0';
}

MyString::MyString(const char* s)
{
	int temp = 0;
	while (s[temp] != 0)
	{
		temp++;
	}
	length = temp;
	str = new char[length + 1];
	for (int i = 0; i < length; i++)
	{
		str[i] = s[i];
	}
	str[length] = '\0';
}

MyString::~MyString()
{
	delete[] str;
}

void MyString::Input()
{
	char buffer[100];
	cout << "Enter String :";
	cin >> buffer;

	delete[]str;
	length = 0;
	while (buffer[length] != '\0')
	{
		length++;
	}

	str = new char[length + 1];
	for (int i = 0; i < length; i++)
	{
		str[i] = buffer[i];
	}
	str[length] = '\0';
}

void MyString::MyStrcpy(MyString& obj)
{
	length = obj.length;
	str = new char[length + 1];
	for (int i = 0; i < length; i++)
	{
		str[i] = obj.str[i];
	}
	str[length] = '\0';
}


bool MyString::MyStrStr(const char* substr)
{
	int sub = 0;
	while (substr[sub] != '\0')
	{
		sub++;
	}
	if (sub == 0)
		return true;
	for (int i = 0; i <= length - sub; i++)
	{
		int j = 0;
		while (j < sub && str[i + j] == substr[j])
		{
			j++;
		}
		if (j == sub)
			return true;
	}
	return false;
}

int MyString::MyChr(char c)
{
	for (int i = 0; i < length; i++)
	{
		if (str[i] == c)
			return i;
	}
	return -1;
}

int MyString::MyStrLen()
{
	return length;
}

void MyString::MyStrCat(MyString& b)
{
	int newLen = length + b.length;
	char* newStr = new char[newLen + 1];
	{
		int i = 0;
		while (str[i] != '\0')
		{
			newStr[i] = str[i];
			i++;
		}
		newStr[i] = '\0';
	}

	int i = length, j = 0;
	while (b.str[j] != '\0') {
		newStr[i++] = b.str[j++];
	}
	newStr[i] = '\0';

	delete[] str;
	str = newStr;
	length = newLen;
}

int MyString::MyStrCmp(const char* s1, const char* s2)
{
	int i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] < s2[i])
			return -1;
		if (s1[i] > s2[i])
			return 1;
		i++;
	}
	if (s1[i] == '\0' && s2[i] == '\0')
		return 0;
	if (s1[i] == '\0')
		return -1;
	return 1;
}

char& MyString::operator[](int index)
{
	if (index < 0 || index >= length)
	{
		cout << "Error//////////////////////";
		char temp = '\0';
		return temp;
	}
	return str[index];
}

MyString MyString::operator+(char c) const
{
	MyString temp;
	temp.length = length + 1;
	temp.str = new char[temp.length + 1];
	for (int i = 0; i < length; i++)
	{
		temp.str[i] = str[i];
	}
	temp.str[length] = c;
	temp.str[temp.length] = '\0';
	return temp;
}

//void operator()() 
//{
//	Input();
//}

MyString MyString::operator+(int n) const
{
	MyString temp;
	temp.length = length + n;
	temp.str = new char[temp.length + 1];
	for (int i = 0; i < length; i++)
	{
		temp.str[i] = str[i];
	}
	for (int i = length; i < temp.length; i++)
	{
		temp.str[i] = '*';
	}
	temp.str[temp.length] = '\0';
	return temp;
}

MyString MyString::operator++(int)
{
	MyString temp(*this);
	char c = 'A';
	MyString res = *this + c;
	*this = res;
	return temp;
}

MyString MyString::operator++()
{
	char c = 'A';
	MyString res = *this + c;
	*this = res;
	return *this;
}

void MyString::MyDelChr(char c)
{
	int j = 0;
	for (int i = 0; i < length; i++) {
		if (str[i] != c) str[j++] = str[i];
	}
	str[j] = '\0';
	length = j;
}

void MyString::Print()
{
	cout << str << endl;
}

MyString operator+(char c, const MyString& obj)
{
	MyString temp;
	temp.length = obj.length + 1;
	temp.str = new char[temp.length + 1];
	temp.str[0] = c;
	for (int i = 0; i < obj.length; i++)
	{
		temp.str[i + 1] = obj.str[i];
	}
	temp.str[temp.length] = '\0';
	return temp;
}

MyString operator+(int n, const MyString& obj)
{
	MyString temp;
	temp.length = obj.length + n;
	temp.str = new char[temp.length + 1];
	for (int i = 0; i < n; i++) temp.str[i] = '*';
	for (int i = 0; i < obj.length; i++) temp.str[i + n] = obj.str[i];
	temp.str[temp.length] = '\0';
	return temp;
}
