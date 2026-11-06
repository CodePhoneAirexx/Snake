#include <array>
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

void ClearScreen();

class Snake {
private:
	int length; // Длина змейки
	short appleX{}; // Координат яблока по оси X
	short appleY{}; // Координат яблока по оси Y
	short snakeX{}; // Координат змейки по оси X
	short snakeY{}; // Координат змейки по оси Y
public:
    explicit Snake(int initialLength) : length(initialLength) {
        display();
    }

    void display() const {
        for (int i = 0; i < length; ++i) {
            cout << (i == length - 1 ? "[)" : "[]");
        }
        cout << '\n';
    }

    void grow() {
        ++length;
    }

    void AppleSpawn() {
        appleX = static_cast<short>(rand() % 20);
        appleY = static_cast<short>(rand() % 10);

		for (int i = 0; i == appleX; ++i) {
            cout << " ";
		}
		for (int j = 0; j == appleY; ++j) {
			cout << "\n";
		}
        cout << "()";
    }

    void move() {
        ClearScreen();
        cout << ' ';
        display();
    }

    array<short, 4> Coordinations() {
        return { appleX, appleY, snakeX, snakeY };
    }
};

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    Snake mySnake(3);
    mySnake.AppleSpawn();

    char input{};

    while (cin >> input) {
        switch (input) {
        case 'd':
        case 'D':
            mySnake.Coordinations();
            break;

        case 'q':
        case 'Q':
            return 0;

        default:
            cout << "Используйте D для движения или Q для выхода.\n";
            break;
        }
    }

    return 0;
}

void ClearScreen() {
    cout << "\033[2J\033[1;1H";
}