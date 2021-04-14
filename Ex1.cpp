#include <iostream>
#include <string>
using namespace std;


//Q1
class Complex
{
public:
	int a, b;
	void input(string s)
	{
		int v1 = 0;
		int i = 0;
		while (s[i] != '+')
		{
			v1 = v1 * 10 + s[i] - '0';
			i++;
		}
		while (s[i] == ' ' || s[i] == '+' || s[i] == 'i')
		{
			i++;
		}
		int v2 = 0;
		while (i < s.length())
		{
			v2 = v2 * 10 + s[i] - '0';
			i++;
		}
		a = v1;
		b = v2;

	}

	Complex operator+ (const Complex & first) const
	{
		Complex ret;
		ret.a = a + first.a;
		ret.b = b + first.b;
		return ret;
	}
	friend ostream& operator<<(ostream& os, const Complex& dt) {
		os << dt.a << "+i" << dt.b << "\n";
		return os;
	}

};

//Q2
class Box
{
private:
	int l, b, h;
public:

	Box(int length, int breadth, int height)
	{
		l = length;
		b = breadth;
		h = height;
	}
	Box() {
		l = 0;
		b = 0;
		h = 0;
	}
	Box(const Box &other) {
		l = other.l;
		b = other.b;
		h = other.h;
	}

	int getLength() {
		return l;
	}
	int getBreadth() {
		return b;
	}
	int getHeight() {
		return h;
	}

	long long CalculateVolume() {
		return h*b*l;
	}

	bool operator<(const Box &other) const {
		if (l < other.l)
		{
			return true;
		}
		if (b < other.b && l == other.l)
		{
			return true;
		}
		if (h < other.h && b == other.b && l == other.l)
		{
			return true;
		}
		return false;
	}

	 friend ostream& operator<<(ostream& out, Box& B){
		out << B.l << " " << B.b << " " << B.h << "\n";
		return out;
	}

};

class Person {
private : 

	string first_name_ ;
	string last_name_;


public :
	Person(const string& first_name, const string& last_name) : first_name_(first_name), last_name_(last_name) {}

	const string& git_first_name() const {
		return first_name_;
	}

	const string& get_last_name() const {
		return last_name_;
	}

	friend ostream& operator<<(ostream& os, const Person& p) {
		os << "first_name=" << p.first_name_ << ",last_name=" << p.last_name_;
		return os;
	}

};



void main()
{
	//Q1
	Complex x, y;
	string s1, s2;
	cin >> s1;
	cin >> s2;
	x.input(s1);
	y.input(s2);
	Complex z = x + y;
	cout << z << endl;

	//Q2
	Box b1; // Should set b1.l = b1.b = b1.h = 0;
	Box b2(2, 3, 4); // Should set b1.l = 2, b1.b = 3, b1.h = 4;
	b2.getLength();	// Should return 2
	b2.getBreadth(); // Should return 3
	b2.getHeight();	// Should return 4
	b2.CalculateVolume(); // Should return 24
	bool x = (b1 < b2);	// Should return true based on the conditions given
	cout << b2; // Should print 2 3 4 in order.
	int n;
	cin >> n;
	Box temp;
	for (int i = 0; i < n; i++)
	{
		int type;
		cin >> type;
		if (type == 1)
		{
			cout << temp << endl;
		}
		if (type == 2)
		{
			int l, b, h;
			cin >> l >> b >> h;
			Box NewBox(l, b, h);
			temp = NewBox;
			cout << temp << endl;

		}
		if (type == 3)
		{
			int l, b, h;
			cin >> l >> b >> h;
			Box NewBox(l, b, h);
			if (NewBox < temp)
			{
				cout << "Lesser\n";
			}
			else {
				cout << "Greater\n";
			}
		}
		if (type == 4)
		{
			cout << temp.CalculateVolume() << endl;
		}
		if (type == 5)
		{
			Box NewBox(temp);
			cout << NewBox << endl;
		}
	

	}
	//Q3 
	string first_name, last_name, event;
	cin >> first_name >> last_name >> event;
	auto p = Person(first_name, last_name);
	cout << p << " " << event << endl;



}