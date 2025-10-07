#include "MyString.h"
#include <iostream>
using namespace std;

int main()
{
	MyString s2(46);
	MyString s1("Cat on my chair");


	/*s2.Input();
	cout << "S2: ";
	s2.Print();

	MyString s4;
	s4.MyStrcpy(s1);
	cout << "copy s1 t0 s4 : ";
	s4.Print();

	cout << "Search cat (1-yes/0-no) in s2: ";
	cout << s2.MyStrStr("cat") << endl;

	cout << "Position 'o' in s1: " << s1.MyChr('o') << endl;
	cout << "Position 'd' in s1: " << s1.MyChr('d') << endl;

	cout << "Length s2: " << s2.MyStrLen() << endl;

	s1.MyStrCat(s2);
	cout << "s1 + s2: ";
	s1.Print();

	int cmpResult = s1.MyStrCmp(s1.str, s2.str);
	if (cmpResult == 0)
	{
		cout << "s1 = s2 " << endl;
	}
	else if (cmpResult < 0)
	{
		 cout << "s1 < s2" << endl;
	}
	else
	{
		cout << "s1 > s2" << endl;
	}*/

	MyString s3 = s1 + 'A';
	cout << "s1 + 'A': ";
	s3.Print();

	MyString s4 = 'A' + s1;
	cout << "'A' + s1: ";
	s4.Print();

	MyString s5 = s1 + 10;
	cout << "s1 + 10: ";
	s5.Print();

	MyString s6 = 10 + s1;
	cout << "10 + s1: ";
	s6.Print();

	cout << " s1++: ";
	s1++;
	s1.Print();

	cout << " ++s1: ";
	++s1;
	s1.Print();

}