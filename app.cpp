#include "linkedlist.cpp"
#include <iostream>
#include <random>
#include <chrono>
#include <fcntl.h>
#include <io.h>

using namespace std;


void createSnakeOrSnail(LinkedList *list){
    std::mt19937_64 rng;
    // initialize the random number generator with time-dependent seed
    uint64_t timeSeed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    std::seed_seq ss{uint32_t(timeSeed & 0xffffffff), uint32_t(timeSeed>>32)};
    rng.seed(ss);
    // initialize a uniform distribution between 0 and 1
    std::uniform_real_distribution<double> unif(0, 1);
    // ready to generate random numbers

    // snake
    if(unif(rng) > 0.5){
        while(unif(rng) > 0.01) {
            list->add_node((int)(unif(rng)*100));
        }
    } else {
        node *loop_node = new node();
        while(unif(rng) > 0.02) {
            int new_node = (int)(unif(rng)*100);
            list->add_node(new_node);
            // check if the last inserted node is the loop node and save it
            if(unif(rng) <= 0.015){
                loop_node = list->get_tail();
            }
        }
        // change the next of the last inserted node to the loop node
        list->get_tail()->next = loop_node;
    }
};

node *SnakeOrSnail(LinkedList *list){
    if (list->get_head() == NULL || list->get_head()->next == NULL)
        return NULL;

    node* slow = list->get_head(); 
    node* fast = list->get_head();
    slow = slow->next;
    fast = fast->next->next;

    while (fast && fast->next){
        if(slow == fast)
            break;
        slow = slow->next;
        fast = fast->next->next;
    }
    wcout<<endl;
    if(slow != fast)
        return NULL;
    
    slow = list->get_head();
    while(slow != fast){
        slow = slow->next;
        fast = fast->next;
    } 
    return slow;
};
 
// left arrow unicode u2192, uparrow with tip to the right 21b1, down arrow with tip to the left 21b2
void printSnakeOrSnail(LinkedList *list){
    _setmode(_fileno(stdout), 0x00020000);
    node *loop_node = new node();
    loop_node = SnakeOrSnail(list); 
    // it is a snake
    cout << loop_node << endl;
    int counter = 0;
    if(loop_node == NULL){
        node *temp=new node();
        temp = list->get_head();
        while(temp!=NULL)
        {
            wcout<<temp->data<<L"\x2192";
            temp=temp->next;
            counter++;
        }
        wcout<<"null" << endl;
        wcout << "number of nodes in the snake are: " << counter << endl;
    } else {
        int counter = 3;
        int counterLoop = 2;
        node *temp=new node;
        temp=list->get_head();
        while(temp->next->next!=loop_node){
            counter++;   
            wcout<<temp->data<<L"\x2192";
            temp=temp->next;
        }
        wcout<<temp->data;
        temp=temp->next;
        // the next node is the beginning of the loop
        temp=temp->next;
        wcout<<L"\x21B1" << temp->data << L"\x2192";
        temp=temp->next;

        // when the next time the next node is the loop node we've reached the end
        while(temp->next!=loop_node)
        {   
            counter++;
            counterLoop++;
            wcout<<temp->data<<L"\x2192";
            temp=temp->next;
        }
        wcout<<temp->data;
        wcout<<L"\x21B2"<<endl;
        wcout<<"Number of nodes in the snail: "<<counter<<" Number of nodes in the loop: "<<counterLoop<<endl;
    }
};

int main(){
    LinkedList list;
    createSnakeOrSnail(&list);
    printSnakeOrSnail(&list);
    return 0;
}
 