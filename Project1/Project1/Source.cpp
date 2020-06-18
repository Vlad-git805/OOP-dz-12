#include <iostream>
#include "Queue.h"
#include "Document.h"

using namespace std;



int main()
{

	Queue q1(10);

	Client cl1("Vlad", THIRD);
	Document doc1("doc1");
	Document doc2("doc2");
	Document doc3("doc3");

	cl1.AddDocument(doc1);
	cl1.AddDocument(doc2);
	cl1.AddDocument(doc3);

	Client cl2("Vas9", FIVE);
	Document doc123("doc123");
	Document doc222("doc222");
	Document doc321("doc321");

	cl2.AddDocument(doc123);
	cl2.AddDocument(doc222);
	cl2.AddDocument(doc321);

	q1.AddClientToPrint(cl2);
	q1.AddClientToPrint(cl1);

	q1.Show();

	q1.ExtractElem();
	q1.ExtractElem();

	//q1.Show();
	cout << endl;
	q1.ShowStat();
	system("pause");
	return 0;
}