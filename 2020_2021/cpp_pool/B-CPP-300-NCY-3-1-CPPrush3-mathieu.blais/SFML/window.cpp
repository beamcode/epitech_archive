#include "window.hpp"
#include <unistd.h>
#include <sys/utsname.h>
#include <sys/sysinfo.h>
#include "../backend/cpu.hpp"

Window::Window() : window(sf::VideoMode(1000, 600), "GKrellm")
{
    this->display = 3;
}

Window::~Window()
{

}

void Window::closeWindow(Window *win)
{
  for (size_t i = 0; i < this->vec.size(); i++)
      delete this->vec[i];
  for (size_t i = 0; i < this->txt.size(); i++)
      delete this->txt[i];
  for (size_t i = 0; i < this->but.size(); i++)
      delete this->but[i];
  for (size_t i = 0; i < this->rec.size(); i++)
      delete this->rec[i];
  this->window.close();
  delete win;
}


//------------INITIALISATION----------


void Window::initializeObject()
{
  this->createSprite();
  this->createRectangleShape();
  this->initCpu();
  this->createText();
}

void Window::initCpu()
{
    cpu a;

    a.refresh();
    this->total = a.getTotal();
    this->stvec = a.getcpu();
}

//------------FIN INITIALISATION----------


//--------------DRAW---------------------


void Window::drawObject()
{
  this->window.clear();
  this->drawSprite();
  this->drawRectangle();
  this->drawButton();
  this->drawText();
  this->window.display();
}


//--------------FIN DRAW---------------------


//----------------------GESTION SPRITE/BUTTON-------------------


void Window::initSprite(const std::string &txt, const float &x, const float &y, const int index)
{
    Sprite *sprite = new Sprite(txt, x, y, index);
    this->vec.push_back(sprite);
}

void Window::initButton(const std::string &txt, const float &x, const float &y, const int index)
{
    Button *button = new Button(txt, x, y, index);
    this->but.push_back(button);
}

void Window::createSprite()
{
    this->initSprite("SFML/ressources/fond.png", 0, 0, 0);
    this->initButton("SFML/ressources/rectangle.png", 15, 67, 1);
    this->initButton("SFML/ressources/rectangle.png", 15, 168, 2);
    this->initButton("SFML/ressources/rectangle.png", 15, 267, 2);
    this->initButton("SFML/ressources/rectangle2.png", 15, 67, 3);
    this->initButton("SFML/ressources/rectangle2.png", 15, 168, 4);
    this->initButton("SFML/ressources/rectangle2.png", 15, 267, 5);
}

void Window::drawSprite()
{
    for (size_t i = 0; i < this->vec.size(); i++)
        this->vec[i]->drawSprite(this->window);
}

void Window::drawButton()
{
  for (size_t i = 0; i < this->but.size(); i++) {
    if (this->but[i]->on == 1 && this->but[i]->getIndex() > 2)
        this->but[i]->drawSprite(this->window);
    if (this->but[i]->on == 0 && this->but[i]->getIndex() >= 1 && this->but[i]->getIndex() <= 2)
        this->but[i]->drawSprite(this->window);
  }
}


//--------------------FIN GESTION SPRITE/BUTTON-------------------


//--------------------GESTION TEXT-----------------------


void Window::initText(const std::string &txt, const float &x, const float &y, const int &cSize, const int index)
{
    Text *text = new Text(txt, x, y, cSize, index);
    this->txt.push_back(text);
}

