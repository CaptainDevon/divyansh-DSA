#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int value)
    {
        data = value;
        next = nullptr;
    }
    node(int value, node *newptr)
    {
        data = value;
        next = newptr;
    }
};
class linkedlist
{
public:
    node *head;
    void printing(node *head)
    {
        node *ptr = head;
        while (ptr != nullptr)
        {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
        cout << endl;
    }
    node *converting_array_to_linked_list(vector<int> &nums)
    {
        node *head = new node(nums[0]);
        node *mover = head;
        for (int i = 1; i < nums.size(); i++)
        {
            node *temp = new node(nums[i]);
            mover->next = temp;
            mover = temp;
        }
        return head;
    }
    int length_of_ll(node *head)
    {
        node *ptr = head;
        int count = 0;
        while (ptr != nullptr)
        {
            count++;
            ptr = ptr->next;
        }
        return count;
    }

    int if_present_in_ll(node *head, int query)
    {
        node *ptr = head;
        while (ptr != nullptr)
        {
            if (ptr->data == query)
            {
                return 1;
                break;
            }
            ptr = ptr->next;
        }
        return 0;
    }

    node *inserting_at_beginning(node *head, int number)
    {
        node *newnode = new node(number);
        newnode->next = head;
        head = newnode;
        return head;
    }

    node *insert_at_end(node *head, int number)
    {
        node *newnode = new node(number, nullptr);
        node *ptr = head;
        while (ptr->next != nullptr)
        {
            ptr = ptr->next;
        }
        ptr->next = newnode;
        return head;
    }
    node *insert_at_middle(node *head, int number, int pos)
    {
        int count = 0;
        node *newnode = new node(number);
        node *ptr = head;
        while (count <= pos)
        {
            count++;
            ptr = ptr->next;
        }
        newnode->next = ptr->next;
        ptr->next = newnode;
        return head;
    }

    node *delete_from_beginning(node *head)
    {
        node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    node *delete_at_end(node *head)
    {
        node *ptr = head;
        while (ptr->next != nullptr)
        {
            ptr = ptr->next;
        }
        node *ptrp = head;
        while (ptrp->next != ptr)
        {
            ptrp = ptrp->next;
        }
        free(ptr);
        ptrp->next = nullptr;
        return head;
    }
    node *delete_at_position(node *head, int pos)
    {
        int count = 0;
        node *ptr = head;
        node *ptrp = head;
        while (count < pos)
        {
            count++;
            ptr = ptr->next;
        }
        while (ptrp->next != ptr)
        {
            ptrp = ptrp->next;
        }
        ptrp->next = ptr->next;
        free(ptr);
        return head;
    }
    int finding_middle_of_ll(node *head)
    {
        node *slow = head;
        node *fast = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow->data;
    }
    node *deleteMiddle(node *head)
    {

        // Write your code here.

        if (head->next == nullptr) {
            delete head;
            return nullptr;
        }
        node* slow = head;
        node* fast = head;
        node* prev = nullptr;
        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = slow->next;
        slow->next = nullptr;
        delete slow;
        return head;
    }
    
};
int main()
{
    vector<int> a = {1, 2, 3, 4, 5};
    linkedlist l;
    node *head = l.converting_array_to_linked_list(a);
    l.printing(head);
    cout << l.length_of_ll(head) << endl;
    int number = 0;
    head = l.inserting_at_beginning(head, number);
    l.printing(head);
    int query = 4;
    cout << l.if_present_in_ll(head, query) << endl;
    int number1 = 6;
    head = l.insert_at_middle(head, number1, 2);
    l.printing(head);
    int number2 = 8;
    head = l.insert_at_end(head, number2);
    l.printing(head);
    head = l.delete_from_beginning(head);
    l.printing(head);
    head = l.delete_at_end(head);
    l.printing(head);
    head = l.delete_at_position(head, 3);
    l.printing(head);
    cout << l.finding_middle_of_ll(head) << endl;
    head = l.deleteMiddle(head);
    l.printing(head);
}