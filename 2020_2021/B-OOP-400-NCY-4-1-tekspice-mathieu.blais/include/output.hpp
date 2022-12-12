/*
** EPITECH PROJECT, 2021
** output.hpp
** File description:
** output class header
*/

#ifndef OUTPUT_H
#define OUTPUT_H

#include "Component.hpp"

class Output : public Component {
    public:
        virtual ~Output();
        Output();

        nts::Tristate compute(std::size_t pin = 1) override;
    private:
    protected:
};

#endif /* !OUTPUT_HPP_ */
