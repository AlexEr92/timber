#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/WindowStyle.hpp>

int main() {
    // Create a video mode object
    sf::VideoMode vm(1920, 1080);

    // Create and open a window for the game
    sf::RenderWindow window(vm, "Timber", sf::Style::Default);

    // Main game loop
    while (window.isOpen()) {
        // Event handling
        sf::Event event;
        while (window.pollEvent(event)) {
            if ((event.type == sf::Event::Closed) ||
                (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) {
                window.close();
            }
        }

        // Clear everything from the last frame
        window.clear();

        // Draw game scene

        // Show everything we just draw
        window.display();
    }

    return 0;
}
