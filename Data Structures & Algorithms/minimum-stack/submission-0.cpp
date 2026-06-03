class MinStack {
public:
    struct Node{
        int data;
        int min_value;
        Node *next;
    };

    Node *head;
    MinStack() {
        head = NULL;
    }
    
    void push(int val) {
        Node *newNode = new Node;
        newNode->data = val;
        if (head == NULL){
            newNode->min_value = val;
            newNode->next = NULL;
            head = newNode;
            return;
        }
        if(val < head->min_value){
            newNode->min_value = val;
        }
        else{
            newNode->min_value = head->min_value;
        }
        newNode->next = head;
        head = newNode;
    }
    
    void pop() {
        if (head == NULL) return;
        Node *tmp = head;
        head = head->next;
        delete tmp;
    }
    
    int top() {
        if (head != NULL) return head->data;
    }
    
    int getMin() {
        if (head != NULL) return head->min_value;
    }
};
