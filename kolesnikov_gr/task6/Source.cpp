#include <BnC.h>
using namespace std;
int BnC::count = 0;
void main()
{
	srand(time(NULL));
	BnC Game;
	bool win = 0;
	int length = 5;
	cout << "Enter the Length";
	cin >> length;
	Game.SetLenght(length);
	Game.SetNumber();
	while (!win)
	{
		Game.Guessing();
		win = Game.WinCheck();
		BnC::count++;
		cout << BnC::count << " attempt" << endl;
	}
	BnC::count = 0;
	cout << endl;
	cin >> win;
}
