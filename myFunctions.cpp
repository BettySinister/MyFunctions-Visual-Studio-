#include <iostream>
#include <vector>
using namespace std;

enum order { ASC, DESC };


/*** ПРОТОТИПЫ ФУНКЦИЙ ***/

int findIndexOfInt(int x, int integers[]);
// Возвращает индекс первого попавшегося в массиве числа, равного заданному

int findIndexOfInt(int x, int integers[], int count[]);
// Возвращает индекс первого попавшегося в массиве числа, равного заданному, и сохраняет количество совпадений в первый элемент списка

void intBubbleSort(int integers[], int size, order myOrder = order::ASC);
// Сортирует элементы в массиве

void arrayInput(int integers[]);
// Ввод элементов в массив с консоли

void arrayPrint(int integers[]);
// Вывод элементов массива на экран

vector <vector <int>> amountAndIndexes(int x, int integers[]);
// Возвращает вектор векторов, где первый вектор - количество совпадений с x, а во втором хранятся все индексы совпавших элементов

void amountAndIndexesPrint(vector <vector<int>> container);
// Вывод на экран вектора, который вернула функция amountAndIndexes




/*** ТЕЛО ПРОГРАММЫ ***/

int main()
{
    int ints[7];
    arrayInput(ints);
    int toFind = 20;
    amountAndIndexesPrint(amountAndIndexes(toFind, ints));
    
    
    /*char descOrderResponse;
    while (true) {
        cout << "Sort descending or ascending? (d - descending / a - ascending)" << endl;
        cin >> descOrderResponse;
        if ((descOrderResponse == 'a') || (descOrderResponse == 'd')) {
            break;
        }
        else {
            cout << "Incorrect input!" << endl;
        }
    }
    descOrderResponse == 'a' ? intBubbleSort(ints, 7, order::ASC) : intBubbleSort(ints, 7, order::DESC);

    intBubbleSort(ints, 7);
    arrayPrint(ints);

    */



    /*try
    {
        cout << findIndexOfInt(toFind, ints, count) << "\n";
    }
    catch (const exception& ex)
    {
        cout << ex.what() << endl;
    }
    */
}




/*** ФУНКЦИИ ***/

int findIndexOfInt(int x, int integers[]) // Возвращает индекс первого попавшегося в массиве числа, равного заданному 
{
    int i = 0;
    while (i < 7)
    {
        if (integers[i] == x)
        {
            return i;
        }
        i++;
    }
    //    throw exception("Item not found!");
}


int findIndexOfInt(int x, int integers[], int count[]) // Возвращает индекс первого попавшегося в массиве числа, равного заданному, и сохраняет количество совпадений в первый элемент списка
{
    int i = 0;
    int counter = 0;
    for (int i = 0; i < 7; i++)
    {
        if (integers[i] == x)
        {
            counter++;
        }
    }
    count[0] = counter;

    for (int i = 0; i < 7; i++)
    {
        if (integers[i] == x)
        {
            return i;
        }
    }
}


void intBubbleSort(int integers[], int size, order myOrder) // Сортирует элементы в массиве
{
    bool sortCheck = false;
    while (!sortCheck)
    {
        sortCheck = true;
        for (int i = 0; i < size - 1; i++)
        {
            int comparisonResult =
                myOrder == order::ASC ?
                integers[i] - integers[i + 1]
                : integers[i + 1] - integers[i];
            if (comparisonResult > 0)
            {
                int temp = integers[i];
                integers[i] = integers[i + 1];
                integers[i + 1] = temp;
                sortCheck = false;
            }
        }
    }
}


void arrayInput(int integers[]) // Ввод элементов в массив с консоли
{
    cout << "Enter the values for the array one by one." << endl;
    for (int i = 0; i < 7; i++)
    {
        cout << "Value " << i + 1 << " out of 7: ";
        cin >> integers[i];
    }
}


void arrayPrint(int integers[]) // Вывод элементов массива на экран
{
    cout << "[ ";
    for (int i = 0; i < 7; i++)
    {
        cout << integers[i] << " ";
    }
    cout << "]";
}


vector <vector <int>> amountAndIndexes(int x, int integers[])
{
    vector <vector <int>> container = { {0},{} };
    for (int i = 0; i < 7; i++)
    {
        if (integers[i] == x) {
            ++container[0][0];
            container[1].push_back(i);
        }
    }
    return container;
}
   
void amountAndIndexesPrint(vector < vector < int > > container)
{
    cout << "Matches: " << container[0][0] << endl;
    cout << "Indexes: ";
    for (int i = 0; i < container[1].size(); i++)
    {
        cout << container[1][i] << " ";
    }
}
