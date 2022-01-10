//
// Created by dj on 04.01.2022.
//

#ifndef YETANOTHERCHESSGAME_SETTINGS_HPP
#define YETANOTHERCHESSGAME_SETTINGS_HPP


class Settings {
    public:
        bool getShowIcons();
        void setShowIcons(bool showIcons);
        bool getShowPossibleMoves();
        void setShowPossibleMoves(bool showPossibleMoves);
        bool getResetUI();
        void setResetUI(bool resetUI);
        int getTimeMode();
        void setTimeMode(int timeMode);

    private:
        bool showIcons;
        bool showPossibleMoves;
        bool resetUI;
        int timeMode = 4;
};


#endif //YETANOTHERCHESSGAME_SETTINGS_HPP
