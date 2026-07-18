#include <iostream>
#include <cstdlib>
#include <limits>
#include <ctime>
#include "Utility.h"

void clearScreen()
{
	system("cls");
}

void pauseScreen(const std::string& message)
{
	std::cout << '\n' << message;
	std::cin.get();
}

int getMenuOption(int min, int max)
{
	int option;

	while (true)
	{
		if (std::cin >> option)
		{
			if (option >= min && option <= max)
			{
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				return option;
			}
		}

		std::cout << "The input is invalid. Please try again." << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
}

void displayTitle(const std::string& title)
{
	std::cout << "=======================================================================\n";
	std::cout << title << std::endl;
	std::cout << "=======================================================================\n";
}

std::string getCurrentDate()
{
	time_t now = time(nullptr);

	tm localTime{};

	localtime_s(&localTime, &now);

	char buffer[11];

	strftime(buffer, sizeof(buffer), "%Y-%m-%d", &localTime);

	return std::string(buffer);
}
