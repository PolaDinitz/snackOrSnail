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
};