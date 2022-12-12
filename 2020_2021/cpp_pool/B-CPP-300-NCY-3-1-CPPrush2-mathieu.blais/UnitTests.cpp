/*
** EPITECH PROJECT, 2021
** main.cpp
** File description:
** rush2
*/

#include "Object.hpp"
#include "Teddy.hpp"
#include "Wrap.hpp"
#include "GiftPaper.hpp"
#include "LittlePony.hpp"
#include "Toy.hpp"
#include "Box.hpp"
#include "PapaXmasElf.hpp"
#include "PapaXmasTable.hpp"
#include "PapaXmasConveyorBelt.hpp"
#include "ITable.hpp"
#include <cassert>  
#include <iostream>  
#include <typeinfo>
#include <new> 

Object **MyUnitTests1()
{
    const std::string a = "happy pony";
    const std::string b = "cuddles";
    try {
        Object **tab;

        tab = new Object*[2];
        tab[0] = new LittlePony(a);
        tab[1] = new Teddy(b);
        assert(tab[0]->getName() == a);
        assert(tab[1]->getName() == b);
        return (tab);
    }
    catch (std::bad_alloc& ba) {
        std::cout << "Bad Malloc: "
	    << ba.what() << std::endl;
        return (NULL);
    }
}

Object *MyUnitTests2(Object **test)
{
    Teddy* bear = dynamic_cast<Teddy*>(test[0]);
    Box* box = dynamic_cast<Box*>(test[1]);
    GiftPaper* gift = dynamic_cast<GiftPaper*>(test[2]);

    box->openMe();
    box->wrapMeThat(bear);
    gift->wrapMeThat(box);
    return (gift);
}

void status_tests()
{
    Teddy *ted = new Teddy("ola");
    Box *box = new Box("wow");
    GiftPaper *gift = new GiftPaper("nice");

    auto items = new Object*[4];
	items[0] = new Teddy("cuddles");
	items[1] = new Box("g");
	items[2] = new GiftPaper("g");
	items[3] = NULL;

    std::cout << "---- [TEST 1] ----" << std::endl;
    box->Status = Box::CLOSED;
    box->wrapMeThat(ted);
    std::cout << std::endl;

    std::cout << "---- [TEST 2] ----" << std::endl;
    gift->Status = GiftPaper::CLOSED;
    gift->wrapMeThat(box);
    std::cout << std::endl;

    std::cout << "---- [TEST 3] ----" << std::endl;
    gift->Status = GiftPaper::OPEN;
    gift->wrapMeThat(box);
    std::cout << std::endl;
}

void table_test()
{
    Object *a = new Teddy("test1");
	Object *b = new LittlePony("test1");
    ITable *table = new PapaXmasTable();

	std::cout << "-- Testing stuff with tables --" << std::endl;
	std::cout << "Putting bear on the table" << std::endl;
	table->put(a);

	std::cout << "\nPutting pony on the table" << std::endl;
	table->put(b);

	std::cout << "\nTaking bear off the table" << std::endl;
    std::string *g;
    g = table->look();

    std::cout << g[0] << std::endl;
    std::cout << g[1] << std::endl;
    b = table->take();
	a = table->take();

	std::cout << "\nTaking pony off the table\n" << std::endl;

	std::cout << "\n-- Testing if the toys still exist --" << std::endl;
	std::cout << a->getName() << std::endl;
	((Teddy *)a)->isTaken();
	std::cout << b->getName() << std::endl;
	((LittlePony *)b)->isTaken();
}

void belt_test()
{
    Object *a = new Teddy("test1");
	Object *b = new LittlePony("test2");
    PapaXmasConveyorBelt *table = new PapaXmasConveyorBelt();

	std::cout << "-- Testing stuff with tables --" << std::endl;
	std::cout << "Putting bear on the table" << std::endl;
	table->put(a);

	std::cout << "\nPutting pony on the table" << std::endl;
	table->put(b) ;

	std::cout << "\nTaking bear off the table" << std::endl;
	a = table->take();

	std::cout << "\nTaking pony off the table\n" << std::endl;
	b = table->take();

	std::cout << "\n-- Testing stuff with conveyor belts --" << std::endl;
	std::cout << "Putting bear on the conveyorBelt" << std::endl;


	std::cout << "\n-- Testing if the toys still exist --" << std::endl;
	std::cout << a->getName() << std::endl;
	((Teddy *)a)->isTaken();
	std::cout << b->getName() << std::endl;
	((LittlePony *)b)->isTaken();
}


void box_test()
{

}

void elf_test()
{
	Object *a = new Teddy("maybe");
	Object *c = new GiftPaper();
	Object *d = new Box();
    PapaXmasElf *elf = new PapaXmasElf();


    elf->putOnTable(a);
    /*
    elf->TakeFromTable();

    elf->putOnTable(a);
    elf->lookTable();
    */
    //elf->pressIn();
    //elf->pressOut();
    //elf->wrap(a);
    
    std::cout << "I hope the kids get their f*****g toys" << std::endl; 
}

int main()
{
    elf_test();
    //table_test();
    //belt_test();
    //status_tests();
    //box_test();
    return (0);
}