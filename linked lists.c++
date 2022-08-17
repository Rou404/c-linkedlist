#include <iostream>

using namespace std;

struct node
{
    node* next;
    int data;
};

class linked_list
{
    node* head;

    public:
        linked_list();
        void print_list();
        void head_insert(int value);
        void tail_insert(int value);
        void delete_node(int value);
        void search_node(int value);

};

linked_list::linked_list()
{
    head = NULL;
}

void linked_list::head_insert(int value)
{
    node* new_node = new node;
    new_node->data = value;
    new_node->next = NULL;

    if(head == NULL)
    {
        head = new_node;
    }
    else
    {
        new_node->next = head;
        head = new_node;
    }
}

void linked_list::tail_insert(int value)
{
    node* new_node = new node;
    new_node->data = value;
    new_node->next = NULL;

    if(head == NULL)
    {
        head = new_node;
    }
    else
    {
        node* tmp = new node;
        tmp = head;
        while(tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        tmp->next = new_node;
    }
}
void linked_list::print_list()
{
    cout<<"\n";
    node* tmp = new node;
    tmp = head;
    while (tmp != NULL)
    {
        cout<<tmp->data<<" ";
        tmp = tmp->next;
    }
    cout<<"\n";
       
}

void linked_list::search_node(int value)
{
    node* tmp = new node;
    tmp = head;
    while (tmp != NULL)
    {
        cout<<"Searching...\n";
        if(tmp->data == value)
            cout<<"Found! \n";
        tmp = tmp->next;
    }
    
}

void linked_list::delete_node(int value)
{
    cout<<"Searching for deletion...\n";
    if(head->data == value)
    {
        delete head;
        head = head->next;
        return;
    }

    if(head->next == NULL)
    {
        if(head->data == value)
        {
            delete head;
            head = NULL;
            return;
        }
    }
    node* tmp = new node;
    tmp = head;
    while (tmp->next != NULL)
    {
        if(tmp->next->data == value)
        {
            node* temp_pointer = tmp->next->next;
            delete tmp->next;
            tmp->next = temp_pointer;
            return;
        }
        tmp = tmp->next;
    }
}
int main()
{
    int n;
    cin>>n;
    linked_list list;
    for(int i = 0; i < n ;i++)
    {
        int tmp;
        cin >> tmp;
        list.tail_insert(tmp);
    }
    list.search_node(2);
    list.print_list();
    cout<<"Node to delete";
    int tmp;
    cin>>tmp;
    list.delete_node(tmp);
    list.print_list();

    return 0;

}