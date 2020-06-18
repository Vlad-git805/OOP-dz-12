#include "Client.h"



Client::Client() : name(" "), documents(nullptr), prior(NON), size(0) {}

Client::Client(string name, Priorit prior) : name(name), documents(nullptr), prior(prior), size(0) {}

void Client::AddDocument(const Document& doc)
{
	Document * temp = new Document[size + 1];
	for (int i = 0; i < size; i++)
	{
		temp[i] = documents[i];
	}
	temp[size] = doc;
	delete[]documents;
	documents = temp;
	++size;
}

void Client::PrintAllInfo()const
{
	cout << "Name: " << name << endl;
	cout << "Priority: " << prior << endl;
	cout << "Documents: " << size << endl;
	for (int i = 0; i < size; i++)
	{
		cout << i + 1 << ") " << documents[i].name << endl;
	}
}

void Client::operator=(const Client& other)
{
	this->name = other.name;
	this->prior = other.prior;
	this->size = other.size;
	documents = new Document[size];
	for (int i = 0; i < size; i++)
	{
		documents[i] = other.documents[i];
	}
}

Client::~Client()
{
	if (documents != nullptr)
		delete[]documents;
}
