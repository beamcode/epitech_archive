/*
** EPITECH PROJECT, 2021
** dlfunctions
** File description:
** arcade 2021
*/

#include "dlfcn.hpp"

void *my_dlib::my_dlopen(const char *filename, int flag)
{
  return (dlopen(filename, flag));
}

std::string	my_dlib::my_dlerror(void)
{
  return (dlerror());
}

void *my_dlib::my_dlsym(void *handle, const char *symbol)
{
  return (dlsym(handle, symbol));
}

int	my_dlib::my_dlclose(void *handle)
{
  if (handle != NULL)
    return (dlclose(handle));
  else
    return (0);
}