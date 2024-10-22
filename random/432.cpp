class AllOne {
private:
	struct Node{
		int val;
		Node* prev;
		Node* next;
		Node(int val){
			this->val = val;
			prev = next = nullptr;
		}
	};
	class DoublyLinkedList{
	private:
		Node* head;
		Node* tail;
	public:
		DoublyLinkedList() : head(nullptr), tail(nullptr){}
		~DoublyLinkedList(){
            Node* temp = head;
            while(head && head->next){
                head = head->next;
                delete temp;
                temp = head;
                head->prev = nullptr;
            }
            delete head;
            head = tail = nullptr;
		}

        int getHead(){
            return head->val;
        }
        int getTail(){
            return tail->val;
        }
        Node* getHeadNode(){
            return head;
        }
        Node* getTailNode(){
            return tail;
        }
		void insertFront(Node* node){
			if(head == nullptr)
				head = tail = node;
			else{
				node->next = head;
				head->prev = node;
				head = node;
			}
		}
		void insertBack(Node* node){
			if(head == nullptr)
				head = tail = node;
			else{
				tail->next = node;
				node->prev = tail;
				tail = node;
			}
		}
		void insertBetween(Node* node, Node* prev, Node* next){
			node->next = next;
			node->prev = prev;
			prev->next = node;
			next->prev = node;
		}
		void deleteFront(){
			Node* temp = head;
			head = head->next;
			temp->next = temp->prev = nullptr;
            if(head)
                head->prev = nullptr;

			delete temp;
		}
		void deleteBack(){
			Node* temp = tail;
			tail = tail->prev;
			temp->next = temp->prev = nullptr;
            tail->next = nullptr;
            if(tail)
                tail->next = nullptr;
            delete temp;
		}
		void deleteInBetween(Node* node){
			node->prev->next = node->next;
			node->next->prev = node->prev;
			node->next = node->prev = nullptr;

			delete node;
		}
		bool isEmpty(){
			return head == nullptr || tail == nullptr;
		}
		int getMax(){
			if(isEmpty())
				return -1;
			return tail->val;
		}
		int getMin(){
			if(isEmpty())
				return -1;
			return head->val;
		}
	};

	DoublyLinkedList* dll;
	unordered_map<string, int> stringFreqMap; // the current frequency for every key
	unordered_map<int, unordered_set<string>> freqStringsMap; // the strings with the same frequency
	unordered_map<int, Node*> freqPointerMap; // the address for every frequency node in the DLL

	void addString(const string& str, int freq){
		freqStringsMap[freq].insert(str); // insert string to the new freq
        if(freq > 1)
            freqStringsMap[freq - 1].erase(str); // remove the string from the previous freq

        if((int)freqStringsMap[freq].size() == 1){ // freq wasn't existed, add it
            Node* node = new Node(freq);
            if(dll->isEmpty() || dll->getMin() > freq)
                dll->insertFront(node);
            else if(dll->getMax() < freq)
                dll->insertBack(node);
            else{
                Node* prev = freqPointerMap[freq - 1];
                Node* next = prev->next;
                dll->insertBetween(node, prev, next);
            }
            freqPointerMap[freq] = node;
        }

        if(freq > 1 && freqStringsMap[freq - 1].empty()){ // if the prev freq is empty, remove it
            Node* nodeToRemove = freqPointerMap[freq - 1];
            freqPointerMap.erase(freq - 1);

            if(nodeToRemove->val == dll->getMin())
                dll->deleteFront();
            else if(nodeToRemove->val == dll->getMax())
                dll->deleteBack();
            else
                dll->deleteInBetween(nodeToRemove);
        }
	}
    void deleteString(const string& str, int freq){
        freqStringsMap[freq + 1].erase(str);
        if(freq > 0){
            freqStringsMap[freq].insert(str);
            if(freqStringsMap[freq].size() == 1){
                Node* node = new Node(freq);
                if(dll->isEmpty() || dll->getMin() > freq)
                    dll->insertFront(node);
                else if(dll->getMax() < freq)
                    dll->insertBack(node);
                else{
                    Node* next = freqPointerMap[freq + 1];
                    Node* prev = next->prev;
                    dll->insertBetween(node, prev, next);
                }
                freqPointerMap[freq] = node;
            }
        }
        if(freqStringsMap[freq + 1].empty()){
            Node* nodeToRemove = freqPointerMap[freq + 1];
            if(dll->getMin() == nodeToRemove->val)
                dll->deleteFront();
            else if(dll->getMax() == nodeToRemove->val)
                dll->deleteBack();
            else
                dll->deleteInBetween(nodeToRemove);
            freqPointerMap.erase(freq + 1);
        }
    }
public:
    AllOne() {
        dll = new DoublyLinkedList();
    }
    ~AllOne(){
    	delete dll;
    	freqPointerMap.clear();
    }
    void inc(const string& key) {
    	int &freq = stringFreqMap[key];
    	++freq;

    	addString(key, freq);
    }

    void dec(string key) {
        int &freq = stringFreqMap[key];
        --freq;

        deleteString(key, freq);
    }

    string getMaxKey() {
        if(dll->isEmpty())
            return "";
        return *freqStringsMap[dll->getMax()].begin();
    }

    string getMinKey() {
        if(dll->isEmpty())
            return "";
        
        return *freqStringsMap[dll->getMin()].begin();
    }
};
