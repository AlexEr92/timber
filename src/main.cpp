#include "Clouds.hpp"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/WindowStyle.hpp>

int main() {
    // Create a video mode object
    sf::VideoMode vm(1920, 1080);

    // Create and open a window for the game
    sf::RenderWindow window(vm, "Timber", sf::Style::Default);

    // Create background texture and sprite
    sf::Texture backgroundTexture;
    backgroundTexture.loadFromFile("assets/graphics/background.png");

    sf::Sprite backgroundSprite;
    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setPosition(0, 0);

    // Create clouds
    Clouds clouds;
    clouds.loadTexture("assets/graphics/cloud.png");
    clouds.spawnClouds(3); // Создаем 3 облака

    sf::Clock clock;

    // Main game loop
    while (window.isOpen()) {
        sf::Time dt = clock.restart();

        // Event handling
        sf::Event event;
        while (window.pollEvent(event)) {
            if ((event.type == sf::Event::Closed) ||
                (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) {
                window.close();
            }
        }

        clouds.update(dt.asSeconds()); // Обновление позиций

        // Clear everything from the last frame
        window.clear();

        // Draw game scene
        window.draw(backgroundSprite);
        clouds.draw(window); // Отрисовка

        // Show everything we just draw
        window.display();
    }

    return 0;
}
