#include <iostream>

using namespace std;

typedef struct ListNode
{
	int data;
	bool check = false;
	struct ListNode* next;
} ListNode;

void InsertAtEnd(ListNode** head, int data)
{
	ListNode* inserted = new ListNode;
	inserted->data = data;
	if (*head == NULL)
	{
		*head = inserted;
		inserted->next = *head;
	}
	else
	{
		ListNode* tail = *head;
		while (tail->next != *head)
		{
			tail = tail->next;
		}
		tail->next = inserted;
		inserted->next = *head;
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int people, count, size = 0;
	ListNode* head = NULL;
	ListNode* currentNode = NULL;

	cin >> people;
	cin >> count;
	for (int i = 0; i < people; i++)
	{
		InsertAtEnd(&head, i + 1);
		size++;
	}

	cout << "<";
	do 
	{
		currentNode = head;
		for (int i = 0; i < count; i++)
		{
			currentNode = head;
			head = currentNode->next;
			if (currentNode->check == true)
			{
				while (currentNode->check != false)
				{
					currentNode = head;
					head = currentNode->next;
				}
			}
		}
		cout << currentNode->data;
		currentNode->check = true;
		size--;
		if (size != 0)
		{
			cout << ", ";
		}
	} while (size != 0);
	cout << ">";
}

