#include "Batch.h"

Batch::Batch(std::shared_ptr<Batch> batch, double offsetX, double offsetY, double scale, double rotation) : batch(batch), offsetX(offsetX),
                                                                             offsetY(offsetY), scale(scale), rotation(rotation) {};

void Batch::fillCircle(double x, double y, double radius, Color color, double borderWidth, Color borderColor) const {
    if(!batch) return;
    batch->fillCircle(offsetX + x * scale, offsetY + y * scale, radius * scale, color, borderWidth, borderColor);
}

void Batch::fillHexagon(double x, double y, double radius, Color color, double borderWidth, Color borderColor) const {
    if(!batch) return;
    batch->fillHexagon(offsetX + x * scale, offsetY + y * scale, radius * scale, color, borderWidth, borderColor);
}

void Batch::fillTriangle(double x, double y, double a, Color color, double borderWidth, Color borderColor) const {
    if (!batch) return;
    batch->fillTriangle(offsetX + x * scale, offsetY + y * scale, a * scale, color, borderWidth, borderColor);
}

void Batch::update(std::shared_ptr<Batch> batch, double offsetX, double offsetY, double scale, double rotation) {
    this->batch = batch;
    this->offsetX = offsetX;
    this->offsetY = offsetY;
    this->scale = scale;
    this->rotation = rotation;
}
