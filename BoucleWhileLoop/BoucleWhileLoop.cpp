#include <iostream>
using namespace std;

long maFonction(long x);

int main()
{
    long resultat;
    long inputNumber;

    system("chcp 65001 > nul");

    // Demander à l'utilisateur d'entrer un nombre
    cout << "Boucle While Loop" << endl;
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
        xor eax, eax;  // initialiser eax (compteur) à 0
        xor ebx, ebx;  // initialiser ebx (résultat) à 0
    somme_loop_while:
        cmp eax, x;    // comparer eax à x
        jge fin_boucle; // si eax >= x, terminer la boucle
        inc eax;       // incrémenter eax
        add ebx, eax;  // ajouter eax à ebx
        jmp somme_loop_while; // retourner au début de la boucle

    fin_boucle:
        mov result, ebx; // stocker le résultat final dans 'result'
    };
    return result;
}
