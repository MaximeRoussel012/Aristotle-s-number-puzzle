#include <Eigen/Core>
#include <Eigen/LU>
#include <Eigen/SVD>
#include <Eigen/Dense>
#include <cmath>
#include<list>
#include<vector>
#include <iostream>
#include<algorithm>

using namespace std;
using namespace Eigen;
int n=19;
 

int main() {
   
MatrixXd A =Eigen::MatrixXd::Zero(n,n);

//4 conditions lignes
  A(0,0) = 1;  A(0,1) = 1;  A(0,2) = 1;
  A(1,3) = 1;  A(1,4) = 1;  A(1,5) = 1;  A(1,6) = 1;
  A(2,7) = 1;  A(2,8) = 1;  A(2,9) = 1;  A(2,10) = 1;  A(2,11) = 1;
  A(3,12) = 1;  A(3,13) = 1;  A(3,14) = 1;  A(3,15) = 1;
  //4 conditions diagonnales "/"
  A(4,0) = 1;  A(4,3) = 1;  A(4,7) = 1;
  A(5,1) = 1;  A(5,4) = 1;  A(5,8) = 1;  A(5,12) = 1;
  A(6,2) = 1;  A(6,5) = 1;  A(6,9) = 1;  A(6,13) = 1;  A(6,16) = 1;
  A(7,6) = 1;  A(7,10) = 1;  A(7,14) = 1;  A(7,17) = 1;
  //4 conditions diagonnales"\"
  A(8,2) = 1;  A(8,6) = 1;  A(8,11) = 1;
  A(9,1) = 1;  A(9,5) = 1;  A(9,10) = 1;  A(9,15) = 1;
  A(10,0) = 1;  A(10,4) = 1;  A(10,9) = 1;  A(10,14) = 1;  A(10,18) = 1;
  A(11,3) = 1;  A(11,8) = 1;  A(11,13) = 1;  A(11,17) = 1;
  // 6 conditions pour imposer les coins
  A(12,0)= 1;
  A(13,1)= 1;
  A(14,6)= 1;
  A(15,15)=1;
  A(16,17)=1;
  A(17,12)=1;
  // la condition du cercle intérieur 
  A(18,4)=1; 
  
  
 //code pour vérifier que la matrice A est de rang 19 et donc qu'elle est bien inversible
 JacobiSVD<Eigen::MatrixXd> svd(A);
 const double epsilon = 1e-10;  // Tolérance numérique pour considérer un zéro
 int rank = (svd.singularValues().array() > epsilon).count();
 cout<<"la matrice \n"<< A <<endl<< "son rang "  << rank <<  " et de det "<< A.determinant() << endl; 



return 0;
}


