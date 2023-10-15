#include <iostream>
long maFonction(char op, long n1, long n2);
using namespace std;

int main()
{
    char operation;
    long num1, num2, resultat;

    // Demander à l'utilisateur les valeurs
    std::cout << "Instruction Switch" << std::endl;
    std::cout << "----------------------" << std::endl;
    cout << "Entrez l'opération (+,-,*,/): ";
    cin >> operation;
    cout << "Entrez le premier nombre: ";
    cin >> num1;
    cout << "Entrez le deuxieme nombre: ";
    cin >> num2;

    resultat = maFonction(operation, num1, num2);
    cout << "Resultat = " << resultat << "\n";

    return 0;
}

long maFonction(char op, long n1, long n2) 
{
    long result = 0;
    __asm
    {
        mov eax, n1; Mettre n1 dans eax(pour utilisation avec al)
        mov ebx, n2; Mettre n2 dans ebx
        xor ecx, ecx; Vider ecx
        mov cl, op; Mettre op dans cl(partie basse de ecx)

        cmp cl, '+'; Vérifier si l'opérateur est ' + '
        je case_addition

        cmp cl, '-'; Vérifier si l'opérateur est ' - '
        je case_subtraction

        cmp cl, '*'; Vérifier si l'opérateur est ' * '
        je case_multiplication

        cmp cl, '/'; Vérifier si l'opérateur est ' / '
        je case_division

        jmp end_switch

        case_addition :
        add eax, ebx
            mov result, eax
            jmp end_switch

            case_subtraction :
        sub eax, ebx
            mov result, eax
            jmp end_switch

            case_multiplication :
        imul eax, ebx
            mov result, eax
            jmp end_switch

            case_division :
        test ebx, ebx; Vérifier pour éviter la division par zéro
            je end_switch
            cdq
            idiv ebx
            mov result, eax

            end_switch :
    }
    return result;
}
