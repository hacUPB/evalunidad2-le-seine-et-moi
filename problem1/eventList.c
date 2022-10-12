#include "eventList.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

EventList *CreateEventList(void)
{

    EventList *elptr;
    elptr = (EventList *)malloc(sizeof(EventList));
    elptr ->head = NULL;
    elptr ->last = NULL;
    elptr ->isEmpty = 0;
    if(!elptr)
        perror("None memory space reserve");
    return elptr;
}

void DestroyEventList(EventList *this)
{
free(this);
}

Event *SearchEvent(EventList *this, char *name)
{
    Event *event = this->head;

    if(this->isEmpty != 0){
        while(event != NULL){
            if(strcmp(name, event->eventName) == 0){
                return event;
            }else{
                event = event->next;
            }
        }
    }else{
        return NULL;
    }
}

void AddEvent(EventList *this, Event *event)
{
    Event *aux = this->last;
    Event *eventT = SearchEvent(this, event->eventName);
    if(this->isEmpty == 0){
            this->head = event;
            this->last = event;
            this->isEmpty = 1;
        }else{
            if(eventT == NULL){
                aux->next = event;
                this->last = event;
            }else{
                eventT = NULL;
            }
        }
}

void RemoveEvent(EventList *this, char *name)
{
    Event *event = this->head;
    char flag = 0;
    Event *nEvent = SearchEvent(this, name);

    if(this->isEmpty != 0){
        if(nEvent != NULL){
            do{
                if(nEvent == this->head){
                    this->head = nEvent->next;
                    DestroyEvent(nEvent);
                    flag = 1;
                        
                }else {/*
                    if(nEvent->next == event){
                        nEvent->next = event->next;
                    }else{
                        nEvent = nEvent->next;
                    }    */

                    while(event->next != nEvent){
                        event = event->next;
                    }

                    if(nEvent == this->last){
                        event->next = nEvent->next;
                        DestroyEvent(nEvent);
                        this->last = event;
                        flag = 1;
                    }else{
                        event->next = nEvent->next;
                        DestroyEvent(nEvent);
                        flag = 1;
                    }
                }
            }while(flag != 1);
        }
        
    }

}

void ListEvents(EventList *this)
{
    Event *aux = this->head;

    if(this->isEmpty == 0){
        printf("empty\n");
    }else{
        do{
            printf("%s\n", aux->eventName);
            aux = aux->next;
        }
        while(aux != NULL);
        
    }
}
