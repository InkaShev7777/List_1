#include <iostream>
using namespace std;
template<typename T>
struct Node
{
	T value;
	Node* next;
	Node* prev;
};
template<typename T>
class List
{
	Node<T>* head;
	Node<T>* end;
	int size;
public:
	List()
	{
		this->end = NULL;
		this->head = NULL;
		this->size = 0;
	}
	void Add(T value)
	{
		Node<T>* tmp = this->head;
		if (tmp == NULL)
		{
			tmp = new Node<T>;
			tmp->value = value;
			tmp->next = nullptr;
			tmp->prev = nullptr;
			this->head = tmp;
		}
		else
		{
			while (tmp->next != nullptr)
			{
				tmp = tmp->next;
			}
			tmp->next = new Node<T>;
			tmp->next->value = value;
			tmp->next->prev = tmp;
			tmp->next->next = nullptr;
			//this->end = tmp;
		}
		this->size++;
	}
	void print()
	{
		Node<T>* tmp = this->head;
		while (tmp!=nullptr)
		{
			cout << "Prev: " << tmp->prev << "\tValue: " << tmp->value<<"\tAdres: "<<tmp << "\tNext: " << tmp->next << "\n";
			tmp = tmp->next;
		}
		delete tmp;
	}
	bool isList(T value)
	{
		Node<T>* tmp = this->head;
		int f = 0;
		while (tmp!= nullptr)
		{
			if (tmp->value == value)
			{
				f = 1;
				break;
			}
			tmp = tmp->next;
		}
		delete tmp;

		if (f == 1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void removeByValue(T value)
	{
		Node<T>* tmp = this->head;
		if (tmp->value == value)
		{	
			tmp->next = tmp->next->prev;
			tmp->next->prev = nullptr;
			this->head = tmp->next;
		}
		else
		{
			Node<T>* iter = this->head;
			while (iter->next != nullptr)
			{
				if (iter->value == value)
				{
					//tmp->value = tmp->next->value;
				/*	iter->next->prev = iter->prev;
					iter->next->value = iter->value;
					iter->prev->next = iter->next;*/

					iter->next = iter->next->next;
					iter->next->next->prev = iter;
					break;
				}
				iter = iter->next;

			}
			tmp = iter->next;
		}
		//delete tmp;
		size--;
	}
};
int main()
{
	List<int> list;
	list.Add(1);
	list.Add(2);
	list.Add(3);
	list.Add(4);
	list.Add(5);
	list.print();
	cout<<list.isList(5);
	list.removeByValue(2);
	cout << "\n\n\n";
	list.print();
}