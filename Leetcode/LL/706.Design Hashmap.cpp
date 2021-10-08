/*706. Design HashMap

Design a HashMap without using any built-in hash table libraries.

Implement the MyHashMap class:

MyHashMap() initializes the object with an empty map.
void put(int key, int value) inserts a (key, value) pair into the HashMap. If the key already exists in the map, update the corresponding value.
int get(int key) returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key.
void remove(key) removes the key and its corresponding value if the map contains the mapping for the key.
 

Example 1:

Input
["MyHashMap", "put", "put", "get", "get", "put", "get", "remove", "get"]
[[], [1, 1], [2, 2], [1], [3], [2, 1], [2], [2], [2]]
Output
[null, null, null, 1, -1, null, 1, null, -1]

Explanation
MyHashMap myHashMap = new MyHashMap();
myHashMap.put(1, 1); // The map is now [[1,1]]
myHashMap.put(2, 2); // The map is now [[1,1], [2,2]]
myHashMap.get(1);    // return 1, The map is now [[1,1], [2,2]]
myHashMap.get(3);    // return -1 (i.e., not found), The map is now [[1,1], [2,2]]
myHashMap.put(2, 1); // The map is now [[1,1], [2,1]] (i.e., update the existing value)
myHashMap.get(2);    // return 1, The map is now [[1,1], [2,1]]
myHashMap.remove(2); // remove the mapping for 2, The map is now [[1,1]]
myHashMap.get(2);    // return -1 (i.e., not found), The map is now [[1,1]]
 

Constraints:

0 <= key, value <= 106
At most 104 calls will be made to put, get, and remove.*/
struct Node{
    int key;
    int value;
    Node* next;
    
    Node(int k, int v, Node* n):key(k),value(v),next(n){}
};
class MyHashMap {
public:
    const static int H_SIZE = 32;
    Node* map[H_SIZE];
    
    MyHashMap() {
        for(int i=0; i<H_SIZE; i++){
            map[i] = NULL;
        }
    }
    /** value will always be non-negative. */
    void put(int key, int value) {
             
        int hsh = hash(key);
        Node* h = map[hsh];
        Node* n = new Node(key, value, NULL);
        if(h==NULL){
            map[hsh] = n;
        }
        else{
            while(h->next != NULL){
                if(h->key == key){
                    h->value = value;
                    return;
                }
                h = h->next;
            }
            if(h->key == key){
                h->value = value;
                return;
            }
            h->next = n;
        }   
    }
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int hsh = hash(key);
        Node* h = map[hsh];
        while(h!=NULL){
            if(h->key == key){
                return h->value;
            }
            h=h->next;
        }
        return -1;
    }
      /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
                int hsh = hash(key);
        Node* h = map[hsh];
        Node* prev = NULL;
        while(h!=NULL){
            if(h->key == key){
                if(prev!=NULL){
                    prev->next = h->next;
                }
                else{
                    map[hsh] = h->next;
                }
                Node* t = h;
                h = h->next;
                delete t;
                return;
            }
            prev = h;
            h = h->next;
        }
    }
      int hash(int index){
        return index & (H_SIZE - 1);
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
