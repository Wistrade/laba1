#include "application.h"
#include <iostream>
#include "number.h"
#include "array.h"
using namespace std;
Application::Application()
{

}

int Application::exec()
{
    int ch;
    Array* A = new Array(2);

    while (true)
    {
        ch = menu();
        switch (ch)
        {
        case 0:
        {
            delete A;
            return 0;
        }
        case 1:
        {
            int n;
            cout << "Введите длину массива: ";
            cin >> n;

            A = new Array(n);

            for (int i = 0; i < n; i++)
            {
                number val;
                cin >> val;
                A->set(i, val);
            }
            cout << endl;
            break;
        }
        case 2:
        {
            number xResult;
            number skoResult;
            xResult = A->middle();
            skoResult = A->sko();

            cout << "Среднее значение элементов массива: " << xResult << "СКО элементов массива: " << skoResult << endl;
            break;
        }
        case 3:
        {
            Array T(A->sortIncreas());
            cout << T << endl;
            break;
        }
        case 4:
        {
            Array N(A->sortDecreas());
            cout << N << endl;
            break;
        }
        case 5:
        {
            int newN;
            cout << "Введите новую длину массива: ";
            cin >> newN;
            Array C(A->changeSize(newN));
            cout << C << endl;
            break;
        }
        case 6:
        {
            int i;
            cout << "Выберите номер элемента для изменения: ";
            cin >> i;
            number X;
            cout << "Выберите новое значение для элемента: ";
            cin >> X;
            Array J(A->changeElement(i, X));
            break;
        }
        case 7:
        {
            for (unsigned int i = 0; i < n; ++i) {
                cout << A[i] << endl;
            }
        }
        default:
        {
            delete A;
            break;
        }
        }
    }
}

int Application::menu()
{
    int ch;
    cout << "1 - создать массив с N эл и заполнить" << endl;
    cout << "2 - рассчитать среднее и СКО массива" << endl;
    cout << "3 - сортировка по возрастанию" << endl;
    cout << "4 - сортировка по убыванию" << endl;
    cout << "5 - изменить размер массива" << endl;
    cout << "6 - изменить эл массива" << endl;
    cout << "7 - вывод массива" << endl;
    cout << "0 - exit" << endl << "> ";
    cin >> ch;
    cout << endl;
    return ch;
}