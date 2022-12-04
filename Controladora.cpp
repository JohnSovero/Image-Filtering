#include "Controladora.h"
Controladora::Controladora(){}
Controladora::~Controladora(){}
Bitmap^ Controladora::FiltrarImagen(Graphics^ g, Bitmap^ bmp)
{
	double bn;
	Color color, ColorBN;
	for (int i = 0; i < bmp->Width; i++) {
		for (int j = 0; j < bmp->Height; j++) {
			color = bmp->GetPixel(i, j);
			bn = (int)((color.R + color.G + color.B)/3);
			ColorBN = Color::FromArgb(bn, bn, bn);
			bmp->SetPixel(i, j, ColorBN);
		}
	}
	return bmp;
}
// Esta funcion elimina los valores que no nos interesan (red, green, blue, alpha)
// y pasa solo los valores que nos interesan (escala de grises)
vector<vector<int>> Controladora::convertToMatrix(Bitmap^ bmp)
{
	vector<vector<int>> aux_matrix (bmp->Height, vector<int>(bmp->Width));
	for (int i = 0; i < bmp->Height; i++) {
		for (int j = 0; j < bmp->Width; j++) {
			aux_matrix[i][j] = bmp->GetPixel(j, i).R;
		}
	}
	matrix = aux_matrix;
	return matrix;
}
// Esta funcion devuelve el pixel en una cierta coordenada(x,y) y los pixeles vecinos
vector<int> Controladora::getValues(vector<vector<int>> matrix, int x, int y, int matrixSize, bool addO = true)
{
	vector<int> values;
	int aux = floor(matrixSize / 2);

	for (int i = 0; i < matrixSize; i++) {
		for (int j = 0; j < matrixSize; j++) {
			if (
				x - aux + j < 0 ||
				x - aux + j >= matrix[y].size() ||
				y - aux + i < 0 ||
				y - aux + i >= matrix.size()
				) {
				if (addO) values.push_back(0);
				continue;
			}
			values.push_back(matrix[y - aux + i][x - aux + j]);
		}
	}
	return values;
}
// Esta funcion pasa la matriz de valores en escala de grises a los valores (red, green, blue) para poder crear la nueva imagen
Bitmap^ Controladora::convertToPixels(vector<vector<int>> matrixCopia, Bitmap^ bmp)
{
	int bn;
	Color ColorBN;
	for (int i = 0; i < bmp->Width; i++) {
		for (int j = 0; j < bmp->Height; j++) {
			bn = matrixCopia[j][i];
			ColorBN = Color::FromArgb(bn,bn,bn);
			bmp->SetPixel(i, j, ColorBN);
		}
	}
	return bmp;
}
vector<vector<int>> Controladora::filtroMediana(Bitmap^ bmp, int matrixSize)
{
	// inicializacion de la matriz que contendra los nuevos valores de la imagen (despues de aplicar el filtro)
	vector<vector<int>> matrixCopia(bmp->Height, vector<int>(bmp->Width));
	// Doble bucle for para recorrer todos los pixeles de nuestra imagen
	for (int y = 0; y < bmp->Height; y++) {
		for (int x = 0; x < bmp->Width; x++) {
			vector<int> values;
			values = getValues(matrix, x, y, matrixSize, false);
			int newPixelValue;
			//se ordena los valores obtenidos de la vecindad
			sort(values.begin(), values.end());
			//encontramos la mediana
			if (values.size() % 2 == 0) {
				int mid1 = values[floor(values.size() / 2)];
				int mid2 = values[floor(values.size() / 2 - 1)];
				newPixelValue = round((mid1 + mid2) / 2);
			}
			else newPixelValue = values[floor(values.size() / 2)];
			matrixCopia[y][x] = newPixelValue;
		}
	}
	return matrixCopia;
}
vector<vector<int>> Controladora::filtroMedia(Bitmap^ bmp, int mascara[], int divisor)
{
	// inicializacion de la matriz que contendra el los nuevos valores de la imagen (despues de aplicar el filtro)
	vector<vector<int>> matrixCopia(bmp->Height, vector<int>(bmp->Width));
	// Doble bucle for para recorrer todos los pixeles de nuestra imagen
	for (int y = 0; y < bmp->Height; y++) {
		for (int x = 0; x < bmp->Width; x++) {
			vector<int> values;
			values = getValues(matrix, x, y, 3);
			int suma = 0;

			// Se multiplican los valores de la vecindad y la mascara elegida y se acumulan en la variable suma
			for (int j = 0; j < values.size(); j++) {
				suma += values.at(j) * mascara[j] ;
			}
			int newPixelValue = round(suma / divisor);
			matrixCopia[y][x] = newPixelValue;
		}
	}
	return matrixCopia;
}
vector<vector<int>> Controladora::filtroLaplaciano(Bitmap^ bmp, int mascara[])
{
	// inicializacion de las variables mayor y menor
	// Estas variables nos serviran mas adelante para reescalar el histograma
	int mayor = 0;
	int menor = 0;
	vector<vector<int>> matrixCopia(bmp->Height, vector<int>(bmp->Width));
	// Doble bucle for para recorrer todos los pixeles de nuestra imagen
	for (int y = 0; y < bmp->Height; y++) {
		for (int x = 0; x < bmp->Width; x++) {
			vector<int> values;
			values = getValues(matrix, x, y, 3);
			int suma = 0;

			// Se multiplican los valores de la vecindad y la mascara elegida y se acumulan en la variable suma
			for (int j = 0; j < values.size(); j++) {
				suma += values.at(j) * mascara[j];
			}
			int newPixelValue = round(suma);
			if (newPixelValue > mayor) mayor = newPixelValue;
			if (newPixelValue < menor) menor = newPixelValue;
			matrixCopia[y][x] = newPixelValue;
		}
	}
	matrixCopia = reescalarHistograma(matrixCopia, menor, mayor);
	return matrixCopia;
}
vector<vector<int>> Controladora::filtroSobel(Bitmap^ bmp, int mascara[])
{
	int mayor = 0;
	int menor = 0;
	vector<vector<int>> matrixCopia(bmp->Height, vector<int>(bmp->Width));
	for (int y = 0; y < bmp->Height; y++) {
		for (int x = 0; x < bmp->Width; x++) {
			vector<int> values;
			values = getValues(matrix, x, y, 3);
			int suma = 0;

			// Se multiplican los valores de la vecindad y la mascara elegida y se acumulan en la variable suma
			for (int j = 0; j < values.size(); j++) {
				suma += values.at(j) * mascara[j];
			}
			int newPixelValue = round(suma);
			if (newPixelValue > mayor) mayor = newPixelValue;
			if (newPixelValue < menor) menor = newPixelValue;
			matrixCopia[y][x] = newPixelValue;
		}
	}
	matrixCopia = reescalarHistograma(matrixCopia, menor, mayor);
	return matrixCopia;
}
vector<vector<int>> Controladora::reescalarHistograma(vector<vector<int>> histograma, int menor, int mayor) 
{
	double m = 255 / (double)(mayor - menor);
	double b = -m * menor;
	for (int i = 0; i < histograma.size(); i++){
		for (int j = 0; j < histograma[i].size(); j++){
			histograma[i][j] = ecuacion(m, histograma[i][j], b);
		}
	}
	return histograma;
}
double Controladora::ecuacion(double m, int r, double b)
{
	return round(round((m * r + b) * 100) / 100);
}
