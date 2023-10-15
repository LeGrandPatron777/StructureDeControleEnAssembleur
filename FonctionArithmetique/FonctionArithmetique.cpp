#include <iostream>
long maFonction(long n1, long n2, char op);
using namespace std;

int main()
{
    long n1, n2, resultat;
    char operateur;
    std::cout << "Fonction Arithmetique" << std::endl;
    std::cout << "----------------------" << std::endl;
    std::cout << "Entrez le premier nombre: ";
    std::cin >> n1;

    std::cout << "Entrez le deuxieme nombre: ";
    std::cin >> n2;

    std::cout << "Entrez l'operateur (+, -, *, /): ";
    std::cin >> operateur;

    switch (operateur)
    {
    case '+':
    case '-':
    case '*':
    case '/':
        resultat = maFonction(n1, n2, operateur);
        break;
    default:
        std::cout << "Operateur invalide!" << std::endl;
        return 1;
    }

    std::cout << "Resultat: " << resultat << std::endl;

    return 0;
}

long maFonction(long n1, long n2, char op)
{
    long resultat;
    __asm {
        mov eax, n1
        mov ebx, n2
        xor ecx, ecx; Mettre ecx à zéro
        mov cl, op; Déplacer 'op' dans le byte de poids faible de ecx

        ; Vérifiez l'opérateur et effectuez l'opération appropriée
        cmp ecx, '+'
        je _addition
        cmp ecx, '-'
        je _soustraction
        cmp ecx, '*'
        je _multiplication
        cmp ecx, '/'
        je _division

        xor eax, eax; Si aucun des opérateurs ci - dessus n'est trouvé, retournez 0
        jmp _end

        _addition :
        add eax, ebx
            jmp _end

            _soustraction :
        sub eax, ebx
            jmp _end

            _multiplication :
        imul eax, ebx
            jmp _end

            _division :
        test ebx, ebx
            jz _error
            cdq
            idiv ebx
            jmp _end

            _error :
        ; En cas de division par zéro, retournez une grande valeur
            mov eax, 0x7FFFFFFF

            _end:
        mov resultat, eax
    }
    return resultat;
}