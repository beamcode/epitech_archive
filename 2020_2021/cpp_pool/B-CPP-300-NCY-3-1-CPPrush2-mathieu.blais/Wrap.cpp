#include "Wrap.hpp"
#include "Box.hpp"
Wrap::Wrap(const std::string &name) : Object(name)
{
    this->_iswrap = false;
    this->_name = name;
    std::cout << "whistles while working" << std::endl;
    this->Status = OPEN;
    this->obj = NULL;
}

Wrap::Wrap()
{

}

Wrap::~Wrap()
{
    free(this->obj);
}

bool Wrap::getWrap() const
{
    return (this->_iswrap);
}

void Wrap::wrapMeThat(Object *object)
{
  if (object == NULL)
      return;
  if (this->_iswrap == 0) {
      if (this->Status == OPEN) {
        this->Status = CLOSED;
        this->obj = object;
        std::cout << "tuuuut tuuut tuut" << std::endl;
        return;
      }
      else
          std::cerr << "The box is close" << std::endl;
  }
  else
      std::cerr << "The gift is already wrap" << std::endl;
}

bool Wrap::isOpen() const
{
    if (this->Status == OPEN)
        return (true);
    return (false);
}
