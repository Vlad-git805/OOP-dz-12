#include "QueueDefault.h"

QueueDefault::QueueDefault()
{
	sizeOfStatistic = 0;
	statistic = new string[sizeOfStatistic];
}

QueueDefault::~QueueDefault()
{
	// ��������� �����
	delete[]statistic;
}


void QueueDefault::Enqueue(string elem)
{
	string* temp = new string[sizeOfStatistic + 1];
	for (int i = 0; i < sizeOfStatistic; i++)
	{
		temp[i] = statistic[i];
	}
	temp[sizeOfStatistic] = elem;
	delete[] statistic;
	statistic = temp;
	sizeOfStatistic++;
}


void QueueDefault::Dequeue()
{
	if (!IsEmpty())
	{
		string* temp = new string[sizeOfStatistic - 1];
		for (int i = 0, j = 0; i < sizeOfStatistic; i++)
		{
			if (i != 0)
			{
				temp[j] = statistic[i];
				j++;
			}
		}
		delete[] statistic;
		statistic = temp;
		sizeOfStatistic--;
	}
}

bool QueueDefault::IsEmpty() const
{
	// �������?
	return sizeOfStatistic == 0;
}

int QueueDefault::GetCount() const
{
	// ����� �����
	return sizeOfStatistic;
}

void QueueDefault::Clear()
{
	// ������� �����
	delete[]statistic;
}

void QueueDefault::Show() const
{
	cout << "\n-----------------------------------\n";
	// ����� �����
	for (int i = 0; i < sizeOfStatistic; i++)
		cout << statistic[i] << "\n";
	cout << "\n-----------------------------------\n";
}
