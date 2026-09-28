
#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <algorithm>
#include <cctype>

using namespace std;

void display_playlist(const vector<string>& playlist);

int main() {
    int num_songs = 0;
    vector<string> playlist;

    while (true) {
        cout << "How many songs would you like to add to your playlist (3-10)? ";

        if (cin >> num_songs) {
            if (num_songs >= 3 && num_songs <= 10) {
                break;
            }
            else {
                cout << "Invalid range. Please enter a number between 3 and 10.\n";
            }
        }
        else {
            cout << "Invalid input. That is not a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "\nEnter Your Songs\n";

    for (int i = 0; i < num_songs; ++i) {
        string title;

        cout << "Enter title for song #" << (i + 1) << ": ";
        getline(cin, title);

        playlist.push_back(title);
    }

    display_playlist(playlist);

    char search_choice;

    while (true) {
        cout << "Would you like to search for a song in your playlist? (y/n): ";
        cin >> search_choice;

        search_choice = tolower(search_choice);

        if (search_choice == 'y' || search_choice == 'n') {
            break;
        }

        cout << "Invalid input. Please enter 'y' for yes or 'n' for no.\n";

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    if (search_choice == 'y') {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string search_title;

        cout << "Enter the song title to search for: ";
        getline(cin, search_title);

        bool found = false;

        for (const auto& song : playlist) {
            if (song == search_title) {
                found = true;
                break;
            }
        }

        if (found) {
            cout << "Success! \"" << search_title
                 << "\" was found in your playlist.\n";
        }
        else {
            cout << "Sorry, \"" << search_title
                 << "\" was not found in your playlist.\n";
        }
    }

    cout << "\nThank you for using Playlist Builder!\n";

    return 0;
}

void display_playlist(const vector<string>& playlist) {
    cout << "\nYour Playlist\n";

    for (size_t i = 0; i < playlist.size(); ++i) {
        cout << (i + 1) << ". " << playlist[i] << "\n";
    }

    cout << "\n";
}
