#pragma once
#include <iostream>
#include <string>
#include "Document.h"
#include <Windows.h>
using namespace std;

class Queue
{
	Document * data;
	int * priorities;
	int maxSize;
	int size;
	Document * statistic;
	int statisticSize;
public:
	Queue(int maxSize);
	~Queue();
	void AddWithPriority(Document elem);
	Document ExtractElem();
	Document Peek() const;
	bool IsEmpty() const;
	bool IsFull() const;
	int GetCount() const;
	void Clear();
	void Show() const;
	void ShowStatistic()const;
};
