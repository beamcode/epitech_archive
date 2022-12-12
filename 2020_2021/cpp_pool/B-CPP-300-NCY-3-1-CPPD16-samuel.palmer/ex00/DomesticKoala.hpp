/*
** EPITECH PROJECT, 2021
** DomesticKoala.hpp
** File description:
** DomesticKoala
*/

#ifndef DOMESTICKOALA_HPP_
#define DOMESTICKOALA_HPP_

#include "KoalaAction.hpp"
#include <iostream>
#include <string>

class DomesticKoala {
    public:
        DomesticKoala(KoalaAction &action);
        ~DomesticKoala();

        DomesticKoala(const DomesticKoala &);
        DomesticKoala &operator=(const DomesticKoala &);
        using methodPointer_t = XXXXX; // Figuring out the actual type is up to you

        // Retrieves a vector containing all the member function pointers
        const std ::vector<methodPointer_t> *getActions() const;

        // Sets a member function pointer , linking the character (the command ) to the
        // pointer (the action ).
        void learnAction(unsigned char command, methodPointer_t action);

        // Deletes the command .
        void unlearnAction(unsigned char command);

        // Executes the action linked to the given command . The string is the parameter
        // given to the member function .
        void doAction(unsigned char command, const std ::string &param);
        
        // Affects a new KoalaAction class to the domestic Koala .
        // This erases the pointers table .
        void setKoalaAction(KoalaAction &);

        //KoalaAction
    protected:
    private:
        KoalaAction _action;
        
};

#endif /* !DOMESTICKOALA_HPP_ */
