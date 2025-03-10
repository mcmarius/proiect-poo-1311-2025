#include <iostream>
#include <array>

#include <Helper.h>
#include <ostream>
#include <vector>

class Student {
    std::string nume;
    int grupa;
    bool chef;

public:
    Student(const std::string &nume, int grupa, bool chef)
        : nume(nume),
          grupa(grupa),
          chef(chef) {
        std::cout << "constr init student: " << nume << std::endl;
    }

    ~Student() {
        std::cout << "destr student " << nume << std::endl;
    }

    Student(const Student &other)
        : nume(other.nume),
          grupa(other.grupa),
          chef(other.chef) {
        std::cout << "cc student: " << nume << std::endl;
    }

    Student& operator=(const Student &other) {
        if (this == &other)
            return *this;
        nume = other.nume;
        grupa = other.grupa;
        chef = other.chef;
        std::cout << "op= student: " << nume << std::endl;
        return *this;
    }
    friend std::ostream& operator<<(std::ostream& os, const Student& student);
};

class Profesor {
    std::string nume;
    short salariu;

public:
    Profesor(const std::string &nume, short salariu)
        : nume(nume),
          salariu(salariu) {
        std::cout << "constr init profesor: " << nume << std::endl;
    }

    friend std::ostream & operator<<(std::ostream &os, const Profesor &obj) {
        return os
               << "nume: " << obj.nume
               << " salariu: " << obj.salariu;
    }
};

class Facultate {
    std::string nume;
    std::vector<Student> studenti;
    std::vector<Profesor> profi;

public:
    Facultate() = default;

    explicit Facultate(const std::string &nume)
        : nume(nume) {
    }

    Facultate(const std::string &nume, const std::vector<Student> &studenti, const std::vector<Profesor> &profi)
        : nume(nume),
          studenti(studenti),
          profi(profi) {
    }

    friend std::ostream & operator<<(std::ostream &os, const Facultate &obj) {
        os
               << "nume: " << obj.nume
               << "\nstudenti: ";
        for (const auto& student : obj.studenti) {
            os << student << ", ";
        }
               os << "\nprofi: ";
        for (const auto& prof : obj.profi)
            os << prof << ", ";
        os << std::endl;
        return os;
    }
};

std::ostream& operator<<(std::ostream& os, const Student& student) {
    os << student.nume << " " << student.grupa << " " << student.chef << std::endl;
    return os;
}

int main() {

    Student st1{"abc", 131, true}, st2(st1), st3(st2);
    Profesor p1("abc", 1);
    Facultate f1("fmi", {st1}, {p1});
    //st1 = st2 = st3;
    //st1.operator=(st2.operator=(st3));
    std::cout << "Ce frumos e afară când nu sunt bormașini!\n";
    operator<<(std::cout, "Ce \"frumos\" e C++...\n");
    // (std::cout << st1) << st2;
    std::cout << st1 << st2 << f1;
    operator<<(operator<<(std::cout, st1), st2);
    std::array<int, 100> v{};
    int nr;
    std::cout << "Introduceți nr: ";
    /////////////////////////////////////////////////////////////////////////
    /// Observație: dacă aveți nevoie să citiți date de intrare de la tastatură,
    /// dați exemple de date de intrare folosind fișierul tastatura.txt
    /// Trebuie să aveți în fișierul tastatura.txt suficiente date de intrare
    /// (în formatul impus de voi) astfel încât execuția programului să se încheie.
    /// De asemenea, trebuie să adăugați în acest fișier date de intrare
    /// pentru cât mai multe ramuri de execuție.
    /// Dorim să facem acest lucru pentru a automatiza testarea codului, fără să
    /// mai pierdem timp de fiecare dată să introducem de la zero aceleași date de intrare.
    ///
    /// Pe GitHub Actions (bife), fișierul tastatura.txt este folosit
    /// pentru a simula date introduse de la tastatură.
    /// Bifele verifică dacă programul are erori de compilare, erori de memorie și memory leaks.
    ///
    /// Dacă nu puneți în tastatura.txt suficiente date de intrare, îmi rezerv dreptul să vă
    /// testez codul cu ce date de intrare am chef și să nu pun notă dacă găsesc vreun bug.
    /// Impun această cerință ca să învățați să faceți un demo și să arătați părțile din
    /// program care merg (și să le evitați pe cele care nu merg).
    ///
    /////////////////////////////////////////////////////////////////////////
    std::cin >> nr;
    /////////////////////////////////////////////////////////////////////////
    for(int i = 0; i < nr; ++i) {
        std::cout << "v[" << i << "] = ";
        std::cin >> v[i];
    }
    std::cout << "\n\n";
    std::cout << "Am citit de la tastatură " << nr << " elemente:\n";
    for(int i = 0; i < nr; ++i) {
        std::cout << "- " << v[i] << "\n";
    }
    ///////////////////////////////////////////////////////////////////////////
    /// Pentru date citite din fișier, NU folosiți tastatura.txt. Creați-vă voi
    /// alt fișier propriu cu ce alt nume doriți.
    /// Exemplu:
    /// std::ifstream fis("date.txt");
    /// for(int i = 0; i < nr2; ++i)
    ///     fis >> v2[i];
    ///
    ///////////////////////////////////////////////////////////////////////////
    ///                Exemplu de utilizare cod generat                     ///
    ///////////////////////////////////////////////////////////////////////////
    Helper helper;
    helper.help();
    ///////////////////////////////////////////////////////////////////////////
    return 0;
}
