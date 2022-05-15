#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void CreateBIN(char* fname);
void PrintBIN(char* fname);
void Serch(char* fname, char* gname, char* hname);

int main() {
	char fname[100] = "";
	cout << "enter file name 1: "; cin >> fname;

	CreateBIN(fname);
	PrintBIN(fname);

	char gname[100] = "";
	cout << "enter file name with even numbers: "; cin >> gname;
	char hname[100] = "";
	cout << "enter file name with odd numbers: "; cin >> hname;
	Serch(fname, gname, hname);
	cout << "file with even numbers : "<< hname;
	PrintBIN(hname);
	cout << "file with odd numbers : " << hname;
	PrintBIN(gname);
	return 0;
}
void CreateBIN(char* fname)
{
	ofstream f(fname, ios::binary);
	char ch;
	string s;

	do {
		cin.get();
		cin.sync();

		cout << "enter line: "; getline(cin, s);

		s += '\n';

		for (unsigned i = 0; i < s.length(); i++)
			f.write((char*)&s[i], sizeof(s[i]));

		cout << "continue? (y/n): "; cin >> ch;
	} while (ch == 'y' || ch == 'Y');

	f.close();

	cout << endl;
}
void PrintBIN(char* fname)
{
	ifstream f(fname, ios::binary);
	string s;
	char ch;

	cout << endl;
	while (f.read((char*)&ch, sizeof(ch)))
	{
		if (ch == '\n') {
			cout << s << endl;
			s = "";
		}
		else {
			s += ch;
		}
	}
	cout << endl;
}
void Serch(char* fname, char* gname, char* hname) {
	ifstream f(fname);
	ofstream g(gname);
	ofstream h(hname);
	char word[64];
	int x;
	while (f >> x)
	{
		if (x % 2)
			g << x << endl;
		else
			h << x << endl;

	}
	f.close();
	g.close();
	h.close();
}