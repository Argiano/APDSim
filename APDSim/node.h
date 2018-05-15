#pragma once
class node
{
	//atributos
	std::string content;
	std::string transition;
	node *next;
public:
	node();
	void insertar(node ** tabla, std::string transition);
	int pos(std::string transition);
	~node();
};

