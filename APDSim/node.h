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
	node(std::string content);
	void insertar(node ** tabla, std::string state, std::string transition);
	void insertarTrans(node * state, std::string transition);
	int existState(node *tabla, std::string state);
	std::string getContent();
	std::string getTransition();
	node * getDown();
	node * getNext();
	void printTable(node**table);
	std::string getTransition(node * table, std::string state,std::string content);
	~node();
};

