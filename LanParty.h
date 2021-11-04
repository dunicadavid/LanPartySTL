#pragma once
#include "Team.h"
#include <list>
#include <queue>
#include <stack>
#include <iomanip>
#include <set>

class LanParty
{
private:
	int n;
	list<Team*> listaEchipe;
	queue<Team*> coadaEchipe;
	stack<Team*> stivaCastig, stivaPierz;
	list<Team*> listaTop8;
	set<Team> arboreBinar;
	set<Team> arboreAVL;

public:
	LanParty() { this->n = 0; }
	~LanParty() {}

	void InserareListaEchipa(istream&);
	void ReducereListaEchipe();
	void GenerareMeciuri(ostream&);
	void CompletareCoada();
	void CompletareBST(ostream&);
	void AfisareSubpunctul_1(ostream&);
	void CreareAVLsiAfisare_5(ostream&);
	
};

