//
// Created by lwj on 5/7/22.
//
#include <iostream>
#include <unordered_map>

class Node {
public:
    int key;
    int value;
    Node* prev;
    Node* next;
    Node() : key(0), value(0), prev(nullptr), next(nullptr) {}
    Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
};

// double linklist
class DoubleList {
public:
    DoubleList() {
        size = 0;
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
    }
    // 在链表尾部添加节点，时间o(1)
    void AddLast(Node* node) {
        node->prev = tail->prev;
        node->next = tail;
        tail->prev->next = node;
        tail->prev = node;
        size++;
    }
    // 删除链表中的节点，时间o(1)
    void DeleteNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        size--;
//        delete node;
    }
    // 删除链表中第一个节点
    Node* DeleteFirst() {
        if (head->next == tail) {
            return nullptr;
        }
        Node* first = head->next;
        DeleteNode(first);
        return first;
    }

    int Size() { return size; }

private:
    Node* head;
    Node* tail;
    int size;
};
class LRUCache {
public:
    LRUCache(int capacity) : capacity_(capacity) {}

    int get(int key) {
        if (!map_.count(key)) {
            return -1;
        }
        MakeRecently(key);
        return map_[key]->value;
    }

    void put(int key, int value) {
        if (map_.count(key)) {
            DeleteKey(key);
            AddRecently(key, value);
            return;
        }

        if (capacity_ == cache_.Size()) {
            RemoveLeastRecently();
        }
        AddRecently(key, value);
    }

private:
    // 将某个key提升
    void MakeRecently(int key) {
        Node* node = map_[key];
        cache_.DeleteNode(node);
        cache_.AddLast(node);
    }

    void AddRecently(int key, int value) {
        Node* node = new Node(key, value);
        cache_.AddLast(node);
        map_[key] = node;
    }

    void DeleteKey(int key) {
        Node* node = map_[key];
        cache_.DeleteNode(node);
        map_.erase(key);
    }

    void RemoveLeastRecently() {
        Node* node = cache_.DeleteFirst();
        int key = node->key;
        map_.erase(key);
    }

private:
    int capacity_;
    DoubleList cache_;
    std::unordered_map<int, Node*> map_;
};

int main() {
    std::cout << "LRUCache" << std::endl;
//    LRUCache lRUCache(2);
//    lRUCache.put(1, 1); // 缓存是 {1=1}
//    lRUCache.put(2, 2); // 缓存是 {1=1, 2=2}
//    lRUCache.get(1);    // 返回 1
//    lRUCache.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
//    lRUCache.get(2);    // 返回 -1 (未找到)
//    lRUCache.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
//    lRUCache.get(1);    // 返回 -1 (未找到)
//    lRUCache.get(3);    // 返回 3
//    lRUCache.get(4);    // 返回 4
    LRUCache lRUCache(2);
    lRUCache.put(2, 1);
    lRUCache.put(1, 1);
    lRUCache.put(2, 3);
    lRUCache.put(4, 1);
    lRUCache.get(1);
    lRUCache.get(2);
    return 0;
}