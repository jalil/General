#include <iostream>

using namespace std;

int main(int argc, const char *argv[]) {
	int i;
	cout << "Hi! I'm a soda machine. Here are my choices:\n1 -> Coke\n2 -> Sprite\n3 -> Water\n4 -> Ginger Ale\n5 -> Sam Adams What number do you want?\n->";
	cin >> i;

	switch(i) {
		case 1:
			cout << "Here's your Coke!" << endl;
			break;
		case 2: 
			cout << "Here's your Sprite!" << endl;
			break;
		case 3: 
			cout << "Here's your water!" << endl;
			break;
		case 4: 
			cout << "Here's your Ginger Ale!" << endl;
			break;
		case 5:
			cout << "Out of order. I'm a cola machine; not a beer tap!" << endl;
			break;
		default:
			cout << "Please insert a value between 1 and 5. There are no other drinks available at this time!" << endl;
			break;
	}

	return 0;
}

