/*
** EPITECH PROJECT, 2021
** Cesar.hpp
** File description:
** Cesar
*/

#ifndef CESAR_HPP_
#define CESAR_HPP_

#include <iostream>
#include <string>
#include <cctype>

#include "IEncryptionMethod.hpp"

class Cesar : public IEncryptionMethod {
    public:
        Cesar();
        ~Cesar();

        void encryptChar(char plainchar);
        void decryptChar(char cipherchar);
        void reset();
    protected:
    private:
        int _shift;
};

#endif /* !CESAR_HPP_ */
