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
	cout << "Выберите сколько дел вам нужно: ";
	cin >> numbersDelo;
	Job* delo = new Job[numbersDelo];
	for (int i = 0; i < numbersDelo; i++) {
		cout << endl;
		cout << "Введите имя дела: ";
		cin >> delo[i].name;
		cin.ignore();
		cout << "Введите приоритет дела: ";
		cin >> delo[i].priority;

		cout << "Введите описания к делу: ";
		cin >> delo[i].description;
		cin.ignore();
		cout << "Введите день дела: ";
		getline(cin, delo[i].day);
		cout << "Введите месяц дела: ";
		getline(cin, delo[i].month);

		cout << "Введите время дела: ";
		getline(cin, delo[i].time);

	}
	cout << endl;
	system("cls");
	while (true) {
		int variant = 0;
		cout << "Меню: " << endl;
		cout << "1.Добавления дела " << endl;
		cout << "2.Редактирование дела " << endl;
		cout << "3.Поиск дела по дате" << endl;
		cout << "4.Поиск дела" << endl;
		cout << "5.Удаления дела " << endl;
		cout << "6.Список всех дел " << endl;
		cout << "7.Выход " << endl;
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
			cout << "Введите номер дела который изменить: ";
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
			cout << "Введите название дела,который вы хотите удалить: ";
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
			cout << "Неправильный вариант" << endl;
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
		cout << "Всего дел: " << numbersDelo << endl;
		cout << endl;
		cout << "Выберите сортивовку: " << endl;
		cout << "1.По приоритету: " << endl;
		cout << "2.По времени" << endl;
		cout << "3.Без сортирвоки " << endl;
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
				cout << "Дело: " << i << ". Название: " << delo[i].name << endl;
				cout << "Дело: " << i << ". Приоритет: " << delo[i].priority << endl;
				cout << "Дело: " << i << ". Описание: " << delo[i].description << endl;
				cout << "Дело: " << i << ". День: " << delo[i].day << endl;
				cout << "Дело: " << i << ". Месяц: " << delo[i].month << endl;
				cout << "Дело: " << i << ". Время: " << delo[i].time << endl;
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
				cout << "Дело: " << i << ". Название: " << delo[i].name << endl;
				cout << "Дело: " << i << ". Приоритет: " << delo[i].priority << endl;
				cout << "Дело: " << i << ". Описание: " << delo[i].description << endl;
				cout << "Дело: " << i << ". День: " << delo[i].day << endl;
				cout << "Дело: " << i << ". Месяц: " << delo[i].month << endl;
				cout << "Дело: " << i << ". Время: " << delo[i].time << endl;
				cout << endl;

			}
		}
		if (variant == 3) {
			for (int i = 0; i < numbersDelo; i++) {
				cout << "Дело: " << i << ". Название: " << delo[i].name << endl;
				cout << "Дело: " << i << ". Приоритет: " << delo[i].priority << endl;
				cout << "Дело: " << i << ". Описание: " << delo[i].description << endl;
				cout << "Дело: " << i << ". День: " << delo[i].day << endl;
				cout << "Дело: " << i << ". Месяц: " << delo[i].month << endl;
				cout << "Дело: " << i << ". Время: " << delo[i].time << endl;
				cout << endl;

			}
		}
		return 0;
	}
	void createDelo(Job * delo, const int numbersDelo) {
		cout << endl;
		cout << "Введите имя дела: ";
		cin >> delo[numbersDelo].name;
		cin.ignore();
		cout << "Введите приоритет дела: ";
		cin >> delo[numbersDelo].priority;

		cout << "Введите описания к делу: ";
		cin >> delo[numbersDelo].description;
		cin.ignore();                                              //eto
		cout << "Введите день дела: ";
		getline(cin, delo[numbersDelo].day);

		cout << "Введите месяц дела: ";
		getline(cin, delo[numbersDelo].month);

		cout << "Введите время дела: ";
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
		cout << "Выберите что вы хотите изменить: " << endl;
		cout << "1. Название " << endl;
		cout << "2. Приоритет " << endl;
		cout << "3. Описание " << endl;
		cout << "4. День " << endl;
		cout << "5. Месяц " << endl;
		cout << "6. Время " << endl;
		cout << ">>> ";
		cin >> variant;
		switch (variant) {
		case 1:
			cout << "Новое имя: ";
			cin >> delo[tmp].name;
			break;
		case 2:
			cout << "Новый приоритет: ";
			cin >> delo[tmp].priority;
			break;
		case 3:
			cout << "Новое описание: ";
			cin >> delo[tmp].description;
			break;
		case 4:
			cout << "Новый день: ";
			cin >> delo[tmp].day;
			break;
		case 5:
			cout << "Новый месяц: ";
			cin >> delo[tmp].month;
			break;
		case 6:
			cout << "Новое время: ";
			cin >> delo[tmp].time;
			break;
		default:
			cout << "Неправильный вариант" << endl;
			break;
		}
	}
	// вы спросите почему я не сделал функции для дел, там где их много, а тем что она будет всё выводить, даже когда в if я пробывал всё, посчитал так юудет тоже норм
	void showList(Job * delo, int& numbersDelo)
	{
		int day, month, sevenDays;
		int variant;
		cout << "Отображения списка на: " << endl;
		cout << "1. 1 день " << endl;
		cout << "2. 7 дней " << endl;
		cout << "3. 30 дней " << endl;
		cout << ">>> ";
		cin >> variant;
		system("cls");
		if (variant == 1) {
			cout << "Введите день(цифрой): ";
			cin >> day;
			for (int i = 0; i < numbersDelo; i++) {
				if (to_string(day) == delo[i].day) {
					cout << "Дело: " << i << ". Название: " << delo[i].name << endl;
					cout << "Дело: " << i << ". Приоритет: " << delo[i].priority << endl;
					cout << "Дело: " << i << ". Описание: " << delo[i].description << endl;
					cout << "Дело: " << i << ". День: " << delo[i].day << endl;
					cout << "Дело: " << i << ". Месяц: " << delo[i].month << endl;
					cout << "Дело: " << i << ". Время: " << delo[i].time << endl;
					cout << endl;
				}
			}
		}
		if (variant == 2) {
			cout << "Введите неделю(цифрой): ";
			cin >> sevenDays;
			for (int i = 0; i < numbersDelo; i++) {
				if (to_string(sevenDays) >= delo[i].day + to_string(7)) {
					cout << "Дело: " << i << ". Название: " << delo[i].name << endl;
					cout << "Дело: " << i << ". Приоритет: " << delo[i].priority << endl;
					cout << "Дело: " << i << ". Описание: " << delo[i].description << endl;
					cout << "Дело: " << i << ". День: " << delo[i].day << endl;
					cout << "Дело: " << i << ". Месяц: " << delo[i].month << endl;
					cout << "Дело: " << i << ". Время: " << delo[i].time << endl;
					cout << endl;
				}
			}
		}
		if (variant == 3) {
			cout << "Введите месяц(цифрой): ";
			cin >> month;
			for (int i = 0; i < numbersDelo; i++) {
				if (to_string(month) == delo[i].month) {
					cout << "Дело: " << i << ". Название: " << delo[i].name << endl;
					cout << "Дело: " << i << ". Приоритет: " << delo[i].priority << endl;
					cout << "Дело: " << i << ". Описание: " << delo[i].description << endl;
					cout << "Дело: " << i << ". День: " << delo[i].day << endl;
					cout << "Дело: " << i << ". Месяц: " << delo[i].month << endl;
					cout << "Дело: " << i << ". Время: " << delo[i].time << endl;
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
		cout << "Выберите поиск" << endl;
		cout << "1. По названию" << endl;
		cout << "2. По приоритету" << endl;
		cout << "3. По описания" << endl;
		cout << "4. По дню, или месяцу" << endl;
		cout << "5. По времени" << endl;
		cout << ">>> ";
		cin >> variant;
		switch (variant) {
		case 1:
			cout << "Введите название: ";
			cin >> name;
			for (int i = 0; i < numbersDelo; i++) {
				if (delo[i].name == name) {
					cout << "Дело: " << i << ". Название: " << delo[i].name << endl;
					cout << "Дело: " << i << ". Приоритет: " << delo[i].priority << endl;
					cout << "Дело: " << i << ". Описание: " << delo[i].description << endl;
					cout << "Дело: " << i << ". День: " << delo[i].day << endl;
					cout << "Дело: " << i << ". Месяц: " << delo[i].month << endl;
					cout << "Дело: " << i << ". Время: " << delo[i].time << endl;
					cout << endl;
				}
			}
			system("pause");
			system("cls");
			break;
		case 2:
			cout << "Введите приоритет: ";
			cin >> priority;
			for (int i = 0; i < numbersDelo; i++) {
				if (delo[i].priority == priority) {
					cout << "Дело: " << i << ". Название: " << delo[i].name << endl;
					cout << "Дело: " << i << ". Приоритет: " << delo[i].priority << endl;
					cout << "Дело: " << i << ". Описание: " << delo[i].description << endl;
					cout << "Дело: " << i << ". День: " << delo[i].day << endl;
					cout << "Дело: " << i << ". Месяц: " << delo[i].month << endl;
					cout << "Дело: " << i << ". Время: " << delo[i].time << endl;
					cout << endl;
				}
			}
			system("pause");
			system("cls");
			break;
		case 3:
			cout << "Введите описание: ";
			cin >> description;
			for (int i = 0; i < numbersDelo; i++) {
				if (delo[i].description == description) {
					cout << "Дело: " << i << ". Название: " << delo[i].name << endl;
					cout << "Дело: " << i << ". Приоритет: " << delo[i].priority << endl;
					cout << "Дело: " << i << ". Описание: " << delo[i].description << endl;
					cout << "Дело: " << i << ". День: " << delo[i].day << endl;
					cout << "Дело: " << i << ". Месяц: " << delo[i].month << endl;
					cout << "Дело: " << i << ". Время: " << delo[i].time << endl;
					cout << endl;
				}
			}
			system("pause");
			system("cls");
			break;
		case 4:
			system("cls");
			cout << "1. По дню" << endl;
			cout << "2. По месяцю" << endl;
			cout << ">>> ";
			cin >> variantTwo;
			if (variantTwo == 1) {
				cout << "Введите день: ";
				cin >> day;
				for (int i = 0; i < numbersDelo; i++) {
					if (delo[i].day == to_string(day)) {
						cout << "Дело: " << i << ". Название: " << delo[i].name << endl;
						cout << "Дело: " << i << ". Приоритет: " << delo[i].priority << endl;
						cout << "Дело: " << i << ". Описание: " << delo[i].description << endl;
						cout << "Дело: " << i << ". День: " << delo[i].day << endl;
						cout << "Дело: " << i << ". Месяц: " << delo[i].month << endl;
						cout << "Дело: " << i << ". Время: " << delo[i].time << endl;
						cout << endl;
					}
				}
			}
			if (variantTwo == 2) {
				cout << "Введите месяц: ";
				cin >> month;
				for (int i = 0; i < numbersDelo; i++) {
					if (delo[i].month == to_string(month)) {
						cout << "Дело: " << i << ". Название: " << delo[i].name << endl;
						cout << "Дело: " << i << ". Приоритет: " << delo[i].priority << endl;
						cout << "Дело: " << i << ". Описание: " << delo[i].description << endl;
						cout << "Дело: " << i << ". День: " << delo[i].day << endl;
						cout << "Дело: " << i << ". Месяц: " << delo[i].month << endl;
						cout << "Дело: " << i << ". Время: " << delo[i].time << endl;
						cout << endl;
					}
				}
			}
			system("pause");
			system("cls");
			break;
		case 5:
			cout << "Введите время: ";
			cin >> time;
			for (int i = 0; i < numbersDelo; i++) {
				if (delo[i].time == to_string(time)) {
					cout << "Дело: " << i << ". Название: " << delo[i].name << endl;
					cout << "Дело: " << i << ". Приоритет: " << delo[i].priority << endl;
					cout << "Дело: " << i << ". Описание: " << delo[i].description << endl;
					cout << "Дело: " << i << ". День: " << delo[i].day << endl;
					cout << "Дело: " << i << ". Месяц: " << delo[i].month << endl;
					cout << "Дело: " << i << ". Время: " << delo[i].time << endl;
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


