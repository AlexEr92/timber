#include "Clouds.hpp"
#include <stdexcept>

Clouds::Clouds(const std::string &texturePath) : m_randomEngine(std::random_device{}()) {
    if (!m_texture.loadFromFile(texturePath)) {
        throw std::runtime_error("Failed to load clouds texture: " + texturePath);
    }
}

void Clouds::spawnClouds(int count) {
    m_clouds.resize(count);
    for (auto &cloud : m_clouds) {
        cloud.sprite.setTexture(m_texture);
        resetCloud(cloud);
    }
}

void Clouds::resetCloud(Cloud &cloud) {
    std::uniform_real_distribution<float> speedDist(50.f, 200.f);
    std::uniform_real_distribution<float> heightDist(0.f, 450.f);

    cloud.speed = speedDist(m_randomEngine);
    cloud.sprite.setPosition(-200.f, heightDist(m_randomEngine) - 150.f);
    cloud.isActive = true;
}

void Clouds::update(float dt) {
    for (auto &cloud : m_clouds) {
        if (cloud.isActive) {
            cloud.sprite.move(cloud.speed * dt, 0);

            if (cloud.sprite.getPosition().x > 1920) {
                cloud.isActive = false;
                resetCloud(cloud);
            }
        }
    }
}

void Clouds::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    for (const auto &cloud : m_clouds) {
        if (cloud.isActive) {
            target.draw(cloud.sprite, states);
        }
    }
}
