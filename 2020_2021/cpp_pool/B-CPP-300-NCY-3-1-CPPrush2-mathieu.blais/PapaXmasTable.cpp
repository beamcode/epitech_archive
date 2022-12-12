#include "PapaXmasTable.hpp"
#include "TableRand.hpp"
PapaXmasTable::PapaXmasTable()
{
    this->_number = 0;
    for (int i = 0; i <= 10; i++)
        this->_tableContent[i] = NULL;
}

PapaXmasTable::~PapaXmasTable()
{
  for (int i = 0; i < 10; i++) {
      if (this->_tableContent != NULL)
        delete this->_tableContent[i];
  }
}

ITable *PapaXmasTable::createTable()
{
    ITable *table = new PapaXmasTable();
    return (table);
}

void PapaXmasTable::put(Object *object)
{
    if (object == NULL)
        return;
    for (int i = 0; i <= 9; i++) {
      if (this->_tableContent[i] == NULL) {
          this->_tableContent[i] = object;
          this->_number++;
          return;
      }
    }
    std::cerr << "The table is full" << std::endl;
}

Object *PapaXmasTable::take()
{
    Object *tmp = NULL;

    for (int i = 0; i <= 9; i++) {
        if (this->_tableContent[i+1] == NULL) {
            tmp = this->_tableContent[i];
            this->_tableContent[i] = NULL;
            this->_number--;
            return (tmp);
        }
        if (this->_tableContent[0] == NULL) {
            std::cerr << "The table is empty" << std::endl;
            return (NULL);
        }
    }
    return (NULL);
}

std::string *PapaXmasTable::look()
{
    std::string *_titleContent = new std::string[10];
    int a = 0;

    for (int i = 0; i < 10; i++, a++) {
        if (this->_tableContent[i] != NULL)
            _titleContent[a] = this->_tableContent[i]->getName();
    }
    a++;
    for ( ; a < 10; a++)
        _titleContent[a] = "";
    return (_titleContent);
}
