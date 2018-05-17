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

void stack::push(stack ** pila, std::string palabra)
{
	//Inserta palabra en stack en reversa
	while (palabra.size() >= 1)
	{
		std::cout << (char*)palabra.at(palabra.size() - 1) << std::endl;
		(*pila)->push(pila, (char*)palabra.at(palabra.size() - 1));
		palabra.pop_back();
	}
}

void stack::pop(stack ** pila)
{
	stack *nodo = *pila;
	*pila = nodo->next;
}

stack * stack::popNode(stack ** pila)
{
	stack *n = *pila;
	pop(pila);
	return n;
}

std::string stack::popStr(stack ** pila)
{
	if (*pila != NULL)
	{
		stack *nodo = *pila;
		std::string cnt = nodo->getContent();
		*pila = nodo->next;
		return cnt;
	}
	else
	{
		return "e";
	}
	
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
