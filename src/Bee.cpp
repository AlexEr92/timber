#include "Bee.hpp"

Bee::Bee(const std::string &texturePath) : m_speed{0.f}, m_isActive{false}, m_randomEngine{std::random_device{}()} {
    if (!m_texture.loadFromFile(texturePath)) {
        throw std::runtime_error("Failed to load bee texture: " + texturePath);
    }
    m_sprite.setTexture(m_texture);
}

void Bee::setPosition(float x, float y) { m_sprite.setPosition(x, y); }

void Bee::update(float dt) {
    if (!m_isActive) {
        std::uniform_real_distribution<float> speedDist(200.f, 400.f);
        std::uniform_real_distribution<float> heightDist(500.f, 1000.f);

        m_speed = speedDist(m_randomEngine);
        m_sprite.setPosition(2000.f, heightDist(m_randomEngine));
        m_isActive = true;
    } else {
        m_sprite.move(-m_speed * dt, 0.f);

        if (m_sprite.getPosition().x < -100.f) {
            m_isActive = false;
        }
    }
}

void Bee::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    if (m_isActive) {
        target.draw(m_sprite, states);
    }
}
