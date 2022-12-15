//
// Created by Brandon Hargitay on 12/14/22.
//

#include "Poker_Analysis_Runner.h"

void Poker_Analysis_Runner::run() {
    srand((unsigned int)time(NULL));
    double numberOfHands = 50000;
//    std::cout<<"How many poker hands would you like to analyze: ";
//    std::cin >> numberOfHands;

    PokerScore total;
    for(int i = 0; i < numberOfHands; i++){
        Deck d3;
        d3.shuffle();

        CardHand p1,p2,p3,p4,p5;

        for(int j = 0; j < 5; j++){
            p1.addCard(d3.dealCard());
            p2.addCard(d3.dealCard());
            p3.addCard(d3.dealCard());
            p4.addCard(d3.dealCard());
            p5.addCard(d3.dealCard());
        }
        CardHandScorer::handScore(p1);

    }
    std::cout << total;


    //Displays window
    DrawStatistics statistics(numberOfHands);
    Deck d2;
    d2.shuffle();
    sf::RenderWindow window({1920, 1080, 32},"Top Hat Guy");
    window.setFramerateLimit(60);
    CardDrawable c (d2.getCardAt(0).getSuit(), d2.getCardAt(0).getRank());
    CardDrawable c2 (d2.getCardAt(1).getSuit(), d2.getCardAt(1).getRank());
    CardDrawable c3 (d2.getCardAt(2).getSuit(), d2.getCardAt(2).getRank());
    CardDrawable c4 (d2.getCardAt(3).getSuit(), d2.getCardAt(3).getRank());
    CardDrawable c5 (d2.getCardAt(4).getSuit(), d2.getCardAt(4).getRank());
    CardHandDrawable p1;

    p1.addCard(c);
    p1.addCard(c2);
    p1.addCard(c3);
    p1.addCard(c4);
    p1.addCard(c5);
//    p1.setPosition({100, 100});
    p1.position();
    //std::cout << d2;
    //std::cout << p1;
    //c2.setPosition({500,30});
    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(sf::Event::Closed == event.type)
                window.close();
            if((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)){
                window.close();
            }
        }
        //c.setPosition({0.f,0.f});
        window.clear(sf::Color(50,168,82));
        window.draw(p1);
        window.draw(statistics);
        window.display();
    }

}
