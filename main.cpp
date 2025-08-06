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
 
const bool verified(const std::vector<int>& v){
for (int i=0;i<v.size()-1;i++){
    for (int j=i+1;j<v.size();j++){
        if(v[j]==v[i] || v[j]>=20 || v[i]>=20 || v[j]<=0 || v[i]<=0 ){return false;}
    } 
}     
return true;
}


int main() {
/*   
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
  
  
 //code pour vérifier que la matrice A est de rang 19 et donc qu'elle est inversible
 JacobiSVD<Eigen::MatrixXd> svd(A);
 const double epsilon = 1e-10;  // Tolérance numérique pour considérer un zéro
 int rank = (svd.singularValues().array() > epsilon).count();
 cout<<"la matrice \n"<< A <<endl<< "son rang "  << rank <<  " et de det "<< A.determinant() << endl; 
 */

//détrerminons toutes les combinaisons possible et classons les dans un vecteur de vecteurs
std::vector<std::vector<int>> v(20);
v[0]={0};
for (int i=1;i<20;i++){
    for (int j=1;j<1+(38-i)/2;j++){
        int k= 38-i-j;
        if(i!=j && i!=k && j!=k && k<20 && k>0){ 
        v[i].push_back(j);
        v[i].push_back(k);    
        } 
    }
} 
/*
const std::vector<std::vector<int>> v= {{0},
{18,19},
{17,19},
{16,17,18,19},
{15,16,18,19},
{14,15,16,17,18,19},
{13,14,15,17,18,19},
{12,13,14,15,16,17,18,19},
{11,12,13,14,16,17,18,19},
{10,11,12,13,14,15,16,17,18,19},
{9,11,12,13,15,16,17,19},
{8,9,10,12,13,14,15,17,18,19},
{7,8,9,10,11,15,16,17,18,19},
{6,7,8,9,10,11,14,15,16,17,18,19},
{5,6,7,8,9,11,13,15,16,17,18,19},
{4,5,6,7,9,10,11,12,13,14,16,17,18,19},
{3,4,5,7,8,9,10,12,13,14,15,17,18,19},
{2,3,5,6,7,8,9,10,11,12,13,14,15,16,18,19},
{1,3,4,5,6,7,8,9,11,12,13,14,15,16,17,19}, 
{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18},
};*/

const std::list<int> num = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
std::list<std::vector<int>> soluces;


for(int a=3;a<=19;a++){
    for (int b: v[a]){
        int c =38-b-a;
        for (int d : v[c]){
            int e=38-d-c;
            for (int f : v[e]){
                int g = 38-e-f;
                for (int h: v[g]){
                    int i=38-h-g;
                    for(int j:v[i]){
                        int k= 38-j-i;
                        int l= 38-k-a;
                        std::vector<int> bord ={a,b,c,d,e,f,g,h,i,j,k,l}; //représente les nombres sur les bords 
                        if(verified(bord)){
                            std::list<int> rest= num;
                            rest.remove(a);
                            rest.remove(b);
                            rest.remove(c);
                            rest.remove(d);
                            rest.remove(e);
                            rest.remove(f);
                            rest.remove(g);
                            rest.remove(h);
                            rest.remove(i);
                            rest.remove(j);
                            rest.remove(k);
                            rest.remove(l);
                            for (int m : rest){
                                int n= 38-m-b-j;
                                int o= 38-n-l-h;
                                int p= 38-o-j-f;
                                int q=38-p-h-d;
                                int r=38-b-q-f;
                                int s=38-r-c-o-i;
                                std::vector<int> sol={a,b,c,l,m,r,d,k,n,s,q,e,j,o,p,f,i,h,g};
                                if(verified(sol)){soluces.push_back(sol);}
                            }
                        }                         
                    } 
                }
            }
        }
    }
}


for (auto sol : soluces){
    for (int element : sol){
        std::cout<< element << " ";
    }
    std::cout<< '\n';
}



return 0;
}


