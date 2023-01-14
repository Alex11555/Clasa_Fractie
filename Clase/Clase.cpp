#include <iostream>

using namespace std;

class Fractie {
private:
    int numarator, numitor; // proprietăți
    void simplifica();      // metodă privată
public:
    Fractie(int _numarator = 0, int _numitor = 1); // constructor
    Fractie(const Fractie&);   // constructor de copiere
    Fractie& citeste();    //  metodă publică
    Fractie& scrie();      // metodă publică
    friend Fractie Suma(Fractie, Fractie); // functie prietena
    friend Fractie Produs(Fractie, Fractie);   // functie prietena
};

Fractie::Fractie(const Fractie& F)
{   // constructor de copiere
    numarator = F.numarator;
    numitor = F.numitor;
    simplifica();
}

Fractie::Fractie(int _numarator /* = 0 */, int _numitor /* = 1 */)
{   // constructor
    numitor = _numitor, numarator = _numarator;
    simplifica();
}
Fractie& Fractie::citeste()
{
    // citeste numaratorul si numitorul obiectului curent
    // returnează obiectul curent
    cin >> numarator >> numitor;
    return *this;
}

Fractie& Fractie::scrie()
{
    // afisează numaratorul si numitorul obiectului curent
    // returnează obiectul curent
    cout << numarator << " " << numitor << endl;
    return *this;
}

void Fractie::simplifica()
{   //metoda privata; realizeaza simplificarea fractiei merorate în obiectul curent
    int a = numarator, b = numitor;
    while (b)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    numarator /= a;
    numitor /= a;
}

Fractie Suma(Fractie F, Fractie G)
{
    // funcție prietenă. Putem accesa datele private ale obiectelor F , G
    int x = F.numarator * G.numitor + F.numitor * G.numarator,
        y = F.numitor * G.numitor;
    Fractie Rez(x, y); // s-a apelat constructorul pentru crearea obiectului. Aici s-a făcut simplificarea
    return Rez; // s-a apelat costructorul de copiere
}

Fractie Produs(Fractie F, Fractie G)
{
    // funcție prietenă. Putem accesa datele private ale obiectelor F , G
    int x = F.numarator * G.numarator,
        y = F.numitor * G.numitor;
    return Fractie(x, y); // se apelează constructorul de copiere. Aici se face simplificarea
}

int main()
{
    Fractie A, B;
    A.citeste(), B.citeste();
    Fractie S = Suma(A, B);
    S.scrie();
    Produs(A, B).scrie();
    return 0;
}