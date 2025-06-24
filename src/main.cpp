#include <SFML/Audio.hpp>

int main() {
    sf::Music music("music.mp3");
    music.play();

    while(music.getStatus() == sf::Music::Status::Playing) {
    }
    return 0;
}