#include <stdio.h>
#include "phone.h"

void show_item(PHONE *head)
{
    printf("\033[0;33m\t姓名: %s\033[0m\n",head->next->name);
    printf("\033[0;33m\t电话号码: %s\033[0m\n",head->next->phone_number);
    printf("\033[0;33m\t家庭地址: %s\033[0m\n",head->next->home_address);
    printf("\033[0;33m\t公司电话: %s\033[0m\n",head->next->company_number);
}

int init(PHONE **head)
{
    PHONE *newnode = (PHONE *)malloc(sizeof(PHONE));
    if(NULL == newnode)
    {
        return -1;
    }
    newnode->next = NULL;
    *head = newnode;
    return 0;
}

int create(PHONE *head)
{
    PHONE *p;
    p = head;
    PHONE *newstudent - (PHONE *)malloc(sizeof(PHONE));
    if(NULL == newstudent)
    {
        return -1;
    }
    printf("\33[0;34m请输入信息\33[0m\n");
    srand((unsigned)time(NULL));
    newstudent->id = rand()%100;  //cread one rand number
    printf("%d\n",newstudent->id);
    printf("\33[0;34m名字\33[0m\n");
    printf("name　:\n");
    scanf("%s",newstudent->name);
    printf("\33[0;34m电话号码\33[0m\n");
    scanf("%s",newstudent->phone_number);
    printf("\33[0;34m家庭住址\33[0m\n");
    scanf("%s",newstudent->home_address);
    printf("\33[0;34m公司号码\33[0m\n");
    scanf("%s",newstudent->company_number);

    newstudent->next = NULL;
    while(head->next != NULL)
    {
        head = head->next;
    }
    head->next =newstudent;
    newstudent->next = NULL;
    printf("\33[0;32m create! \33[0m\n");
    getchar();
    getchar();

    head = p;

    return 0;
}

int delete(PHONE *head)
{
    PHONE *p;
    p = head;

    char name[20];
    int count = 0;
    printf("please input your want delete one name:\n");
    scanf("%s",name);

    while(head->next != NULL)
    {
        if(strcmp(head->next->name,name) == 0)
        {
            count++;
            PHONE *ptr = head->next;
            head->next = ptr->next;
            free(ptr);
        }
    }
    if(count == 0){
        printf("NO this one name!\n");
        return -1;
    }
    else{
        printf("\33[0;32m delete is ok!\33[0m\n");
    }

    head = p;
    printf("\n");
    return 0;
}

int display(PHONE *head)
{
    PHONE *p;
    p = head;
    int num = 0;
    if(head == NULL)
    {
        printf("\33[0;31m No this people! \33[0m\n");
        return -1;
    }
    while(head->next != NULL)
    {
        printf("\033[[0;33m+---------------[%d]-------------------+\033[0m\n",num++);
        show_item(head);
        head = head->next;
    }
    printf("\033[0;33m++-----------------end------------------+\033[0m\n");
    getchar();

    getchar();

    head = p;  //return head node
}

int search(PHONE *head)
{
    PHONE *p;
    p = head;
    int count = 0;
    char name[30];
    printf("please input you want search name:\n");
    scanf("%s",name);
    while(head->next != NULL)
    {
        if(strcmp(head->next->name,name) == 0)
        {
            count++;
            show_item(head);
        }
        head = head->next;
    }
    if(count == 0)
    {
        printf("No search this people!\n");
        printf("Search error!\n");
    }
    printf("\n");
    head = p;
}

PHONE *allfree(PHONE *head)
{
    while(head->next != NULL)
    {
        PHONE *ptr = head;
        head = head->next;
        free(ptr);
    }

    free(head);
    head = NULL;
    return head;
}