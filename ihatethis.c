#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

// datatype for storing operators and operands
typedef struct node
{
    double number;
    char sign;
    struct node *next;
} node;

// prototypes
void rblanks(char *test);
node *split(char n[], node *ls);
double calculate(node *ls);
void md(node *ls);
double as(node *ls);
void listfree(node *ls);
void clear(char *i);
double brackethandle(char *n, int i);
char *arr;

double result;

int main(void)
{
    arr = malloc(1000);
    // list with values and operands
    node *list;

    // input string
    char *input = malloc(1000 * sizeof(char));

    // prompt
    printf("INPUT: ");
    fgets(input, 1000, stdin);

    // making string readable to calculator
    rblanks(input);

    list = malloc(sizeof(node));
    // sorting string as linked list
    list = split(input, list);

    // calculating result
    result = calculate(list);

    // printing result
    fprintf(stdout, "OUTPUT: %lf\n", result);

    // clear input array
    free(arr);
    free(input);

    return EXIT_SUCCESS;
}

// removes blanks
void rblanks(char *test)
{

    // loops to end of string
    for (int a = 0, k = 0; a < strlen(test); a++)
    {

        // copies characters to itself
        test[a] = test[a + k];

        // removes whitespace if copied overwriting with other characters in string
        if (test[a] == ' ' || test[a] == '\t')
        {
            a--;
            k++;
        }

        // if newline, copy void character and return string
        if (test[a] == '\n')
        {
            test[a] = '\0';
            return;
        }
    }
}

// splits string into linked list
node *split(char *n, node *ls)
{
    // temporary pointer for initializing linked list
    node *temp = ls;

    // cursor for each character in string
    char cursor;
    int state, pten;
    state = 0;
    pten = 1;
    // set number of node to 0
    temp->number = 0;

    // loop through string
    for (int a = 0; a < strlen(n); a++)
    {
        // set cursor
        cursor = n[a];

        // check for number
        switch (state)
        {
        case 0:
            // number handling
            if (cursor >= '0' && cursor <= '9')
            {
                // append number to number of list (non decimal place)
                temp->number = temp->number * 10 + (float)((int)cursor - 48);
            }
            // decimal handling
            else if (cursor == '.')
            {
                state = 1;
            }
            // result handling
            else if (cursor == 'a')
            {
                temp->number = result;
            }
            // bracket handling
            else if (cursor == '(')
            {
                temp->number = brackethandle(n, a + 1);
                state = 2;
            }
            else
            {
                // add sign to sign of list
                temp->sign = cursor;

                // create new node
                temp->next = malloc(sizeof(node));
                node *head = temp->next;
                temp = head;
                temp->number = 0;
            }
            break;

        case 1:
            if (cursor >= '0' && cursor <= '9')
            {
                // append number to number of list (decimal place)
                temp->number = (temp->number * pow(10.00, (double)pten) + (float)((int)cursor - 48)) / pow(10.00, (double)pten);
                ++pten;
            }
            else
            {
                // add sign to sign of list
                temp->sign = cursor;

                // create new node
                temp->next = malloc(sizeof(node));
                node *head = temp->next;
                temp = head;
                temp->number = 0;
                pten = 1;
                state = 0;
            }
            break;
        case 2:
            // skipping till end of bracket
            if (cursor == ')')
            {
                state = 0;
            }
            else
            {
                ;
            }
            break;
        }
    }
    return ls;
}

// calculates result
double calculate(node *ls)
{
    // multiplication and division
    md(ls);

    // addition and substraction
    double result = as(ls);

    // returning result
    listfree(ls);

    return result;
}

void md(node *ls)
{
    node *head = ls->next;
    // returning if end of list
    if (head == NULL)
        return;
    // if sign is * or /
    switch (ls->sign)
    {
    // division
    case '/':

        // divide number by next number
        head->number = ls->number / head->number;
        ls->sign = '+';
        ls->number = 0;
        break;

    // multiplication
    case '*':

        // multiply number by next number
        head->number = ls->number * head->number;
        ls->sign = '+';
        ls->number = 0;
        break;

    // else
    default:
        break;
    }

    // next element
    md(ls->next);
}

double as(node *ls)
{
    node *head = ls->next;
    // last number
    if (head == NULL)
        return ls->number;
    // addition
    else if (ls->sign == '+')
        return ls->number + as(head);

    // subtraction
    else if (ls->sign == '-')
        return ls->number - as(head);
}

// freeing memory
void listfree(node *ls)
{
    if (ls->next == NULL)
    {
        free(ls);
    }
    else
    {
        node *head = ls->next;
        listfree(head);
        free(ls);
    }
    return;
}

double brackethandle(char *n, int i)
{

    arr = realloc(arr, 1000);
    for (int k = 0; n[i] != ')'; k++, i++)
    {
        arr[k] = n[i];
    }
    node *l = malloc(sizeof(node));
    rblanks(arr);
    l = split(arr, l);
    return calculate(l);
}
