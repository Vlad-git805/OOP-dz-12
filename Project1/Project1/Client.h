#pragma once
#include <iostream>
#include <string>
#include "Document.h"
#include <Windows.h>
using namespace std;

enum Priorit
{
	FIRST = 1, SECOND, THIRD, FOUR, FIVE, NON = -1
};

class Client
{
private:
	string name;
	Document* documents;
	Priorit prior;
	int size;
public:
	Client();
	Client(string name, Priorit prior);
	void operator=(const Client& other);
	void AddDocument(const Document& doc);
	void PrintAllInfo()const;
	~Client();

	friend class Queue;
};

