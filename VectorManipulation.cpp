#include <iostream>
#include <windows.h>
#include <time.h>

using namespace std;

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

int v[10];
bool gen = false;

void optMenu() 
{
    SetConsoleTextAttribute(h, 6); 
    cout << "[*] Vector Manipulation by luz [*]\n" << endl;
    SetConsoleTextAttribute(h, 15);
    cout << "[1] - Generate Array (Default Length: 10)" << endl;
    cout << "[2] - Print Array" << endl;
    cout << "[3] - Sorting" << endl;
    cout << "[4] - Exit\n" << endl;
}

int checkDup(int i)
{
    int j = 0;
    bool dup = false;

    while (j < i && dup == false)
    {
        if (v[i] == v[j])
        {
            dup = true;
        }

        j++;
    }

    if (dup == false)
    {
        i++;
    }

    return i;
}

void genArray()
{
    srand(time(NULL));

    for (int i = 0; i < 10; i++)
    {
        v[i] = (rand() % (100 + 1 - 1) + 1); 

        i = checkDup(i);
    }

    SetConsoleTextAttribute(h, 10);
    cout << "Array generated!\n" << endl;
    SetConsoleTextAttribute(h, 15);
}

void printArray()
{
    SetConsoleTextAttribute(h, 6);
    cout << "Array Generated: " << endl;
    SetConsoleTextAttribute(h, 15);

    for (int i = 0; i < 10; i++)
    {
        cout << "[" << (i + 1) << "] " << v[i] << endl;
    }

    cout << endl;
}

void bubbleSort(int arr[], int n)
{
    int i, j;

    for (i = 0; (i < 10 - 1); i++)
    {
        for (j = 0; (j < 10 - i - 1); j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main()
{
    int choice;

    optMenu();

    do
    {
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            genArray();
            gen = true;
            break;
        case 2:
            if (gen == false)
            {
                SetConsoleTextAttribute(h, 12);
                cout << "[!] You must generate the array.\n" << endl;
                SetConsoleTextAttribute(h, 15);
            }
            else
            {
                printArray();
            }
            break;
        case 3:
            bubbleSort(v, sizeof(v));
            printArray();
            break;
        case 4:
            SetConsoleTextAttribute(h, 12);
            cout << "[!] Thank you.\n" << endl;
            SetConsoleTextAttribute(h, 15);
            exit(0);
        default:
            SetConsoleTextAttribute(h, 12);
            cout << "[!] Insert a valid option.\n" << endl;
            SetConsoleTextAttribute(h, 15);
        }
    } while (choice != 4);

    return 0;
}
