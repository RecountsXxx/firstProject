#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
using namespace std;
struct Job {
	string name{};
	int priority;
	string description;
	string day;
	string month;
	string time;
};


void createDelo(Job* delo, const int numbersDelo);
Job* deleteDelo(Job* delo, int& numbersDelo, string key);
Job* createDeloD(Job* stud, int& numbersStudent);
void editDelo(Job* delo, int& numbersDelo, int tmp);
void showList(Job* delo, int& numbersDelo);
void findDelo(Job* delo, int& numbersDelo);
int showListAll(Job* delo, int numbersDelo);

int main() {
	string key;
	srand(time(NULL));
	int exit = 0, tmp = 0;
	int i = 0;
	setlocale(LC_ALL, "Russian");
	int numbersDelo;
	cout << "�������� ������� ��� ��� �����: ";
	cin >> numbersDelo;
	Job* delo = new Job[numbersDelo];
	for (int i = 0; i < numbersDelo; i++) {
		cout << endl;
		cout << "������� ��� ����: ";
		cin >> delo[i].name;
		cin.ignore();
		cout << "������� ��������� ����: ";
		cin >> delo[i].priority;

		cout << "������� �������� � ����: ";
		cin >> delo[i].description;
		cin.ignore();
		cout << "������� ���� ����: ";
		getline(cin, delo[i].day);
		cout << "������� ����� ����: ";
		getline(cin, delo[i].month);

		cout << "������� ����� ����: ";
		getline(cin, delo[i].time);

	}
	cout << endl;
	system("cls");
	while (true) {
		int variant = 0;
		cout << "����: " << endl;
		cout << "1.���������� ���� " << endl;
		cout << "2.�������������� ���� " << endl;
		cout << "3.����� ���� �� ����" << endl;
		cout << "4.����� ����" << endl;
		cout << "5.�������� ���� " << endl;
		cout << "6.������ ���� ��� " << endl;
		cout << "7.����� " << endl;
		cout << ">>> ";
		cin >> variant;
		switch (variant) {
		case 1:
			delo = createDeloD(delo, numbersDelo);
			system("cls");
			createDelo(delo, numbersDelo);
			system("pause");
			system("cls");
			break;
		case 2:
			cout << "������� ����� ���� ������� ��������: ";
			cin >> tmp;
			editDelo(delo, numbersDelo, tmp);
			system("pause");
			system("cls");
			break;
		case 3:
			showList(delo, numbersDelo);
			system("pause");
			system("cls");
			break;
		case 4:
			system("cls");
			findDelo(delo, numbersDelo);
			system("pause");
			system("cls");
			break;
		case 5:
			cout << "������� �������� ����,������� �� ������ �������: ";
			cin >> key;
			deleteDelo(delo, numbersDelo, key);
			system("pause");
			system("cls");
			break;
		case 6:
			showListAll(delo, numbersDelo);
			system("pause");
			system("cls");
			break;

		case 7:
			false;
			break;
		default:
			cout << "������������ �������" << endl;
			break;
		}
	}
	delete[] delo;
	system("pause");
	return 0;

}
	Job* createDeloD(Job * delo, int& numbersDelo) {
		numbersDelo++;
		Job* studTemp = new Job[numbersDelo];
		for (int i = 0; i < numbersDelo - 1; i++) {
			studTemp[i] = delo[i];                            //eto
		}
		delete[] delo;
		studTemp = delo;
		return delo;
	}
	int showListAll(Job * delo, int numbersDelo) {
		system("cls");
		int variant = 0;
		cout << "����� ���: " << numbersDelo << endl;
		cout << endl;
		cout << "�������� ����������: " << endl;
		cout << "1.�� ����������: " << endl;
		cout << "2.�� �������" << endl;
		cout << "3.��� ���������� " << endl;
		cout << ">>> ";
		cin >> variant;
		if (variant == 1) {
			int length = numbersDelo;
			int array[3];
			for (int i = 0; i < numbersDelo; i++) {
				array[i] = delo[i].priority;
			}
			for (int startIndex = 0; startIndex < length - 1; ++startIndex)
			{
				int smallestIndex = startIndex;
				for (int currentIndex = startIndex + 1; currentIndex < length; ++currentIndex)
				{
					if (array[currentIndex] < array[smallestIndex])
						smallestIndex = currentIndex;
				}
				std::swap(array[startIndex], array[smallestIndex]);
			}
			for (int i = 0; i < numbersDelo; i++) {
				delo[i].priority = array[i];
				cout << "����: " << i << ". ��������: " << delo[i].name << endl;
				cout << "����: " << i << ". ���������: " << delo[i].priority << endl;
				cout << "����: " << i << ". ��������: " << delo[i].description << endl;
				cout << "����: " << i << ". ����: " << delo[i].day << endl;
				cout << "����: " << i << ". �����: " << delo[i].month << endl;
				cout << "����: " << i << ". �����: " << delo[i].time << endl;
				cout << endl;

			}
		}
		if (variant == 2) {
			int length = numbersDelo;
			string array[3];
			for (int i = 0; i < numbersDelo; i++) {
				array[i] = delo[i].time;
			}
			for (int startIndex = 0; startIndex < length - 1; ++startIndex)
			{
				int smallestIndex = startIndex;
				for (int currentIndex = startIndex + 1; currentIndex < length; ++currentIndex)
				{
					if (array[currentIndex] < array[smallestIndex])
						smallestIndex = currentIndex;
				}
				std::swap(array[startIndex], array[smallestIndex]);
			}
			for (int i = 0; i < numbersDelo; i++) {
				delo[i].time = array[i];
				cout << "����: " << i << ". ��������: " << delo[i].name << endl;
				cout << "����: " << i << ". ���������: " << delo[i].priority << endl;
				cout << "����: " << i << ". ��������: " << delo[i].description << endl;
				cout << "����: " << i << ". ����: " << delo[i].day << endl;
				cout << "����: " << i << ". �����: " << delo[i].month << endl;
				cout << "����: " << i << ". �����: " << delo[i].time << endl;
				cout << endl;

			}
		}
		if (variant == 3) {
			for (int i = 0; i < numbersDelo; i++) {
				cout << "����: " << i << ". ��������: " << delo[i].name << endl;
				cout << "����: " << i << ". ���������: " << delo[i].priority << endl;
				cout << "����: " << i << ". ��������: " << delo[i].description << endl;
				cout << "����: " << i << ". ����: " << delo[i].day << endl;
				cout << "����: " << i << ". �����: " << delo[i].month << endl;
				cout << "����: " << i << ". �����: " << delo[i].time << endl;
				cout << endl;

			}
		}
		return 0;
	}
	void createDelo(Job * delo, const int numbersDelo) {
		cout << endl;
		cout << "������� ��� ����: ";
		cin >> delo[numbersDelo].name;
		cin.ignore();
		cout << "������� ��������� ����: ";
		cin >> delo[numbersDelo].priority;

		cout << "������� �������� � ����: ";
		cin >> delo[numbersDelo].description;
		cin.ignore();                                              //eto
		cout << "������� ���� ����: ";
		getline(cin, delo[numbersDelo].day);

		cout << "������� ����� ����: ";
		getline(cin, delo[numbersDelo].month);

		cout << "������� ����� ����: ";
		getline(cin, delo[numbersDelo].time);
		system("cls");
	}
	Job* deleteDelo(Job * delo, int& numbersDelo, string key) {
		numbersDelo--;
		Job* jobTemp = new Job[numbersDelo];
		for (int i = 0, j = 0; i < numbersDelo; i++, j++) {
			if (to_string(i) == key) {
				j++;
			}
			jobTemp[i] = delo[i];
		}
		delete[] delo;                                         //eto
		delo = jobTemp;
		return delo;
	}
	void editDelo(Job * delo, int& numbersDelo, int tmp) {
		int variant = 0;
		cout << "�������� ��� �� ������ ��������: " << endl;
		cout << "1. �������� " << endl;
		cout << "2. ��������� " << endl;
		cout << "3. �������� " << endl;
		cout << "4. ���� " << endl;
		cout << "5. ����� " << endl;
		cout << "6. ����� " << endl;
		cout << ">>> ";
		cin >> variant;
		switch (variant) {
		case 1:
			cout << "����� ���: ";
			cin >> delo[tmp].name;
			break;
		case 2:
			cout << "����� ���������: ";
			cin >> delo[tmp].priority;
			break;
		case 3:
			cout << "����� ��������: ";
			cin >> delo[tmp].description;
			break;
		case 4:
			cout << "����� ����: ";
			cin >> delo[tmp].day;
			break;
		case 5:
			cout << "����� �����: ";
			cin >> delo[tmp].month;
			break;
		case 6:
			cout << "����� �����: ";
			cin >> delo[tmp].time;
			break;
		default:
			cout << "������������ �������" << endl;
			break;
		}
	}
	// �� �������� ������ � �� ������ ������� ��� ���, ��� ��� �� �����, � ��� ��� ��� ����� �� ��������, ���� ����� � if � �������� ��, �������� ��� ����� ���� ����
	void showList(Job * delo, int& numbersDelo)
	{
		int day, month, sevenDays;
		int variant;
		cout << "����������� ������ ��: " << endl;
		cout << "1. 1 ���� " << endl;
		cout << "2. 7 ���� " << endl;
		cout << "3. 30 ���� " << endl;
		cout << ">>> ";
		cin >> variant;
		system("cls");
		if (variant == 1) {
			cout << "������� ����(������): ";
			cin >> day;
			for (int i = 0; i < numbersDelo; i++) {
				if (to_string(day) == delo[i].day) {
					cout << "����: " << i << ". ��������: " << delo[i].name << endl;
					cout << "����: " << i << ". ���������: " << delo[i].priority << endl;
					cout << "����: " << i << ". ��������: " << delo[i].description << endl;
					cout << "����: " << i << ". ����: " << delo[i].day << endl;
					cout << "����: " << i << ". �����: " << delo[i].month << endl;
					cout << "����: " << i << ". �����: " << delo[i].time << endl;
					cout << endl;
				}
			}
		}
		if (variant == 2) {
			cout << "������� ������(������): ";
			cin >> sevenDays;
			for (int i = 0; i < numbersDelo; i++) {
				if (to_string(sevenDays) >= delo[i].day + to_string(7)) {
					cout << "����: " << i << ". ��������: " << delo[i].name << endl;
					cout << "����: " << i << ". ���������: " << delo[i].priority << endl;
					cout << "����: " << i << ". ��������: " << delo[i].description << endl;
					cout << "����: " << i << ". ����: " << delo[i].day << endl;
					cout << "����: " << i << ". �����: " << delo[i].month << endl;
					cout << "����: " << i << ". �����: " << delo[i].time << endl;
					cout << endl;
				}
			}
		}
		if (variant == 3) {
			cout << "������� �����(������): ";
			cin >> month;
			for (int i = 0; i < numbersDelo; i++) {
				if (to_string(month) == delo[i].month) {
					cout << "����: " << i << ". ��������: " << delo[i].name << endl;
					cout << "����: " << i << ". ���������: " << delo[i].priority << endl;
					cout << "����: " << i << ". ��������: " << delo[i].description << endl;
					cout << "����: " << i << ". ����: " << delo[i].day << endl;
					cout << "����: " << i << ". �����: " << delo[i].month << endl;
					cout << "����: " << i << ". �����: " << delo[i].time << endl;
					cout << endl;
				}
			}
		}
	}
	void findDelo(Job * delo, int& numbersDelo) {
		int variant, variantTwo;
		string name, description;
		int day, month, time;
		int priority;
		cout << "�������� �����" << endl;
		cout << "1. �� ��������" << endl;
		cout << "2. �� ����������" << endl;
		cout << "3. �� ��������" << endl;
		cout << "4. �� ���, ��� ������" << endl;
		cout << "5. �� �������" << endl;
		cout << ">>> ";
		cin >> variant;
		switch (variant) {
		case 1:
			cout << "������� ��������: ";
			cin >> name;
			for (int i = 0; i < numbersDelo; i++) {
				if (delo[i].name == name) {
					cout << "����: " << i << ". ��������: " << delo[i].name << endl;
					cout << "����: " << i << ". ���������: " << delo[i].priority << endl;
					cout << "����: " << i << ". ��������: " << delo[i].description << endl;
					cout << "����: " << i << ". ����: " << delo[i].day << endl;
					cout << "����: " << i << ". �����: " << delo[i].month << endl;
					cout << "����: " << i << ". �����: " << delo[i].time << endl;
					cout << endl;
				}
			}
			system("pause");
			system("cls");
			break;
		case 2:
			cout << "������� ���������: ";
			cin >> priority;
			for (int i = 0; i < numbersDelo; i++) {
				if (delo[i].priority == priority) {
					cout << "����: " << i << ". ��������: " << delo[i].name << endl;
					cout << "����: " << i << ". ���������: " << delo[i].priority << endl;
					cout << "����: " << i << ". ��������: " << delo[i].description << endl;
					cout << "����: " << i << ". ����: " << delo[i].day << endl;
					cout << "����: " << i << ". �����: " << delo[i].month << endl;
					cout << "����: " << i << ". �����: " << delo[i].time << endl;
					cout << endl;
				}
			}
			system("pause");
			system("cls");
			break;
		case 3:
			cout << "������� ��������: ";
			cin >> description;
			for (int i = 0; i < numbersDelo; i++) {
				if (delo[i].description == description) {
					cout << "����: " << i << ". ��������: " << delo[i].name << endl;
					cout << "����: " << i << ". ���������: " << delo[i].priority << endl;
					cout << "����: " << i << ". ��������: " << delo[i].description << endl;
					cout << "����: " << i << ". ����: " << delo[i].day << endl;
					cout << "����: " << i << ". �����: " << delo[i].month << endl;
					cout << "����: " << i << ". �����: " << delo[i].time << endl;
					cout << endl;
				}
			}
			system("pause");
			system("cls");
			break;
		case 4:
			system("cls");
			cout << "1. �� ���" << endl;
			cout << "2. �� ������" << endl;
			cout << ">>> ";
			cin >> variantTwo;
			if (variantTwo == 1) {
				cout << "������� ����: ";
				cin >> day;
				for (int i = 0; i < numbersDelo; i++) {
					if (delo[i].day == to_string(day)) {
						cout << "����: " << i << ". ��������: " << delo[i].name << endl;
						cout << "����: " << i << ". ���������: " << delo[i].priority << endl;
						cout << "����: " << i << ". ��������: " << delo[i].description << endl;
						cout << "����: " << i << ". ����: " << delo[i].day << endl;
						cout << "����: " << i << ". �����: " << delo[i].month << endl;
						cout << "����: " << i << ". �����: " << delo[i].time << endl;
						cout << endl;
					}
				}
			}
			if (variantTwo == 2) {
				cout << "������� �����: ";
				cin >> month;
				for (int i = 0; i < numbersDelo; i++) {
					if (delo[i].month == to_string(month)) {
						cout << "����: " << i << ". ��������: " << delo[i].name << endl;
						cout << "����: " << i << ". ���������: " << delo[i].priority << endl;
						cout << "����: " << i << ". ��������: " << delo[i].description << endl;
						cout << "����: " << i << ". ����: " << delo[i].day << endl;
						cout << "����: " << i << ". �����: " << delo[i].month << endl;
						cout << "����: " << i << ". �����: " << delo[i].time << endl;
						cout << endl;
					}
				}
			}
			system("pause");
			system("cls");
			break;
		case 5:
			cout << "������� �����: ";
			cin >> time;
			for (int i = 0; i < numbersDelo; i++) {
				if (delo[i].time == to_string(time)) {
					cout << "����: " << i << ". ��������: " << delo[i].name << endl;
					cout << "����: " << i << ". ���������: " << delo[i].priority << endl;
					cout << "����: " << i << ". ��������: " << delo[i].description << endl;
					cout << "����: " << i << ". ����: " << delo[i].day << endl;
					cout << "����: " << i << ". �����: " << delo[i].month << endl;
					cout << "����: " << i << ". �����: " << delo[i].time << endl;
					cout << endl;
				}
			}
			system("pause");
			system("cls");
			break;
		default:
			break;

		}
	}


