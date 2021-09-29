//
// Created by flamy on 28/09/21.
//

#include "Printed.Circuit.Board.h"

namespace Lab3A {
    printedCircuitBoard::Contact::Contact() {
        type = notStated;
        x = 0;
        y = 0;
        numberOfContact = -1;
    }

    printedCircuitBoard::Contact::Contact(contactType t, int x, int y) {
        if (t != 0 && t != 1)
            throw std::invalid_argument("Incorrect type of contact!");
        type = t;
        this->x = x;
        this->y = y;
        numberOfContact = -1;
    }

    printedCircuitBoard::Contact printedCircuitBoard::inputContact() {
        int x, y, t;
        contactType type;
        std::cout << "Enter type of contact (0 for input, 1 for output): --> ";
        checkInput(t);
        type = isCorrectType(t);
        std::cout << "Enter the first coordinate of contact: --> ";
        checkInput(x);
        std::cout << "Enter the second coordinate of contact: --> ";
        checkInput(y);
        Contact c (type, x, y);
        return c;
    }

    contactType printedCircuitBoard::isCorrectType(int t) {
        if (t == 0)
            return in;
        if (t == 1)
            return out;
        throw std::invalid_argument("Incorrect type of contact");
    }

    void printedCircuitBoard::print() const {
        if (currentNumber == 0) {
            std::cout << "The PCB has no contacts!" << std::endl;
            return;
        }
        for (int i = 0; i < currentNumber; ++i) {
            std::cout << "Number of contact: --> " << i << std::endl;
            std:: cout << "Type of contact: --> ";
            if (contacts[i].type == in)
                std::cout << "input" << std::endl;
            if (contacts[i].type == out)
                std::cout << "output" << std::endl;
            std::cout << "First coordinate: --> " << contacts[i].x << std::endl;
            std::cout << "Second coordinate: --> " << contacts[i].y << std::endl;
            if (contacts[i].numberOfContact == -1)
                std::cout << "This contact is disconnected from other contacts" << std::endl;
            else
                std::cout << "Number of related contact: --> " << contacts[i].numberOfContact << std::endl;
            std::cout << std::endl;
        }
    }

    bool printedCircuitBoard::isCorrectConnection(short c1, short c2) {
        if (!isCorrectNumber(c1) || !isCorrectNumber(c2))
            throw std::invalid_argument("There is no such contact(s)!");
        if (contacts[c1].type == contacts[c2].type)
            return false;
        if (contacts[c1].numberOfContact != -1 || contacts[c2].numberOfContact != -1)
            return false;
        return true;
    }

    void printedCircuitBoard::addContact() {
        Contact c = inputContact();
        if (currentNumber == maxNumber) {
            throw std::overflow_error("Cannot add more contacts!");
        }
        contacts[currentNumber] = c;
        currentNumber++;
    }

    void printedCircuitBoard::establishConnect(short c1, short c2) {
        if(!isCorrectConnection(c1, c2))
            throw std::invalid_argument("Cannot establish connect between these contacts");
        contacts[c1].numberOfContact = c2;
        contacts[c2].numberOfContact = c1;
    }

    void printedCircuitBoard::printGroup() const {
        int t;
        std::cout << "Enter type of contact (0 for in, 1 for out): --> ";
        checkInput(t);
        contactType type = isCorrectType(t);
        bool is = false;
        std::cout << "The following contacts are of this type: ";
        for (int i = 0; i < currentNumber; ++i) {
            if (contacts[i].type == type){
                std::cout << i << " ";
                is = true;
            }
        }
        if (!is) {
            std::cout << "there is no such contacts." << std::endl;
        }
    }

    double printedCircuitBoard::lengthOfTrack(short c1, short c2) {
        if (!isCorrectNumber(c1) || !isCorrectNumber(c2))
            throw std::invalid_argument("There are no such contacts");
        if (contacts[c1].numberOfContact != c2) {
            throw std::invalid_argument("These contacts are not connected");
        }
        int x1 = contacts[c1].x;
        int x2 = contacts[c2].x;
        int y1 = contacts[c1].y;
        int y2 = contacts[c2].y;
        return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    }

}
