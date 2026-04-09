#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

class Weapon {
private:
	string name;
	int damage;
public:
	Weapon(string n = "", int d = 0) : name(n), damage(d) {}
	string getName() const {
		return name;
	}
	int getDamage() const {
		return damage;
	}
	void display() const {
		cout << left << setw(10) << name << damage << endl;
	}
};

class WeaponManager {
	private:
	vector<Weapon> weapons;
	public:
	void input() {
		int n; cin >> n;
		cin.ignore();
		for (int i = 0; i < n; i++) {
			string name; int damage;
			getline(cin, name);
			cin >> damage;
			cin.ignore();
			weapons.push_back({name, damage});
		}
	}
	void display() const {
		if (weapons.empty()) {
			cout << "Danh sach rong\n";
			return;
		}
		cout << left << setw(5) << "ID" << left << setw(10) << "NAME" << "DAMAGE" << endl;
		cout << "----------------------\n" << endl;
		for (int i = 0; i < weapons.size(); i++) {
			cout << left << setw(5) << i + 1;
			weapons[i].display();
		}
	}
	void add() {
		string name; int damage;
		getline(cin, name);
		cin >> damage;
		cin.ignore();
		weapons.push_back({name, damage});
	}
	void strongest() {
		if (weapons.empty()) return;
		int maxDamage = weapons[0].getDamage();
		int index = 0;
		for (int i = 1; i < weapons.size(); i++) {
			if (weapons[i].getDamage() > maxDamage) {
				maxDamage = weapons[i].getDamage();
				index = i;
			}
		}
		cout << weapons[index].getName() << " strongest" << " with damage: " << weapons[index].getDamage() << endl;
	}
};
int main() {
	WeaponManager wm;
	int choice;
	do {
		cin >> choice;
		cin.ignore();
		switch (choice) {
			case 1: wm.input(); break;
			case 2: wm.display(); break;
			case 3: wm.add(); break;
			case 4: wm.strongest(); break;
		}
	} while (choice != 0);
}

// Làm thêm TÌM, XÓA vũ khí.
// Học làm việc với file ngoài.