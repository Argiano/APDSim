// APDSim.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


using namespace std;
string estadoInicial;
string estadoFinal;
string acepta;
string transicion;

void decompose(string trans)//TEST PURPOSES
{
	string e_ori = trans.substr(trans.find_first_of("(")+1,estadoInicial.size());
	string letra = trans.substr(trans.find_first_of(",")+1, 1);
	string stackLetter = trans.substr(trans.find(letra)+2, 1);
	cout << e_ori + "|" + letra + "|" + stackLetter << endl;
}

int main()
{
	cout << "Ingrese estado inicial: ";
	cin >> estadoInicial;

	do
	{
		cout << "Stack Vacio o Estado final? (stack/final): ";
		cin >> acepta;
	} while (acepta.compare("stack") && acepta.compare("final"));

	if (!acepta.compare("final"))
	{
		cout << "Estado Final: ";
		cin >> estadoFinal;	
	}
	
		
	while (transicion.compare("fin"))
	{
		cout << "Transiciones (escriba \"fin\" para finalizar): ";
		cin >> transicion;
		if(transicion.compare("fin"))decompose(transicion);
	}

	stack *pila = new stack("R");

	node *table = new node();

	return EXIT_SUCCESS;
}
