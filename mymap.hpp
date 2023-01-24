#include <iostream>

//this is my map
template<class T1, class T2>
struct Node {
    T1 key;
    T2 value;
    Node *prev = nullptr;
    Node *next = nullptr;
};

template<class T1, class T2>
class MyMapIterator{
    public:
        explicit MyMapIterator(Node<T1, T2>* node): current(node) {}
        bool operator !=(const MyMapIterator &rhs) const;
    private:
        Node<T1, T2>* current;
};

template<class T1, class T2>
class MyMap{
    private:
        Node<T1, T2> *start = nullptr;
        Node<T1, T2> *end = nullptr;
    public:
        Node<T1, T2>* find(const T1 &key);
        bool insert(Node<T1, T2> *new_node);
        bool emplace(T1 &key, T2 &value);
        bool erase(const T1 &key);
        MyMapIterator<T1, T2> begin();
        MyMapIterator<T1, T2> myend();
        ~MyMap();
};

template<class T1, class T2>
MyMapIterator<T1, T2> MyMap<T1, T2>::begin(){
    return MyMapIterator<T1, T2>(start);
}

template<class T1, class T2>
MyMapIterator<T1, T2> MyMap<T1, T2>::myend(){
    return MyMapIterator<T1, T2>(nullptr);
}

template<class T1, class T2>
Node<T1, T2>* MyMap<T1, T2>::find(const T1 &key){
    Node<T1, T2> *cur = start;
    for (cur; cur->next != nullptr; cur = cur->next){
        if (cur->key == key){
             return cur;
        }
    }
    return nullptr;
}

template <class T1, class T2>
inline bool MyMap<T1, T2>::emplace(T1 &key, T2 &value)
{
    return false;
}

template<class T1, class T2>
bool MyMap<T1, T2>::insert(Node<T1, T2> *new_node){
    if (start == nullptr){
        start = new_node;
    }
    else{
        end->next = new_node;
    }
    end = new_node;
    return true;
}

template<class T1, class T2>
bool MyMap<T1, T2>::erase(const T1 &key){
    Node<T1, T2> *res = find(key);
    if (res == nullptr){
        return false;
    }
    if (res->prev != nullptr){
        if (res->next != nullptr){
            res->next->prev = res->prev;
            res->prev->next = res->next;
            res->next = nullptr;
            res->prev = nullptr;
        }
        else{
            end = res->prev;
            res->prev->next = nullptr;
            res->prev = nullptr;
        }
    }
    start = res->next;
    res->next->prev = nullptr;
    res->next = nullptr;
    delete res;
    return true;
}

template<class T1, class T2>
MyMap<T1, T2>::~MyMap(){
    if (start != nullptr){
        while (start -> next != nullptr){
            Node<T1, T2> *cur = start;
            start = start->next;
            cur->next->prev = nullptr;
            cur->next = nullptr;
            delete cur;
        }
        end = nullptr;
        delete start;
        start = nullptr;
    }
}
