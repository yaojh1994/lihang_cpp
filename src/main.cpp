#include <iostream>
#include <string>
#include <armadillo>
#include "Perceptron.hpp"
#include "tool.hpp"

using namespace std;
using namespace arma;

int main() {
  cout << "Test Model: " << endl;
  cout << "1: Perceptron Model" << endl;
  int model_num;
  cin >> model_num;
  switch (model_num) {
    case 1: {
 	    cout << "Perceptron Model Selected: " << endl;
 	    cout << "Start training: " << endl;
      arma::mat data;
      data.load("data/train_binary.csv");
      int ncol = data.n_cols;
      int nrow = data.n_rows;
      int sample_size = 10000;
      mat features_train = data.submat(0, 1, nrow - sample_size - 1, ncol - 1);
      vec labels_train = data.col(0).subvec(0, nrow - sample_size - 1);
      mat features_test = data.submat(nrow - sample_size, 1, nrow - 1, ncol - 1);
      vec labels_test = data.col(0).subvec(nrow - sample_size, nrow - 1);
      Perceptron perceptron(0.001, 5000);
      perceptron.train(features_train, labels_train, true);
      vec labels_pre_train = perceptron.predict(features_train);
      vec labels_pre_test = perceptron.predict(features_test);
      double res_train = 1 - mean(arma::abs(labels_train - labels_pre_train));
      double res_test = 1 - mean(arma::abs(labels_test - labels_pre_test));
      cout << "训练集准确率: " << res_train << endl;
      cout << "测试集准确率: " << res_test << endl;
      break;
    }
    default:
      break;
  }
  return 0;
}


