#include <iostream>
using namespace std;

struct Node
{
public:
	int Info;
	Node* Link;

	Node()
	{
		Info = 0;
		Link = NULL;
	}

	Node(int item) //If the stack is empty
	{
		Info = item;
		Link = NULL;
	}
};

struct Stack
{
public:
	Node* Top;

	Stack()
	{
		Top = NULL;
	}

	void Push(int New)
	{
		if (IsEmpty())
		{
			Node* NewNode = new Node(New);
			Top = NewNode;
		}
		else
		{
			Node* NewNode = new Node();
			NewNode->Info = New;
			NewNode->Link = Top;
			Top = NewNode;
		}
	}

	int Pop() //return the deleted value
	{
		int DeletedValue;
		Node* DeletedPointer = Top;
		DeletedValue = DeletedPointer->Info; // DeletedValue = Top->Data
		Top = Top->Link;
		delete DeletedPointer;
		return DeletedValue;
	}

	void PrintElements()
	{
		Node* Temp = Top;
		while (Temp != NULL)
		{
			cout << Temp->Info << " ";
			Temp = Temp->Link;
		}
		cout << endl;
	}

	int TopElement()
	{
		return Top->Info;
	}

	bool IsEmpty()
	{
		return (Top == NULL);
	}

};

int main()
{
	Stack S;
	int item;
	for (int i = 0; i < 5; i++)
	{
		cout << "Enter item to insert into Stack : " << endl;
		cin >> item;
		S.Push(item);
	}
	S.PrintElements();
	cout << "The deleted Value is " << S.Pop() << endl;
	S.Pop();
	cout << "The top of Stack is " << S.TopElement() << endl;
	S.PrintElements();
	system("Pause");
	return 0;
}