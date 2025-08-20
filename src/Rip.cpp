#include "Rip.hpp"

#include <SFML/Graphics/Rect.hpp>

bool Rip::loadFromFile(const std::string &texturePath) {
    if (!m_texture.loadFromFile(texturePath)) {
        return false;
    }
    m_sprite.setTexture(m_texture);
    return true;
}

void Rip::show(float x, float y, Side side) {
    m_isVisible = true;
    sf::FloatRect bounds = m_sprite.getLocalBounds();
    m_sprite.setOrigin(bounds.width / 2.0f, bounds.height / 2.0f);
    if (side == Side::LEFT) {
        m_sprite.setPosition(x + RIP_OFFSET_X, y + RIP_OFFSET_Y);
    } else if (side == Side::RIGHT) {
        m_sprite.setPosition(x - RIP_OFFSET_X, y + RIP_OFFSET_Y);
    }
}

void Rip::hide() {
    m_isVisible = false;
    m_sprite.setPosition(0.f, RIP_HIDDEN_Y);
}

void Rip::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    if (m_isVisible) {
        target.draw(m_sprite, states);
    }
}
