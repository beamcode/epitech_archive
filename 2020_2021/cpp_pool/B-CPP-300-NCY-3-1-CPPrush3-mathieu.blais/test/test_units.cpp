/*
** EPITECH PROJECT, 2021
** test_units
** File description:
** cppoolrush3
*/

#include "../backend/cpu.hpp"
#include "../backend/ram.hpp"
#include "../backend/info.hpp"
#include "../backend/hardware.hpp"
#include <criterion/assert.h>
#include <criterion/criterion.h>
#include <cassert>  
#include <iostream>  
#include <typeinfo>
#include <new>

Test(test1, test_cpu)
{
    cpu a;
    const std::string cnull = "";
    std::string null = ""; 
    a.refresh();

     std::cout << "\n---- [TEST 1] --CPU----\n" << std::endl;
    
    cr_assert_neq(a.getTotal(), cnull);
    cr_assert_neq(a.getTotal(), cnull);
    cr_assert(a.isCpu(cnull) == false);
}

Test(test2, test_ram)
{

    std::cout << "\n---- [TEST 2] --RAM----\n" << std::endl;
    ram a;
    
    cr_assert_gt(a.get_free_ram(), -1);
    cr_assert_gt(a.get_shared_ram(), -1);
    cr_assert_gt(a.get_total_ram(), -1);
}

Test(test3, test_ram)
{

    std::cout << "\n---- [TEST 3] --info----\n" << std::endl;
    info a;
    const std::string cnull = "";
    std::string null = ""; 
    
    cr_assert_neq(a.get_machine(), cnull);
    cr_assert_neq(a.get_sys(), cnull);
    cr_assert_neq(a.get_time(), cnull);
    cr_assert_neq(a.get_uname(), cnull);
    cr_assert_neq(a.get_user(), cnull);
    cr_assert_neq(a.get_version(), cnull);
}

Test(test4, test_hardware)
{

    std::cout << "\n---- [TEST 4] --Hardware----\n" << std::endl;
    hardware a;
    const std::string cnull = "";
    std::string null = ""; 
    
    cr_assert_neq(a.getCache(), cnull);
    cr_assert_neq(a.getCores(), cnull);
    cr_assert_neq(a.getFreq(), cnull);
    cr_assert_neq(a.getModel(), cnull);
    cr_assert_neq(a.getVendor(), cnull);
}

/*
Test(test4, test_look_on_table)
{
    Object *a = new Teddy("Teddy");
	Object *b = new LittlePony("Pony");
    Object *c = new Box("boite");
    ITable *table = new PapaXmasTable();
    std::string *g;

  
    std::cout << "\n---- [TEST 3] --Look on table----\n" << std::endl;
	std::cout << "Putting bear on the table" << std::endl;
	table->put(a);

	std::cout << "\nPutting pony on the table" << std::endl;
	table->put(b);

    std::cout << "\nPutting Box on the table" << std::endl;
	table->put(c);

	std::cout << "\nLooking on the table" << std::endl;
    g = table->look();

    cr_assert_eq(g[0], "Teddy");
    cr_assert_eq(g[1], "Pony");
    cr_assert_eq(g[2], "boite");
    cr_assert_eq(g[3], "");

    delete(a);
    delete(b);
    delete(c);
}

Test(test3, test_Conv_Belt)
{
    Object *a = new Teddy("Teddy");
	Object *b = new LittlePony("Pony");
    PapaXmasConveyorBelt *table = new PapaXmasConveyorBelt();

    std::cout << "\n---- [TEST 4] --Look on Conv-table----\n" << std::endl;
	std::cout << "Putting bear on the convbelt" << std::endl;
	table->put(a);
	std::cout << "\nTaking bear off the convbelt" << std::endl;
	a = table->take();
	std::cout << "\n-- Testing if the toys still exist --" << std::endl;
	std::cout << a->getName() << std::endl;
	((Teddy *)a)->isTaken();
	((LittlePony *)b)->isTaken();
    delete (a);
    delete(b);
}


Test(test2, test_elf)
{
	Object *d = new Box();
    PapaXmasTable yes;
    PapaXmasConveyorBelt be;
    ITable *res = yes.createTable();
    Wrap *tes = NULL;
    IConveyorBelt *belt = be.createConveyorBelt();
    PapaXmasElf *elf = new PapaXmasElf(res, belt, tes);

    std::cout << "\n---- [TEST 5] --Elf-Action----\n" << std::endl;
    elf->pressIn();
    std::cout << "\n----elf-pressIn----\n" << std::endl;
    elf->putOnTable(d);
    std::cout << "\n----elf-Put-on-Table----\n" << std::endl;
    elf->TakeFromTable();
    std::cout << "\n----elf-Take-from-Table----\n" << std::endl;
    elf->pressOut();
    std::cout << "\n----elf-Press-out----\n" << std::endl;
    delete (d);
}



Test(test1, test_collapse)
{
    std::cout << "\n---- [TEST 6] --Crash-our-program----\n" << std::endl;
    PapaXmasTable yes;

    yes.put(new Teddy("1"));
    yes.put(new Teddy("2"));
    yes.put(new Teddy("3"));
    yes.put(new LittlePony("4"));
    yes.put(new LittlePony("5"));
    yes.put(new Box("6")); 
    yes.put(new Box("7")); 
    yes.put(new Box("8")); 
    yes.put(new Box("9")); 
    yes.put(new Box("10")); 
    yes.put(new Box("11")); 
}
*/