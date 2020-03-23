/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** lib loader class
*/
#include "LibLoader.hpp"

LibLoader::LibLoader()
{
}

LibLoader::~LibLoader()
{
}

void LibLoader::load()
{
    void *handle = dlopen(this->libPath.at(0).c_str(), RTLD_LAZY);

    if (!handle) {
        std::cerr << "Cannot open library: " << dlerror() << std::endl;
        exit(84);
    }
    // Chargement de la fonction "func"
	create_t * load_sfml = (create_t *)dlsym(handle, "create");
    const char* dlsym_error = dlerror();
	if (dlsym_error)
	{
		std::cerr << "Cannot load symbol create: " << dlsym_error << '\n';
        exit(84);
	}
    AbstractGraph *sfml = load_sfml();
    sfml->getCh();
    dlclose(handle);
}

void LibLoader::unLoad()
{
}
