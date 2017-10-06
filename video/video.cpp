#include <opencv2/opencv.hpp>
#include <iostream>
#include <stdio.h>

using namespace cv;
using namespace std;

int main(int, char **){
    Mat frame;
    //Cria o objeto camera 
    VideoCapture cap;
    // Abre a camera padrao
    cap.open(0);
    
    // Verifica se foi aberto 
    if (!cap.isOpened()){
        cerr << "ERROR! Camera nao encontrada\n";
        return -1;
    }
    //--- Comeca o loop de captura 
    cout << "Comecando live" << endl
         << "Pressione qualquer tecla para terminar" << endl;
    for (;;){
        // Espera por um novo e salva um novo'frame'
        cap.read(frame);
        // Verifica se o frame foi capturado
        if (frame.empty())
        {
            cerr << "ERROR! frame em branco capturado\n";
            break;
        }
        // mostra a livre e espera tempo suficiente para para o termino se solicitado
        imshow("Live", frame);
        if (waitKey(5) >= 0)
            break;
    }
    // A camera e desinicializada automaticamente  
    return 0;
}