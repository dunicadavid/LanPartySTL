#include "Team.h"

Team::Team()
{
	this->players = 0;
	this->numeEchipa = "";
	this->medie = 0.0;
}

Team::Team(int i, string s, vector<Player> v)
{
	this->players = i;
	this->numeEchipa = s;
	this->p = v;
	this->medie = 0.0;
}

Team::~Team()
{
}

bool Team::operator <(const Team& t) const
{
	if (this->medie > t.medie)
		return true;
	else if (this->medie == t.medie)
		if (this->numeEchipa > t.numeEchipa)
			return true;
	return false;
}


void Team::setNrPlayers(int players)
{
	this->players = players;
}

void Team::setName(string numeEchipa)
{
	this->numeEchipa = numeEchipa;
}

void Team::setPlayers(vector<Player> p)
{
	this->p = p;
}

int Team::getNrPlayers()
{
	return players;
}

string Team::getName() const
{
	return numeEchipa;
}

vector<Player> Team::getPlayers()
{
	return p;
}

float Team::getMedie() const
{
	return medie;
}

float Team::getMedieInit()
{
	float medie = 0;
	for (int i = 0; i < players; medie += p[i].getPoints(), i++);
	return medie / players;
}

void Team::setMedie(float medie)
{
	this->medie = medie;
}
