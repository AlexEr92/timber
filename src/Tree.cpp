#include "Tree.hpp"

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>
#include <stdexcept>

bool Tree::loadFromFile(const std::string& texturePath) {
    if (!m_texture.loadFromFile(texturePath)) {
        return false;
    }
    m_sprite.setTexture(m_texture);
    return true;
}

void Tree::setPosition(float x, float y) {
    m_sprite.setPosition(x, y);
}

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

const sf::Sprite& Tree::getSprite() const {
    if (!m_sprite.getTexture()) {
        throw std::logic_error("Sprite texture not loaded");
    }
    return m_sprite;
}
