/*
Given two SORTED Circular Linked Lists ,
Write a function to merge those two linked lists .
The First Linked List head should point to the final merged linked list .
The Final merged linked list should also be in SORTED order and a Circular Linked List.
You need to return the Length of Final SLL.

*********
The First linked list head should now point to the Final sorted(Ascending) Linked list First Node
*********
Ex : A: 0->3->5->10->20 (and 20 now pointing back to 0,instead of Null )
B: 1->2->6->11->21->50->70 (70 Pointing back to 1).

The Final Linked List is A:0->1->2->3->5->6->10->11->20->21->50->70 .

Note : Dont use Malloc or create any new nodes ,Only pointers need to be interchanged,
You can use temp pointers although.
Note : The Final Linked List should be  also be a circular Linked List where Last node is
pointing towards the first node.
Note : Return -1 for Invalid Inputs like NULL;

Input : head1 and head2 are Addresses of Two Circular Linked Lists heads .
Output :Return Length of New SLL .Modify the head1 value, such that it now points to 
Merged Sorted Circular SLL .

Difficulty : Medium
*/
#include <stdlib.h>
#include <stdio.h>

struct node{
	int data;
	struct node *next;
};
struct node * merge2LinkedLists_1(struct node *head1, struct node *head2) {
	struct node*temp1 = NULL, *temp2 = NULL, *result = NULL;
	if (head1 == NULL && head2 == NULL)
		return NULL;
	if (head1 == NULL && head2 != NULL)
		return head2;
	//k
	if (head1 != NULL && head2 == NULL)
		return head1;
	if (head1->data < head2->data)
	{
		result = head1;
		result->next = merge2LinkedLists_1(head1->next, head2);
	}
	else
	{
		result = head2;
		result->next = merge2LinkedLists_1(head1, head2->next);
	}
	return result;
}

int merge_circularlists(struct node **head1, struct node **head2){
	//Returns Length of merged Sorted circular SLL and also points *head1 to final SLL .
	struct node *temp1 = *head1, *p = *head1, *temp2 = *head2, *q = *head2;
	int count = 0;
	if (temp1==NULL||temp2==NULL)
		return -1;
	while (p)
	{
		if (p->next == temp1)
			p->next = NULL;
		p = p->next;

	}
	while (q)
	{
		if (q->next == temp2)
			q->next = NULL;
		q = q->next;

	}
	temp1 = merge2LinkedLists_1(temp1, temp2);
	p = temp1;
	q = temp1;
	while (p)
	{
		q = p;
		p = p->next;
		count++;
	}
	q->next = temp1;
	*head1 = temp1;

	return count;
}