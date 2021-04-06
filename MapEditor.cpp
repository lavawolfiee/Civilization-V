#include "MapEditor.h"


MapEditor::MapEditor(): mapGenerator(), delta(0), mapX(0.0), mapY(0.0), zoom(-1.0){
    map = mapGenerator.generateMap(config);
};

void MapEditor::setGUI(std::shared_ptr<GUI> gui) {
    this->gui = std::move(gui);
    this->gui->createButton("Regenerate", {"90%", "50%"}, {"5%", "5%"},
                            std::bind(&MapEditor::regenerateMap, std::ref(*this)));
    this->gui->createSlider({"87,5%", "45%"}, {"10%", "1%"}, 0.05,
                            std::bind(&MapEditor::setFrequency, std::ref(*this), std::placeholders::_1));
    this->gui->createSlider({"87,5%", "40%"}, {"10%", "1%"}, 0.05,
                            std::bind(&MapEditor::setStep, std::ref(*this), std::placeholders::_1));
}

void MapEditor::loop() {

    double cameraVelocity = 500;
    gui->delta();
    while (gui->isOpen()) {
        delta = gui->delta();
        const Mouse& mouse = gui->mouse;
        gui->pollEvents();

        if (mouse.x <= 0.025 * gui->width)
            mapX += cameraVelocity * static_cast<double>(delta) / 1'000'000;
        else if (mouse.x >= 0.975 * gui->width)
            mapX -= cameraVelocity * static_cast<double>(delta) / 1'000'000;

        if (mouse.y <= 0.025 * gui->height)
            mapY += cameraVelocity * static_cast<double>(delta) / 1'000'000;
        else if (mouse.y >= 0.975 * gui->height)
            mapY -= cameraVelocity * static_cast<double>(delta) / 1'000'000;

        gui->clear({129, 212, 250});
        if(map) {
            double x = gui->width / 2 - mapX, y = gui->height / 2 - mapY;
            map->render(std::make_shared<Batch>(
                    std::make_shared<Batch>(std::make_shared<BatchGUI>(gui, mapX, mapY), x, y,
                                            (zoom >= 1.0 ? tanh(zoom) * 1.5 : tanh(zoom) / 2) + 1), -x, -y));
        }
        gui->display();
    }
}

void MapEditor::regenerateMap() {
    map = mapGenerator.generateMap(config);
}

void MapEditor::setFrequency(float freq) {
    config.frequency[0] = freq * 3;
}

void MapEditor::setStep(float step) {
    config.step[0] = round(step * 100);
}

