#pragma once
#include <string>

using namespace std;

class s_list
{
public:
	static int c;
private:
	string value;
	s_list *next;

public:
	s_list(string);
	~s_list();

	void setNext(s_list *);
	void append(s_list *,string);
	void drop(s_list *);
	string pop(void);
	void showAll(s_list *);
	void functionC(void);
};