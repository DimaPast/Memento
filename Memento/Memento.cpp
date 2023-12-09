#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>


class Memento {
private:
    std::string state;

public:
    Memento(const std::string& s) : state(s) {}

    std::string getState() const {
        return state;
    }
};


class Originator {
private:
    std::string state;

public:
    void setState(const std::string& s) {
        state = s;
    }

    std::string getState() const {
        return state;
    }

    Memento createMemento() const {
        return Memento(state);
    }

    void restoreMemento(const Memento& m) {
        state = m.getState();
    }

    void appendText(const std::string& text) {
        state += " " + text; 
    }

    void displayState() const {
        std::cout << "Поточний стан: " << state << std::endl;
    }
};


class Caretaker {
private:
    std::vector<Memento> mementos;

public:
    void addMemento(const Memento& m) {
        mementos.push_back(m);
    }

    Memento getMemento(int index) const {
        if (index >= 0 && index < mementos.size()) {
            return mementos[index];
        }
        else {
           
            return Memento("");
        }
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Originator originator;
    Caretaker caretaker;

    
    originator.setState("Привіт,");
    originator.displayState();
    caretaker.addMemento(originator.createMemento());

  
    originator.appendText("як справи?");
    originator.displayState();
    caretaker.addMemento(originator.createMemento());

    
    Memento memento1 = caretaker.getMemento(0);
    originator.restoreMemento(memento1);
    originator.displayState();

  
    Memento memento2 = caretaker.getMemento(1);
    originator.restoreMemento(memento2);
    originator.displayState();

    return 0;
}
