#include "Queue.h"

Queue::Queue(int maxSize)
{
	this->maxSize = maxSize;
	data = new Client[maxSize];
	priorities = new int[maxSize];
	size = 0;
}

Queue::~Queue()
{
	if(data != nullptr)
		delete[]data;
	if (priorities != nullptr)
		delete[]priorities;
}


void Queue::AddClientToPrint(Client& client)
{
	if (!IsFull())
	{
		data[size] = client;
		priorities[size] = client.prior;
		++size;
		
		for (int i = 0; i < size - 1; i++) {
			for (int j = 0; j < size - i - 1; j++) {
				if (data[j].prior > data[j + 1].prior) {
					swap(data[j + 1], data[j]);
					swap(priorities[j + 1], priorities[j]);
				}
			}
		}
	}
}

void Queue::ExtractElem()
{
	if (!IsEmpty())
	{

		SYSTEMTIME st;
		GetSystemTime(&st);
		string time_doc;
		int str = 0;

		time_doc += "Time ";
		str = st.wHour;
		time_doc += to_string(str);
		str = st.wMinute;
		time_doc += ":";
		time_doc += to_string(str);
		str = st.wSecond;
		time_doc += ":";
		time_doc += to_string(str);
		time_doc += "  name :";
		time_doc += data[0].name;

		stat.Enqueue(time_doc);


		for (int i = 0; i < size - 1; i++)
		{
			data[i] = data[i + 1];
			priorities[i] = priorities[i + 1];
		}

		--size;	

	}
}

Client Queue::Peek() const
{
	if (!IsEmpty())
	{
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
		cout << "_____________________ " << "Client " << i + 1 <<" _____________________" << endl;
		data[i].PrintAllInfo();
	}
}

void Queue::ShowStat() const
{
	stat.Show();
}
