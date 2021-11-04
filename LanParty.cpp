#include "LanParty.h"

void LanParty::InserareListaEchipa(istream& file)
{
	int auxiliarInt1,auxiliarInt2;
	string auxiliarString1, auxiliarString2, auxiliarString3;
	Team* echipa;
	vector<Player> playerVector;
	Player player;

	file >> n;

	for (int k = 0; k < n; k++)
	{
		file >> auxiliarInt1;
		getline(file, auxiliarString3);
	    auxiliarString3 = auxiliarString3.substr(1, auxiliarString3.length() - 1);
		while (auxiliarString3[auxiliarString3.length() - 1] == ' ')
			auxiliarString3 = auxiliarString3.substr(0, auxiliarString3.length() - 1);
	    for (int i = 0; i < auxiliarInt1; i++)
		{
			file >> auxiliarString1 >> auxiliarString2 >> auxiliarInt2;
			player = Player(auxiliarString1, auxiliarString2, auxiliarInt2);
			playerVector.push_back(player);
		}
		echipa = new Team(auxiliarInt1, auxiliarString3, playerVector);
		playerVector.clear();
		listaEchipe.push_front(echipa);
	}
}

void LanParty::ReducereListaEchipe()
{
	int nGenerat = 1;
	while (nGenerat <= n)
		nGenerat *= 2;
	nGenerat /= 2;
	n -= nGenerat;

	while (n)
	{
		list<Team*>::iterator jt;
		float medie = std::numeric_limits<float>::max();
		for (list<Team*>::iterator it = listaEchipe.begin(); it != listaEchipe.end(); it++)
		{
			if ((*it)->getMedieInit() < medie)
			{
				medie = (*it)->getMedieInit();
				jt = it;
			}
		}
		listaEchipe.erase(jt);
		n--;
	}
	n = nGenerat;
}

void LanParty::GenerareMeciuri(ostream& file)
{
	int contor = 1;
	CompletareCoada();
	while (n > 1)
	{
		file << endl << "--- ROUND NO:" << contor << endl;
		while (coadaEchipe.size())
		{
			Team* echipa1,* echipa2;
			echipa1 = coadaEchipe.front();
			coadaEchipe.pop();
			echipa2 = coadaEchipe.front();
			coadaEchipe.pop();
			file << echipa1->getName() << setw(34 - echipa1->getName().length()) << "-" << setw(33) << echipa2->getName() << endl;
			if (echipa1->getMedieInit() > echipa2->getMedieInit())
			{
				stivaCastig.push(echipa1);
				stivaPierz.push(echipa2);	
			}
			else
			{
				stivaPierz.push(echipa1);
				stivaCastig.push(echipa2);
			}
		}

		//recompletare coada din stiva de winners + afisare castigatori:

		file << endl << "WINNERS OF ROUND NO:" << contor << endl;

		while (stivaCastig.size())
		{
			//verificare si completare lista top 8
			if (n == 16)
			{
				listaTop8.push_back(stivaCastig.top());
				listaTop8.back()->setMedie(stivaCastig.top()->getMedieInit() + contor);
			}
			coadaEchipe.push(stivaCastig.top());
			file << stivaCastig.top()->getName() << setw(37 - stivaCastig.top()->getName().length()) << "-  " << fixed << setprecision(2) << stivaCastig.top()->getMedieInit() + contor<< endl;
			stivaCastig.pop();
		}

		while (stivaPierz.size())
		{
			stivaPierz.pop();
		}

		n /= 2;
		contor++;
	}

	while (stivaCastig.size())
	{
		stivaCastig.pop();
	}
}

void LanParty::CompletareCoada()
{
	for (list<Team*>::iterator it = listaEchipe.begin(); it != listaEchipe.end(); it++)
	{
		(*it)->setMedie((*it)->getMedieInit());
		coadaEchipe.push(*it);
	}
}

void LanParty::CompletareBST(ostream& file)
{
	for (auto const& lista : listaTop8)
	{
		arboreBinar.insert(*lista);
	}
	file << endl << "TOP 8 TEAMS:" << endl;
	for (set<Team>::iterator it = arboreBinar.begin(); it != arboreBinar.end(); it++)
	{
		file << it->getName() << setw(37 - it->getName().length()) << "-  " << fixed << setprecision(2) << it->getMedie() << endl;
	}
	
}

void LanParty::AfisareSubpunctul_1(ostream& file)
{
	for (list<Team*>::iterator it = listaEchipe.begin(); it != listaEchipe.end(); it++)
		file<< (*it)->getName() << endl;
}

void LanParty::CreareAVLsiAfisare_5(ostream& file)
{
	int k = 1;
	for (set<Team>::iterator it = arboreBinar.begin(); it != arboreBinar.end(); k++, it++)
	{
		if (k == 4)
		{
			arboreAVL.insert(*it);
			break;
		}
	}
	k = 1;
	for (set<Team>::iterator it = arboreBinar.begin(); it != arboreBinar.end(); k++, it++)
	{
		if (k == 2 || k == 6)
		{
			arboreAVL.insert(*it);
		}
	}
	k = 1;
	for (set<Team>::iterator it = arboreBinar.begin(); it != arboreBinar.end(); k++, it++)
	{
		if (k % 2)
		{
			arboreAVL.insert(*it);
		}
	}
	arboreAVL.insert(*arboreBinar.rbegin());
	k = 1;
	file << endl << "THE LEVEL 2 TEAMS ARE:" << endl;
	for (set<Team>::iterator it = arboreAVL.begin(); it != arboreAVL.end(); k++, it++)
	{
		if (k % 2)
			file << it->getName() << endl;
	}
}
