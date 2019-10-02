#include <iostream>
using namespace std;

char maze[10][9] = {
	{ '+', '-', '-', '-', '-', '-', '-', '-', '+' },
	{ '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|' },
	{ '|', ' ', '|', ' ', ' ', ' ', '|', ' ', '|' },
	{ '|', ' ', '+', '-', '-', '-', '+', ' ', '|' },
	{ '|', '#', '|', ' ', ' ', ' ', ' ', ' ', '|' },
	{ '|', '-', '+', ' ', '+', ' ', '+', '-', '|' },
	{ '|', ' ', ' ', ' ', '|', ' ', '|', ' ', '|' },
	{ '|', ' ', '|', ' ', '+', '-', '+', ' ', '|' },
	{ '|', 'x', '|', ' ', ' ', ' ', ' ', ' ', '|' },
	{ '+', '-', '-', '-', '-', '-', '-', '-', '+' }
};
int current_x = 1;
int current_y = 8;
bool game_over = false;

int PrintMaze() {
	for(int i = 0; i < 10; i++) {
		for(int j = 0; j < 9; j++) {
			cout << maze[i][j];
		}
		cout << endl;
	}
	return 0;
}

char Move() {
	char move = ' ';
	while(move!='u'&&move!='d'&&move!='l'&&move!='r'&&move!='q') {
		cout << "move with u/d/l/r or quit with q: ";
		cin >> move;
	}
	return move;
}

int GameOver() {
	game_over = true;
	cout << "Game Over!" << endl;
	return 0;
}

int UpdateMaze(char move) {
	if (move == 'u') {
		if (maze[current_y - 1][current_x] == ' ') {
			maze[current_y][current_x] = ' ';
			current_y--;
			maze[current_y][current_x] = 'x';
		} else if(maze[current_y - 1][current_x]=='#') {
			GameOver();
		} else {
			cout << "[error]you cannot move there!" << endl;
		}
	} else if (move == 'd') {
		if (maze[current_y + 1][current_x] == ' ') {
			maze[current_y][current_x] = ' ';
			current_y++;
			maze[current_y][current_x] = 'x';
		} else if(maze[current_y + 1][current_x]=='#') {
			GameOver();
		} else {
			cout << "[error]you cannot move there!" << endl;
		}
	} else if (move == 'l') {
		if (maze[current_y][current_x - 1] == ' ') {
			maze[current_y][current_x] = ' ';
			current_x--;
			maze[current_y][current_x] = 'x';
		} else if(maze[current_y][current_x - 1]=='#') {
			GameOver();
		} else {
			cout << "[error]you cannot move there!" << endl;
		}
	} else if (move == 'r') {
		if (maze[current_y][current_x + 1] == ' ') {
			maze[current_y][current_x] = ' ';
			current_x++;
			maze[current_y][current_x] = 'x';
		} else if(maze[current_y][current_x + 1]=='#') {
			GameOver();
		} else {
			cout << "[error]you cannot move there!" << endl;
		}
	} else if (move == 'q') {
		GameOver();
	} else {
		cout << "something wrong happended!" << endl;
	}

	return 0;
}

int main() {
	while(!game_over) {
		PrintMaze();
		UpdateMaze(Move());
	}
}
