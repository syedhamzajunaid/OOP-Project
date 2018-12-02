#pragma once
#include"Node.h"
#include "Timer.h"
#include "PlayerVan.h"

class Queue
{
private:
    Node* head;
    Node* tail;
    int m_size ;
    bool collision_check ;
public:
    Queue();
    ~Queue();
    void CollisionManager();
    void Enqueue(GameObject* obj);
    void Dequeue();
    int GetSize();
    void Clean();
    void Render();
    Node* GetHead() ;
    Node* GetTail() ;
};
