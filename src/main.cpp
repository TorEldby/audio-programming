#include <SFML/Audio.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/SoundChannel.hpp>
#include <SFML/System/Sleep.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Window/Keyboard.hpp>

#include <cmath>
#include <iostream>
#include <algorithm>

int main() {
    
    //A sound is a wave, which is a set of points/samples made at a certain sampling rate.
    constexpr std::size_t SAMPLES = 44100;
    constexpr std::size_t SAMPLE_RATE = 44100;

    //Vector holding sample points. Sound sample points are stored as 16-bit signed integers in SFML
    std::vector<std::int16_t> raw(SAMPLES);

    constexpr std::int16_t AMPLITUDE = 30000;
    constexpr double TWO_PI = 6.28318;
    constexpr double increment = 440.0 / 44100.0;
    
    std::generate(raw.begin(), raw.end(), [](){
        static int i = 0;
        return static_cast<std::int16_t>(AMPLITUDE * std::sin((++i*increment) * TWO_PI));
    });

    //SoundBuffer holding sample points for a Sound object. Sound is designed for shorter sounds which can fit easily in memory
    sf::SoundBuffer buffer{};
    if(!buffer.loadFromSamples(raw.data(), raw.size(), 1, SAMPLE_RATE, {sf::SoundChannel::Mono})) {
        std::cerr << "Loading failed!" << std::endl;
        return -1;
    }

    sf::Sound sound(buffer);
    sound.play();
    sound.setLooping(true);
    while(!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
        sf::sleep(sf::milliseconds(100));
    }
    return 0;
}