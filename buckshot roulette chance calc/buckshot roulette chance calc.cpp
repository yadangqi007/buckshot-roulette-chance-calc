// buckshot roulette chance calc.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "..\..\Skele_lib\console\Console.hpp"
auto console = SKC::Console::Console(); 
static void promptRoundCount(int& live, int& blank) {
	console.Print("enter the number of live rounds --> ");
	std::cin >> live;
	console.Print("\nenter the number of blank rounds --> ");
	std::cin >> blank;
}
int main(){
	console.Reset();

	int live{}, blank{};
	promptRoundCount(live, blank); 
	int total = live + blank;
	
	while (total > 0) {
		char roundtype = 0;
		double blankChance = floor((double)blank / (double)total * 10000) / 100; 
		double liveChance = floor((double)live / (double)total * 10000) / 100; 
		console.Clear();
		console.SetFGColor(255, 100, 0).Print("live rounds ",live, '\n');
		console.SetFGColor(50, 255, 50).Print("blank rounds ",blank,'\n');
		console.SetFGColor(55, 150, 150).Print("blank chance ", blankChance,"%\n");
		console.SetFGColor(255, 100, 100).Print("live chance ", liveChance,"%\n");
		console.Reset(); 
		console.Print("\n\n[L]ive [B]lank\n");
		std::cin >> roundtype;
		bool isLive = roundtype == 'l' || roundtype == 'L'; 
		bool isBlank = roundtype == 'b' || roundtype == 'B'; 
		if (!(isBlank || isLive)) continue;
		if (isLive && live > 0)  --live; 
		if (isBlank && blank > 0) --blank; 
		--total; 
		 

	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
