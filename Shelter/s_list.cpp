#include <string>
#include <iostream>
#include "s_list.h"


using namespace std;
s_list::s_list(string _value = "")
{
	value = _value;
	next = nullptr;
}


s_list::~s_list()
{
	if (next != nullptr)
	{
		delete next;
	}
}

void s_list::setNext(s_list *_next)
{
	next = (_next != nullptr) ? _next : nullptr;
}

void s_list::append(s_list *first_element, string _value)
{
	s_list *new_element = new s_list;
	s_list *temp = first_element;

	while (temp->next != nullptr)
	{
		temp = temp->next;
	}
	temp->next = (new_element != nullptr) ? new_element : nullptr;
	temp->next->value = _value;
}

void s_list::drop(s_list *first_element)
{
	delete first_element;
}

string s_list::pop(void)
{
	return string();
}

void s_list::showAll(s_list *_list)
{
	while (_list->next != nullptr)
	{
		cout << _list->value << endl;
		_list = _list->next;
	}
	cout << _list->value << endl;
}

void s_list::functionC(void)
{
	c = 1;
}
int s_list::c = 0;