


#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	//Display title
	cout << "\t\t\t Mythology Jumble \n\n";
	cout << " Unjumble the names of the Gods \n";

		// user rounds
		for (int i = 0; i < 3; i++)
		{
			cout << "\n Round " << i + 1 << " of 3. \n\n";

			enum fields { WORD, HINT, NUM_FIELDS };
			const int NUM_WORDS = 10;
			const string WORDS[NUM_WORDS][NUM_FIELDS] =
			{
				{"Zeus"," King of Olympus "}, //1
				{"Posiden"," King of the Seven Seas "}, //2 
				{"Hades"," King of the Underworld "}, //3
				{"Ares"," God of War "}, //4
				{"Athena"," Goddess of Wisdom "}, //5
				{"Hephaestus"," God of Blacksmiths "}, //6
				{"Aphrodite"," Goddess of Love "}, //7
				{"Dionysus"," God of Wine "}, //8
				{"Artemis"," Goddess of Hunting "}, //9
				{"Apollo"," God of Music "}, //10
			};

			srand(static_cast<unsigned int>(time(0)));
			int choice = (rand() % NUM_WORDS);
			string theWord = WORDS[choice][WORD];
			string theHint = WORDS[choice][HINT];
//----------------------------------------------------------------
			string jumble = theWord;
			int length = jumble.size();
			for (int i = 0; i < length; ++i)
			{
				int index1 = (rand() % length);
				int index2 = (rand() % length);
				char temp = jumble[index1];
				jumble[index1] = jumble[index2];
				jumble[index2] = temp;
			}

			cout << "Enter 'hint' for a hint. \n";
			cout << "Enter 'quit' to quit the game. \n\n";
			cout << "The jumble is: " << jumble;

			string guess;
			cout << "\n\n Your guess: ";
			cin >> guess;
//----------------------------------------------------------------
			while ((guess != theWord) && (guess != "quit"))
			{
				if (guess == "hint")
				{
					cout << theHint;
				}
				else
				{
					cout << "Sorry, that's not it.";
				}
				cout << "\n\n Your guess: ";
				cin >> guess;
			}

			if (guess == theWord)
			{
				cout << " Input correct";
			}
		}
//----------------------------------------------------------------
		cout << "\n Go in knowledge of the Greek Gods \n";
//----------------------------------------------------------------
	cout << "\n Go forth in the name of Olympus \n";

	return 0;
}