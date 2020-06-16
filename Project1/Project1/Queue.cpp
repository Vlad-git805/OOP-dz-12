#include "Queue.h"

Queue::Queue(int maxSize)
{
	this->maxSize = maxSize;
	data = new Document[maxSize];
	priorities = new int[maxSize];
	size = 0;
	statistic = new Document[maxSize];
	statisticSize = 0;
}

Queue::~Queue()
{
	if(data != nullptr)
		delete[]data;
	if (priorities != nullptr)
		delete[]priorities;
	if (statistic != nullptr)
		delete[]statistic;
}


void Queue::AddWithPriority(Document elem)
{
	if (!IsFull())
	{
		SYSTEMTIME st;
		GetSystemTime(&st);
		data[size] = elem;
		priorities[size] = elem.prior;
		statistic[statisticSize] = elem;
		statistic[statisticSize].time.hour = st.wHour;
		statistic[statisticSize].time.minits = st.wMinute;
		statistic[statisticSize].time.second = st.wSecond;
		++size;
		++statisticSize;
		for (int i = 0; i < size - 1; i++) {
			for (int j = 0; j < size - i - 1; j++) {
				if (data[j].prior > data[j + 1].prior) {
					swap(data[j + 1], data[j]);
					swap(priorities[j + 1], priorities[j]);
				}
			}
		}
		Sleep(1000);
	}
}

Document Queue::ExtractElem()
{
	if (!IsEmpty())
	{
		// Зберігаємо перший елемент		
		//int prIndex = 0;
		//int prValue = priorities[0];
		//// Пошук найпріорітетнішого елемента (мінімальне значення)
		//for (int i = 1; i < size; ++i)
		//{
		//	if (priorities[i] < prValue)
		//	{
		//		prValue = priorities[i];
		//		prIndex = i;
		//	}
		//}
		//int element = data[prIndex];
		//// Підсовуємо всі елементи
		//for (int i = prIndex; i < size - 1; i++)
		//{
		//	data[i] = data[i + 1];
		//	priorities[i] = priorities[i + 1];
		//}
		//// Проста черга

		Document temp = data[0];

		for (int i = 0; i < size - 1; i++)
		{
			data[i] = data[i + 1];
			priorities[i] = priorities[i + 1];
		}

		--size;	

		return temp;
	}
}

Document Queue::Peek() const
{
	if (!IsEmpty())
	{
		// Зберігаємо перший елемент		
		//int prIndex = 0;
		//int prValue = priorities[0];
		//// Пошук найпріорітетнішого елемента
		//for (int i = 1; i < size; ++i)
		//{
		//	if (priorities[i] < prValue)
		//	{
		//		prValue = priorities[i];
		//		prIndex = i;
		//	}
		//}

		return data[0];
	}
}

bool Queue::IsEmpty() const
{
	return size == 0;
}

bool Queue::IsFull() const
{
	return size == maxSize;
}

int Queue::GetCount() const
{
	return size;
}

void Queue::Clear()
{
	size = 0;
}

void Queue::Show() const
{
	for (int i = 0; i < size; i++)
	{
		data[i].Print();
	}
}

void Queue::ShowStatistic()const
{
	for (int i = 0; i < statisticSize; i++)
	{
		cout << "Name: " << statistic[i].name << "; Time: " << statistic[i].time.hour << ":" << statistic[i].time.minits << ":" << statistic[i].time.second << endl;
	}
}
