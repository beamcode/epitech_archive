/*
** EPITECH PROJECT, 2021
** arcade 2021
** File description:
** dlfunctions
*/

#include <dlfcn.h>
#include <iostream>
#include <cstring>
#include <iomanip>

class my_dlib
{
  public:
  	static void *my_dlopen(const char *filename, int flag);
  	static std::string my_dlerror(void);
  	static void *my_dlsym(void *handle, const char *symbol);
  	static int	my_dlclose(void *handle);
};