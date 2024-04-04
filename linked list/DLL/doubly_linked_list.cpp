#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node *back;
    node(int value, node *next, node *back)
    {
        this->data = value;
        this->back = back;
        this->next = next;
    }
    node(int value)
    {
        this->data = value;
        this->back = nullptr;
        this->next = nullptr;
    }
};

node *array_to_dll(vector<int> nums)
{
    node *head = new node(nums[0]);
    node *prev = head;
    for (int i = 0; i < nums.size(); i++)
    {
        node *temp = new node(nums[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

void print(node* head)
{
    while(head)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
}
int main()
{
    vector<int> a = {1, 2, 3, 4, 5};
    node *head = array_to_dll(a);
    print(head);
}