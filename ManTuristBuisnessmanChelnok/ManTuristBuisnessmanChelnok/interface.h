#include "ochered.h"
#include "File.h"
#include "Konteiner.h"
#include <deque> //контейнер последовательности поддерживает указзанный пользователем порядок вставляемых элементов
				//обеспечивает быструю вставку и удаление в начале и в конце контейнера
				//обладает преимуществами прямого доступа и гибкой длины
				//не обеспечивает связанное хранение данных
template <class T>
class Interface
{
	T ob;
	queue <T> Ochered;
	Queue <T> kont;
public:

	void Menu()
	{
		int choose;
		Interface <Tourist> objt;
		Interface <Businessman> objb;


		do
		{
			system("cls");
			cout << "1. Туристы" << endl;
			cout << "2. Бизнессмены" << endl;
			cout << "0. Выход" << endl;
			cout << "\nСделайте ваш выбор:\n";
			cin >> choose;
			
			switch (choose)
			{
			case 1:
				objt.menuOcheredi("Tourist.txt");
				break;
			case 2:
				txtFile <Businessman> txt("Businessman.txt");
				objb.menuOcheredi("Businessman.txt");
			}
		} while (choose);
 }

	void menuOcheredi(char *TXTfile)
	{
		int choose = 122;
		deque <T> deq;
		int i;

		while (choose)
		{
			system("cls");
			cout << "1. Добавить элемент в начало" << endl;
			cout << "2. Добавить элемент в конец" << endl;
			cout << "3. Просмотр первого элемента дека" << endl;
			cout << "4. Просмотр последнего элемента дека" << endl;
			cout << "5. Просмотр элементов дека" << endl;
			cout << "6. Удалить последний элемент дека" << endl;
			cout << "7. Удалить первый элемент дека" << endl;
			cout << "8. Очистить дек" << endl;
			cout << "0. Выход" << endl;
			
			cout << "\nВаш выбор: ";
			cin >> choose;
		
			system("cls");

			switch (choose)
			{
			 case 1:
				cout << "Запись в начало" << endl;
				cin >> ob;

				deq.push_front(ob);
				break;
		 	case 2:
				cout << "Запись в конец" << endl;
				cin >> ob;

				deq.push_back(ob);
				break;
			case 3:
				if (deq.empty())
					cout << "Дек пуст" << endl;
				else
				{
					cout << "Первый элемент" << endl;
					ob.Shapka();
					cout << deq.front() << endl;
				}
				break;
			case 4:
				if (deq.empty())
					cout << "Дек пуст" << endl;
				else
				{
					cout << "Последний элемент" << endl;
					ob.Shapka();
					cout << deq.back() << endl;
				}
				break;
			case 5:
				if (deq.empty())
					cout << "Дек пуст" << endl;
				else
				{
					cout << "Дек" << endl;
					ob.Shapka();
					for (i = 0; i < deq.size(); i++)
						cout << deq[i] << endl;
					cout << endl;
				}
				break;
			case 6:
				if (deq.empty())
					cout << "Дек пуст" << endl;
				else
				{
					cout << "Удаление последнего" << endl;
					deq.pop_back();
				}
				break;
			case 7:
				if (deq.empty())
					cout << "Дек пуст" << endl;
				else
				{
					cout << "Удаление первого" << endl;
					deq.erase(deq.begin());
				}
				break;
			case 8:
				if (deq.empty())
					cout << "Дек пуст" << endl;
				else
				{
					deq.clear();
					cout << "Дек пуст" << endl;
				}
			}
			system("pause");
		} 
	}
};