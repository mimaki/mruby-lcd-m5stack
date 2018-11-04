#include <M5Stack.h>

#include "mruby.h"
#include "mruby/class.h"
#include "mruby/string.h"

#ifdef __cplusplus
extern "C" {
#endif

// M5.lcd.setBrightness(uint8_t brightness);
static mrb_value
mrb_lcd_set_brightness(mrb_state *mrb, mrb_value self)
{
  mrb_int b;
  mrb_get_args(mrb, "i", &b);
  M5.Lcd.setBrightness(b);
  return self;
}

// M5.Lcd.drawPixel(int16_t x, int16_t y, uint16_t color);
static mrb_value
mrb_lcd_pixel(mrb_state *mrb, mrb_value self)
{
  mrb_int x, y, c;
  mrb_get_args(mrb, "iii", &x, &y, &c);
  M5.Lcd.drawPixel(x, y, c);
  return self;
}

// M5.Lcd.drawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color);
static mrb_value
mrb_lcd_line(mrb_state *mrb, mrb_value self)
{
  mrb_int x1, y1, x2, y2, c;
  mrb_get_args(mrb, "iiiii", &x1, &y1, &x2, &y2, &c);
  M5.Lcd.drawLine(x1, y1, x2, y2, c);
  return self;
}

// M5.Lcd.drawRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color);
static mrb_value
mrb_lcd_draw_rect(mrb_state *mrb, mrb_value self)
{
  mrb_int x, y, w, h, c;
  mrb_get_args(mrb, "iiiii", &x, &y, &w, &h, &c);
  M5.Lcd.drawRect(x, y, w, h, c);
  return self;
}

// M5.Lcd.fillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color);
static mrb_value
mrb_lcd_fill_rect(mrb_state *mrb, mrb_value self)
{
  mrb_int x, y, w, h, c;
  mrb_get_args(mrb, "iiiii", &x, &y, &w, &h, &c);
  M5.Lcd.fillRect(x, y, w, h, c);
  return self;
}

// M5.Lcd.fillScreen(uint16_t color);
static mrb_value
mrb_lcd_fill_screen(mrb_state *mrb, mrb_value self)
{
  mrb_int c;
  mrb_get_args(mrb, "i", &c);
  M5.Lcd.fillScreen(c);
  return self;
}

static mrb_value
mrb_lcd_clear(mrb_state *mrb, mrb_value self)
{
  M5.Lcd.fillScreen(0);
  M5.Lcd.setCursor(0, 0);
  return self;
}

// M5.Lcd.drawCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color);
static mrb_value
mrb_lcd_circle(mrb_state *mrb, mrb_value self)
{
  mrb_int x, y, r, c;
  mrb_get_args(mrb, "iiii", &x, &y, &r, &c);
  M5.Lcd.drawCircle(x, y, r, c);
  return self;
}

// M5.Lcd.fillCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color);
static mrb_value
mrb_lcd_fill_circle(mrb_state *mrb, mrb_value self)
{
  mrb_int x, y, r, c;
  mrb_get_args(mrb, "iiii", &x, &y, &r, &c);
  M5.Lcd.fillCircle(x, y, r, c);
  return self;
}

// M5.Lcd.drawTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint16_t color);
static mrb_value
mrb_lcd_triangle(mrb_state *mrb, mrb_value self)
{
  mrb_int x1, y1, x2, y2, x3, y3, c;
  mrb_get_args(mrb, "iiiiiii", &x1, &y1, &x2, &y2, &x3, &y3, &c);
  M5.Lcd.drawTriangle(x1, y1, x2, y2, x3, y3, c);
  return self;
}

// M5.Lcd.fillTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint16_t color);
static mrb_value
mrb_lcd_fill_triangle(mrb_state *mrb, mrb_value self)
{
  mrb_int x1, y1, x2, y2, x3, y3, c;
  mrb_get_args(mrb, "iiiiiii", &x1, &y1, &x2, &y2, &x3, &y3, &c);
  M5.Lcd.fillTriangle(x1, y1, x2, y2, x3, y3, c);
  return self;
}

// M5.Lcd.drawRoundRect(int16_t x0, int16_t y0, int16_t w, int16_t h, int16_t radius, uint16_t color);
static mrb_value
mrb_lcd_round_rect(mrb_state *mrb, mrb_value self)
{
  mrb_int x, y, w, h, r, c;
  mrb_get_args(mrb, "iiiiii", &x, &y, &w, &h, &r, &c);
  M5.Lcd.drawRoundRect(x, y, w, h, r, c);
  return self;
}

// M5.Lcd.fillRoundRect(int16_t x0, int16_t y0, int16_t w, int16_t h, int16_t radius, uint16_t color);
static mrb_value
mrb_lcd_fill_round_rect(mrb_state *mrb, mrb_value self)
{
  mrb_int x, y, w, h, r, c;
  mrb_get_args(mrb, "iiiiii", &x, &y, &w, &h, &r, &c);
  M5.Lcd.fillRoundRect(x, y, w, h, r, c);
  return self;
}

// M5.Lcd.drawBitmap(int16_t x0, int16_t y0, int16_t w, int16_t h, const uint16_t *data);
static mrb_value
mrb_lcd_draw_bitmap(mrb_state *mrb, mrb_value self)
{
  mrb_int x, y, w, h;
  mrb_value bmp;
  mrb_get_args(mrb, "iiiiS", &x, &y, &w, &h, &bmp);
  M5.Lcd.drawBitmap(x, y, w, h, (const uint16_t*)RSTRING_PTR(bmp));
  return self;
}

// M5.Lcd.drawChar(uint16_t x, uint16_t y, char c, uint16_t color, uint16_t bg, uint8_t size);
static mrb_value
mrb_lcd_draw_char(mrb_state *mrb, mrb_value self)
{
  mrb_int x, y, chr, fc, bc, sz;
  mrb_get_args(mrb, "iiiiii", &x, &y, &chr, &fc, &bc, &sz);
  M5.Lcd.drawChar(x, y, chr, fc, bc, sz);
  return self;
}

///

static mrb_value
mrb_lcd_set_cursor(mrb_state *mrb, mrb_value self)
{
  mrb_int x, y;
  mrb_get_args(mrb, "ii", &x, &y);
  M5.Lcd.setCursor(x, y);
  return mrb_nil_value();
}

static mrb_value
mrb_lcd_draw_string(mrb_state *mrb, mrb_value self)
{
  mrb_int x, y, c;
  char *s;
  mrb_get_args(mrb, "ziii", &s, &x, &y, &c);
  M5.Lcd.drawCentreString(s, x, y, c);
  return self;
}

static mrb_value
mrb_lcd_set_text_size(mrb_state *mrb, mrb_value self)
{
  mrb_int s;
  mrb_get_args(mrb, "i", &s);
  M5.Lcd.setTextSize((uint8_t)s);
  return mrb_nil_value();
}

static mrb_value
mrb_lcd_set_text_wrap(mrb_state *mrb, mrb_value self)
{
  mrb_bool wx, wy;
  mrb_get_args(mrb, "bb", &wx, &wy);
  M5.Lcd.setTextWrap(wx, wy);
  return self;
}

static mrb_value
mrb_lcd_set_text_color(mrb_state *mrb, mrb_value self)
{
  mrb_int fc;
  mrb_get_args(mrb, "i", &fc);
  M5.Lcd.setTextColor((uint16_t)fc);
  return mrb_nil_value();
}

mrb_value mrb_f_sprintf(mrb_state *mrb, mrb_value obj); /* in sprintf.c */

static mrb_value
mrb_lcd_printf(mrb_state *mrb, mrb_value self)
{
  mrb_value str;
  char *cstr;
  str = mrb_f_sprintf(mrb, self);
  cstr = mrb_str_to_cstr(mrb, str);
  M5.Lcd.print(cstr);
  return self;
}

static mrb_value
mrb_lcd_print(mrb_state *mrb, mrb_value self)
{
  mrb_value *argv;
  mrb_int len;
  mrb_value str;
  char *cstr;

  mrb_get_args(mrb, "*", &argv, &len);
  if (len <= 0) {
    mrb_raise(mrb, E_ARGUMENT_ERROR, "wrong nuber of arguments");
  }
  for (int i = 0; i < len; i++) {
    str = mrb_str_to_str(mrb, argv[i]);
    cstr = mrb_str_to_cstr(mrb, str);
    M5.Lcd.print(cstr);
  }
  return self;
}


///

// Set rotation for text drawing.
// 1..4: left->right
//  1: top->bottom
//  2: right->left
//  3: bottom->top
//  4: left->right
// 5..8: right->left
//  5: bottom->top
//  6: left->right
//  7: top->bottom
//  8: right->left
static mrb_value
mrb_lcd_rotate(mrb_state *mrb, mrb_value self)
{
  mrb_int r;
  mrb_get_args(mrb, "i", &r);
  M5.Lcd.setRotation(r);
  return self;
}

// Get cursor X position (pixel unit)
static mrb_value
mrb_lcd_cx(mrb_state *mrb, mrb_value self)
{
  return mrb_fixnum_value(M5.Lcd.getCursorX());
}

// Get cursor Y position (pixel unit)
static mrb_value
mrb_lcd_cy(mrb_state *mrb, mrb_value self)
{
  return mrb_fixnum_value(M5.Lcd.getCursorY());
}

/// Scroll
// Lcd.readRect() not work. (SPI MISO not connected.)
// #define LINES 8
// static mrb_value
// mrb_lcd_rollup(mrb_state *mrb, mrb_value self)
// {
//   static uint16_t img[320*LINES];
//   int y;
//   for (y=0; y<240-LINES; y+=LINES) {
//     M5.Lcd.readRect(0, y+LINES, 320, LINES, img);
//     M5.Lcd.pushImage(0, y, 320, LINES, (const uint16_t *)img);
//   }
//   return self;
// }

/// Button

static mrb_value
mrb_btn_is_pressed(mrb_state *mrb, mrb_value self)
{
  uint8_t b;
  M5.update();
  b = M5.BtnA.isPressed();
  return mrb_bool_value(b != 0);
}

static mrb_value
mrb_btn_is_released(mrb_state *mrb, mrb_value self)
{
  uint8_t b;
  M5.update();
  b = M5.BtnA.isReleased();
  return mrb_bool_value(b != 0);
}

void
mrb_mruby_lcd_m5stack_gem_init(mrb_state *mrb)
{
  struct RClass *lcd = mrb_define_class(mrb, "LCD",  mrb->object_class);

  // M5.lcd.setBrightness(uint8_t brightness);
  mrb_define_class_method(mrb, lcd, "brightness=", mrb_lcd_set_brightness, MRB_ARGS_REQ(1));

  // M5.Lcd.drawPixel(int16_t x, int16_t y, uint16_t color);
  mrb_define_class_method(mrb, lcd, "pixel", mrb_lcd_pixel, MRB_ARGS_REQ(3));

  // M5.Lcd.drawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color);
  mrb_define_class_method(mrb, lcd, "line", mrb_lcd_line, MRB_ARGS_REQ(5));

  // M5.Lcd.drawRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color);
  mrb_define_class_method(mrb, lcd, "draw_rect", mrb_lcd_draw_rect, MRB_ARGS_REQ(5));

  // M5.Lcd.fillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color);
  mrb_define_class_method(mrb, lcd, "fill_rect", mrb_lcd_fill_rect, MRB_ARGS_REQ(5));

  // M5.Lcd.fillScreen(uint16_t color);
  mrb_define_class_method(mrb, lcd, "fill_screen", mrb_lcd_fill_screen, MRB_ARGS_REQ(1));
  mrb_define_class_method(mrb, lcd, "clear", mrb_lcd_clear, MRB_ARGS_NONE());

  // M5.Lcd.drawCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color);
  mrb_define_class_method(mrb, lcd, "circle", mrb_lcd_circle, MRB_ARGS_REQ(4));

  // M5.Lcd.drawCircleHelper(int16_t x0, int16_t y0, int16_t r, uint8_t cornername,uint16_t color);

  // M5.Lcd.fillCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color);
  mrb_define_class_method(mrb, lcd, "fill_circle", mrb_lcd_fill_circle, MRB_ARGS_REQ(4));

  // M5.Lcd.fillCircleHelper(int16_t x0, int16_t y0, int16_t r, uint8_t cornername,int16_t delta, uint16_t color);

  // M5.Lcd.drawTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint16_t color);
  mrb_define_class_method(mrb, lcd, "triangle", mrb_lcd_triangle, MRB_ARGS_REQ(7));

  // M5.Lcd.fillTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint16_t color);
  mrb_define_class_method(mrb, lcd, "fill_triangle", mrb_lcd_fill_triangle, MRB_ARGS_REQ(7));

  // M5.Lcd.drawRoundRect(int16_t x0, int16_t y0, int16_t w, int16_t h, int16_t radius, uint16_t color);
  mrb_define_class_method(mrb, lcd, "round_rect", mrb_lcd_round_rect, MRB_ARGS_REQ(6));

  // M5.Lcd.fillRoundRect(int16_t x0, int16_t y0, int16_t w, int16_t h, int16_t radius, uint16_t color);
  mrb_define_class_method(mrb, lcd, "fill_round_rect", mrb_lcd_fill_round_rect, MRB_ARGS_REQ(6));

  // M5.Lcd.drawBitmap(int16_t x, int16_t y, const uint8_t bitmap[], int16_t w, int16_t h, uint16_t color);
  // -> M5.Lcd.drawBitmap(int16_t x0, int16_t y0, int16_t w, int16_t h, const uint16_t *data);
  mrb_define_class_method(mrb, lcd, "draw_bitmap", mrb_lcd_draw_bitmap, MRB_ARGS_REQ(5));

  // M5.Lcd.drawRGBBitmap(int16_t x, int16_t y, const uint16_t bitmap[], int16_t w, int16_t h);
  // -> NOT found.

  // M5.Lcd.drawChar(uint16_t x, uint16_t y, char c, uint16_t color, uint16_t bg, uint8_t size);
  mrb_define_class_method(mrb, lcd, "draw_char", mrb_lcd_draw_char, MRB_ARGS_REQ(6));

  // M5.Lcd.setCursor(uint16_t x0, uint16_t y0);
  mrb_define_class_method(mrb, lcd, "set_cursor", mrb_lcd_set_cursor, MRB_ARGS_REQ(2));

  // M5.Lcd.setTextColor(uint16_t color);
  mrb_define_class_method(mrb, lcd, "text_color=", mrb_lcd_set_text_color, MRB_ARGS_REQ(1));

  // M5.Lcd.setTextColor(uint16_t color, uint16_t backgroundcolor);

  // M5.Lcd.setTextSize(uint8_t size);
  mrb_define_class_method(mrb, lcd, "text_size=", mrb_lcd_set_text_size, MRB_ARGS_REQ(1));

  // M5.Lcd.setTextWrap(boolean w);
  // -> M5.Lcd.setTextWrap(boolean w, boolean h);
  mrb_define_class_method(mrb, lcd, "set_text_wrap", mrb_lcd_set_text_wrap, MRB_ARGS_REQ(2));

  // M5.Lcd.printf();
  mrb_define_class_method(mrb, lcd, "printf", mrb_lcd_printf, MRB_ARGS_ANY());

  // M5.Lcd.print();
  mrb_define_class_method(mrb, lcd, "print", mrb_lcd_print, MRB_ARGS_ANY());

  // M5.Lcd.println();

  // M5.Lcd.drawCentreString(const char *string, int dX, int poY, int font);
  mrb_define_class_method(mrb, lcd, "draw_string", mrb_lcd_draw_string, MRB_ARGS_REQ(4));

  // M5.Lcd.drawRightString(const char *string, int dX, int poY, int font);

  // M5.Lcd.drawJpg(const uint8_t *jpg_data, size_t jpg_len, uint16_t x, uint16_t y);

  // M5.Lcd.drawJpgFile(fs::FS &fs, const char *path, uint16_t x, uint16_t y);

  // M5.Lcd.drawBmpFile(fs::FS &fs, const char *path, uint16_t x, uint16_t y);

///
  mrb_define_class_method(mrb, lcd, "rotate", mrb_lcd_rotate, MRB_ARGS_REQ(1));

  mrb_define_class_method(mrb, lcd, "cx", mrb_lcd_cx, MRB_ARGS_NONE());
  mrb_define_class_method(mrb, lcd, "cy", mrb_lcd_cy, MRB_ARGS_NONE());
///

  // TODO: move to Button class
  struct RClass *btn = mrb_define_class(mrb, "Button", mrb->object_class);
  mrb_define_class_method(mrb, btn, "pressed?", mrb_btn_is_pressed, MRB_ARGS_NONE());
  mrb_define_class_method(mrb, btn, "released?", mrb_btn_is_released, MRB_ARGS_NONE());
}

void
mrb_mruby_lcd_m5stack_gem_final(mrb_state *mrb)
{
}

#ifdef __cplusplus
}
#endif
