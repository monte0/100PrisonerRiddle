#include <iostream>
#include <array>
#include <random>
#include <chrono>

const int MAX_USERS = 100;
const int MAX_BOXES = 50;

template<typename T>
void printThis(const T& ar)
{
	for (int i = 0; i < MAX_USERS; i++)
	{
		if (i % 10 == 0 && i != 0)
		{
			std::cout << std::endl;
		}
		std::cout << ar[i] << "\t";
	}
	std::cout << "\n";
}

//randomizes boxes
void mixBoxes(std::array<int,MAX_USERS> &ar)
{
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	shuffle(ar.begin(), ar.end(), std::default_random_engine(seed));
}

//searches through 50 boxes to find an index, returns true or false.
int open50Boxes(std::array<int, MAX_USERS>& boxes, int startIndex)
{
	int nextIndex = startIndex;
	for (int i = 0; i < MAX_BOXES; i++)
	{
		if (boxes[nextIndex] == startIndex)
		{
			return 1;
		}
		nextIndex = boxes[nextIndex];
	}
	return -1;
}

//each user looks for thier number, returns false if out of 50 limit.
//true if they all find their number
bool tryOnce(std::array<int, MAX_USERS>& boxs, std::array<int, MAX_USERS>& people)
{
	for (int i = 0; i < MAX_USERS; i++)
	{
		people[i] = open50Boxes(boxs, i);
		if (people[i] == 1)
		{
			continue;
		}
		if (people[i] == -1)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	std::array<int, MAX_USERS> prisoners;
	std::array<int, MAX_USERS> boxes;
	double count = 0;
	double wins = 0;
	int losses = 0;

	for (int i = 0; i < MAX_USERS; i++)
	{
		boxes[i] = i;
	}
	for (int i = 0; i < 10000000; i++)
	{
		mixBoxes(boxes);
		bool tmp = tryOnce(boxes, prisoners);
		if (tmp == true)
		{
			wins++;
		}
		else
		{
			losses++;
		}
		count++;
		double percent = wins / count;

		switch (int(count))
		{
		case 10:
			std::cout << count << " Passed : " << wins << "\t\t Failed : " << losses << ": " << percent << std::endl;
			break;
		case 100: 
			std::cout << count << " Passed : " << wins << "\t\t Failed : " << losses << ": " << percent << std::endl;
			break;
		case 1000:
			std::cout << count << " Passed : " << wins << "\t\t Failed : " << losses << ": " << percent << std::endl;
			break;
		case 10000:
			std::cout << count << " Passed : " << wins << "\t\t Failed : " << losses << ": " << percent << std::endl;
			break;
		case 100000:
			std::cout << count << " Passed : " << wins << "\t\t Failed : " << losses << ": " << percent << std::endl;
			break;
		case 1000000:
			std::cout << count << " Passed : " << wins << "\t\t Failed : " << losses << ": " << percent << std::endl;
			break;
		case 10000000:
			std::cout << count << " Passed : " << wins << "\t\t Failed : " << losses << ": " << percent << std::endl;
			break;
		default:
			break;
		}
			
	}
	std::cin.get();
}