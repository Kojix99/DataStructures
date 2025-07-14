#pragma once

#include <iostream>

using namespace std;

class clsGreeting
{
private:
	string _message = "Hello world";
public:

	static void Greeting(string name)
	{
		cout << "Hello " + name << endl;
	}
};