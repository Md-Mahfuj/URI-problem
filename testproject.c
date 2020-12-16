
#include<stdio.h>
#include<stdlib.h>

#define NULL_VALUE -99999
#define SUCCESS_VALUE 99999


struct listNode
{
    int item ; //will be used to store value
    struct listNode *next ; //will keep address of next node
} ;
struct listNode * list ;
int length;

void initializeList()
{
    list = 0 ; //set to NULL
    length=0;
}

int insertItemBegin(int item)
{
    struct listNode * newNode,*temp;
    newNode = (struct listNode*) malloc (sizeof(struct listNode)) ;
    newNode->item = item ;
    newNode->next = list ;
    list = newNode ;
    length++;
    return SUCCESS_VALUE ;
}







int insertItemLast(int item)
{
    struct listNode *fnNode, *tmp;
    fnNode = (struct listNode*)malloc(sizeof(struct listNode));
    fnNode->item = item;

    if(list == 0)
    {
       fnNode->next = list ;
       list = fnNode ;
    }

    else
    {
            //Links the data part
        fnNode->next = NULL;
        tmp = list;
        while(tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = fnNode;  //Links the address part
    }
     length++;
    return SUCCESS_VALUE;
}

int deletelastItem()
{
    struct listNode *fnNode, *tmp;
    fnNode = (struct listNode*)malloc(sizeof(struct listNode));


    if(list == 0)
    {

    }

    else
    {


        tmp = list;
        while(tmp->next != NULL){
            fnNode=tmp;
             tmp = tmp->next;
        }

         fnNode->next=NULL;
          //Links the address part
    }
     length--;
    return SUCCESS_VALUE;
}


int NumOfItems()
{
    int count = 0;  // Initialize count
    struct listNode* current = list;  // Initialize current
    while (current != 0)
    {
        count++;
        current = current->next;
    }
     printf("Length: %d\n",count);
    return SUCCESS_VALUE;


}



int  deleteFirstItem()
{
    struct listNode *toDelete;

    if(list == 0)
    {
        printf("List is already empty.");
    }
    else
    {
        toDelete = list;
        list = list->next;

        printf("\nData deleted = %d\n", toDelete->item);

        /* Clears the memory occupied by first node*/
        free(toDelete);

        printf("SUCCESSFULLY DELETED FIRST NODE FROM LIST\n");
    }
    return SUCCESS_VALUE;
}

int insertItemAT( int position,int item)
{
    int i;
    struct listNode *newNode, *temp;

     newNode = (struct listNode*) malloc (sizeof(struct listNode)) ;

    if(newNode == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        newNode->item = item; // Link data part
        newNode->next = NULL;

        temp = list;

        /*
         * Traverse to the n-1 position
         */
        for(i=2; i<=position-1; i++)
        {
            temp = temp->next;

            if(temp == NULL)
                break;
        }

        if(temp != NULL)
        {
            /* Link address part of new node */
            newNode->next = temp->next;

            /* Link address part of n-1 node */
            temp->next = newNode;

            printf("DATA INSERTED SUCCESSFULLY\n");
        }
        else
        {
            printf("UNABLE TO INSERT DATA AT THE GIVEN POSITION\n");
        }
    }
}



int deleteALLOccurrence(int item){
  struct  listNode *temp;
  struct  listNode *prev = 0;
  struct  listNode *next;

    for (temp = list;  temp != 0;  temp = next) {
        next = temp->next;

        if (temp->item != item) {
            prev = temp;
            continue;
        }

        if (prev != 0)
            prev->next = next;
        else
            list = next;

        free(temp) ;
    }
}




void PrintALL()
{
    struct listNode *temp;
    temp = list ; //start at the beginning
    while (temp != 0)
    {
        printf("%d ",temp->item);
        temp = temp->next ; //move to next node
    }
    printf("\n");
}


int deleteFirstOccurrence(int item)
{
    struct listNode *temp, *prev ;
    temp = list ; //start at the beginning
    while (temp != 0)
    {
        if (temp->item == item) break ;
        prev = temp;
        temp = temp->next ; //move to next node
    }
    if (temp == 0) return NULL_VALUE ; //item not found to delete
    if (temp == list) //delete first node
    {
        list = list->next ;
        length--;
        free(temp) ;
    }
    else
    {
        prev->next = temp->next ;
        length--;
        free(temp);
    }

    return SUCCESS_VALUE ;
}


int deleteLastOccurrence(int item)
{

   struct listNode *temp = list, *ptr = NULL;
    while (temp) {

        // If found key, update
        if (temp->item == item)
            ptr = temp;
        temp = temp->next;
    }

    // If the last occurrence is the last node
    if (ptr != NULL && ptr->next == NULL) {
        temp = list;
        while (temp->next != ptr)
            temp = temp->next;
        temp->next = NULL;
    }

    // If it is not the last node
    if (ptr != NULL && ptr->next != NULL) {
        ptr->item = ptr->next->item;
        temp = ptr->next;
        ptr->next = ptr->next->next;
        free(temp);
    }
    return SUCCESS_VALUE ;
}












//Assignment
//                 int insertItemLast(int item);// Insert item at the last position of the list
//                 int insertItemAT(int position, int item);// Insert item at the given position of the list
//                  int NumOfItems(int item);// return the number of the occurrence of the given item
//                  int deleteALLOccurrence(int item);// Delete all the occurrence of the given item in the list with preserving order
//int deleteLastOccurrence(int item);// Delete the last occurrence of the given item in the list
//                    int deleteFirstItem(); // delete the first item of the list
//                     int deletelastItem();// delete the last item of the list


int main()
{
    char inp1, chk;
    int inp2,inp3;
    int s;
    initializeList();
    while(1){
        scanf("%c",&inp1);


        switch(inp1)
        {
        case 'I':
            scanf("%d",&inp2);
            s=insertItemBegin(inp2);
            break;
        case 'E':
            scanf("%d",&inp2);
            s=insertItemLast(inp2);
            break;

        case  'D':
            s=deletelastItem();
            break;
         case  'F':
            s=deleteFirstItem();
            break;

        case 'R'://delete the item of first occurrence
            scanf("%d",&inp2);
            scanf("%d",&inp3);
            s=insertItemAT(inp2,inp3);
            break;

        case 'P':
            PrintALL();
            break;
        case 'L':
            s=NumOfItems();

            break;
        case 'O' :
            scanf("%d",&inp2);
            s=deleteALLOccurrence(inp2);

        case  'Z':
            scanf("%d",&inp2);
            s=deleteLastOccurrence(inp2);
        }
        if(s==NULL_VALUE) break;
    }

}
