


#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	//Display title
	cout << "\t\t\t Word Jumble \n\n";
	cout << "Find the key words. \n";

	bool playAgain = false;
	char userPlayAgainChoice;

	do
	{
		// user rounds
		for (int i = 0; i < 3; i++)
		{
			cout << "\n Round " << i + 1 << " of 5. \n\n";

			enum fields { WORD, HINT, NUM_FIELDS };
			const int NUM_WORDS = 5;
			const string WORDS[NUM_WORDS][NUM_FIELDS] =
			{
				{"wall", "Do you feel you're banging you head against something?"},
				{"glasses", "These might help you see the answer."},
				{"labored","Going slowly, is it?"},
				{"persistent","Keep at it"},
				{"jumble","It's what the game is all about."}
			};
			srand(static_cast<unsigned int>(time(0)));
			int choice = (rand() % NUM_WORDS);
			string theWord = WORDS[choice][WORD];
			string theHint = WORDS[choice][HINT];

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
				cout << " Input correct"
			}
		}


		cout << "\n You have completed 5 rounds and the game is over! \n";

		cout << "\n Would you like to play again? (y/n) ";
		cin >> usersPlayAgainChoice;
		if (usersPlayAgainChoice == 'y')
		{
			playAgain = true;
		}
		else
		{
			playAgain = false;
		}
			
	}
	while (playAgain);

	cout << "\n Thanks for playing. \n";

	return 0;
}