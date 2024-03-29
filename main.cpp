#include "lib/Printed.Circuit.Board.h"

using namespace Lab3A;

int main() {
    int a = 0;
    short c1, c2;
    printedCircuitBoard::Contact c;
    printedCircuitBoard p;
    std::cout << "Hello! You can do many things to printed circuit board, in particular:" << std::endl;
    do {
        std::cout << "0. Quit;" << std::endl;
        std::cout << "1. Print information about PCB;" << std::endl;
        std::cout << "2. Add contact on PCB;" << std::endl;
        std::cout << "3. Establish connect between contacts;" << std::endl;
        std::cout << "4. Get contacts that are in the same group;" << std::endl;
        std::cout << "5. Get length of the track between contacts." << std::endl;
        std::cout << "Make your choice: --> ";
        checkInput(a);
        std::cout << std::endl;
        try {
            switch (a) {
                case 1: {
                    p.print();
                }
                    break;
                case 2: {
                    c = printedCircuitBoard::inputContact();
                    p.addContact(c);
                }
                    break;
                case 3: {
                    std::cout << "Enter number of the first contact: --> ";
                    checkInput(c1);
                    std::cout << "Enter number of the second contact: --> ";
                    checkInput(c2);
                    p.establishConnect(c1, c2);
                }
                    break;
                case 4: {
                    p.groupOfContacts().print();
                }
                    break;
                case 5: {
                    std::cout << "Enter number of the first contact: --> ";
                    checkInput(c1);
                    std::cout << "Enter number of the second contact: --> ";
                    checkInput(c2);
                    std::cout << "Length of track: --> " << p.lengthOfTrack(c1, c2) << std::endl;
                }
                case 0: {
                    break;
                }
                default: {
                    std::cout << "Enter only numbers from 0 to 5!" << std::endl;
                }
                    break;
            }
        }
        catch (std::exception &e) {
            std::cout << e.what();
        }
        std::cout << std::endl;
    } while (a != 0);
    return 0;
}
