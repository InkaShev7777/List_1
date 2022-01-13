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
		cout << "\t\tМеню\n";
		cout << "1 - Добавление элемента в список\n";
		cout << "2 - Вывод всего списка\n";
		cout << "3 - Поиск элемента в списке\n";
		cout << "4 - Удаление элемента из списка\n";
		cout << "0 - Выход\n";
		cout << "Сделайте свой выбор: ";
		cin >> vibor;
		switch (vibor)
		{
		case 1:
			system("cls");
			cout << "Введите элемент который хотите добавить в список: ";
			int a;
			cin >> a;
			list.Add(a);
			cout << "Вы добавили в список: "<<a<<"\n";
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
			cout << "Введите элемент который хотите найти: ";
			cin >> i;
			if (list.isList(i) == 1)
			{
				cout << "Элемент есть в списке!!!\n";
			}
			else
			{
				cout << "Элемента нет в списке!!!\n";
			}
			system("pause");
			system("cls");
			break;
		case 4:
			system("cls");
			int d;
			cout << "Введите элемент который хотите удалить: ";
			cin >> d;
			if (list.isList(d) == 1)
			{
				list.removeByValue(d);
				cout << "Элемент удален!!!\n";
				list.print();
			}
			else
			{
				cout << "Элемента в списке нет!!\n";
			}
			system("pause");
			system("cls");
			break;
		}
	} while (vibor != 0);

}