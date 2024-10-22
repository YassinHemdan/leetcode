auto init_io = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return 0;
}();

class LRUCache {
private:
    struct Node{
        int key;
        Node* prev;
        Node* next;
        Node() : key(0), prev(nullptr), next(nullptr) {} 
        Node(int key) : key(key), prev(nullptr), next(nullptr) {} 
    };

    class DoublyLinkedList{
    private:
        Node* head;
        Node* tail;
    public:
        DoublyLinkedList() : head(nullptr), tail(nullptr) {}
        // ~DoublyLinkedList(){
        //     Node* temp = head;
        //     if(head){
        //         head = head->next;
        //         head->prev = nullptr;
        //         temp->next = nullptr;
        //         delete temp;
        //         temp = head;
        //     }
        // }
        Node* insertFront(int key){
            Node* node = new Node(key);
            if(head == nullptr)
                head = tail = node;
            else{
                node->next = head;
                head->prev = node;
                head = node;
            }
            return node;
        }
        Node* insertBack(int key){
            Node* node = new Node(key);
            if(head == nullptr)
                head = tail = node;
            else{
                node->prev = tail;
                tail->next = node;
                tail = node;
            }
            return node;
        }
        int deleteFront(){
            Node* toDelete = head;
            head = head->next;

            if(head)
                head->prev = nullptr;

            toDelete->next = nullptr;
            int key = toDelete->key;
            
            delete toDelete;

            return key;
        }
        int deleteBack(){
            Node* toDelete = tail;
            tail = tail->prev;

            if(tail)
                tail->next = nullptr;

            toDelete->prev = nullptr;
            int key = toDelete->key;
            
            delete toDelete;

            return key;
        }
        void moveToBack(Node* node){
            if(node == tail)
                return;
            
            if(node == head){
                head = head->next;
                node->next = nullptr;
                head->prev = nullptr;  
            }
            else{
                node->prev->next = node->next;
                node->next->prev = node->prev;
                node->next = node->prev = nullptr;
            }

            tail->next = node;
            node->prev = tail;
            tail = node;
        }
    };

    unordered_map<int, int> keyValue;
    unordered_map<int, Node*> keyPointer;
    DoublyLinkedList* dll;
    int capacity;

    bool isKeyExist(int key){
        return (keyValue.find(key) != keyValue.end());
    }

    void updateExistedKey(int key){
        Node* toMove = keyPointer[key];
        dll->moveToBack(toMove);
    }

    void updateNewKey(int key){
        Node* newNode = dll->insertBack(key);
        keyPointer[key] = newNode;

        if(capacity <= 0){
            int keyToDelete = dll->deleteFront();
            keyValue.erase(keyToDelete);
            keyPointer.erase(keyToDelete);
        }
        else
            capacity--;
    }
public:
    LRUCache(int capacity) : dll(new DoublyLinkedList()), capacity(capacity) {}
    ~LRUCache(){
        if(dll)
            delete dll;
        dll = nullptr;
    }
    
    int get(int key) {
        if(!isKeyExist(key))
            return -1;
        
        int value =  keyValue[key];

        updateExistedKey(key);

        return value;
    }
    
    void put(int key, int value) {
        bool existed = isKeyExist(key);
        keyValue[key] = value;
        if(existed)
            updateExistedKey(key);
        else
            updateNewKey(key);
    }
};
