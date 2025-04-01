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

    void invata() {
        std::cout << "invata student: " << nume << std::endl;
    }
};

class StudentLicenta : public Student {
public:
    StudentLicenta(const std::string &nume, int an) : Student(nume, an, true) {
    }

    void distreaza() {
    }
};

class StudentMaster : public Student {
public:
    StudentMaster(const std::string &nume, int an) : Student(nume, an, false) {
    }

    void lucreaza() {
    }
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

    friend std::ostream &operator<<(std::ostream &os, const Profesor &obj) {
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

    friend std::ostream &operator<<(std::ostream &os, const Facultate &obj) {
        os << "nume: " << obj.nume << "\nstudenti: ";
        for (const auto &student: obj.studenti) {
            os << student << ", ";
        }
        os << "\nprofi: ";
        for (const auto &prof: obj.profi)
            os << prof << ", ";
        os << std::endl;
        return os;
    }
};

std::ostream& operator<<(std::ostream& os, const Student& student) {
    os << student.nume << " " << student.grupa << " " << student.chef << std::endl;
    return os;
}

class Baza {
    int *ptr;
    int q = 1;
    std::string abc = "abc";

public:
    virtual void afis(std::ostream &) const {
    }

    friend std::ostream &operator<<(std::ostream &os, const Baza &obj) {
        os
                << "q: " << obj.q
                << " abc: " << obj.abc << "\n";
        obj.afis(os);
        return os;
    }

    virtual ~Baza() {
        std::cout << "destructor baza: " << std::endl;
        delete ptr;
    }

    void f_ok() {
        f_baza();
        g();
        f();
    }

    virtual void f() = 0;

    Baza() {
        std::cout << "constr baza" << std::endl;
        ptr = new int;
    }

protected:
    Baza(const Baza &other) = default;

    Baza &operator=(const Baza &other) = default;

private:
    void f_baza() {
        std::cout << "f baza" << std::endl;
    }

    void g() {
        std::cout << "g baza" << std::endl;
    }
};

class Derivata1 : public Baza {
    int *ptr2;
    int d1 = 3;

public:
    void afis(std::ostream &os) const override {
        os << " d1: " << d1 << "\n";
    }

    Derivata1() {
        ptr2 = new int;
        std::cout << "constr derivata1" << std::endl;
    }

    ~Derivata1() override {
        std::cout << "destructor derivata1" << std::endl;
        delete ptr2;
    }

    void f() override {
        std::cout << "f derivata1" << std::endl;
    }

    void functiaMeaSpecialaCareNuEsteInNaza() {
        std::cout << "g derivata1" << std::endl;
    }
};

class Derivata2 : public Baza {
public:
    void f() override {
        std::cout << "f derivata2" << std::endl;
    }

    void g() {
        std::cout << "g derivata2" << std::endl;
    }
};

class Derivata3 : public Baza {
public:
    void f() override {
        std::cout << "f derivata3" << std::endl;
    }

    void g() {
        std::cout << "g derivata3" << std::endl;
    }
};

class Derivata4 : public Baza {
public:
    void f() override {
        std::cout << "f derivata4" << std::endl;
    }
};

//
// void f1(Baza b) {
//     std::cout << "f1" << std::endl;
//     b.f();
//     b.g();
//     std::cout << "---------" << std::endl;
// }

void f2(Baza *b) {
    std::cout << "f2" << std::endl;
    b->f();
    // b->g();
    // b->h();
    std::cout << "---------" << std::endl;
}

void f3(Baza &b) {
    std::cout << "f3" << std::endl;
    b.f();
    // b.g();
    std::cout << "---------" << std::endl;
}


int main() {
    // Baza b1;
    Derivata1 d;
    //std::cout << d << std::endl;
    Baza &ref = d;
    std::cout << ref << std::endl;
    // return 0;
    // Baza b;
    Derivata1 d1;
    Derivata2 d2;
    Derivata3 d3;
    d.functiaMeaSpecialaCareNuEsteInNaza();
    d.f_ok();
    // f1(b);
    // f1(d1);
    // f1(d2);
    // f1(d3);
    //f2(&b);
    f2(&d1);
    f2(&d2);
    f2(&d3);
    //f3(b);
    f3(d1);
    f3(d2);
    f3(d3);
    StudentLicenta sl1("John", 1);
    StudentLicenta sl2("John", 1);
    sl1.distreaza();
    sl1.invata();
    sl2.distreaza();
    StudentMaster sm1("John", 1);
    StudentMaster sm2("John", 1);
    sm1.lucreaza();
    sm1.invata();
    sm2.lucreaza();
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
