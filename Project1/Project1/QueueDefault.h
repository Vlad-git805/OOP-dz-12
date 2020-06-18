#pragma once
#include <iostream>
#include <string>

using namespace std;

class QueueDefault
{
private:

	string* statistic;
	int sizeOfStatistic;

public:
	QueueDefault();
	~QueueDefault();

	void Enqueue(string elem);
	void Dequeue();
	bool IsEmpty() const;
	int GetCount() const;
	void Clear();
	void Show() const;

	friend class Queue;
};
