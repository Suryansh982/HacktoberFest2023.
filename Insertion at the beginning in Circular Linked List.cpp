#include<iostream>
#include<stdio.h>
using namespace std;

// structure for Circular Linked List
struct Node
{
  int data;
  struct Node *next;
};

int calcSize (struct Node *head);

void insertStart (struct Node **head, int data)
{
  struct Node *newNode = (struct Node *) malloc (sizeof (struct Node));
  newNode->data = data;

  // if its the first node being entered
  if (*head == NULL)
    {
      *head = newNode;		// assigning itself as head
      (*head)->next = *head;	// assigning itself as next node

      cout << newNode->data << " Inserted\n";
      return;
    }

  // if CLL already as >=1 node
  struct Node *curr = *head;

  // traverse till last node in CLL
  while (curr->next != *head)
    {
      curr = curr->next;
    }

  curr->next = newNode;		// last node's next as this new node
  newNode->next = *head;	// new node's next as current head node

  *head = newNode;		// changing head node to this new node
  cout << newNode->data << " Inserted\n";

  // previous head node becomes 2nd node
}

void display (struct Node *head)
{
  // if there are no node in CLL
  if (head == NULL)
    return;

  struct Node *temp = head;
  cout << "\nLinked List : ";

  //need to take care of circular structure of CLL
  do
    {
      cout << temp->data << " ";
      temp = temp->next;

    }
  while (temp != head);
  cout << endl;
}

int main ()
{

  struct Node *head = NULL;

  insertStart (&head, 1);
  insertStart (&head, 2);
  insertStart (&head, 3);
  insertStart (&head, 4);
  insertStart (&head, 5);

  display (head);

  return 0;
}
