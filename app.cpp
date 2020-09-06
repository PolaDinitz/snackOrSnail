#include "linkedlist.cpp"
#include <iostream>
#include <random>

using namespace std;

LinkedList *createSnakeOrSnail(LinkedList *list){
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(0, 1);//uniform distribution between 0 and 1

    // snake
    if(dis(rd) >= 0.5){
        while(dis(rd) > 0.1) {
            list->add_node((int)dis(rd)*1000);
        } 
    } else {
        node *loop_node = new node();
        while(dis(rd) > 0.02) {
            list->add_node((int)dis(rd)*1000);
            // check if the last inserted node is the loop node and save it
            if(dis(rd) <= 0.015){
                loop_node = list->get_tail();
            }
        }
        // change the next of the last inserted node to the loop node
        list->get_tail()->next = loop_node;
    }
    return list;
}

node *SnakeOrSnail(LinkedList *list){
    return NULL;
}
    
// left arrow unicode u2192, uparrow with tip to the right 21b1, down arrow with tip to the left 21b2
void printSnakeOrSnail(LinkedList *list){
    node *loop_node = SnakeOrSnail(list); 
    // it is a snake
    if(loop_node == NULL){
        node *temp=new node;
        temp=list->get_head();
        while(temp!=NULL)
        {
            cout<<temp->data<<'\u2192';
            temp=temp->next;
        }
        cout<<'\u2192'<<"NULL\n";
    } else {
        node *temp=new node;
        temp=list->get_head();
        while(temp->next!=loop_node)
        {   
            cout<<temp->data<<'\u2192';
            temp=temp->next;
        }
        // the next node is the beginning of the loop
        temp=temp->next;
        cout<<'\u21b1';
        // when the next time the next node is the loop node we've reached the end
        while(temp->next!=loop_node)
        {   
            cout<<temp->data<<'\u2192';
            temp=temp->next;
        }
        cout<<'\u21b2';
    }
}

int main(){ 
    LinkedList a;
    return 0;
}
