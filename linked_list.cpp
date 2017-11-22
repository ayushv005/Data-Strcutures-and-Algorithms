#include<iostream>
using namespace std;

struct Node
{
  int data;
  Node* next;
}*head;

Node* getNode(int data)
{
  Node* newNode = new Node();
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

void insertNode(int data)
{
  if(head==NULL)
  {
    head = getNode(data);
  }
  else
  {
    Node* itr = head;
    while(itr->next!=NULL)
    {
      itr = itr->next;
    }
    itr->next = getNode(data);
  }
}

void deleteNode(int data)
{
  if(head==NULL)
  {
    return;
  }

  if(head->data==data)
  {
    head = head->next;
    return;
  }

  Node* itr = head;
  while(itr->next!=NULL && itr->next->data != data)
  {
    itr = itr->next;
  }
  if(itr->next->data == data)
  {
    itr->next = itr->next->next;
  }
}

void printList()
{
  Node* itr = head;
  while(itr!=NULL)
  {
    cout<<itr->data<<"\t";
    itr = itr->next;
  }
  cout<<endl;
}


int main()
{
  insertNode(10);
  insertNode(20);
  insertNode(30);
  insertNode(40);
  insertNode(90);
  insertNode(100);
  printList();

  deleteNode(100);
  printList();
  return 0;
}
