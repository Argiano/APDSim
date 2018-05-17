#include "stdafx.h"
#include "node.h"
#include <string>


node::node()
{
}

node::node(std::string content)
{
	this->content = content;
}

void node::insertar(node ** tabla,std::string state, std::string transition)
{	  
	node *n = *tabla;
	if (n==NULL)
	{		
		n = new node(state);
		*tabla = n;
		insertarTrans(*tabla, transition);
		std::cout << "New node: " + n->content << std::endl;
	}
	else if (existState(n, state))
	{
		std::cout << "New State" << std::endl;
		node *d = n->down;
		while (d != NULL)
		{
			n = d;
			d = d->down;
		}
		d = new node(state);
		n->down = d;
		insertarTrans(d, transition);
		std::cout << d->content << std::endl;
	}
	else
	{
		std::cout << "New Transition" << std::endl;
		while (state.compare(n->getContent()))
		{
			n = n->getDown();
		}
		insertarTrans(n, transition);
	}
}

void node::insertarTrans(node *state, std::string transition)
{
	node *n = state;
	while (n->next != NULL)
	{
		n = n->next;
	}
	node *t = new node();
	t->content = transition.substr(transition.find_first_of(",") + 1, 3);
	t->transition = transition.substr(transition.find_first_of("=") + 1, transition.size() - transition.find_first_of("="));
	n->next = t;
}

int node::existState(node *start, std::string state)
{
	int exists = 0;
	node *n = start;
	do
	{
		exists = state.compare(n->content);
		n = n->down;
	} while (n != NULL && exists);
	std::cout << "Exists: " + exists << std::endl;
	return exists;
}

std::string node::getContent()
{
	return content;
}

std::string node::getTransition()
{
	return transition;
}

node * node::getDown()
{
	return down;
}

node * node::getNext()
{
	return next;
}

void node::printTable(node**table)
{
	node *n = *table;
	while (n != NULL)
	{
		std::cout << n->getContent() + "->";
		node *t = n->getNext();
		while (t != NULL)
		{
			std::cout << t->getContent() + "->";
			t = t->getNext();
		}
		std::cout << std::endl;
		n = n->getDown();
	}
}

std::string node::getTransition(node * table, std::string state, std::string content)
{
	node *n = table;
	std::cout << "Searching: " + content << std::endl;
	while (n !=NULL && state.compare(n->getContent()))
	{
		n = n->getDown();
	}
	while (n != NULL && content.compare(n->getContent()))
	{
		n = n->getNext();
	}
	if (n!= NULL)
	{
		std::string transition = n->getTransition();
		if (transition.at(0) == '(')
		{
			transition = transition.substr(1,transition.size()-2);
		}
		return transition;
	}
	else
	{
		return "NT";
	}
}


node::~node()
{
}
