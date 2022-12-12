#include "GiftPaper.hpp"

GiftPaper::GiftPaper(const std::string &name) : Wrap(name)
{
    this->_name = name;
}

GiftPaper::GiftPaper()
{
    this->_name = "GiftPaper";
}

GiftPaper::~GiftPaper()
{

}

void GiftPaper::openMe()
{

}

void GiftPaper::closeMe()
{

}
