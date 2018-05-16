#include "stdafx.h"
#include "node.h"
#include <string>


node::node()
{
}

void node::insertar(node ** tabla,std::string state, std::string transition)
{
	if (existState(*tabla,state));
}

bool node::existState(node *start, std::string state)
{
	bool exists = false;
	node *n = start;
	do
	{
		exists = state.compare(n->content);
		n = n->down;
	} while (n != NULL);

	return exists;
}


node::~node()
{
}
