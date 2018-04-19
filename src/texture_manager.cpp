#include <map>
#include <string>
#include <SFML/Graphics.hpp>

#include "../include/texture_manager.hpp"

void TextureManager::loadTexture(const std::string& name, const std::string& filename) {
  /* Load the texture */
  sf::Texture tex;
  tex.loadFromFile(filename);

  /* Add it to the list of textures */
  this->textures[name] = tex;

  return;
}

sf::Texture& TextureManager::getRef(const std::string& texture) {
  return this->textures.at(texture);
}
