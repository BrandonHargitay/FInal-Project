//
// Created by Brandon Hargitay on 12/15/22.
//

#include "AppDetails.h"

std::string AppDetails::getAppSummary(AppsEnum app) {
    switch (app) {
    case GREEN_CIRCLE:
        return "Drawing a green circle! (excting)";
    case PING_PONG:
        return "A fun game of ping-pong!";
    case TOP_HAT_GUY:
        return "Drawing a snowman!";
    case PLAYING_CARD:
        return "Drawing a playing card!";
    case POKER:
        return "Drawing poker statistics";
    case ASTEROID:
        return "Final Game of Asteroids!";
    case APP_LAST_APP:
        return "";
    }

}
