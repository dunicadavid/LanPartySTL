#include "LanParty.h"
#include <fstream>
int main(int argc, char** argv)
{
    ifstream fin1(argv[2] , ios::in);
    ofstream fout(argv[3], ios::out);
    ifstream fin2(argv[1], ios::in);
    LanParty x;
    x.InserareListaEchipa(fin1);

    int v[5];
    for (int i = 0; i < 5; i++)
        fin2 >> v[i];

    if (v[0] && !v[1])
    {
        x.AfisareSubpunctul_1(fout);
    }

    if (v[1] && !v[2])
    {
        x.ReducereListaEchipe();
        x.AfisareSubpunctul_1(fout);
    }

    if (v[2] && !v[3])
    {
        x.ReducereListaEchipe();
        x.AfisareSubpunctul_1(fout);
        x.GenerareMeciuri(fout);
    }

    if (v[3] && !v[4])
    {
        x.ReducereListaEchipe();
        x.AfisareSubpunctul_1(fout);
        x.GenerareMeciuri(fout);
        x.CompletareBST(fout);
    }

    if (v[4])
    {
        x.ReducereListaEchipe();
        x.AfisareSubpunctul_1(fout);
        x.GenerareMeciuri(fout);
        x.CompletareBST(fout);
        x.CreareAVLsiAfisare_5(fout);
    }

    return 0;
}
