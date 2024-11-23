/*Question 6.7 (ADM)
Design and implement an efficient data structure to maintain a least recently
used (LRU) cache of n integer elements. A LRU cache will discard the least
recently accessed element once the cache has reached its capacity, supporting
the following operations:

• get(k)– Return the value associated with the key k if it currently exists in
the cache, otherwise return -1.

• put(k,v) – Set the value associated with key k to v, or insert if k is not
already present. If there are already n items in the queue, delete the least
recently used item before inserting (k, v).

Both operations should be done in O(1) expected time.
*/

#include <iostream>
#include <unordered_map>
using namespace std;

// Node for doubly LL
struct Node
{
    int key, value;
    Node *prev;
    Node *next;

    Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {};
};

// LRU Cache Class
class LRUCache
{
private:
    unordered_map<int, Node *> cache;
    Node *head;
    Node *tail;
    int capacity;
    int size;

    void addNode(Node *node)
    {
        node->next = head;
        node->prev = nullptr;

        if (head != nullptr)
        {
            head->prev = node;
        }
        head = node;

        if (tail = nullptr)
        {
            tail = node;
        }
    }

    void removeNode(Node *node)
    {
        if (node->prev != nullptr)
        {
            node->prev->next = node->next;
        }
        else
        {
            head = node->next;
        }

        if (node->next != nullptr)
        {
            node->next->prev = node->prev;
        }
        else
        {
            tail = node->prev;
        }
    }

    void moveToHead(Node *node)
    {
        removeNode(node);
        addNode(node);
    }

    Node *removeTail()
    {
        Node *temp = tail;
        removeNode(tail);
        return temp;
    }

public:
    LRUCache(int cap) : capacity(cap), size(0), head(nullptr), tail(nullptr) {}

    int get(int key)
    {
        if (cache.find(key) == cache.end())
        {
            return -1;
        }

        Node *node = cache[key];
        moveToHead(node);
        return node->value;
    }

    void put(int key, int value)
    {
        if (cache.find(key) != cache.end())
        {
            Node *node = cache[key];
            node->value = value;
            moveToHead(node);
        }
        else
        {
            Node *newNode = new Node(key, value);

            if (size < capacity)
            {
                addNode(newNode);
                cache[key] = newNode;
                size++;
            }
            else
            {
                Node *tailNode = removeTail();
                cache.erase(tailNode->key);
                delete tailNode;

                addNode(newNode);
                cache[key] = newNode;
            }
        }
    }

    ~LRUCache()
    {
        Node *curr = head;
        while (curr != nullptr)
        {
            Node *temp = curr;
            curr = curr->next;
            delete temp;
        }
    }
};

int main()
{
    LRUCache cache(3);
    cache.put(1, 10);
    cache.put(2, 20);
    cache.put(3, 30);
    cout << "Get 1: " << cache.get(1) << endl; // Outputs 10

    cache.put(4, 40);                          // Evicts key 2 (least recently used)
    cout << "Get 2: " << cache.get(2) << endl; // Outputs -1 (not found)

    cache.put(5, 50);                          // Evicts key 3
    cout << "Get 3: " << cache.get(3) << endl; // Outputs -1 (not found)
    cout << "Get 4: " << cache.get(4) << endl; // Outputs 40
    cout << "Get 5: " << cache.get(5) << endl; // Outputs 50

    return 0;
}