#ifndef CIVILIZATION_V_BATCH_H
#define CIVILIZATION_V_BATCH_H

#include <memory>
#include "Color.h"

class Batch {
protected:
    std::shared_ptr<Batch> batch;
    double offsetX, offsetY, rotation, scale;

public:
    Batch(std::shared_ptr<Batch> batch, double offsetX = 0.0, double offsetY = 0.0, double scale = 1.0, double rotation = 0.0);
    virtual void update(std::shared_ptr<Batch> batch, double offsetX = 0.0, double offsetY = 0.0, double scale = 1.0, double rotation = 0.0);
    virtual void fillCircle(double x, double y, double radius, Color color, double borderWidth = 0, Color borderColor = Color("black")) const;
    virtual void fillHexagon(double x, double y, double radius, Color color, double borderWidth = 0, Color borderColor = Color("black")) const;
    virtual void fillTriangle(double x, double y, double a, Color color, double borderWidth = 0, Color borderColor = Color("black")) const;
};


#endif //CIVILIZATION_V_BATCH_H
