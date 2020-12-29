#include <sgg/graphics.h>

// The custom callback function that the library calls
// to check for and set the current application state.
void update(float /*ms*/)
{
  graphics::MouseState mouse{};
  graphics::getMouseState(mouse);
  if (mouse.button_left_released) {
    graphics::playSound("assets\\door2.wav", 1.0F, false);
  }
}

// The window content drawing function.
void draw()
{
  graphics::Brush br;

  graphics::setOrientation(45);

  br.texture = "assets\\boy2.png";
  br.outline_opacity = 0.0F;

  graphics::drawRect(500, 250, 200, 200, br);

  br.fill_color[0] = 0.5F;
  br.fill_color[1] = 0.0F;
  br.fill_color[2] = 0.0F;

  graphics::resetPose();
  drawText(300, 440, 70, "Hello World!", br);
}

auto main() -> int
{
  graphics::createWindow(1200, 600, "Hello World");

  graphics::setDrawFunction(draw);
  graphics::setUpdateFunction(update);

  graphics::setCanvasSize(1000, 500);
  graphics::setCanvasScaleMode(graphics::CANVAS_SCALE_FIT);

  graphics::Brush br;
  br.fill_color[0] = 0.5F;
  br.fill_color[1] = 0.7F;
  br.fill_color[2] = 0.9F;
  graphics::setWindowBackground(br);

  graphics::setFont("assets\\orange juice 2.0.ttf");

  graphics::startMessageLoop();

  return 0;
}
