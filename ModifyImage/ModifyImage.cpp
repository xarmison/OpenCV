#include<opencv2/opencv.hpp>

using namespace cv;

int main(int argc, char **argv){
    //pega a imagem passada como argumento
    char* imageName = argv[1];
    Mat image;
    image = imread(imageName, IMREAD_COLOR);

    //checa se um argumento foi passado
    if (argc != 2 || !image.data)
    {
        printf("Nenhuma imagem foi passada\n");
        return -1;
    }

    //transforma a imagem para gray scale
    Mat gray_image;
    cvtColor(image, gray_image, COLOR_BGR2GRAY);

    //salva a imagem em gray scale
    imwrite("./GRAY_IMAGE.jpg", gray_image);

    //cria uma janela para cada imagem 
    namedWindow(imageName, WINDOW_AUTOSIZE);
    namedWindow("Gray Image FUCK YEAH!", WINDOW_AUTOSIZE);

    //mostra as imagens nas janelas 
    imshow(imageName, image);
    imshow("Gray Image FUCK YEAH!", gray_image);

    //espera ate uma tecla ser digitada
    waitKey(0);
    return 0;
}

