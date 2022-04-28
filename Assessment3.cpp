// Assessment 4...
/*Merge A Linked List into another Linked List at alternate Position...*/
#include <iostream>
using namespace std;
class Node       // Node class for defining Node attributes
{
    public:        // Data members
        int data;
        Node* next;
        Node(int value)     // Parametrized Constructor
        {
            data = value;
            next = NULL;
        }
};
class LinkedList    // class LinkedList to Implement Linked List Data Structure
{
    public:
        void InsertAtTail(Node* &head, int value)     // Inserting Node at End
        {
            Node* n = new Node(value);
            if(head == NULL)      // If the Linked List is empty
            {
                head = n;
                return;
            }
            Node* temp = head;           // If the Linked List is not empty
            while(temp -> next != NULL)
            {
                temp = temp -> next;
            }
            temp -> next = n;
            n -> next = NULL;
        }
        void DisplayList(Node* &head)     // Displaying Linked List
        {
            Node* temp = head;
            for(; temp != NULL; temp = temp -> next)    // Iterating through List O(n) time...
            {
                cout << temp -> data << " -> ";
            }
            cout << "Null" << endl;
        }
        void MergeLinkedList(Node* &head1, Node* &head2, Node* &newhead1, Node* &newhead2)
        {       // Merging List together as a user-defined Operation
            newhead1 = head1;        // Storing head Node of First List
            Node* temp = head1;
            Node* temp1 = head2;
            while(temp1 -> next != NULL && temp -> next != NULL)  // Traversing to the end of both Lists
            {
                temp = head1 -> next;     // Moving to the next node of first List
                temp1 = head2 -> next;    // Moving to the next node of second List
                head1 -> next = head2;    // The next pointer of the first List is changed
                head2 -> next = temp;     // The next pointer of the second List is changed
                head1 = temp;             // The head pointer of the first List is updated
                head2 = temp1;            // The head pointer of the second List is updated
            }
            if(head2 != NULL)     // If the updated head of second list is not Null
            {
                head1 -> next = head2;
                if(head2 -> next != NULL)    // If the next pointer does not point to Null
                {
                    newhead2 = head2 -> next;
                    head2 -> next = NULL;
                }
            }
        }
};
int main()
{
    Node* head1 = NULL;    // Head pointer of the first List created
    Node* head2 = NULL;    // Head pointer of the second List created
    LinkedList linkedlist;
    int s, x;
    cout << "Enter the number of Additions to perform : ";
    cin >> s;
    cout << "Enter the first linked list !! " << endl;
    for(int i = 0; i < s; i++)     // Loop for Addition of Nodes
    {
        cout << "Enter data : ";
        cin >> x;
        linkedlist.InsertAtTail(head1, x);     // Insertion for first List
    }
    linkedlist.DisplayList(head1);
    cout << "Enter the number of Additions to perform : ";
    cin >> s;
    cout << "Enter the second linked list !! " << endl;
    for(int i = 0; i < s; i++)      // Loop for Addition of Nodes
    {
        cout << "Enter data : ";
        cin >> x;
        linkedlist.InsertAtTail(head2, x);      // Insertion for second List
    }
    Node* newhead1 = NULL;
    Node* newhead2 = NULL;
    linkedlist.DisplayList(head2);
    linkedlist.MergeLinkedList(head1, head2, newhead1, newhead2);     // Calling the Merge function
    cout << "The first Linked List after Merge Operation : " << endl;
    linkedlist.DisplayList(newhead1);
    cout << "The second Linked List after Merge Operation : " << endl;
    linkedlist.DisplayList(newhead2);
    return 0;    // End of the program
}