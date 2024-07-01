/*
 *  File Name: MyArray.cpp
 *  Assignment: ENSF 694 Lab 1 Exercise F
 *  Created by: Yael Gonzalez
 *  Submission Date: July 3, 2024
 */
#include "MyArray.h"

// TODO: Ask if I should include comments for this, and in such case add them.
int search(const MyArray *myArray, int obj)
{
    for (int i = 0; i < myArray->list_size; i++)
    {
        if (myArray->array[i] == obj)
        {
            return i;
        }
    }

    return -1;
}

void initialize(MyArray *myArray)
{
    myArray->list_size = 0;
}

int retrieve_at(MyArray *myArray, int pos)
{
    return myArray->array[pos];
}

int count(MyArray *myArray, int obj)
{
    int sum = 0;

    for (int i = 0; i < myArray->list_size; i++)
    {
        if (myArray->array[i] == obj)
        {
            sum++;
        }
    }

    return sum;
}

void append(MyArray *myArray, int array[], int n)
{
    if ((myArray->list_size + n) <= SIZE)
    {
        for (int i = 0; i < n; i++)
        {
            myArray->array[myArray->list_size++] = array[i];
        }
    }
}

void insert_at(MyArray *myArray, int pos, int val)
{
    for (int i = myArray->list_size; i > pos; i--)
    {
        myArray->array[i] = myArray->array[i - 1];
    }

    myArray->array[pos] = val;

    myArray->list_size++;
}

int remove_at(MyArray *myArray, int pos)
{
    int removed_value = myArray->array[pos];

    for (int i = pos; i < myArray->list_size - 1; i++)
    {
        myArray->array[i] = myArray->array[i + 1];
    }

    myArray->list_size--;

    return removed_value;
}

int remove_all(MyArray *myArray, int value)
{
    int count = 0;

    for (int i = 0; i < myArray->list_size; i++)
    {
        if (myArray->array[i] == value)
        {
            remove_at(myArray, i);
            count++;
        }
    }
    return count;
}

void display_all(MyArray *myArray)
{
    for (int i = 0; i < myArray->list_size; i++)
    {
        cout << myArray->array[i] << "  ";
    }
    cout << endl;
}

bool is_full(MyArray *myArray)
{
    if (myArray->list_size == SIZE)
    {
        return true;
    }

    return false;
}

bool isEmpty(MyArray *myArray)
{
    if (myArray->list_size == 0)
    {
        return true;
    }

    return false;
}

int size(MyArray *myArray)
{
    return myArray->list_size;
}
