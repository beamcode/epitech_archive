#include "TableRand.hpp"

TableRand::TableRand()
{
    int i = 0;
    int j = 0;

    while (i < 10) {
        j = rand() % 4;
        if (j == 0)
            this->_tableContent[i] = new LittlePony("Poney");
        if (j == 1)
            this->_tableContent[i] = new Teddy("Teddy");
        if (j == 2)
            this->_tableContent[i] = new GiftPaper("GiftPaper");
        else
            this->_tableContent[i] = new Box("Box");
    i++;
    }
}

TableRand::~TableRand()
{

}
