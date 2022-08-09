#include <iostream>
using namespace std;

/*
This is a list of common mistakes with pointers that result in runtime errors that will NOT be caught by Intellisense.
It is important you recognize these errors, as they can be hard to debug and find without knowing what causes these errors.
*/

// Linked List Node Struct
struct IntNode
{
    IntNode() : value(0), next(nullptr) {}
    IntNode(int x) {value = x; next = nullptr; }
    IntNode(int x, IntNode* next) {value = x; this->next = next;}
    int value;
    IntNode* next;
};


/*
Depending on how far out of range you go, this might not result in a runtime error, but simply undefined behavior, which is far harder to spot since your program doesn't terminate.
However, it is still important to make sure you stay within the bounds of any array/vector/linked list/data structure you may be using.
*/
void arrayIndexOutOfBounds()
{
    int size = 10;
    int arr[size];
    // The error is the i <= size, since you would be iterating up to an element that doesn't exist in the array.
    for (int i = 0; i <= size; i++)
    {
        arr[i] = i;
        cout << arr[i] << ' ';
    }
    // How would you fix this?
}

/*
Dereferencing a null pointer results in a segementation fault, but you don't get any feedback from a segmentation fault.
Make sure that whenever you dereference any pointer that you have, it can NEVER be a nullptr at that point.
*/
void dereferenceNull()
{
    // Since a node's next element is initialized to nullptr...
    IntNode* node = new IntNode(1, nullptr);
    // attemping to access it will result in a segementation fault.
    int x = node->next->value;
}

/*
If a pointer is uninitialized, and we dereference it, it can result in undefined behavior, or a segementation fault.
Make sure that a pointer is initialized before it is dereferenced.
*/
void uninitializedPointer()
{
    int* pointer;
    int x = *pointer;
}

/*
The same goes for the other way around...
but this error is arguably far worse since this won't result in your program terminating, making it harder to catch.
Make sure you initialize your variables. 
*/
void uninitializedVariable()
{
    int x;
    int* pointer = &x;
}

/*
A double free is easier to catch simply because your program will tell you if you did a double free or not. 
However, it is still important to make sure you only delete elements exactly once. 
This is important to keep in mind when you are deleting all the nodes in your linked lists.

NOTE: A good way to avoid double frees are to assign nullptr to pointers you delete.
Most compilers these days are smart enough to not delete nullptr.
*/
void doubleFree()
{
    IntNode* node = new IntNode(0);
    delete node;
    delete node;
}

/*
Another thing to keep in mind whenever you're deleting a linked list: 
make sure you don't delete your only reference to the next node.
This may result in memory leaks.
*/
void lostMemory()
{
    IntNode* head = new IntNode(0);             // initializes 1st node
    IntNode* tail = new IntNode(1, nullptr);    // initializes 2nd node
    head->next = tail;                          // setting the nodes to be linked
    delete head;                                // the first node is deleted
    
    // Now, how do you get to the 2nd node (without calling tail ;) )? You can't!
    // This is a common issue when you have to delete a linked list...
    // ...but you only have access to the head of the linked list!
    // How would you fix this issue?
}

/*
You only need to "delete" what you allocate with "new" (remember, heap vs stack)
This will result in something called an access violation.
*/
void invalidFree()
{
    int* pointer1;
    int x = 0;
    pointer1 = &x;

    delete pointer1; // Not needed
}

/*
Make sure that you delete your heap-allocated objects only after you're done using them.
This will result in undefined behavior.
To catch this error, you can assign nullptr after you delete, so that this operation results in an access violation so your program stops, making it easier to find.
*/
void dereferenceAfterDelete()
{
    IntNode* node = new IntNode(1);
    delete node;
    node->value = 2;
}
/*
Note that node and nodeCopy point to the exact same node.
Thus, when freed with "delete node", any use of nodeCopy will result in undefined behavior.
However, also note that if we delete nodeCopy, that results in a double free!
*/
void deletingCopy()
{
    IntNode* node = new IntNode(1);
    IntNode* nodeCopy = node;
    delete node;
    nodeCopy->value = 2;
}

/*
What will the output of this function be?
While two different pointers may point to equivalent values, they will never be equal.
This is because they point to two different MEMORY LOCATIONS, not values.
Thus, if you compare these pointers, what will happen? How would you fix this logic error?
*/
void comparisionError()
{
    int* pointer1 = new int(1);
    int* pointer2 = new int(1);
    if (pointer1 == pointer2) 
    {
        cout << "The two values are equal." << endl;
    }
    else 
    {
        cout << "The two values are not equal." << endl;
    }
}

int main() 
{
    deletingCopy();
}