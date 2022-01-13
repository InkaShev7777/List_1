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
		//delete tmp;
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
			if (tmp->next != nullptr)
			{
				tmp->next->prev = nullptr;
				this->head = this->head->next;
			}
			else
			{
				this->head = this->head->next;
			}
		}
		else
		{
			Node<T>* iter = this->head;
			while (iter->next != nullptr)
			{
				if (iter->value == value)
				{
					iter->prev->next = iter->next;
					iter->next->prev = iter->prev;
					break;
				}
				iter = iter->next;
				if (iter->next == nullptr)
				{
					iter->prev->next = iter->next;
				}
			}
			tmp = iter->next;
		}
		delete tmp;
		size--;
	}
};
int main()
{
	List<int> list;
	setlocale(0, "");
	int vibor;
	do
	{
		cout << "\t\t����\n";
		cout << "1 - ���������� �������� � ������\n";
		cout << "2 - ����� ����� ������\n";
		cout << "3 - ����� �������� � ������\n";
		cout << "4 - �������� �������� �� ������\n";
		cout << "0 - �����\n";
		cout << "�������� ���� �����: ";
		cin >> vibor;
		switch (vibor)
		{
		case 1:
			system("cls");
			cout << "������� ������� ������� ������ �������� � ������: ";
			int a;
			cin >> a;
			list.Add(a);
			cout << "�� �������� � ������: "<<a<<"\n";
			system("pause");
			system("cls");
			break;
		case 2:
			system("cls");
			list.print();
			system("pause");
			system("cls");
			break;
		case 3:
			system("cls");
			int i;
			cout << "������� ������� ������� ������ �����: ";
			cin >> i;
			if (list.isList(i) == 1)
			{
				cout << "������� ���� � ������!!!\n";
			}
			else
			{
				cout << "�������� ��� � ������!!!\n";
			}
			system("pause");
			system("cls");
			break;
		case 4:
			system("cls");
			int d;
			cout << "������� ������� ������� ������ �������: ";
			cin >> d;
			if (list.isList(d) == 1)
			{
				list.removeByValue(d);
				cout << "������� ������!!!\n";
				list.print();
			}
			else
			{
				cout << "�������� � ������ ���!!\n";
			}
			system("pause");
			system("cls");
			break;
		}
	} while (vibor != 0);

}