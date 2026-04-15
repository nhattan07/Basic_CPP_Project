#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

class Weapon {
private:
    string name;
    int damage;
public:
    Weapon(string n = "", int d = 0) : name(n), damage(d) {}

    string getName() const { return name; }
    int getDamage() const { return damage; }

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
        cout << left << setw(5) << "ID" << setw(10) << "NAME" << "DAMAGE\n";
        cout << "----------------------\n";
        for (int i = 0; i < weapons.size(); i++) {
            cout << left << setw(5) << i + 1;
            weapons[i].display();
        }
    }

    void add() {
        string name; int damage;
        cout << "Nhap ten: ";
        getline(cin, name);
        cout << "Nhap damage: ";
        cin >> damage;
        cin.ignore();
        weapons.push_back({name, damage});
    }

    void strongest() {
        if (weapons.empty()) return;

        int index = 0;
        for (int i = 1; i < weapons.size(); i++) {
            if (weapons[i].getDamage() > weapons[index].getDamage()) {
                index = i;
            }
        }

        cout << weapons[index].getName()
             << " strongest with damage: "
             << weapons[index].getDamage() << endl;
    }

    void xoaVK() {
        if (weapons.empty()) return;

        display();
        cout << "Nhap ID can xoa: ";
        int id; cin >> id;
        cin.ignore();

        if (id < 1 || id > weapons.size()) {
            cout << "ID khong hop le!\n";
            return;
        }

        weapons.erase(weapons.begin() + id - 1);
        cout << "Da xoa!\n";
    }

    void suaVK() {
        if (weapons.empty()) return;

        display();
        cout << "Nhap ID can sua: ";
        int id; cin >> id;
        cin.ignore();

        if (id < 1 || id > weapons.size()) {
            cout << "ID khong hop le!\n";
            return;
        }

        string name; int damage;
        cout << "Ten moi: ";
        getline(cin, name);
        cout << "Damage moi: ";
        cin >> damage;
        cin.ignore();

        weapons[id - 1] = Weapon(name, damage);
        cout << "Da cap nhat!\n";
    }

    string toLower(string s) {
        for (char &c : s) c = tolower(c);
        return s;
    }

    void timVK() {
        if (weapons.empty()) return;

        string name;
        cout << "Nhap ten can tim: ";
        getline(cin, name);

        string key = toLower(name);
        bool found = false;

        for (auto &w : weapons) {
            if (toLower(w.getName()) == key) {
                w.display();
                found = true;
            }
        }

        if (!found) cout << "Khong tim thay!\n";
    }

    void sortByDamage() {
        sort(weapons.begin(), weapons.end(),
            [](Weapon a, Weapon b) {
                return a.getDamage() > b.getDamage();
            });

        cout << "Da sap xep!\n";
    }
};

int main() {
    WeaponManager wm;
    int choice;

    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Nhap danh sach\n";
        cout << "2. Hien thi\n";
        cout << "3. Them weapon\n";
        cout << "4. Strongest\n";
        cout << "5. Xoa weapon\n";
        cout << "6. Sua weapon\n";
        cout << "7. Tim kiem\n";
        cout << "8. Sap xep damage\n";
        cout << "0. Thoat\n";
        cout << "Chon: ";

        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: wm.input(); break;
            case 2: wm.display(); break;
            case 3: wm.add(); break;
            case 4: wm.strongest(); break;
            case 5: wm.xoaVK(); break;
            case 6: wm.suaVK(); break;
            case 7: wm.timVK(); break;
            case 8: wm.sortByDamage(); break;
        }
    } while (choice != 0);
};