#include "Document.h"

Document::Document() : name(""), siz(0), prior(NON) {}

Document::Document(string name, int siz, Priorit pr)  : name(name), siz(siz), prior(pr)  {}

void Document::Print()
{
	cout << "Name: " << name << " Size: " << siz << " Priority: " << prior << endl;
}

Document::~Document() {}
