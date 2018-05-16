#include "stdafx.h"
#include "stack.h"
#include <string>

stack::stack()
{
}

stack::stack(const char *name)
{
	strcpy_s(content,name);
}


void stack::push(stack ** pila,const char * name)
{
	stack *nodo = new stack(name);
	nodo->next = *pila;
	*pila = nodo;
}

void stack::pop(stack ** pila)
{
	stack *nodo = *pila;
	*pila = nodo->next;
}


char * stack::getContent()
{
	return content;
}

stack * stack::getNext()
{
	return next;
}


stack::~stack()
{
}
