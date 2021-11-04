#pragma once
#include "Player.h"
#include <vector>
#include <algorithm>

class Team
{
private:
	int players;
	float medie;
	string numeEchipa;
	vector <Player> p;
public:
	Team();
	Team(int, string, vector<Player>);
	~Team();
	bool operator < (const Team&) const;

	void setNrPlayers(int);
	void setName(string);
	void setPlayers(vector<Player>);
	int getNrPlayers();
	string getName() const;
	vector<Player> getPlayers();

	float getMedie() const;
	float getMedieInit();
	void setMedie(float);
};

