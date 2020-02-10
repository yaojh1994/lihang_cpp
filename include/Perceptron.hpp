#ifndef PERCEPTRON_HPP
#define PERCEPTRON_HPP

#include <iostream>
#include <string>
#include <armadillo>
#include "tool.hpp"

using namespace std;
using namespace arma;

class Perceptron {
  double learning_ratio;
  int max_iteration;

public:
  vec w;
  
  Perceptron(double lr, int mi) {
    learning_ratio = lr;
    max_iteration = mi;
  }

  void train(mat features, vec labels, bool verbose = false) {
    int ncol = features.n_cols;
    int nrow = features.n_rows;
    w.resize(ncol + 1);
    w.fill(0.0);
    vec b = ones<vec>(nrow);
    features.insert_cols(ncol, b);
    labels.for_each([](mat::elem_type &val) { val = val * 2 - 1;});
    int correct_count = 0;
    int count = 0;
    int index = 0;
    rowvec x;
    double y;
    double wx;

    while (true) {
      index = random(nrow);
      x = features.row(index);
      y = labels[index];
      wx = dot(w, x);
      if (verbose && (count++) % 100 == 0) {
        cout << "count: " << count++ << "    ";
        cout << "correct_count: " << correct_count << endl;
      }
      if (wx * y > 0) {
        correct_count += 1;
        if (correct_count > max_iteration) {
          break;
        }
        continue;
      }
      w = w + learning_ratio * y * x.t();
    }
  }

  vec predict(mat features) {
    int ncol = features.n_cols;
    int nrow = features.n_rows;
    vec b = ones<vec>(nrow);
    features.insert_cols(ncol, b);
    vec label = features * w;
    label.for_each([](mat::elem_type &val) {
      if (val > 0) {
        val = 1;
      } else {
        val = 0;
      }
    });
    return label;
  }

};

#endif