/*
Автор: Боев Максим
 Калькулятор с 6 базовыми функциями
 Пользователю необходимо выбрать одну из допустимых операций и 2 числа, после калькулятор произведёт вычисления и предложит пользователю продолжить или прекратить работу

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main (void)
{
    printf (" Hello!\n");
    printf (" This program performs the selected operation between two numbers \n" );
    printf (" To be successful, you must first enter the operation and then the 2 numbers [ 1 in the case of the factorial] \n" );
    printf (" Available operations :addition(+), subtraction(-), multiplication(*), division(/ ), exponentiation(^), factorial(!) \n" );
    
    // Введём переменные
    double num1, num2; // Числа, вводимые пользователем с клавиатуры
    double res; // Результат операции
    char operation; // Вид операции
    char consent; // Перемаенная для возобновления работы после завершения программы (при желании пользователя)
    do // Цикл для возобновленя работы после завершения программы
    {
        setvbuf (stdout, NULL, _IONBF, 0);
        setvbuf (stderr, NULL, _IONBF, 0);
        // Выбор операции
        printf ("\n Select an operation ( +, -, *, /, ^, !):");
        scanf (" %c", &operation);
        
        // Операции
        switch (operation)
        {
            // Функция для сложения чисел
        case '+':
            printf ("\nEnter the first number:");
            scanf (" %lf", &num1);
            printf ("\nEnter the second number:");
            scanf (" %lf", &num2);
            res = num1 + num2;
            printf ("\n%lf + %lf = %lf", num1, num2, res);
            break;

            //Функция для вычитания чисел
        case '-':
            printf ("\nEnter the first number:");
            scanf (" %lf", &num1);
            printf ("\nEnter the second number:");
            scanf (" %lf", &num2);
            res = num1 - num2;
            printf ("\n%lf - %lf = %lf", num1, num2, res);
            break;

            //Функция для умножения чисел
        case '*':
            printf ("\nEnter the first number:");
            scanf (" %lf", &num1);
            printf ("\nEnter the second number:");
            scanf (" %lf", &num2);
            res = num1 * num2;
            printf ("\n%lf * %lf = %lf", num1, num2, res);
            break;

            //Фунция для деления чисел
        case '/':
            printf ("\nEnter the first number:");
            scanf (" %lf", &num1);
            printf ("\nEnter the second number  :");
            scanf (" %lf", &num2);
            res = num1 / num2;
            if (num2 == 0) printf ("Делить на ноль нельзя!");
            else printf ("\n%lf / %lf = %lf", num1, num2, res);
            break;

            //Функция для возведения числа в степень
        case '^':
            printf ("\nEnter the first number:");
            scanf (" %lf", &num1);
            printf ("\nEnter the second number:");
            scanf (" %lf", &num2);
            double numb1 = num1;
            if (num2 == 0) {
                printf ("\n %lf^%lf= 1", num1, num2);
            }
            else if (num2 == 1) {
                printf ("\n %lf^%lf= %lf", num1, num2, num1);
            }
            else if (num2 == -1) {
                res = 1 / num1;
                printf ("\n %lf^%lf=%lf", num1, num2, res);
            }
            else if (num2 < 0) {
                num2 *= -1;
                for (int i = 1; i < num2; i++)
                {
                    num1 = num1 * numb1;
                    res = 1/num1;
                }
                printf ("\n%lf ^ %lf = %lf", numb1, num2, res);
            }
            else if (num2>0) {

                for (int i = 1; i < num2; i++)
                {
                    num1 = num1 * numb1;
                    res = num1;
                }
                printf ("\n%lf ^ %lf = %lf", numb1, num2, res);
            }
            
            break;

            //Функция для нахождения факториала числа 
        case '!':
            printf ("\nEnter the number:");
            scanf (" %lf", &num1);
            double numv1 = num1;
            if (num1 > 0) for (int i = 1; i < numv1; i++)
            {
                num1 = num1 * (numv1 - i);
            }
            if (num1 == 0) printf ("0! = 1");
            else if (num1 < 0) printf ("Undefined");
            else printf ("\n%lf! = %lf", numv1, num1);
            break; 
         // При ошибке при введении операции
        default:
            printf("\nOperation selection error");
        }
        // Согласие/отказ дальше работать с программой
        printf ("\nWould you like to continue? Yes=y,No=n:");
        scanf (" %c", &consent);
        // Условие продолжения
    } while (consent == 'y');
    //Условие завершения
    if (consent == 'n') printf("\nGoodbye!");
    else printf ("\nOperation selection error");
    return 0;
}