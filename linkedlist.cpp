#include <iostream>
#include <fcntl.h>
#include <io.h>

using namespace std;

struct node {
    int data;
    node *next;
};

class LinkedList{
    private:
        node *head, *tail;
    public:
        LinkedList(){
            head = NULL;
            tail = NULL;
        }

        node* get_head() { 
            return head;};
        node* get_tail() { return tail;};

        void add_node(int a){
            node *tmp = new node;
            tmp->data = a;
            tmp->next = NULL;

            if(head == NULL){
                head = tmp;
                tail = tmp;
            }
            else{
                tail->next = tmp;
                tail = tail->next;
            }
        }

        void display(){
           _setmode(_fileno(stdout), 0x00020000);
            node *temp=new node;
            temp=head;
            while(temp!=NULL)
            {
                wcout<<temp->data<<"\t";
                temp=temp->next;
            }
        } 

};