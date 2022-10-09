#include "eventList.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

EventList *CreateEventList(void)
{
    EventList *eventList = malloc(sizeof(EventList));
    eventList ->isEmpty = 1;
    eventList ->head = NULL;
    eventList ->last = NULL;
    return eventList;

}

void DestroyEventList(EventList *this)
{
    free(this); 
}

Event *SearchEvent(EventList *this, char *name)
{
    Event *phead = this->head;
    
    if(this->isEmpty==0)
    {
        while (phead->next != NULL)
        {
            if(strcmp(name, phead->eventName) == 0)
            {
                printf("%s",phead->eventName);
                this->isEmpty=1;
                break;
            }
            phead = phead->next;
        }
        if(this->isEmpty==0)
        {
            printf("NULL");
        }
        this->head = phead; 
    }
    else
    {
        printf("NULL");
    }
}

void AddEvent(EventList *this, Event *event)
{
    if(this->isEmpty == 1)
    {
        this->isEmpty = 1;
        this->head = event;
        this->last = event; 
    }
    else
    {
        Event *phead = this->head;
        
        while(phead != NULL)
        {
            //printf("nametec: %s\n", event->eventName);
            //printf("namehead: %s\n", this->head->eventName);
            if(strcmp(event->eventName, phead->eventName) == 0)
            {
                return;
            }    
            phead = phead->next;
        }
        // Insertar el evento en la lista

        this->last->next = event;
        this->last = event;  
    }
    
}

void RemoveEvent(EventList *this, char *name)
{
    //printf("nametec: %c\n", *name);
    //printf("namehead: %c\n", *this->head->eventName);

    if (this->isEmpty == 0)
    {       
        if(strcmp(name, this->head->eventName) == 0)
        {
            Event *phead = this->head;
            if(this->head->next == NULL)
            {
                this->head = NULL;
                this->last = NULL;
                this->isEmpty = 1;
                DestroyEvent(this->head);
            }
            else
            {
                this->head = this->head->next;
                DestroyEvent(phead);
            }
            
        }
        else if (strcmp(name, this->last->eventName) == 0)
        {
            Event *phead = this->head;
            //printf("ultev\n");
            while (phead->next != NULL)
            {
                if(phead->next->next == NULL)
                {
                    this->last = phead->next;
                    phead->next = NULL;
                    break;
                }
                phead = phead->next;
            }
            DestroyEvent(this->last);
        }
        else 
        {
            Event *phead = this->head;
            Event  *pn = this->head;
            this->isEmpty=0;
            //printf("entra\n");
            while (phead->next != NULL)
            {
                if(strcmp(name, phead->next->eventName) == 0)
                {
                    pn = phead->next;
                    phead->next = phead->next->next;
                  this->isEmpty= 0;
                    break;
                }
                phead = phead->next;
            }
            if (this->isEmpty== 1)
            {
                DestroyEvent(pn);
            }         
        }        
    }
}

void ListEvents(EventList *this)
{
    Event *phead = this->head;

    if(this->isEmpty == 1)
    {
        printf("empty\n");
    }
    else 
    {
        printf("%s\n",this->head->eventName);
        while (phead->next != NULL)
        {
            phead = phead->next;
            printf("%s\n",phead->eventName); 
        }
    }
}