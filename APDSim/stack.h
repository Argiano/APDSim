#pragma once
class stack
{	//atributos
	char content[10];
	stack *next;
public:
	stack();
	stack(const char *name);
	void push(stack **pila,const char *name);
	void push(stack ** pila, std::string palabra);
	void pop(stack **pila);
	stack*popNode(stack **pila);
	std::string popStr(stack ** pila);
	char *getContent();
	stack*getNext();
	~stack();
};

