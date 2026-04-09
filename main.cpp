#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct weapon {
	string name;
	int damage;
};
// =========== NHAP VU KHI =============
void nhapds(vector<weapon> &weapons) {
	int n; cin >> n;
	cin.ignore();
	string name; int damage;
	for (int i = 0; i < n; i++) {
		getline(cin,name);
		cin >> damage;
		cin.ignore();
		weapons.push_back({name, damage});
	}
}
// ============ DS VU KHI ===========
void hien_thi(const vector<weapon> &weapons) {
	cout << left << setw(5) << "ID" << left << setw(5) << "NAME" << left << setw(20) << "DAMAGE" << endl;
	cout << "----------------------------\n";
	for (int i = 0; i < weapons.size(); i++) {
		cout << left << setw(5) << i + 1 << left << setw(5) << weapons[i].name << left << setw(20) <<
			weapons[i].damage << endl;
	}
}
// ========== TIM VU KHI ============
void timVK(const vector<weapon> &weapons) {
	string find; getline(cin,find);
	bool found = false;
	for (int i = 0; i < weapons.size(); i++) {
		if (weapons[i].name == find) {
			cout << "Da tim thay vu khi: " << weapons[i].name << "! Sat thuong gay ra: " << weapons[i].damage << endl;
			found = true;
		}
	}
	if (!found) cout << "Khong tim thay vu khi.\n";
}

// ======= VU KHI MANH NHAT =======
void manhNhat(const vector<weapon> &weapons) {
	if (weapons.empty()) {
		cout << "Danh sach rong!\n";
	}
	else {
		int max = weapons[0].damage;
		int index = 0;
		for (int i = 1; i < weapons.size(); i++) {
			if (weapons[i].damage > max) {
				max = weapons[i].damage;
				index = i;
			}
		}
		cout << "Vu khi manh nhat la: " << weapons[index].name << "| Sat thuong: " << max << endl;
	}
}

// ======== THEM VU KHI ========
void them(vector<weapon> &weapons) {
	string name; int damage;
	cout << "=== THEM VU KHI ===\n";
	cout << "Ten: "; getline(cin,name);
	cout << "Damage: "; cin >> damage;
	cin.ignore();
	weapons.push_back({name, damage});
}

// ======= XOA VU KHI =======
void xoa(vector<weapon> &weapons) {
	if (weapons.empty()) {
		cout << "Danh sach rong!\n";
	}
	else {
		hien_thi(weapons);
		int id;
		cout << "Nhap ID ban muon xoa: ";
		cin >> id;
		cin.ignore();
		if (id < 1 || id > weapons.size()) {
			cout << "ID khong hop le!\n";
		} else {
			weapons.erase(weapons.begin() + id - 1);
			cout << "Da xoa thanh cong!\n";
		}
		hien_thi(weapons);
	}
}
int main() {
	vector<weapon> weapons;
	int choice;
	do {
		cin >> choice;
		cin.ignore();
		switch (choice) {
			case 1: {
				nhapds(weapons);
				break;
			}
			case 2: {
				hien_thi(weapons);
				break;
			}
			case 3: {
				timVK(weapons);
				break;
			}
			case 4: {
				manhNhat(weapons);
				break;
			}
			case 5: {
				them(weapons);
				break;
			}
			case 6: {
				xoa(weapons);
				break;
			}
		}
	}while(choice != 0);
}