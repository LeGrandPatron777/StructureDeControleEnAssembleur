#include <iostream>
using namespace std;

long maFonction(long x);

int main()
{
    long resultat;
    long inputNumber;

    system("chcp 65001 > nul");

    // Demander à l'utilisateur d'entrer un nombre
    cout << "Structure de contrôle If-else if-then" << endl;
    cout << "----------------------" << endl;
    cout << "Entrez le nombre: ";
    cin >> inputNumber;

    resultat = maFonction(inputNumber);
    cout << "Resultat = " << resultat << "\n";
    return 0;
}

long maFonction(long x)
{
    long result = 0;
    _asm
    {
        cmp x, 10
        jle inf_ou_egal  
        mov result, 2
        jmp la_fin
        inf_ou_egal :
        mov result, 100
            la_fin :
    };
    return result;
}
