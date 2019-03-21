// Ух.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <string>

struct PERSON // Структура с функцией вывода информации о студентах.
{
	std::string surname;
	std::string initials;
	std::string FAC;

	struct GROUP
	{
		std::string initials_of_group;
		int number_of_group;
	}G;

	int Date[2];

	void OUTPUT(PERSON *student, int n)
	{
		std::cout << "Name - " << surname << initials << "\n";
		std::cout << "FAC - " << FAC << "\n";
		std::cout << "Group - " << G.initials_of_group << G.number_of_group << "\n";
		std::cout << "Date - " << Date[0] << "." << Date[1] << "." << Date[2] << "\n";
	}
};

void INPUT(PERSON *student, int n) // Функция ввода данных 
{
	for (size_t i = 0; i < n; i++)
	{
		std::cout << "Enter surname: ";
		std::cin >> student[i].surname;

		std::cout << "Enter initials: ";
		std::cin >> student[i].initials;

		std::cout << "Enter FAC: ";
		std::cin >> student[i].FAC;

		std::cout << "Enter information about the group: " << "\n";
		std::cout << "Initials of the group: ";
		std::cin >> student[i].G.initials_of_group;
		std::cout << "Number of the group: ";
		std::cin >> student[i].G.number_of_group;

		std::cout << "Enter date (day, month, year): " << "\n";
		std::cin >> student[i].Date[0];
		std::cin >> student[i].Date[1];
		std::cin >> student[i].Date[2];

	}
}

void SWAP(PERSON *student, int i, int j) // Реализация функции 
{
	PERSON swap;

	swap = student[i];
	student[i] = student[j];
	student[j] = swap;
}

void DATE_SORT(PERSON *student, int n) // Сортировка информации по дате
{
	for (size_t i = 0; i < n + 1; i++)
	{
		for (size_t j = i + 1; j < n; j++)
		{
			if (student[i].Date[2] == student[j].Date[2])
			{
				if (student[i].Date[1] == student[j].Date[1])
				{
					if ((student[i].Date[0] > student[j].Date[0]) || (student[i].Date[0] < student[j].Date[0]))
					{
						SWAP(student, i, j); // вызов функции, меняющей местами студентов по дате
					}
				}
				else if (student[i].Date[1] > student[j].Date[1])
				{
					SWAP(student, i, j);
				}
			}
			else if (student[i].Date[2] > student[j].Date[2])
			{
				SWAP(student, i, j);
			}
		}
	}
}

void sort_name(PERSON *student, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (strcmp(student[i].surname.c_str(), student[j].surname.c_str()) > 0)
			{
				SWAP(student, i, j);
			}
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	const int n = 4;
	PERSON *student = new PERSON[n];

	std::cout << "Enter the information about student:" << "\n";

	INPUT(student, n);

	DATE_SORT(student, n);
	std::cout << "Сортировка по дате: " << "\n" << "\n";

	for (size_t i = 0; i < n; i++) // Вывод отсортированной информации
	{
		student[i].OUTPUT(student, n);
	}

	sort_name(student, n);

	for (size_t i = 0; i < n; i++) // Вывод отсортированной информации
	{
		student[i].OUTPUT(student, n);
	}
}



