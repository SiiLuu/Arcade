/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** lib loader class
*/
#include "LibLoader.hpp"

LibLoader::LibLoader() {}

LibLoader::~LibLoader() {}

void LibLoader::load(std::string av)
{
    this->_handle = dlopen(av.c_str(), RTLD_LAZY);

    create_t *load_lib = (create_t *)dlsym(this->_handle, "create");
    const char *dlsym_error = dlerror();
    if (dlsym_error) {
        std::cerr << "Cannot load symbol create: " << dlsym_error << '\n';
        exit(84);
    }
    this->destroy_lib = (destroy_t *)dlsym(this->_handle, "destroy");
    const char *dlsym_error2 = dlerror();
    if (dlsym_error2) {
        std::cerr << "Cannot load symbol destroy: " << dlsym_error << '\n';
        exit(84);
    }
    this->_actual_lib = load_lib();
}

void LibLoader::destroyLib()
{
    this->destroy_lib(this->_actual_lib);
    dlclose(this->_handle);
}

void LibLoader::unLoad() {}
