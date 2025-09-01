#include "Axe.hpp"

Axe::Axe(const std::string &texturePath) {
    if (!m_texture.loadFromFile(texturePath)) {
        throw std::runtime_error("Failed to load axe texture: " + texturePath);
    }
    m_sprite.setTexture(m_texture);
}

void Axe::setPositionBySide(Side side) {
    switch (side) {
    case Side::LEFT:
        setPosition(AXE_POSITION_LEFT, AXE_POSITION_Y);
        break;
    case Side::RIGHT:
        setPosition(AXE_POSITION_RIGHT, AXE_POSITION_Y);
        break;
    default:
        setPosition(AXE_POSITION_LEFT, AXE_POSITION_Y);
        break;
    }
}

void Axe::setPosition(float x, float y) { m_sprite.setPosition(x, y); }

void Axe::hide() { setPosition(AXE_POSITION_HIDDEN, AXE_POSITION_Y); }

void Axe::draw(sf::RenderTarget &target, sf::RenderStates states) const { target.draw(m_sprite, states); }
