#include "Clouds.hpp"

Clouds::Clouds() : m_randomEngine(std::random_device{}()) {}

bool Clouds::loadTexture(const std::string &filePath) { return m_texture.loadFromFile(filePath); }

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

void Clouds::draw(sf::RenderWindow &window) const {
    for (const auto &cloud : m_clouds) {
        if (cloud.isActive) {
            window.draw(cloud.sprite);
        }
    }
}
