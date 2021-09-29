//
// Created by flamy on 28/09/21.
//

#ifndef LAB3_A_PRINTED_CIRCUIT_BOARD_H
#include <iostream>
#include <cmath>

namespace Lab3A {

    enum errorType {
        ok,
        incorrectInput,
        eof
    };

    enum contactType {
        in = 0,
        out = 1,
        notStated = -1
    };

    class printedCircuitBoard {
    private:
        struct Contact { //Struct should be in the class or no?
            contactType type;
            int x;
            int y;
            short numberOfContact;
            Contact();
            Contact(contactType t, int x, int y);
        };
        const static unsigned short maxNumber = 6;
        Contact contacts[maxNumber];
        unsigned short currentNumber;

        static contactType isCorrectType (int t);
        [[nodiscard]] inline bool isCorrectNumber (short n) const {return (n < currentNumber && n >= 0);}
        bool isCorrectConnection (short c1, short c2);
    public:
        inline printedCircuitBoard():currentNumber(0) {};
        static Contact inputContact() ;
        void print() const;
        void addContact();
        void establishConnect (short c1, short c2);
        void printGroup() const;
        double lengthOfTrack (short c1, short c2);
    };

    template <class T>
    errorType input (T &a){
        std::cin >> a;
        if (!std::cin.good()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return incorrectInput;
        }
        if (std::cin.eof())
            return eof;
        return ok;
    }

    template <class T>
    void checkInput (T &a) {
        errorType error;
        do {
            error = input(a);
            if (error == eof || error == incorrectInput)
                std::cout << "Enter only numbers, please!" << std::endl;
        } while (error != ok);
    }
}

#define LAB3_A_PRINTED_CIRCUIT_BOARD_H

#endif //LAB3_A_PRINTED_CIRCUIT_BOARD_H
