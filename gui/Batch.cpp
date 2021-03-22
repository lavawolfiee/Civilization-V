#include "Batch.h"

Batch::Batch(Batch* batch, double offsetX, double offsetY, double rotation) : batch(batch), offsetX(offsetX),
                                                                             offsetY(offsetY), rotation(rotation) {};

void Batch::fillCircle(double x, double y, double radius, Color color, double borderWidth, Color borderColor) const {
    if(!batch) return;
    batch->fillCircle(offsetX + x, offsetY + y, radius, color, borderWidth, borderColor);
}

void Batch::fillHexagon(double x, double y, double radius, Color color, double borderWidth, Color borderColor) const {
    if(!batch) return;
    batch->fillHexagon(offsetX + x, offsetY + y, radius, color, borderWidth, borderColor);
}