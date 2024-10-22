class LFUCache {
private:
    struct Node {
        int key;
        Node* prev;
        Node* next;

        Node() : key(-1), prev(nullptr), next(nullptr) {} 
        Node(int key) : key(key), prev(nullptr), next(nullptr) {}
    };
    class DoublyLinkedList{
    private:
        Node* head;
        Node* tail;
        
        void link(Node* node1, Node* node2){
            node1->next = node2;
            node2->prev = node1;
        }
    public:
        DoublyLinkedList() : head(nullptr), tail(nullptr) {}
        ~DoublyLinkedList(){
            Node* temp = head;
            if(head){
                head = head->next;
                temp->next = nullptr;
                delete temp;

                temp = head;
            }
        }
        Node* insertFront(int key){
            Node* node = new Node(key);
            if(head == nullptr)
                head = tail = node;
            else
                link(node, head), head = node;
            return node;
        }
         Node* insertBack(int key){
            Node* node = new Node(key);
            if(head == nullptr)
                head = tail = node;
            else
                link(tail, node), tail = node;
            return node;
        }
        void insertBack(Node* node){
            if(head == nullptr)
                head = tail = node;
            else
                link(tail, node),tail = node;
        }
        int deleteFront(){
            if(head == nullptr)
                return -1;
            Node* toDelete = head;
            int key = toDelete->key;

            head = head->next;
            if(head)
                head->prev = nullptr;
            
            toDelete->next = nullptr;
            delete toDelete;

            return key;
        }
        int deleteBack(){
            if(head == nullptr)
                return -1;
            
            Node* toDelete = tail;
            int key = toDelete->key;

            tail = tail->prev;
            if(tail)
                tail->next = nullptr;

            toDelete->prev = nullptr;
            delete toDelete;

            return key;
        }
        void removeNode(Node* node){
            if(node == head){
                head = head->next;
                if(head)
                    head->prev = nullptr;
                
                node->next = nullptr;
            }
            else if(node == tail){
                tail = tail->prev;
                if(tail)
                    tail->next = nullptr;
                
                node->prev = nullptr;
            }
            else{
                link(node->prev, node->next);
                node->prev = node->next = nullptr;
            }
        }
        bool isEmpty(){
            return head == nullptr;
        }
    };

    int capacity;
    int minimumFreq;
    int maximumFreq;
    unordered_map<int, int> keyValue;
    unordered_map<int, Node*> keyPointer;
    unordered_map<int, int> keyFreq;
    unordered_map<int, DoublyLinkedList> freqKeys;

    bool isKeyExist(int key){
        return keyValue.find(key) != keyValue.end();
    }
    
    void removeLFU(){
        int keyToRemove = freqKeys[minimumFreq].deleteFront();
        keyValue.erase(keyToRemove);
        keyPointer.erase(keyToRemove);
        keyFreq.erase(keyToRemove);

        if(freqKeys[minimumFreq].isEmpty())
            freqKeys.erase(minimumFreq);
    }
    void updateExistedKey(int key){
        int keyFrequency = keyFreq[key];
        int newKeyFrequency = keyFrequency + 1;
        Node* keyNode = keyPointer[key];

        // move from old freq to new freq
        freqKeys[keyFrequency].removeNode(keyNode);
        freqKeys[newKeyFrequency].insertBack(keyNode);

        // update the new min and max freq
        if(freqKeys[keyFrequency].isEmpty()){
            freqKeys.erase(keyFrequency);
            if(minimumFreq == keyFrequency)
                minimumFreq++;
        }
        maximumFreq = max(maximumFreq, newKeyFrequency);

        // update the new key freq
        keyFreq[key] = newKeyFrequency;
    }
    void updateNewKey(int key){
        if(capacity <= 0)
            removeLFU();
        --capacity;
        minimumFreq = 1;
        keyFreq[key] = 1;
        Node* newNode = freqKeys[1].insertBack(key);
        keyPointer[key] = newNode;
        maximumFreq = max(maximumFreq, minimumFreq);
    }
public:
    LFUCache(int capacity) : capacity(capacity), minimumFreq(0), maximumFreq(0){}
    
    int get(int key) {
        if(!isKeyExist(key))
            return -1;
        
        int value = keyValue[key];

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
