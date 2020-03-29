/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** lib loader class
*/
#include "LibLoader.hpp"

LibLoader::LibLoader() {}

LibLoader::~LibLoader() {}

void LibLoader::loadGraphical(std::string av, std::vector<std::vector<std::string>> infos)
{
    this->_handle_lib = dlopen(av.c_str(), RTLD_LAZY);

    createGraphical_t *load_lib = (createGraphical_t *)dlsym(this->_handle_lib, "create");
    const char *dlsym_error = dlerror();
    if (dlsym_error) {
        std::cerr << "Cannot load symbol create: " << dlsym_error << '\n';
        exit(84);
    }
    this->destroy__graphical_lib = (destroyGraphical_t *)dlsym(this->_handle_lib, "destroy");
    const char *dlsym_error2 = dlerror();
    if (dlsym_error2) {
        std::cerr << "Cannot load symbol destroy: " << dlsym_error << '\n';
        exit(84);
    }
    this->_actual_graphical_lib = load_lib(infos);
}

void LibLoader::destroyGraphical()
{
    this->destroy__graphical_lib(this->_actual_graphical_lib);
    dlclose(this->_handle_lib);
}

void LibLoader::loadGames(std::string av)
{
    this->_handle_game = dlopen(av.c_str(), RTLD_LAZY);

    createGame_t *load_lib = (createGame_t *)dlsym(this->_handle_game, "create");
    const char *dlsym_error = dlerror();
    if (dlsym_error) {
        std::cerr << "Cannot load symbol create: " << dlsym_error << '\n';
        exit(84);
    }
    this->destroy_game_lib = (destroyGame_t *)dlsym(this->_handle_game, "destroy");
    const char *dlsym_error2 = dlerror();
    if (dlsym_error2) {
        std::cerr << "Cannot load symbol destroy: " << dlsym_error << '\n';
        exit(84);
    }
    this->_actual_game_lib = load_lib();
}

void LibLoader::destroyGames()
{
    this->destroy_game_lib(this->_actual_game_lib);
    dlclose(this->_handle_game);
}
