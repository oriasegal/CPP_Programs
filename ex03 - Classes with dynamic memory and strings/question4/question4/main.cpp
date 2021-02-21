/*
Oria Segal
Exercise no. 3 question 4
This program akes for a 4 word string and whites it in a different order.
*/
#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s1, s2, s3, s4;
	cin >> s1 >> s2 >> s3 >> s4;

	char s5[9] = { "#!!@1234" };

	cout << s1 << "*" << s2 << "*" << s3 << "*" << s4 << endl;
	cout << s1 << "*" << s2 << "*" << s3 << "*" << s5 << endl;
	cout << s2 << "*" << s3 << "*" << s5 << endl;
	cout << s3 << "*" << s5 << endl;
	cout << s5 << endl;

	//system("pause");
	return 0;
}
/*
aaa
bbb
ccc
ddd
aaa*bbb*ccc*ddd
aaa*bbb*ccc*#!!@1234
bbb*ccc*#!!@1234
ccc*#!!@1234
#!!@1234
Press any key to continue . . .
*/
