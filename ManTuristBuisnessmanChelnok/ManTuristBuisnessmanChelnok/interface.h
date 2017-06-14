#include "ochered.h"
#include "File.h"
#include "Konteiner.h"
#include <deque> //��������� ������������������ ������������ ���������� ������������� ������� ����������� ���������
				//������������ ������� ������� � �������� � ������ � � ����� ����������
				//�������� �������������� ������� ������� � ������ �����
				//�� ������������ ��������� �������� ������
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
			cout << "1. �������" << endl;
			cout << "2. �����������" << endl;
			cout << "0. �����" << endl;
			cout << "\n�������� ��� �����:\n";
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
			cout << "1. �������� ������� � ������" << endl;
			cout << "2. �������� ������� � �����" << endl;
			cout << "3. �������� ������� �������� ����" << endl;
			cout << "4. �������� ���������� �������� ����" << endl;
			cout << "5. �������� ��������� ����" << endl;
			cout << "6. ������� ��������� ������� ����" << endl;
			cout << "7. ������� ������ ������� ����" << endl;
			cout << "8. �������� ���" << endl;
			cout << "0. �����" << endl;
			
			cout << "\n��� �����: ";
			cin >> choose;
		
			system("cls");

			switch (choose)
			{
			 case 1:
				cout << "������ � ������" << endl;
				cin >> ob;

				deq.push_front(ob);
				break;
		 	case 2:
				cout << "������ � �����" << endl;
				cin >> ob;

				deq.push_back(ob);
				break;
			case 3:
				if (deq.empty())
					cout << "��� ����" << endl;
				else
				{
					cout << "������ �������" << endl;
					ob.Shapka();
					cout << deq.front() << endl;
				}
				break;
			case 4:
				if (deq.empty())
					cout << "��� ����" << endl;
				else
				{
					cout << "��������� �������" << endl;
					ob.Shapka();
					cout << deq.back() << endl;
				}
				break;
			case 5:
				if (deq.empty())
					cout << "��� ����" << endl;
				else
				{
					cout << "���" << endl;
					ob.Shapka();
					for (i = 0; i < deq.size(); i++)
						cout << deq[i] << endl;
					cout << endl;
				}
				break;
			case 6:
				if (deq.empty())
					cout << "��� ����" << endl;
				else
				{
					cout << "�������� ����������" << endl;
					deq.pop_back();
				}
				break;
			case 7:
				if (deq.empty())
					cout << "��� ����" << endl;
				else
				{
					cout << "�������� �������" << endl;
					deq.erase(deq.begin());
				}
				break;
			case 8:
				if (deq.empty())
					cout << "��� ����" << endl;
				else
				{
					deq.clear();
					cout << "��� ����" << endl;
				}
			}
			system("pause");
		} 
	}
};