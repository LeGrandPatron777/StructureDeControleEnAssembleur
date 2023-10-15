#include <iostream>
using namespace std;

long maFonction(long x);

int main()
{
    long resultat;
    long inputNumber;

    system("chcp 65001 > nul");

    cout << "Boucle For Loop" << endl;
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
        mov ecx, x    // initialiser ecx avec x
        mov eax, 0    // initialiser eax (résultat) à 0
        somme_loop:
        add eax, ecx  // ajouter la valeur de ecx à eax
            dec ecx      // décrémenter ecx
            test ecx, ecx  // tester si ecx est 0
            jnz somme_loop  // si non, continuer la boucle

            mov result, eax  // stocker la valeur de eax dans result
    };
    return result;
}

