#include <bits/stdc++.h>
#include <windows.h>

using namespace std;

struct Nod
{
    int info;
    int frq;
    Nod *st, *dr;
}*r;

struct AB
{
    HANDLE p = GetStdHandle (STD_OUTPUT_HANDLE);
    void Set_Culoare (int caz)
    {
        if(caz == 1)
            SetConsoleTextAttribute (p , 4);
        else if(caz == 2)
            SetConsoleTextAttribute (p , 7);
        else
            return;
    }
    void Afis (const char str[], int caz)
    {
        if(caz == 1)
        {
            Set_Culoare(1);
            cout << "EROARE: ";
        }
        cout << str;
        if(caz == 1)
            Set_Culoare (2);
    }
    void Adauga(Nod *&p, int X)
    {
        if(p)
        {
            if(X < p->info)
                Adauga(p -> st, X);
            else if(X > p->info)
                Adauga(p -> dr, X);
            else
            {
                ++p -> frq;
                Afis("Elemetul exită în arbore\n", 1);
                return;
            }
        }
        else
        {
            p = new Nod;
            p -> info = X;
            p -> st = NULL;
            p -> dr = NULL;
            p -> frq = 1;
            Afis("Element adăugat cu succes\n", 2);
            return;
        }
    }
    void AdaugaI(Nod *&p, int X)
    {
        if(p)
        {
            if(X < p->info)
                AdaugaI(p -> st, X);
            else if(X > p->info)
                AdaugaI(p -> dr, X);
            else
            {
                ++p -> frq;
                return;
            }
        }
        else
        {
            p = new Nod;
            p -> info = X;
            p -> st = NULL;
            p -> dr = NULL;
            p -> frq = 1;
            return;
        }
    }
    void cmd (Nod *&c, Nod *&f)
    {
        Nod *aux;
        if(f -> dr)
            cmd(c, f -> dr);
        else
        {
            c -> info = f -> info;
            aux = f;
            f = f->st;
            delete aux;
        }

    }
    void Sterge (Nod *r, int X)
    {
        if(r == NULL)
        {
            Afis("Arbore nul\n" , 1);
            return;
        }
        sterg(r , X);
    }
    void sterg(Nod *& c, int k)
    {
        Nod *aux;
        if(c)
        {
            if(c -> info == k)
                if(c -> st==0 && c -> dr == 0)  /// daca e nod terminal
                {
                    delete c;
                    c = 0;
                }
                else if(c -> st == 0)     /// are numai subordonat drept
                {
                    aux = c -> dr;
                    delete c;
                    c = aux;
                }
                else if(c -> dr == 0)   /// are numai subordonat drept
                {
                    aux = c -> st;
                    delete c;
                    c = aux;
                }
                else
                    cmd(c, c -> st);   /// are ambii subordonati
            else if(c -> info < k)
                sterg(c -> dr, k);
            else
                sterg(c -> st, k);
        }
        else
            Afis("Valoarea de șters nu se găseste în arbore\n", 1);

    }
    void Frecventa (int X)
    {
        Nod *q = r;
        while(q != NULL)
        {
            if(q -> info == X)
            {
                Afis("Elementul apare de " , 2);
                cout << q -> frq << " ori\n";
                return;
            }
            else if(X < q -> info)
                q = q -> st;
            else
                q = q -> dr;
        }
        Afis("Elementul nu apare în arbore\n" , 1);
        return;
    }
    void Apare (int X)
    {
        Nod *q = r;
        while(q != NULL)
        {
            if(q -> info == X)
            {
                Afis ("Elementul apare în arbore\n" , 2);
                return;
            }
            else if(X < q -> info)
                q = q -> st;
            else
                q = q -> dr;
        }
        Afis("Elementul nu apare în arbore\n" , 1);
        return;
    }
    void Afisare (Nod *r, int caz)
    {
        if(r == NULL)
        {
            Afis("Arbore nul\n", 1);
            return;
        }
        if(caz == 1)
            AfisarePO(r);
        else if(caz == 2)
            AfisareIO(r);
        else
            AfisarePSO(r);
    }
    void AfisarePO (Nod *r)
    {
        if(r == NULL)
            return;
        cout << r-> info << " ";
        AfisarePO (r -> st);
        AfisarePO (r -> dr);
    }
    void AfisareIO (Nod *r)
    {
        if(r == NULL)
            return;
        AfisareIO (r -> st);
        cout << r-> info << " ";
        AfisareIO (r -> dr);
    }
    void AfisarePSO (Nod *r)
    {
        if(r == NULL)
            return;
        AfisarePSO (r -> st);
        AfisarePSO (r -> dr);
        cout << r-> info << " ";
    }
    void Sortare (Nod *r)
    {
        if (r == NULL)
            return;
        Sortare(r -> st);
        cout << r -> info << " ";
        Sortare (r -> dr);
    }
    void AfisareSortata (Nod *r)
    {
        if(r == NULL)
        {
            Afis("Graful este nul\n" , 1);
            return;
        }
        SetConsoleTextAttribute (p , 14);
        cout << "Șirul valorilor sortate este:\n";
        Sortare(r);
        SetConsoleTextAttribute (p , 7);
        cout << "\n";
    }
} T;

void prezentaison()
{
    cout << "Proiect realizat de:\n";
    cout << "Comșa Mirela Elena\n";
    cout << "Maxim Sabin\n";
    cout << "Miron Victor\n";
    cout << "Onuț Alexandru Ioan\n";
    cout << "Rîșca Ioan\n";
    cout << "Poftă bună!!!!!!!\n";
    cout << "\n";
}

int main()
{
    SetConsoleOutputCP(65001);
    ifstream fin ("test.in");
    prezentaison();
    int optiune, X;
    while(fin >> X)
        T.AdaugaI(r, X);
    HANDLE p = GetStdHandle (STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute (p, 100);
    cout << "Tema: Arbori Binari de Căutare\n";
    SetConsoleTextAttribute (p, 7);
    do
    {
        cout << "1 - Adăugare\n";
        cout << "2 - Ștergere\n";
        cout << "3 - Apariție\n";
        cout << "4 - Frecvență\n";
        cout << "5 - Afișare_Preordine\n";
        cout << "6 - Afișare_Inordine\n";
        cout << "7 - Afișare_Postordine\n";
        cout << "8 - Afișare_Sortata\n";
        cout << "0 - exit\n";
        cout << "\n";
        cout << "Introduceți opțiunea: \n";
        cin >> optiune;
        cout << '\n';
        switch(optiune)
        {
        case 1:
        {
            cout << "Introduceți valoarea de inserat:\n";
            cin >> X;
            T.Adauga(r, X);
            T.AfisareIO(r);
            break;
        }
        case 2:
        {
            cout << "Introduceți valoarea de șters:\n";
            cin >> X;
            T.Sterge(r, X);
            T.AfisareIO(r);
            break;
        }
        case 3:
        {
            cout << "Introduceți valoarea:\n";
            cin >> X;
            T.Apare(X);
            break;
        }
        case 4:
        {
            cout << "Introduceți valoarea:\n";
            cin >> X;
            T.Frecventa(X);
            break;
        }
        case 5:
            T.Afisare(r, 1);
            break;
        case 6:
            T.Afisare(r, 2);
            break;
        case 7:
            T.Afisare(r, 3);
            break;
        case 8:
            T.AfisareSortata(r);
            break;
        case 0:
            ;
            break;
        default :
            cout << "Opțiune invalidă!\n";
        }
        cout << "\n";

    }
    while(optiune);
    return 0;
}
