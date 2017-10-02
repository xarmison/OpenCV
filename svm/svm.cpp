//OpenCV
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include "opencv2/imgcodecs.hpp"
#include <opencv2/highgui.hpp>
#include <opencv2/ml.hpp>

using namespace cv;
using namespace cv::ml;

int main(int, char **)
{
    // Representacao visual dos dados 
    int width = 512, height = 512;
    Mat image = Mat::zeros(height, width, CV_8UC3);

    // dados de treinamento 
    int labels[10] = {1, 1, 1, 1, 1, -1, -1, -1, -1, -1};
    float trainingData[10][2] = {{70,70}, {50,50}, {30,30}, {100,120} , {501, 10}, {255, 10}, {501, 255}, {10, 501}, {407, 407}, {508, 210}};

    //Dados como objetos da classe Mat                            
    Mat trainingDataMat(10, 2, CV_32FC1, trainingData);
    Mat labelsMat(10, 1, CV_32SC1, labels);

    // Treinamento da SVM
    Ptr<SVM> svm = SVM::create();
    svm->setType(SVM::C_SVC);
    svm->setKernel(SVM::LINEAR);
    svm->setTermCriteria(TermCriteria(TermCriteria::MAX_ITER, 100, 1e-6));
    svm->train(trainingDataMat, ROW_SAMPLE, labelsMat);

    // Mostra as regioes separadas pela svm
    Vec3b area1(170, 232, 238), area2(238, 238, 175);
    for (int i = 0; i < image.rows; ++i)
        for (int j = 0; j < image.cols; ++j)
        {
            Mat sampleMat = (Mat_<float>(1, 2) << j, i);
            float response = svm->predict(sampleMat);
            if (response == 1)
                image.at<Vec3b>(i, j) = area1;
            else if (response == -1)
                image.at<Vec3b>(i, j) = area2;
        }

    // Show the training data
    int thickness = 1;
    int lineType = 8;
    for(int i=0; i<15; i++){
        circle(image, Point((int)trainingData[i][0], (int)trainingData[i][1]), 5, Scalar(124, 29, 83), thickness, lineType);
    }
  
    // Show support vectors
    thickness = 2;
    lineType = 8;
    Mat sv = svm->getUncompressedSupportVectors();
    for (int i = 0; i < sv.rows; ++i)
    {
        const float *v = sv.ptr<float>(i);
        circle(image, Point((int)v[0], (int)v[1]), 6, Scalar(0, 0, 255), thickness, lineType);
    }

    svm->save("svm.xml");                // salva a svm
    imwrite("result.png", image);        // salva a imagem
    imshow("SVM Simple Example", image); // mostra a imagem
    waitKey(0);
}