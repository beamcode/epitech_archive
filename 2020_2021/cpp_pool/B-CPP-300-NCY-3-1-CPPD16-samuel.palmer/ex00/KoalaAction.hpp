/*
** EPITECH PROJECT, 2021
** KoalaAction.hpp
** File description:
** KoalaAction
*/

#ifndef KOALAACTION_HPP_
#define KOALAACTION_HPP_

class KoalaAction {
    public:
        KoalaAction();
        ~KoalaAction();

        void eat(const std::string &str) {
            std::cout << "I eat: " << str << std::endl; }
        void goTo(const std::string &str) {
            std::cout << "I go to: " << str << std::endl; }
        void sleep(const std::string &str) {
            std::cout << "I sleep, and dream of: " << str << std::endl; }
        void reproduce(const std::string &str) {
            std::cout << "I attempt to reproduce with: " << str << std::endl; }
};

#endif /* !KOALAACTION_HPP_ */
