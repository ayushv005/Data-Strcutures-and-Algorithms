#include<iostream>
using namespace std;

struct Node
{
  int data;
  Node* next;
}*head;

Node* createNode(int data)
{
  Node* temp = new Node(); //allocated at runtime allocation
  temp->data = data;
  temp->next = NULL;
  return temp;
}

void insertTail(int data)
{
  if(head==NULL)
    head = createNode(data);
  else
  {
    Node* itr = head;
    while(itr->next!=NULL)
      itr = itr->next;

    itr->next = createNode(data);
  }
}

void insertHead(int data)
{
  if(head==NULL)
    head = createNode(data);
  else
  {
    Node* itr = createNode(data);
    itr->next = head;
    head = itr;
  }
}

void insertPos(int data, int n)
{
  if (head==NULL || n<1)
    return;
  if (n==1)
  {
    insertHead(data);
    return;
  }
  Node* itr = head;
  for(int i=1;i<n-1;i++)
  {
    if(itr!=NULL)
      itr=itr->next;
    else
      return;
  }
  Node* temp = createNode(data);
  temp->next = itr->next;
  itr->next = temp;
}

void deleteData(int data)
{
  if(head==NULL)
    return;
  if(head->data==data)
  {
    head = head->next;
    return;
  }
  Node* itr = head;
  while(itr->next!=NULL && itr->next->data!=data)
    itr = itr->next;

  if(itr->next->data==data)
    itr->next = itr->next->next;
}

void deletePos(int n)
{
  if(head==NULL || n<1)
    return;
  if(n==1)
  {
    head = head->next;
    return;
  }
  Node* itr = head;
  for(int i=1;i<n-1;i++)
  { //itr points at n-1 node
    if(itr->next!=NULL)
      itr = itr->next;
    else
      return;
  }
  itr->next = itr->next->next;
}

void reverseList()
{
  if(head==NULL || head->next==NULL)
    return;
  Node* current = head;
  Node* prev = NULL;
  Node* nxt_locl;

  while(current!=NULL)
  {
    nxt_locl = current->next;
    current->next = prev;
    prev = current;
    current = nxt_locl;
  }
  head = prev;
}

void print()
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
  insertTail(5);
  insertTail(4);
  insertTail(3);
  insertTail(2);
  insertTail(5);
  insertTail(9);
  insertHead(13);
  insertPos(-199,3);
  print();
  deleteData(5);
  print();
  deletePos(4);
  print();
  reverseList();
  print();
  return 0;
}
