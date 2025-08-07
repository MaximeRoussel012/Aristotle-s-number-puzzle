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

 
const bool verified(const std::vector<int>& v){
for (int i=0;i<v.size()-1;i++){
    for (int j=i+1;j<v.size();j++){
        if(v[j]==v[i] || v[j]>=20 || v[i]>=20 || v[j]<=0 || v[i]<=0 ){return false;}
    } 
}     
return true;
}


int main() {

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



