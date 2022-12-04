//#include "Base.h"
//Base::Base() {}
//Base::~Base() {}
//void Base::cambiar_x(int nuevo) { x = nuevo; }
//void Base::cambiar_y(int nuevo) { y = nuevo; }
//void Base::cambiar_w(int nuevo) { w = nuevo; }
//void Base::cambiar_h(int nuevo) { h = nuevo; }
//void Base::cambiar_numero(int nuevo) { numero = nuevo; }
//void Base::cambiar_max_fil(int nuevo) { max_fil = nuevo; }
//void Base::cambiar_max_col(int nuevo) { max_col = nuevo; }
//void Base::cambiar_fil(int nuevo) { fil = nuevo; }
//void Base::cambiar_col(int nuevo) { col = nuevo; }
//int Base::retornar_x() { return x; }
//int Base::retornar_y() { return y; }
//int Base::retornar_w() { return w; }
//int Base::retornar_h() { return h; }
//int Base::retornar_numero() { return numero; }
//int Base::retornar_max_fil() { return fil; }
//int Base::retornar_max_col() { return col; }
//Rectangle Base::retornar_rectangle() { return Rectangle(x, y, w, h); }
//Rectangle Base::retornar_rectangle(int x, int y) { return Rectangle(x, y, w, h); }
//void Base::Dibujar_conImagen(Graphics^ g, Bitmap^ bmp)
//{
//	w = bmp->Width / max_col;
//	h = bmp->Height / max_fil;
//	Rectangle porcion = Rectangle(col * w, fil * h, w, h);
//	g->DrawImage(bmp, x, y, porcion, GraphicsUnit::Pixel);
//}