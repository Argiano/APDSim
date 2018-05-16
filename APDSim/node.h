#pragma once
class node
{
	//atributos
	std::string content;
	std::string transition;
	node *next;
	node *down;
public:
	node();
	void insertar(node ** tabla,std::string state, std::string transition);
	bool existState(node *start, std::string state);
	~node();
};

