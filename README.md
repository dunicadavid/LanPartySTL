# LanPartySTL
[En] C++ OOP training. Same project as LanParty but using STL library
[Ro]
Fisierul de intelegere al codului:

1. Main
   -> Mi-am declarat o variabila 'x' de tip LanParty (aceasta inglobeaza toate listele,cozile,stivele si arborii utilizati).
   -> Am completat lista din fisier cu functia InserareListaEchipe(istream&)
   -> s1 : Am afisat lista cu funtia AfisareSubpunctul_1(ostream&)
   -> s2 : Am redus lista cu functia ReducereLsitaEchipe() apoi se afiseaza cu AfisareSubpunctul_1(ostream&)
   -> s3 : Am redus lista cu functia ReducereLsitaEchipe(), se afiseaza cu AfisareSubpunctul_1(ostream&), apoi am generat meciurile cu GenerareMeciuri(ostream&)
   -> s4 : In plus fata de 3 am creat si afisat arborele binar cu CompletareBST(ostream&)
   -> s5 : In plus fata de 4 am creat si afisat arborele AVL cu CreareAVLsiAfisare_5(ostream&)
 
2. Player
    ->Clasa ce retine un membru al unei echipe.
private:
        string firstName;                          --> numele jucatorului
        string secondName;                         --> prenumele jucatorului
        int points;                                --> numarul de puncte al jucatorului

public:
    -> Functiile din aceasta clasa sunt standard si anume am implementat constructorii si deconstructorii, set-eri si get-eri

3. Team 
    -> Clasa ce retine echipele participante
private:
	int players;                               --> nr de playeri din echipa
	float medie;                               --> media echipei (se initializeaza cu 0 se completeaza ulterior cu ajutorul functiei getMedieInit)
	string numeEchipa;                         --> numele echipei
	vector <Player> p;                         --> vector ce retine elemente de tip Player (playerii echipei)

public:
   -> Functiile din aceasta clasa sunt standard si anume am implementat constructorii si deconstructorii, set-eri si get-eri, dar sunt 2 precizari:
         -> am folosit functia void getMedie() pentru returnarea mediei si getMedieInit() pentru calcularea mediei initiale (motivul pentru care am folosit 2 functii este faptul ca la victoria echipei algoritmul imi incrementeaza doar variabila 'medie', nu si valoarea playerilor)
         -> am suprascris operatorul < pentru a imi completa corect arborele de tip SET	(care utilizaza operatorul < in completare)

4. LanParty
private:
        int n;                                     --> nr de echipe 
        list<Team*> listaEchipe;                   --> lista de echipe retinuta initial
	queue<Team*> coadaEchipe;                  --> coada de echipe utilizata la generarea meciurilor
	stack<Team*> stivaCastig, stivaPierz;      --> stivele de invingatori si pierzatori care se completeaza dupa fiecare runda de joc
	list<Team*> listaTop8;                     --> lista de echipe ce retine echipele din sferturi - se completeaza in GenereareMeciuri()
	set<Team> arboreBinar;                     --> arbore de cautare binara care imi retine si sorteaza ultimele 8 echipe
	set<Team> arboreAVL;                       --> arborele binar AVL folosit la subpunctul 5

public:
   -> Functia void InserareListaEchipe(istream&) imi completeaza lista de echipe 'listaEchipe' (prin intermediul unor variabile auxiliare memoreaza o variabila de tip Team* 'echipa' pe care o introduce in lista de echipe cu comanda push_front
   -> Functia void ReducereListaEchipe() imi elimina din lista un numar de echipe astfel incat sa ramana cea mai mare putere a lui 2 de echipe (realizam acest lucru printr-o structura de tip for in care cautam maximul si retinem iteratorul acestuia
              intr-o variabila 'jt'. Dupa terminarea secventei for eliminam din lista elementul al carui iterator a fost memorat in 'jt' ,apoi repetam pana acest algoritm pana ramane numarul convenabil de elemente)
   -> Functia void GenerareMeciuri(ostream&) se bazeaza pe o secventa repetitiva care repeta pe rand : recompletarea cozii de meciuri cu echipele din stiva de winners, afisarea meciurilor, deciderea castigatorilor, incrementarea punctajelor
              castigatorilor, generearea de stiva winners si losers si afisarea invingatorilor. Acest algoritm se repeta pana cand 'n' (variabila care retine numarul de echipe --> n = 2^x unde x=numarul de runde)
   -> Functia void CompletareCoada() este utilizata in 'GenerareMeciuri()' pentru a crea coada de meciuri 'coadaEchipe' cu echipele din lista 'listaEchipe' (aceasta completeaza coada printr-o structura repetitiva cu ajutorul get-erelor 
              si set-erelor din clasa Team)
   -> Functia void CompletareBST(ostream&) imi completeaza un arbore binar stl::Set 'arboreBinar' dintr-o lista creata in GenerareMeciuri atunci cand ramasesera 8 echipe ('listaTop8'), iar apoi il afisaza
   -> Functia void AfisareSubpunctul_1(ostream&) imi afiseaza lista de echipe (am folosit-o atat la primul subpunct unde imi cerea sa afisez intreaga lista, cat si la urmatoarele unde afisam lista redusa)
   -> Functia void CreareAVLsiAfisare_5(ostream&) imi afiseaza si creaza arborele AVL 'arboreAVL' dupa un pattern observat de mine, si anume intotdeauna capul arborelui va fi elementul 4 din lista ordonata de elemente, copiii acestuia sunt elementele
              2 si 6, iar copiii copiilor sunt elementele 1,3,5,7, astfel arborele arata asemenea diagramei urmatoare:
            
                                                                      4
                                                                     / \
                                                                    /   \
                                                                   2     6
                                                                  / \   / \
                                                                 1   3 5   7
                                                                /
                                                               8
