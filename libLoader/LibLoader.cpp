/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** lib loader class
*/
#include "../lib/SFML/Sfml.hpp"
#include "LibLoader.hpp"

LibLoader::LibLoader()
{
}

LibLoader::~LibLoader()
{
}

void LibLoader::load()
{
    AbstractGraph *sfml_lib;
    AbstractGraph *(*func)();
    void *handle = dlopen(this->libPath.at(0).c_str(), RTLD_LAZY);

    if (!handle) {
        std::cerr << "Cannot open library: " << dlerror() << std::endl;
        exit(84);
    }
    // Chargement de la fonction "func"
	func = reinterpret_cast<AbstractGraph *(*)()>(dlsym(handle, "create"));
    const char* dlsym_error = dlerror();
	if (dlsym_error)
	{
		std::cerr << "Cannot load symbol create: " << dlsym_error << '\n';
        exit(84);
	}
    sfml_lib = func();
    sfml_lib->getCh();
    dlclose(handle);
    std::cout << "load function" << std::endl;
}

void LibLoader::unLoad()
{
}
