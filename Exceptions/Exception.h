#pragma once
#include <iostream>
#include <string>
#include <queue>

using namespace std;
class Exception
{
private:
	string text;
public:
	Exception(string _text):text(_text) {};
	const string getException() const { return text; };
};