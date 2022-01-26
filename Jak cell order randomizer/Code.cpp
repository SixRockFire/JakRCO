#include <iostream>
#include <time.h>
using namespace std;

const int CELLCOUNT = 94, HUBONE = 34;

int main() {
	srand(time(0));
	string cells[CELLCOUNT] = {
		"Geyser: Cell on path",
		"Geyser: Scout flies",
		"Geyser: Open blue eco door",
		"Geyser: Climb the cliff",
		"Sandover: Yakows",
		"Sandover: Mayor orbs",
		"Sandover: Uncle orbs",
		"Sandover: Oracle orbs",
		"Sandover: Oracle orbs",
		"Sandover: Scout flies",
		"Sentinel: Pelican",
		"Sentinel: Cannon",	
		"Sentinel: Middle sentinel",
		"Sentinel: Green eco cloggers",
		"Sentinel: Seagulls",
		"Sentinel: Flut flut egg",
		"Sentinel: Explore the beach",
		"Sentinel: Scout flies",
		"FJ: Mirrors",
		"FJ: Fish",
		"FJ: Swim to island",
		"FJ: Locked blue eco door",
		"FJ: Open blue eco vent",
		"FJ: Top of tower",
		"FJ: Plant boss",
		"FJ: Scout flies",
		"Misty: Pillar platform",
		"Misty: Cannon",
		"Misty: Ambush",
		"Misty: On top of ship",
		"Misty: Zeppelins",
		"Misty: Wooden ramp",
		"Misty: Scout flies",
		"Misty: Muse",
		"FC: Scout flies",
		"FC: Reach end",
		"Rock Village: Gambler orbs",
		"Rock Village: Geologist orbs",
		"Rock Village: Warrior orbs",
		"Rock Village: Oracle orbs",
		"Rock Village: Oracle orbs",
		"Rock Village: Scout flies",
		"Basin: Moles",
		"Basin: Race",
		"Basin: Over the lake",
		"Basin: Plants",
		"Basin: Purple rings",
		"Basin: Blue rings",
		"Basin: Flying lurkers",
		"Basin: Scout flies",
		"LPC: Pipe cell",
		"LPC: Circle room",
		"LPC: Puzzle",
		"LPC: Piggyback tm",
		"LPC: Far side of pool",
		"LPC: Bottom of city",
		"LPC: Raise the chamber",
		"LPC: Scout flies",
		"Boggy: Tether cell 1",
		"Boggy: Tether cell 2",
		"Boggy: Tether cell 3",
		"Boggy: Tether cell 4",
		"Boggy: Rats",
		"Boggy: Ride Flut Flut",
		"Boggy: Ambush",
		"Boggy: Scout flies",
		"Mountain pass: Klaww",
		"Mountain pass: Secret cell",
		"Mountain pass: Reach end",
		"Mountain pass: Scout Flies",
		"VC: Miners",
		"VC: Miners",
		"VC: Miners",
		"VC: Miners",
		"VC: Oracle orbs",
		"VC: Oracle orbs",
		"VC: Secret cell",
		"VC: Scout flies",
		"Spider Cave: Gnawing lurkers",
		"Spider Cave: Dark eco crystals",
		"Spider Cave: Dark cave",
		"Spider Cave: Top of robot",
		"Spider Cave: Poles",
		"Spider Cave: Spider tunnel",
		"Spider Cave: Platforms",
		"Spider Cave: Scout flies",
		"Snowy: Yellow vent",
		"Snowy: Glacier troops",
		"Snowy: Blockers",
		"Snowy: Secret cell",
		"Snowy: Fortress door",
		"Snowy: Fortress",
		"Snowy: Lurker cave",
		"Snowy: Scout flies" };


	bool duplicate[CELLCOUNT] = { false };

	for (int i = 0; i < 4; i++) { // This just randomizes geyser cell order, since you have to get all 4
		int cellNumber = rand() % 4;
		if (duplicate[cellNumber])
			i--;
		while (duplicate[cellNumber] == false) {
			cout << i + 1 << ". " << cells[cellNumber] << endl;
			duplicate[cellNumber] = true;
		}
	}
	
	int orbCells = 0;
	bool impossiblePurchase = false;

	for (int i = 0; i < 16; i++) { // Hub one cells, ain't nobody doing FCS for this.
			int cellNumber;
			do {
				do {
					if (duplicate[19])
						cellNumber = rand() % HUBONE;
					else cellNumber = rand() % (HUBONE - 8); // This prevents you from getting misty cells before doing fish.
					if (duplicate[19] == false && orbCells == 3 && cellNumber == 7 || cellNumber == 8)
						impossiblePurchase == true;
				} while (duplicate[23] == false && cellNumber == 22 || cellNumber == 24); // This prevents you from getting cells inside temple before top of tower.
			} while (impossiblePurchase);
				if (duplicate[cellNumber])
				i--;
			if (cellNumber > 4 && cellNumber < 9) // This keeps track of how many cells you've been given that require buying.
				orbCells++;
			while (duplicate[cellNumber] == false) {
				cout << i + 5 << ". " << cells[cellNumber] << endl;
				duplicate[cellNumber] = true;
			}
		}

	int FCcheck = 0;

	for (int i = 0; i < 52; i++) {
		int cellNumber;
		do {
			do {
				do {
					if (duplicate[35] == false) // This makes sure you don't get hub 2/3 cells before "reach the end of fire canyon".
						cellNumber = rand() % 36;
					else if ((i-FCcheck) <= 2) // This is just so that you don't get snowy cells before you've been able to unlock gondola, aka 2 cells after FC.
						cellNumber = rand() % (CELLCOUNT - 8); 
					else cellNumber = rand() % CELLCOUNT;
				} while (duplicate[19] == false && cellNumber >= (HUBONE - 8) && cellNumber < HUBONE); // Again, no misty cells before fish.
			} while (duplicate[23] == false && cellNumber == 22 || cellNumber == 24); // Again, no temple before top of tower.
		} while (duplicate[46] == false  && cellNumber == 47); // This makes sure you don't get blue rings before purple rings.
		if (cellNumber == 35)
			FCcheck = i;
		if (duplicate[cellNumber])
			i--;
			while (duplicate[cellNumber] == false) {
				cout << i + 21 << ". " << cells[cellNumber] << endl;
				duplicate[cellNumber] = true;
			}
		}
	
	return 0;
}