void Window::createText()
{
    this->initText("MyGKrellm\n-------------", 25, 10, 30, 1);
    this->initText("Core Manager\n", 23, 118, 25, 2);
    this->initText("Ram\n", 65, 220, 25, 3);
    this->initText("Hostname:  " + inf.get_user() + "  ||  OS:  " + inf.get_sys() + inf.get_version() + "  ||  User:  " + inf.get_uname() + "\nArchitecture:  " + inf.get_machine() + "  ||  Date and hour:  " + inf.get_time() + "\n",205, 10, 18, 4);
    this->initText("Total RAM:  " + std::to_string(a.get_total_ram()) + "\nFree RAM:  " + std::to_string(a.get_free_ram()) + "\nShared RAM:  "+ std::to_string(a.get_shared_ram()) + "\n",400, 500, 25, 5);
    this->initText("25%", 360, 397, 20, 6);
    this->initText("50%", 360, 316, 20, 6);
    this->initText("75%", 360, 237, 20, 6);
    this->initText("100%", 352, 155, 20, 6);
    this->initText(this->total, 200, 540, 25, 8);
    for (size_t i = 0, y = 140; i < this->stvec.size(); i++, y += 50) {
        this->initText(this->stvec[i], 200, y, 25, 7);
    }
    this->initText("core", 210, 110, 15, 9);
    this->initText("user", 275, 110, 15, 9);
    this->initText("nice", 342, 110, 15, 9);
    this->initText("system", 400, 110, 15, 9);
    this->initText("idle", 490, 110, 15, 9);
    this->initText("iowait", 564, 110, 15, 9);
    this->initText("irq", 635, 110, 15, 9);
    this->initText("softirq", 692, 110, 15, 9);
    this->initText("CPU", 65, 318, 25, 10);
    this->initText("Model :    " + h.getModel(), 300, 100, 35, 11);
    this->initText("Vendor :    " + h.getVendor(), 300, 180, 35, 11);
    this->initText("Frequence :    " + h.getFreq() + " MHz", 300, 260, 35, 12);
    this->initText("Cores :    " + h.getCores(), 300, 340, 35, 11);
    this->initText("Cache :    " + h.getCache(), 300, 420, 35, 13);
}

void Window::drawText()
{
  for (size_t i = 0; i < this->txt.size(); i++) {
    if ((this->txt[i]->getIndex() == 5 || this->txt[i]->getIndex() == 6) && this->display == 4)
        this->txt[i]->drawText(this->window);
    if (this->txt[i]->getIndex() < 5)
        this->txt[i]->drawText(this->window);
    if (this->txt[i]->getIndex() >= 7 && this->display == 3 && this->txt[i]->getIndex() < 10)
        this->txt[i]->drawText(this->window);
    if (this->txt[i]->getIndex() == 10)
        this->txt[i]->drawText(this->window);
    if (this->txt[i]->getIndex() >= 11 && this->display == 5)
        this->txt[i]->drawText(this->window);
  }
}


//--------------------FIN GESTION TEXT-----------------------



//-----------------GESTION RectangleShape----------------------


void Window::initRectangle(int sizex, int sizey, int posx, int posy, sf::Color outColor, int thickness, sf::Color fillColor, int index)
{
    RectangleShape *rc = new RectangleShape(sizex, sizey, posx, posy, outColor, thickness, fillColor, index);
    this->rec.push_back(rc);
}

void Window::createRectangleShape()
{
    float percent = (100 * (320 * (a.get_total_ram() - a.get_free_ram()) / a.get_total_ram()) / 320);
    this->initRectangle(150, 585, 8, 8, sf::Color (100, 100, 100), 5, sf::Color (25, 25, 25), 1);
    this->initRectangle(800, 55, 180, 8, sf::Color(100,100,100), 5, sf::Color (25, 25, 25), 1);
    this->initRectangle(300, 90, 400, 500, sf::Color(146,97,171), 5, sf::Color (255, 255, 255, 0), 10);
    this->initRectangle(300, 490, 400, 100, sf::Color(146,97,171), 5, sf::Color (255, 255, 255, 0), 10);
    this->initRectangle(30, 0, 400, 170, sf::Color::White, 2, sf::Color (255, 255, 255, 0), 10);
    this->initRectangle(30, 0, 400, 330, sf::Color::White, 2, sf::Color (255, 255, 255, 0), 10);
    this->initRectangle(30, 0, 400, 250, sf::Color::White, 2, sf::Color (255, 255, 255, 0), 10);
    this->initRectangle(30, 0, 400, 410, sf::Color::White, 2, sf::Color (255, 255, 255, 0), 10);
    if (percent >= 75)
        this->initRectangle(75, (320 * (a.get_total_ram() - a.get_free_ram()) / a.get_total_ram()) , 510, 490 - (320 * (a.get_total_ram() - a.get_free_ram()) / a.get_total_ram()), sf::Color::Red, 5, sf::Color (255, 0, 0, 178), 11);
    else if (percent >= 50 && percent < 75)
        this->initRectangle(75, (320 * (a.get_total_ram() - a.get_free_ram()) / a.get_total_ram()) , 510, 490 - (320 * (a.get_total_ram() - a.get_free_ram()) / a.get_total_ram()), sf::Color(255, 179, 0), 5, sf::Color (255, 179, 0, 178), 11);
    else
        this->initRectangle(75, (320 * (a.get_total_ram() - a.get_free_ram()) / a.get_total_ram()) , 510, 490 - (320 * (a.get_total_ram() - a.get_free_ram()) / a.get_total_ram()), sf::Color(0, 255, 0), 5, sf::Color (0, 255, 0, 178), 11);
}

