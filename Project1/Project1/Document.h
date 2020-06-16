#pragma once
#include <iostream>
#include <string>

using namespace std;

enum Priorit
{
	FIRST = 1, SECOND, THIRD, FOUR, FIVE, NON = -1
};

class Document
{
private:
	string name;
	int siz;
	Priorit prior;
	struct Time
	{
		int hour;
		int minits;
		int second;
	};
	Time time;
public:
	Document();
	Document(string name, int siz, Priorit pr);
	void Print();
	~Document();

	friend class Queue;
};

