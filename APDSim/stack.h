#pragma once
class stack
{
	char content[256];
	stack *next;
public:
	stack();
	stack(const char *name);
	void push(stack **pila,const char *name);
	void pop(stack **pila);
	char *getContent();
	stack*getNext();
	~stack();
};

