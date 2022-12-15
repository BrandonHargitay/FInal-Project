//
// Created by Brandon Hargitay on 10/25/22.
//

#include "Card.h"
sf::Texture Card::texture;
sf::Font Card::font;

std::string Card::rankToString() {
    switch (_rank) {
        case ACE: return  "A";
        case KING: return  "K";
        case QUEEN: return  "Q";
        case JACK: return  "J";
        case TEN: return  "10";
        case NINE: return  "9";
        case EIGHT: return  "8";
        case SEVEN: return  "7";
        case SIX: return  "6";
        case FIVE: return  "5";
        case FOUR: return  "4";
        case THREE: return  "3";
        case TWO: return  "2";
    }
}

std::string Card::suitToString() {
    switch (_suit) {
        case HEARTS: return "images/heart.png";
        case DIAMONDS: return "images/diamond.png";
        case CLUBS: return "images/club.png";
        case SPADES: return "images/spade.png";
    }
}

Card::Card() : Card(HEARTS, ACE) {

}


Card::Card(SuitENum suit, RankENum rank) : _suit(suit), _rank(rank) {
    cardPosition = {0.f, 0.f};
    init();
}

void Card::draw(sf::RenderTarget& window, sf::RenderStates states) const {
    states.transform = getTransform();

    window.draw(background, states);
    window.draw(suit, states);
    window.draw(rank, states);
    window.draw(rank2, states);
}
sf::FloatRect Card::getGlobalBounds(){
    return background.getGlobalBounds();
}

void Card::setFillColor(const sf::Color &color) {

}

void Card::setSize(sf::Vector2f size) {

}

void Card::setSize(float width, float height) {

}

//void Card::setCardPosition(sf::Vector2f position) {
//    cardPosition = position;
//    background.setPosition(cardPosition);
//
//}

void Card::setPosition(sf::Vector2f position) {
    sf::Transformable::setPosition(position);
}
void Card::setOrigin(float x, float y){
    background.setOrigin(x,y);
    suit.setOrigin(x,y);
    rank.setOrigin(x,y);
    rank2.setOrigin(x,y);
}
const sf::Vector2f Card::getOrigin() const{
    return background.getOrigin();
}
const sf::Vector2f Card::getPosition() const{
    return background.getPosition();
}

void Card::init() {
    setupBackground();
    setupRank();
    setupSuit();
}

void Card::setupBackground() {
    background.setSize({150.f,270.f});
    background.setFillColor(sf::Color::White);
    background.setPosition(cardPosition);
}

void Card::setupRank() {
    if(!font.loadFromFile("Font/OpenSans-Bold.ttf"))
        exit(26);
    rank.setFont(font);
    rank2.setFont(font);

    rank.setString(rankToString());
    rank2.setString(rankToString());

    rank.setCharacterSize((int)background.getSize().x / 4 );
    rank2.setCharacterSize((int)background.getSize().x / 4 );

    //rank2.setOrigin(0,0);
    rank2.scale(-1,-1);

    rank.setPosition(background.getPosition().x + 11, background.getPosition().y + 8);
    rank2.setPosition(background.getPosition().x + background.getSize().x - 11 , background.getPosition().y + background.getSize().y - 8);

    if(_suit == DIAMONDS || _suit == HEARTS){
        rank.setFillColor(sf::Color::Red);
        rank2.setFillColor(sf::Color::Red);
    } else{
        rank.setFillColor(sf::Color::Black);
        rank2.setFillColor(sf::Color::Black);
    }
}

void Card::setupSuit() {
    if(!texture.loadFromFile(suitToString()))
        exit(21);
    suit.setTexture(texture);
    suit.setScale({background.getLocalBounds().width * (float)0.002 , background.getLocalBounds().height * (float) 0.0012});
    suit.setOrigin(suit.getLocalBounds().width / 2,suit.getLocalBounds().height / 2);
    suit.setPosition(background.getGlobalBounds().left + (background.getGlobalBounds().width / 2 ) , background.getGlobalBounds().top + (background.getGlobalBounds().height / 2));
}