void Window::drawRectangle()
{
    for (size_t i = 0; i < this->rec.size(); i++) {
        if (this->display == 3 && this->rec[i]->getIndex() > 1 && this->rec[i]->getIndex() < 10)
            this->rec[i]->drawShape(this->window);
        if (this->rec[i]->getIndex() == 1)
            this->rec[i]->drawShape(this->window);
        if (this->display == 4 && this->rec[i]->getIndex() >= 10)
            this->rec[i]->drawShape(this->window);
    }
}


//-----------------FIN GESTION RectangleShape----------------------



//--------------REFRESH------------------


void Window::refreshRam()
{
  float percent = (100 * (320 * (a.get_total_ram() - a.get_free_ram()) / a.get_total_ram()) / 320);
  this->sizex = 75;
  this->sizey = (320 * (a.get_total_ram() - a.get_free_ram()) / a.get_total_ram());
  this->posx = 510;
  this->posy = 490 - (320 * (a.get_total_ram() - a.get_free_ram()) / a.get_total_ram());
  if (percent >= 75) {
    this->fillColor = sf::Color (255, 0, 0, 178);
    this->outColor = sf::Color::Red;
    }
  else if (percent >= 50 && percent < 75) {
    this->fillColor = sf::Color (255, 179, 0, 178);
    this->outColor = sf::Color (255, 179, 0);
    }
  else {
    this->fillColor = sf::Color (0, 255, 0, 178);
    this->outColor = sf::Color(0, 255, 0);
    }
    for (size_t i = 0; i < this->rec.size(); i++) {
        if (this->rec[i]->getIndex() == 11)
            this->rec[i]->refreshShape(this->sizex, this->sizey, this->posx, this->posy, this->fillColor, this->outColor);
    }
}

void Window::refreshModule()
{
  std::string str = "Hostname:  " + inf.get_user() + "  ||  OS:  " + inf.get_sys() + inf.get_version() + "  ||  User:  " + inf.get_uname() + "\nArchitecture:  " + inf.get_machine() + "  ||  Date and hour:  " + inf.get_time() + "\n";
  std::string str2 = "Total RAM:  " + std::to_string(a.get_total_ram()) + " MB" + "\nFree RAM:  " + std::to_string(a.get_free_ram()) + " MB" + "\nShared RAM:  "+ std::to_string(a.get_shared_ram()) + " MB" + "\n";
  for (size_t i = 0; i < this->txt.size(); i++) {
        if (this->txt[i]->getIndex() == 4)
            this->txt[i]->set_String(str);
        if (this->txt[i]->getIndex() == 5)
            this->txt[i]->set_String(str2);
        if (this->txt[i]->getIndex() == 7) {
            this->initCpu();
            this->txt[i]->set_String(this->stvec[i-10]);
        }
        if (this->txt[i]->getIndex() == 8) {
            this->initCpu();
            this->txt[i]->set_String(this->total);
        }
  }
  this->refreshRam();
}

//-------------FIN REFRESH---------------------
