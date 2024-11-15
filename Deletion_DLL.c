#include<stdio.h>
#include<stdlib.h>
struct dlist{
    int info;
    struct dlist *next,*prev;
};
typedef struct dlist node;
void create(node **,node **);
void display(node *,node *);
int del(node **,node **,int );
main()
{
    node *s = NULL  ,*l = NULL;
    int n,r;
    create(&s,&l);
    printf("DLL Created.\n");
    display(s,l);
    printf("Enter the no. to be deleted:");
    scanf("%d",&n);
    r = del(&s,&l,n);
    if (r == 1){
        printf("Node Deleted.\n");
        display(s,l);
    }
    else{
        printf("Node cannot be deleted.");
    }
}

int del(node **s ,node **l,int n)
{
    node *t,*pr;
    if(*s != NULL){
        if((*s)->info == n){
            if((*s)->next == NULL){
                *s = *l = NULL;
            }
            else{
                *s = (*s)->next;
                (*s)->prev = NULL;

            }
            return (0);
        }
        else{
            pr = NULL;
            t = *s;
            while(t != NULL && t->info!=n){
                pr= t;
                t = t->next;
            }
            if(t == NULL){
                return (0);
            }
            else{
                if(t->next == NULL){
                    *l = pr;
                }
                else{
                    t -> next->prev = pr;
                }
                pr->next = t->next;
                free(t);
                return(1);
            }
        }


    }
    else{
        return 0;
    }
}
void create(node **s,node **l)
{
    node *nn;
    int num;
    char ano = 'y';
    while(ano == 'y')
    {
        printf("Enter the number:");
        scanf("%d",&num);                               //Do not use %d\n in create for preventing the input error while 'continue' execution.Newline Error
        nn = (node *)malloc(sizeof(node));
        nn -> info = num;
        nn -> next = NULL;
        if (*s == NULL){
            nn->prev=NULL;
            *s = nn;
        }
        else{
            (*l)->next = nn;
            nn->prev=*l;
        }
        *l = nn;
        printf("Continue[y/n]?");
        fflush(stdin);
        scanf(" %c",&ano);
    }
}
void display(node *s,node *l)
{
    node *temp = s;                                 //temp should be initialized by s and l for printing the elements.
    printf("Forward Printing:\n ");
    while(temp!=NULL){
        printf("%d ",temp->info);
        temp = temp ->next;
    }
    printf("\n");
    temp = l;
    printf("Backward Printing:\n");
    while(temp!=NULL){
        printf("%d ",temp->info);
        temp = temp->prev;
    }
    printf("\n");
}
