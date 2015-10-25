#ifndef PALINDROME_H
#define PALINDROME_H

#include <assert.h>
#include "linkedlist.h"
#include "linkedstack.h"

bool is_palindrome(const char *str)
{
    const char *i, *j;
    i = j = str;

    // Moving j to point to last symbol of str
    while (*j != '\0') ++j; --j;

    // Empty string assertion
    assert(j >= i);

    // Move i from left to right and j from
    // right to left till either pointers
    // contain different characters or they
    // cross
    while (*i == *j && j-- > i++);

    // If we exit 'while' above having 'i'
    // passed 'j' - the word is palindrome
    return j < i;
}

// Converts string to linke list of chars
void str2ll(const char *str, ADS_LinkedList list)
{
    char *s = (char *) str;
    while (*s != '\0')
        ADS_LinkedList_append_node(list, s++);
}

// Checks whether a linked list of chars is a palindrome
bool is_ll_palindrome(ADS_LinkedList list)
{
    // The list should not be empty
    assert(list->size > 0);

    // If list contains one node only - it's a polindrome
    if (list->size == 1)
        return true;

    // Slow/fast runner technique will be used to determine
    // the middle of list
    ADS_LinkedListNode slow = list->head;
    ADS_LinkedListNode fast = slow->next;

    // A stack will be used to hold valus from the first
    // half of linked list
    ADS_LinkedStack stack = ADS_LinkedStack_allocate();

    // Iterate through the list and push values from its
    // first half to stack
    do {
        ADS_LinkedStack_push(stack, slow->value);

        slow = slow->next;
        fast = fast->next;
        if (fast)
            fast = fast->next;
    } while (fast);

    // Now slow runner points to the first element we need
    // to check
    do {
        char *c = ADS_LinkedStack_pop(stack);
        if (*c != *((char *) slow->value))
            break;

        slow = slow->next;
    } while (slow);

    ADS_LinkedStack_destroy(stack);

    // If we left the do-while block above with slow runner
    // set to NULL - it's a palindrome
    return slow == NULL;
}

#endif // PALINDROME_H
