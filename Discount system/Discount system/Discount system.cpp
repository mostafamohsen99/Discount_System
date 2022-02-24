// Discount system.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<string>
using namespace std;
class Discount;
class visit;
class customer
{
private:
	bool membership;
public:
	void member(string a)
	{
		if (a =="OK")
			membership = true;
		else
			membership =false;
	}
	bool ismember()
	{
		if (membership == true)
			return true;
		else
			return false;
	}
	friend class Discount;
	friend class visit;
};
class Discount 
{
private:
	string typee;
public:
	bool checkvalidity(customer a)
	{

		if (a.membership)
			return true;
		else
			return false;
	}
	void type(string a)
	{
		if (a == "platinum")
			this->typee = "platinum";
		else if (a == "gold")
			this->typee = "gold";
		else if (a == "silver")
			this->typee = "silver";
		else
			typee = "not memeber";
	}
	void printdis()
	{
		cout << this->typee;
	}
	friend class visit;
};
class visit
{
private:
	float service=0, product=0, bill=0;
public:
	void calcservice(Discount a, float x)
	{
		if (a.typee =="platinum")
		{
			service = x - (x*0.25);
		}
		else if (a.typee == "gold")
		{
			service = x - (x*0.2);
		}
		else if (a.typee == "silver")
		{
			service = x - (x*0.15);
		}
		else
		{
			service = x;
		}
	}
	void calcproduct(customer a, float x)
	{
		if (a.ismember())
		{
			product = x - (x*0.1);
		}
		else
		{
			product = x;
		}
	}
	float calcbill()
	{
		return (product + service);
	}
};
int main()
{
	customer mostafa;
	float sserivce;
	float pproduct;
	Discount howmuch;
	visit b;
	mostafa.member("OK");
	if (howmuch.checkvalidity(mostafa))
	{
		howmuch.type("platinum");
	}
	cout << "Enter the salary of service" << endl;
	cin >> sserivce;
	b.calcservice(howmuch, sserivce);
	cout << "Enter the salary of product" << endl;
	cin >> pproduct;
	b.calcproduct(mostafa, pproduct);
	cout << "the total bill is" << endl;
	cout << b.calcbill() << endl;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
