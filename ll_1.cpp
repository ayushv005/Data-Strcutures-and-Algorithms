#include<iostream>
#include<unordered_set>
using namespace std;

struct Node
{
  int data;
  Node* next;
}*head;

Node* createNode(int data)
{
  Node* temp = new Node();
  temp->data = data;
  temp->next = NULL;
  return temp;
}

void insertTail(int data)
{
  if (head==NULL)
  {
    head = createNode(data);
    return;
  }
  Node* itr = head;
  while(itr->next!=NULL)
    itr = itr->next;

  itr->next = createNode(data);
}

void removeDuplicates()
{
  unordered_set<int> seen;
  Node* curr = head;
  Node* prev = NULL;

  while(curr!=NULL)
  { //if found
    if(seen.find(curr->data)!=seen.end())
    {
      prev->next = curr->next;
    }
    else
    {
        seen.insert(curr->data);
        prev = curr;
    }
    curr = prev->next;
  }
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

void kToLastElem(int k) //Q2
{
  if(head==NULL)
    return;
  Node* itr = head;
  for(int i=1;i<k;i++)
  {
    if(itr->next!=NULL)
      itr = itr->next;
    else
      return;
  }
  head = itr;
  print();
}

void deleteMid(int data)
{
  if(head==NULL || head->data==data)
    return;
  Node* itr = head;
  while(itr->next!=NULL && itr->next->data!=data)
    itr = itr->next;

  if(itr->next->data==data && itr->next->next!=NULL)
    itr->next = itr->next->next;

}

int main()
{
  insertTail(-1);
  insertTail(2);
  insertTail(3);
  insertTail(67);
  insertTail(54);
  insertTail(-123);
  insertTail(12);
  insertTail(67);
  insertTail(3);
  insertTail(87);
  print();
  //removeDuplicates();
  //kToLastElem(5);
  //deleteMid(87);
  
  return 0;
}
