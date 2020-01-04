#pragma once

#include "SettingsBase.h"
#include "WiFi.h"

struct SettingsData {
    NetworkSettings network;
};

class Settings: public SettingsBase<SettingsData> {
    public:
        Settings();
        SettingsData* getSettings();

    protected:
        void initializeSettings();

    private:
        SettingsData settingsData;
};
