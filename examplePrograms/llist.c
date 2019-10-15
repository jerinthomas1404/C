#include<stdio.h>
#include<stdlib.h>
struct node{
    int item;
    struct node *next;
    
}*head=NULL;
// typedef struct node list;
void deletion(struct node **,int );
struct node * predecessor_list(struct node *l, int x){
    if((l==NULL)||(l->next == NULL)){
        printf("Either first element or Not found");
        return NULL;
    }
    if(l->next->item == x){ return l;}
    else
        return(predecessor_list(l->next,x));
}


void disp(struct node *head){
    struct node *temp = head;
    if(temp!= NULL)
    {printf("\n%d",temp->item);
    disp(temp->next);
    }  
}
struct node * search(struct node *,int );

void insert_beg(struct node **head,int item){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->item = item;
    temp->next = *head;
    *head = temp;
}
int main(int argc , char **argv[]){

insert_beg(&head,30);
insert_beg(&head,50);
insert_beg(&head,80);insert_beg(&head,90);insert_beg(&head,100);
struct node *ptr = search(head,80);
if(ptr != NULL){printf("Print %d",ptr->item);}
printf("****Calling display function****");

disp(head);
deletion(&head,30);
disp(head);

    return 1;
}//Nothing wrong

struct node * search(struct node * l,int item){
    if(l == NULL ){return NULL;}
    if(l->item == item){return l;}
    else{ search(l->next,item);}
}

void  deletion(struct node **head , int x){
    struct node *temp;
    struct node *pred;
    
    struct node *search();
    temp = search(*head,x);
    
    if(temp!=NULL){
        pred = predecessor_list(*head,x);
        if(pred == NULL){
            *head = temp->next;
        }
        else{
            pred->next = temp->next;
        }
        free(temp);
    }
    

}