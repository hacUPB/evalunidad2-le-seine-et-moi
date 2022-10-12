#include "eventList.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

EventList *CreateEventList(void)  
{
    EventList *eventList = malloc(sizeof(EventList));
    eventList->isEmpty = 0;
    eventList->head = NULL;
    eventList->last = NULL;
    
    return eventList;
}

void AddEvent(EventList *this, Event *event)
{
    Event *actualEvent = this->head;
   
    
   if(this->head == NULL)
   {
     this->head = event;
     this->last = event;
     this->isEmpty = 1;   
      
   }
   else
   {
    while (actualEvent != NULL)
     
    {
        if(strcmp(event->eventName, actualEvent->eventName) == 0)
        return;

        actualEvent = actualEvent->next;
    }
       this->last->next = event;
       this->last=event;
   }
}

Event *SearchEvent(EventList *this, char *name)
{
    Event *actualEvent = this->head;
    if (this->isEmpty == 1)
    {
        while (actualEvent != NULL)
        {
            if (strcmp(name, actualEvent->eventName)==0)
            return actualEvent;
            actualEvent = actualEvent->next;
        }
    }
    actualEvent = NULL;
    return actualEvent;
}



void DestroyEventList(EventList *this)
{
    free(this);
}

void RemoveEvent(EventList *this, char *name)
{
    if (this->isEmpty == 1)
    {
       Event *actualEvent = this->head->next;  
       Event *lastEvent = this->head;
       if(strcmp(name, lastEvent->eventName)==0)
       {
            if(lastEvent->next == NULL)
            {
                this->head = NULL;
                this->last = NULL;
                this->isEmpty = 0;
                DestroyEvent(lastEvent);
            }
            else
            {
                this->head=actualEvent;
                DestroyEvent(lastEvent);
            }
       }
       while (actualEvent != NULL)
       {
            if(strcmp(name, actualEvent->eventName)==0)
            {
                lastEvent->next = actualEvent->next;
                if (this->last->next == NULL)
                {
                    this->last = lastEvent;
                    DestroyEvent(actualEvent);
                }
            }
            lastEvent = actualEvent;
            actualEvent = actualEvent->next;
       }
    }
}

void ListEvents(EventList *this)
{
    if (this->isEmpty == 1)
    {
        Event *actualEvent = this->head;


        while (actualEvent != NULL)
        {
            printf("%s\n", actualEvent->eventName);
            actualEvent = actualEvent->next;
        }       
    }
    else
    {
        printf("empty\n");
    }

}

