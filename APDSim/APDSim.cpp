// APDSim.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


using namespace std;
string estadoInicial;
string estadoFinal;
string acepta;
string transicion;
string palabra;
stack<char> pila;
string reiniciar;

void initPila()
{
	while (!pila.empty()) pila.pop();
	pila.push('R');
}

void push(string palabra)
{
	while (palabra.size() != 0)
	{
		pila.push(palabra.at(palabra.size() - 1));
		palabra.pop_back();
	}
}

void evaluate(string estado, string acepta, node*tabla, string palabra)
{
	if (!acepta.compare("final") && !estado.compare(estadoFinal))
	{
		cout << "Palabra Aceptada por estado " + acepta << endl;
		return;
	}
	else if (!acepta.compare("stack") && pila.empty())
	{
		cout << "Palabra Aceptada por " + acepta << endl;
		return;
	}
	else
	{
		string z = pila.empty() ? "e" : string(1,pila.top());
		pila.pop();
		string a = palabra.substr(0, 1);
		string transition = tabla->getTransition(tabla, estado, a + "," + z);
		string state_to_trans = transition.substr(0, estado.size());
		string word_to_stack = transition.substr(transition.find(",")+1);
		
		if (!transition.compare("NT"))
		{
			cout << "Palabra no aceptada" << endl;
			return;
		}
		else
		{
			if(word_to_stack.compare("e")) push(word_to_stack);
			palabra = (palabra.size() - 1 == 0) ? "e" : palabra.substr(1);
			evaluate(state_to_trans, acepta, tabla, palabra);
		}
	}
}

void freeResources() {
	estadoInicial.clear();
	estadoFinal.clear();
	acepta.clear();
	transicion.clear();
	palabra.clear();
}

int main()
{
	do 
	{
		cout << "Ingrese estado inicial: " + estadoInicial;
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

		node *table = NULL;

		while (transicion.compare("fin"))
		{
			cout << "Transiciones (escriba \"fin\" para finalizar): ";
			cin >> transicion;
			if (transicion.compare("fin"))
				table->insertar(&table, transicion.substr(transicion.find_first_of("(") + 1, estadoInicial.size()), transicion);
		}


		while (palabra.compare("fin"))
		{
			initPila();
			cout << "Palabra (escriba \"fin\" para finalizar): ";
			cin >> palabra;
			if (palabra.compare("fin"))evaluate(estadoInicial, acepta, table, palabra);
		}
		
		reiniciar.clear();
		cout << "Reiniciar Programa?(s/n): " << endl;
		cin >> reiniciar;

		free(table);
		freeResources();
	} while (reiniciar.compare("n"));

	return EXIT_SUCCESS;
}
