#pragma once
#include <iostream>
#include <string>

using namespace std;

class Document
{
private:
	string name;
public:
	Document();
	Document(string name);
	void Print();

	friend class Queue;
	friend class Client;
};

