#include "Tree.hpp"

#include <stdexcept>

#include <SFML/System/Vector2.hpp>

Tree::Tree(const std::string &texturePath) {
    if (!m_texture.loadFromFile(texturePath)) {
        throw std::runtime_error("Failed to load tree texture: " + texturePath);
    }
    m_sprite.setTexture(m_texture);
}

void Tree::setPosition(float x, float y) { m_sprite.setPosition(x, y); }

void Tree::centerHorizontally(const sf::RenderWindow &window, float verticalOffset) {
    if (!m_sprite.getTexture()) {
        throw std::logic_error("Texture not loaded before positioning");
    }

    const auto windowSize = static_cast<sf::Vector2f>(window.getSize());
    const auto treeSize = m_sprite.getGlobalBounds();

    const float x = (windowSize.x - treeSize.width) / 2.f;
    const float y = verticalOffset;

    m_sprite.setPosition(x, y);
}

void Tree::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    if (!m_sprite.getTexture()) {
        throw std::logic_error("Sprite texture not loaded");
    }
    target.draw(m_sprite, states);
}
