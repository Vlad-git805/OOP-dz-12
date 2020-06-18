#pragma once
#include <iostream>
#include <string>
#include "Document.h"
#include "Client.h"
#include "QueueDefault.h"
#include <Windows.h>
using namespace std;

class Queue
{
private:
	Client* data;
	int * priorities;
	int maxSize;
	int size;
	QueueDefault stat;
public:
	Queue(int maxSize);
	~Queue();
	void AddClientToPrint(Client& client);
	void ExtractElem();
	Client Peek() const;
	bool IsEmpty() const;
	bool IsFull() const;
	int GetCount() const;
	void Clear();
	void Show() const;
	void ShowStat()const;
};
