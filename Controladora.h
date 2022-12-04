#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <algorithm>
using namespace System::Drawing;
using namespace std;
using namespace std;
class Controladora
{
private:
    vector<vector<int>> matrix;
public:
    Controladora();
    ~Controladora();
    Bitmap^ FiltrarImagen(Graphics^ g, Bitmap^ bmp);
    vector<vector<int>> convertToMatrix(Bitmap ^ imagen);
    Bitmap^ convertToPixels(vector<vector<int>> matrizCopia, Bitmap^ bmp);
    vector<int> getValues(vector<vector<int>> matrix, int x, int y, int matrixSixe, bool addO);
    vector<vector<int>> filtroMediana(Bitmap^ bmp, int n);
    vector<vector<int>> filtroMedia(Bitmap^ bmp, int mascara[], int divisor);
    vector<vector<int>> filtroLaplaciano(Bitmap^ bmp, int mascara[]);
    vector<vector<int>> filtroSobel(Bitmap^ bmp, int mascara[]);
    vector<vector<int>> reescalarHistograma(vector<vector<int>> matrixcopia, int menor, int mayor);
    double ecuacion(double m, int r, double b);
};