#pragma once
#include "GameObject.h"

struct Node
{
    GameObject* G_obj;
    Node* next;
    Node* prev;

    ~Node()
    {
        delete G_obj;
    }
};
