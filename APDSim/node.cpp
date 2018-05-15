#include "stdafx.h"
#include "node.h"
#include <string>


node::node()
{
}

void node::insertar(node ** tabla, std::string transition)
{
	node *start = tabla[pos(transition)];
	start->content = transition.substr(transition.find(","), transition.find("=")-5);
	start->transition = transition.substr(transition.find("="));
}

int node::pos(std::string transition)
{
	return stoi(transition.substr(3, 1), nullptr, 10);
}


node::~node()
{
}
