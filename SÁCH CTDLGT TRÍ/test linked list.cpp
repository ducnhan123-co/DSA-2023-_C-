#include <iostream>
using namespace std;

struct node {
    int info;
    node *link;
}*start;

void create(int);
node* create_node(int);
void display(node *);
void insert_end(int);
void insert_beg(int);
void insert_pos(int,int);
void delete_beg();
void delete_pos(int);
void delete_end();
void search(int);
void reverse();

int main() {
    int choice,data,choice1,pos,no_of_node;
    start=NULL;

    while(1) {
        system("cls"); // equivalent to system("cls"); // equivalent to clrscr();
        cout << "1. Create Linked list" << endl;
        cout << "2. Display Linked list" << endl;
        cout << "3. Insert into Linked list" << endl;
        cout << "4. Delete Node in Linked list" << endl;
        cout << "5. Search in Linked list" << endl;
        cout << "6. Reverse the Linked list" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter Your choice : ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter no of node to be created :";
                cin >> no_of_node;
                create(no_of_node);
                break;

            case 2:
                display(start);
                break;

            case 3:
                system("cls"); // equivalent to system("cls"); // equivalent to clrscr();
                cout << "1. Insert node at begining of list" << endl;
                cout << "2. Insert node at specific position in list" << endl;
                cout << "3. Insert node at End of list" << endl;
                cout << "4. Previous menu" << endl;
                cout << "Enter Choice : ";
                cin >> choice1;
                
                switch(choice1) {
                    case 1:
                        cout << "Enter data for node :";
                        cin >> data;
                        insert_beg(data);
                        break;
                    
                    case 2:
                        cout << "Enter data for node :";
                        cin >> data;
                        cout << "Enter position for node:";
                        cin >> pos;
                        insert_pos(data,pos);
                        break;
                    
                    case 3:
                        cout << "Enter data for node :";
                        cin >> data;
                        insert_end(data);
                        break;
                    
                    case 4:
                        break;
                }
                break;

            case 4:
                system("cls"); // equivalent to system("cls"); // equivalent to clrscr();
                cout << "1. Delete node at begining of list" << endl;
                cout << "2. Delete node at specific position in list" << endl;
                cout << "3. Delete node at End of list" << endl;
                cout << "4. Previous menu" << endl;
                cout << "Enter Choice : ";
                cin >> choice1;

                switch(choice1) {
                    case 1:
                        delete_beg();
                        break;

                    case 2:
                        cout << "Enter position for node:";
                        cin >> pos;
                        delete_pos(pos);
                        break;

                    case 3:
                        delete_end();
                        break;

                    case 4:
                        break;
                }
                break;

            case 5:
                system("cls"); // equivalent to system("cls"); // equivalent to clrscr();
                cout << "Enter Data to be searched :";
                cin >> data;
                search(data);
                break;

            case 6:
                system("cls"); // equivalent to system("cls"); // equivalent to clrscr();
                reverse();
                break;

            case 7:
                exit(0);

            default:
                cout << "Invalid Entry" << endl;
        }
    }
    return 0;
}

void create(int no) {
    int i,data;
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    
    for(i=0;i<no;i++) {
        if(start==NULL) {
            cout << "Enter Data for node " << i << " :";
            cin >> data;
            temp->info=data;
            temp->link=NULL;
            start=temp;
        }
        else {
            cout << "Enter Data for node " << i << " :";
            cin >> data;
            insert_end(data);
        }
    }
    if(no>0)
        cout << "List created" << endl;
    else
        cout << "List not created" << endl;
}

void display(node *start) {
    node *t;
    t = start;
    if (start == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    cout << "Linked List" << endl;
    while (t != NULL) {
        cout << t->info << "->";
        t = t->link;
    }
    cout << "End_of_list" << endl;
}

node* create_node(int data) {
    node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->info=data;
    temp->link=NULL;
    return temp;
}

void insert_end(int data) {
    node *temp;
    temp=start;
    while(1) {
        if(temp->link != NULL)
            temp=temp->link;
        else
            break;
    }
    temp->link=create_node(data);
}

void insert_beg(int data) {
    node *newnode;
    newnode=create_node(data);
    newnode->link=start;
    start=newnode;
}

void insert_pos(int data,int pos) {
    int i;
    node *newnode,*ptr;
    ptr=start;
    for(i=0;i<pos;i++) {
        if(ptr == NULL) {
            cout << "Invalid Position Entered" << endl;
            return;
        }
        ptr=ptr->link;
    }
    if(ptr->link == NULL) {
        insert_end(data);
    }
    else {
        newnode=create_node(data);
        newnode->link=ptr->link;
        ptr->link=newnode;
    }
}

void search(int data) {
    int count=0;
    node *ptr;
    ptr=start;
    do{
        if(ptr->info == data) {
            cout << "Data Found at position : " << count << endl;
            cout << "Address of node with Data : " << ptr << endl;
            return;
        }
        else
            ptr=ptr->link;
        count++;
    } while(ptr->link != NULL);
    cout << "Data Not found" << endl;
}

void delete_beg() {
    node *ptr;
    if(start == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    ptr=start;
    start = ptr->link;
    free(ptr);
    cout << "First Node Deleted" << endl;
}

void delete_pos(int pos) {
    node *ptr,*preptr;
    int i;
    ptr=start->link;
    preptr=start;
    if(ptr == NULL) {
        delete_beg();
        return;
    }
    for(i=0;i<pos-1;i++) {
        if(ptr==NULL) {
            cout << "Invalid position" << endl;
            return;
        }
        preptr=preptr->link;
        ptr=ptr->link;
    }
    preptr->link=ptr->link;
    free(ptr);
}

void delete_end() {
    node *ptr,*preptr;
    if(start == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    ptr=start->link;
    preptr=start;
    while(ptr->link != NULL) {
        ptr=ptr->link;
        preptr=preptr->link;
    }
    preptr->link=NULL;
    free(ptr);
    cout << "Last Node Deleted" << endl;
}

void reverse() {
    if(start == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    else if(start->link ==NULL) {
        cout << "List reversed" << endl;
        return;
    }
    node *p1,*p2,*p3;
    p1=start;
    p2=p1->link;
    p3=p2->link;
    p1->link=NULL;
    p2->link=p1;
    while(p3!=NULL) {
        p1=p2;
        p2=p3;
        p3=p3->link;
        p2->link=p1;
    }
    start=p2;
    cout << "List Reversed" << endl;
}
