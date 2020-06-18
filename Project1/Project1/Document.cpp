#include "Document.h"

Document::Document() : name("") {}

Document::Document(string name)  : name(name) {}

void Document::Print()
{
	cout << "Name: " << name << endl;
}

