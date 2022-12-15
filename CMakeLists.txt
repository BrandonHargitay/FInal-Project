cmake_minimum_required(VERSION 3.23)
project(Final_Project)

set(CMAKE_CXX_STANDARD 14)

include_directories(Asteroids-Game/Enums)
include_directories(Asteroids-Game/include)
include_directories(Ping-Pong-Game)
include_directories(Ping-Pong-Game/include)
include_directories(Top-Hat-Guy)

add_executable(Final_Project
        Asteroids-Game/Enums/fontsEnum.h
        Asteroids-Game/Enums/statesEnum.h
        Asteroids-Game/Enums/textureEnum.h
        Asteroids-Game/include/Asteroids.h
        Asteroids-Game/include/Asteroids_Game_Runner.h
        Asteroids-Game/include/Bullet.h
        Asteroids-Game/include/Fonts.h
        Asteroids-Game/include/Health.h
        Asteroids-Game/include/Heart.h
        Asteroids-Game/include/Rocket.h
        Asteroids-Game/include/ScoreBoard2.h
        Asteroids-Game/include/SpaceshipGun.h
        Asteroids-Game/include/states.h
        Asteroids-Game/include/Texture.h
        Asteroids-Game/src/Asteroids-Game-Runner.cpp
        Asteroids-Game/src/Asteroids.cpp
        Asteroids-Game/src/Bullet.cpp
        Asteroids-Game/src/Fonts.cpp
        Asteroids-Game/src/Health.cpp
        Asteroids-Game/src/Heart.cpp
        Asteroids-Game/src/Rocket.cpp
        Asteroids-Game/src/ScoreBoard2.cpp
        Asteroids-Game/src/SpaceshipGun.cpp
        Asteroids-Game/src/states.cpp
        Asteroids-Game/src/Texture.cpp
        Ping-Pong-Game/include/ball.h
        Ping-Pong-Game/include/paddle.h
        Ping-Pong-Game/include/ScoreBoard.h
        Ping-Pong-Game/src/ball.cpp
        Ping-Pong-Game/src/paddle.cpp
        Ping-Pong-Game/src/ScoreBoard.cpp
        Ping-Pong-Game/Ping_Pong_Game_Runner.cpp
        Ping-Pong-Game/Ping_Pong_Game_Runner.h
        Top-Hat-Guy/topHatGuy.cpp
        Top-Hat-Guy/topHatGuy.h
        main.cpp
        Top-Hat-Guy/Top_Hat_Guy_Runner.cpp
        Top-Hat-Guy/Top_Hat_Guy_Runner.h)

target_link_libraries(Final_Project sfml-graphics sfml-audio)
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)