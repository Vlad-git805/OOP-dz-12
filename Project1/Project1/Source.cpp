#include <iostream>
#include "Queue.h"
#include "Document.h"

using namespace std;



int main()
{

	Document d1("d1", 5, FIRST);
	Document d2("d2", 7, SECOND);
	Document d3("d3", 12, THIRD);
	Document d4("d4", 1234, FOUR);
	Document d5("d5", 8, FIVE);

	Queue q(10);

	q.AddWithPriority(d2);
	q.AddWithPriority(d1);
	q.AddWithPriority(d5);
	q.AddWithPriority(d4);
	q.AddWithPriority(d3);

	q.Show();

	q.ExtractElem();

	cout << endl;
	q.Show();
	cout << endl<<endl;
	q.ShowStatistic();

	system("pause");
	return 0;
}