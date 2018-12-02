#include"Queue.h"
#include"GameLoop.h"
#include"GameObject.h"
#include<iostream>

using namespace std;

Queue::Queue()
{
    collision_check = false;
    head = NULL;
    tail = NULL;
}

Queue::~Queue()
{
    while(head != NULL)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void Queue::Enqueue(GameObject* obj)
{
    if(head == NULL)
    {
        head = new Node;
        head->G_obj = obj;
        head->next = NULL;
        head->prev = NULL;
        tail = head;
    }
    else
    {
        tail->next = new Node;
        tail->next->G_obj = obj;
        tail->next->next = NULL;
        tail->next->prev = tail;
        tail = tail->next;
    }
    m_size ++ ;
}

void Queue::Dequeue()
{
    Node* temp = head;
    while(temp!=NULL)
    {
        if(temp->G_obj->is_present() == false)
        {
            if(temp->prev == NULL)
            {
                head=head->next;
                if(head!=NULL)
                {
                    head->prev = NULL;
                }
                delete temp;
                temp = head;
            }
            else if(temp ->next == NULL)
            {
                tail = tail->prev;
                tail->next = NULL;
                delete temp;
                break;
            }
            else
            {
                Node* carry = temp->next;
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                delete temp;
                temp = carry;
            }
        }
        temp = temp->next;
    }
}

int Queue::GetSize()
{
    return m_size ;
}

void Queue::Clean()
{
    Node* temp = head;
    while(temp!=NULL)
    {
        if(temp->G_obj->is_present() == false)
        {
            if(temp->prev == NULL)
            {
                head=head->next;
                if(head!=NULL)
                {
                    head->prev = NULL;
                }
                delete temp;
                temp = head;
            }
            else if(temp ->next == NULL)
            {
                tail = tail->prev;
                tail->next = NULL;
                delete temp;
                break;
            }
            else
            {
                Node* carry = temp->next;
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                delete temp;
                temp = carry;
            }
        }
        temp = temp->next;
    }
}

void Queue::Render()
{
    Node* temp = head;
    while(temp!=NULL)
    {
        temp->G_obj->Render();
        temp=temp->next;
    }
}


void Queue::CollisionManager()
{
    Node* temp = head;
    GameObject* player = head->G_obj;

    while(temp!=NULL)
    {
        int t = temp->G_obj->GetType() ;
        switch(t)
        {
        case 1:
            //std::cout << "TimeBoost!" << std::endl ;
            if (collision_check == false)
            {
                if (GameLoop::CheckCollision(player->GetDestRect(),temp->G_obj->GetDestRect()))
                {
                    std::cout << "TimeBoost hit." << std::endl ;
                    std::cout << "Time before PowerUp: " <<GameLoop::timer.get_ticks() << std::endl  ;
                    temp->G_obj->PowerUp();
                    temp->G_obj->~GameObject() ;
                    collision_check = true;
                    std::cout << "Time after PowerUp: " << GameLoop::timer.get_ticks() << std::endl ;
                }
            }
            break ;
        case 2:
            if (collision_check == false)
            {
                if (GameLoop::CheckCollision(player->GetDestRect(),temp->G_obj->GetDestRect()))
                {
                    std::cout << "FuelBoost hit." << std::endl ;
                    temp->G_obj->PowerUp();
                    temp->G_obj->~GameObject() ;
                    collision_check = true;
                }
            }
            break ;

        case 3:
            if (collision_check == false)
            {
                if (GameLoop::CheckCollision(player->GetDestRect(),temp->G_obj->GetDestRect()))
                {
                    std::cout << "SpeedBoost hit." << std::endl ;
                    temp->G_obj->PowerUp();
                    temp->G_obj->~GameObject() ;
                    collision_check = true;
                }
            }
            break;
        case 4:
            if (collision_check == false)
            {
                if (GameLoop::CheckCollision(player->GetDestRect(),temp->G_obj->GetDestRect()))
                {
                    std::cout << "Time before RoadBlock hit: "  <<GameLoop::timer.get_ticks() << std::endl  ;
                    GameLoop::timer.set_ticks(GameLoop::timer.get_ticks() - 5) ;
                    collision_check = true;
                    std::cout << "Time after PowerUp: " << GameLoop::timer.get_ticks() << std::endl ;
                }
            }
            break;
        case 5:
            if (collision_check == false)
            {
                if (GameLoop::CheckCollision(player->GetDestRect(),temp->G_obj->GetDestRect()))
                {
                    std::cout << "Time before RoadBlock hit: "  <<GameLoop::timer.get_ticks() << std::endl  ;
                    GameLoop::timer.set_ticks(GameLoop::timer.get_ticks() - 3) ;
                    collision_check = true;
                    std::cout << "Time after PowerUp: " << GameLoop::timer.get_ticks() << std::endl ;
                }
            }
            break ;
       // case 5:

         //   break ;

        default:
            collision_check = false;
            break;
        }


         temp = temp->next;

        }
    }





