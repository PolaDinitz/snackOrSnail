#include "linkedlist.cpp"
#include <iostream>
#include <random>
#include <chrono>

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
    if(unif(rng) >= 0.5){
        cout << "got snake" << endl;
        while(unif(rng) > 0.1) {
            list->add_node((int)(unif(rng)*1000));
        } 
    } else {
        node *loop_node = new node();
        while(unif(rng) > 0.02) {
            list->add_node((int)(unif(rng)*1000));
            // check if the last inserted node is the loop node and save it
            if(unif(rng) <= 0.015){
                cout << "got new loop " <<endl;
                loop_node = list->get_tail();
            }
        }
        // change the next of the last inserted node to the loop node
        list->get_tail()->next = loop_node;
    }
}

node *SnakeOrSnail(LinkedList *list){
    node *slow_p = list->get_head(), *fast_p = list->get_head(); 
        while (slow_p != NULL && fast_p != NULL && fast_p->next != NULL) { 
            slow_p = slow_p->next; 
            fast_p = fast_p->next->next; 
            if (slow_p == fast_p) { 
                return slow_p;
            } 
        } 
        return NULL;
}
    
// left arrow unicode u2192, uparrow with tip to the right 21b1, down arrow with tip to the left 21b2
void printSnakeOrSnail(LinkedList *list){
    node *loop_node = SnakeOrSnail(list); 
    // it is a snake
    cout << loop_node << endl;
    if(loop_node == NULL){
        cout<<"snake"<<endl;
        node *temp=new node;
        temp=list->get_head();
        while(temp!=NULL)
        {
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<"->"<<"NULL\n";
    } else {
        cout<<"snail"<<endl;
        node *temp=new node;
        temp=list->get_head();
        while(temp->next!=loop_node)
        {   
            cout << temp->next << " " << loop_node <<endl;
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        // the next node is the beginning of the loop
        temp=temp->next;
        cout<<"^>";
        // when the next time the next node is the loop node we've reached the end
        while(temp->next!=loop_node)
        {   
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<"v<";
    }
}

int main(){
    LinkedList list;
    createSnakeOrSnail(&list);
    printSnakeOrSnail(&list);
    return 0;
}
 