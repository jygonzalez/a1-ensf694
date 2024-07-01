/*
 *  File Name: MyArray.cpp
 *  Assignment: ENSF 694 Lab 1 Exercise F
 *  Created by: Yael Gonzalez
 *  Submission Date: July 3, 2024
 */
#include "MyArray.h"

int search(const MyArray *myArray, int obj)
{
    // For each element in the list, if the element matches the search object return the index
    // (position) of the element.
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
    int count = 0;

    // For each element in the list, if the element matches the object increment the count
    for (int i = 0; i < myArray->list_size; i++)
    {
        if (myArray->array[i] == obj)
        {
            count++;
        }
    }

    return count;
}

void append(MyArray *myArray, int array[], int n)
{
    // If there is enough space to append the new elements, for each element in the input array:
    // Append it to the list and increment the list size
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
    // Shift elements to the right to make space for the new element
    for (int i = myArray->list_size; i > pos; i--)
    {
        myArray->array[i] = myArray->array[i - 1];
    }

    // Insert the new element at the specified position
    myArray->array[pos] = val;

    // Increment the list size
    myArray->list_size++;
}

int remove_at(MyArray *myArray, int pos)
{
    int removed_value = myArray->array[pos];

    // Shift elements to the left to fill the gap
    for (int i = pos; i < myArray->list_size - 1; i++)
    {
        myArray->array[i] = myArray->array[i + 1];
    }

    // Decrement the list size
    myArray->list_size--;

    return removed_value;
}

int remove_all(MyArray *myArray, int value)
{
    int count = 0;

    // For every element in the list that matches the value to be removed:
    // Remove the element and increment the count of removed elements
    for (int i = 0; i < myArray->list_size; i++)
    {
        if (myArray->array[i] == value)
        {
            remove_at(myArray, i);
            count++;
            i--; // Adjust the index to account for the removed element
        }
    }

    return count;
}

void display_all(MyArray *myArray)
{
    // Print each element in the list, one row per line
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
