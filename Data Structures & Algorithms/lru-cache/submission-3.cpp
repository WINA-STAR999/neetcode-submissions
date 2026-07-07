class LRUCache {
public:
int capacity;
    struct Node{
        int key;
        int value;
        Node* prev;
        Node* next;
        Node (int k, int v){
            key = k;
            value = v;
            prev = next = nullptr;
        }
    };
    unordered_map <int, Node*> mp;
    struct doubleLinkList{
        Node *head = nullptr;
        Node *tail = nullptr;
    };
    doubleLinkList dLL;
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    

    Node* pushFront(int key, int value){
        Node *newNode = new Node(key, value);
        if (dLL.tail == nullptr){
            dLL.tail = newNode;
            dLL.head = newNode;
            return newNode;
        }
        newNode->next = dLL.head;
        dLL.head->prev = newNode;
        dLL.head = newNode;
        return newNode;
    }
    Node* removeTail(){
        if (dLL.tail == nullptr) return nullptr;
        Node* tmp = dLL.tail;
        if (dLL.tail == dLL.head){
            dLL.head = nullptr;
            dLL.tail = nullptr;
            return tmp;
        }
        dLL.tail = dLL.tail->prev;
        dLL.tail->next = nullptr;
        return tmp;
    }
    Node* remove(int key){
        if (mp.find(key) == mp.end()) return nullptr;
        if (mp[key] == dLL.tail){
            return removeTail();
        }
        if (mp[key] == dLL.head){
            Node *tmp = mp[key];
            dLL.head = tmp->next;
            dLL.head->prev = nullptr;
            tmp->next = nullptr;
            tmp->prev = nullptr;
            return tmp;
        }
        Node* tmp = mp[key];
        tmp->prev->next = tmp->next;
        tmp->next->prev = tmp->prev;
        tmp->next = nullptr;
        tmp->prev = nullptr;
        return tmp;
    }
    int get(int key) {
        if (mp.find(key) == mp.end()) return -1;
        Node* tmp = remove(key);
        Node*newNode = pushFront(tmp->key, tmp->value);
        mp[key] = newNode;
        delete tmp;
        return newNode->value;
    }
    void put(int key, int value){
        if (mp.find(key) != mp.end()){
            mp[key]->value = value;
            Node* tmp = remove(key);
            Node *newNode = pushFront(tmp->key, tmp->value);
            mp[key] = newNode;
            delete tmp;
        }
        else if (mp.size() < capacity){
            Node* newNode = pushFront(key, value);
            mp[key] = newNode;
        }
        else{
            Node* del = removeTail();
            mp.erase(del->key);
            delete del;
            Node *newNode = pushFront(key, value);
            mp[key] = newNode;
        }
    }
};
