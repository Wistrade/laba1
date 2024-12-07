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
            cout << "������� ����� �������: ";
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

            cout << "������� �������� ��������� �������: " << xResult << "��� ��������� �������: " << skoResult << endl;
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
            cout << "������� ����� ����� �������: ";
            cin >> newN;
            Array C(A->changeSize(newN));
            cout << C << endl;
            break;
        }
        case 6:
        {
            int i;
            cout << "�������� ����� �������� ��� ���������: ";
            cin >> i;
            number X;
            cout << "�������� ����� �������� ��� ��������: ";
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
    cout << "1 - ������� ������ � N �� � ���������" << endl;
    cout << "2 - ���������� ������� � ��� �������" << endl;
    cout << "3 - ���������� �� �����������" << endl;
    cout << "4 - ���������� �� ��������" << endl;
    cout << "5 - �������� ������ �������" << endl;
    cout << "6 - �������� �� �������" << endl;
    cout << "7 - ����� �������" << endl;
    cout << "0 - exit" << endl << "> ";
    cin >> ch;
    cout << endl;
    return ch;
}