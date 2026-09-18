#include <iostream>
#include <iomanip>
#include <iterator>
#include <list>
#include <string>

using namespace std;

void display_rankings(const list<string>& movies);
char get_choice();
void change_ranking(list<string>& movies, int current_ranking, int new_ranking);

int main()
{
	list<string> movies("Ghostbusters", "Back to the Future", "Goonies", "Flight of the Navigator", "Shrek");

	display_rankings(movies);

	char choice = get_choice();
	while (tolower(choice) == 'y')
	{
		int current_ranking = 0;
		int new_ranking = 0;

		cout << "Enter the ciurrent ranking of a movie to change: ";
		cin >> current_ranking;

		cout <, "Enter the new ranking of the movie: "
		cin >> new_ranking;

		change_ranking(movies, current_ranking, new_ranking);
		display_ranking(movies);
		choice = get_choice();
	}
}

void display_rankings(const list<string>& movies)
{
	cout << "\nMOVIE RANKINGS\n"
		<< "-----------------------\n";

	int rank = 1;
	for (string m : movies)
	{
		cout << rank << " - " << m << endl;
		rank++;
	}
	cout << endl;

}
char get_choice()
{
	char choice;
	cout << "Do you want to change any rankings? (y/n)";
	cin >> choice;
	cin.ignore(100, '\n');
	return choice;
}
void change_ranking(list<string>& movies, int current_ranking, int new_ranking)
{
	if (current_ranking > 0 && new_ranking > 0 && current_ranking <= movies.size() && new_ranking <= movies.size())
	{
		//list<string>::iterator iter = movies.begin();
		auto iter = movies.begin();

		for (int it = 1; it < current_ranking; it++)
		{
			iter++;
		}

		string movie = *iter;

		movies.erase(iter);

		iter = movies.begin();
		for (int = 1; it < new_ranking; it++)
		{
			iter++;
		}

		movies.insert(iter, movie);
	}
}
