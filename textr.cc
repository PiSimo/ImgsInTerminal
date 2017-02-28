#include <opencv2/opencv.hpp>
#include <opencv2/ml.hpp>
#include <iostream>

using namespace std;
using namespace cv;
using namespace cv::ml;

/** Black Blue Green Red White Grey Yellow Grey_2 **/
string colors[] = {"30","31","32","34","47","33","37"};

int main(int argc,char* argv[]){
  if(argc != 2){
    cout<<argv[0]<<" image\n";
  }
  
  int len = 8;
  Mat m = imread(argv[1]),sample(len,3,CV_32F),labels(len,1,CV_32S);
  if(m.empty()){
    cout<<"Error image is empty!\n";
    return -1;
  }

  int w = m.size().width;
  int h = m.size().height;
  if(w > 130 && h > 130){
    if(w > h){
      h = (h*130)/w;
      w = 130;
    }else if(h > w){
      w = (w*130) / h;
      h = 130;
    }else{
      w = 130;
      h = 130;
    }
  }
  //w = 90;
  resize(m,m,Size(w,h));

  sample.at<float>(0,0) =0,sample.at<float>(0,1) =0,sample.at<float>(0,2) =0; //#000
  sample.at<float>(1,0) =0,sample.at<float>(1,1) =0,sample.at<float>(1,2) =255; //00f
  sample.at<float>(2,0) =0,sample.at<float>(2,1) =255,sample.at<float>(2,2) =0; //0f0
  sample.at<float>(3,0) =255,sample.at<float>(3,1) =0,sample.at<float>(3,2) =0; //f00
  sample.at<float>(4,0) =255,sample.at<float>(4,1) =255,sample.at<float>(4,2) =255; //fff
  sample.at<float>(5,0) =100,sample.at<float>(5,1) =100,sample.at<float>(5,2) =100; //999
  sample.at<float>(6,0) =30,sample.at<float>(6,1) = 200,sample.at<float>(6,2) = 200; //1ff
  sample.at<float>(7,0) =170,sample.at<float>(6,1) = 170,sample.at<float>(6,2) = 170; //1ff


  for(int i = 0;i  != len;i++){
    labels.at<int>(i,0) = i;
  }

  Ptr<ml::KNearest> knn = ml::KNearest::create();
  knn->train(sample, ml::ROW_SAMPLE,labels);
  if(!knn->isTrained()){cout<<"Error !\n";return -1;}

  for(int i= 0;i != h;i++){
    for(int k = 0;k != w;k++){
      Mat px(1,3,CV_32F);
      for(int l = 0;l != 3;l++)px.at<float>(0,l) = m.at<Vec3b>(i,k)[l];
      Mat res;
      knn->findNearest(px,2,res);
      int f = res.at<float>(0,0);
      if(f != 4){cout<<"\033[0;"<<colors[(int)f]<<"m #"<<"\033[0m";}
      else cout<<" #"  ;
    }
    cout<<endl;
  }

  return 0;
}
