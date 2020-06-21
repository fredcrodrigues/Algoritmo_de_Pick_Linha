
#include <iostream>
#include <string>
#include <math.h>

using namespace std;

const int TOL= 0; // 0000 
const int ESQU = 1; // 0001 
const int DIR = 2; // 0010 
const int EMBAIXO = 4; // 0100 
const int EMCIMA = 8; // 1000 

const int x_max = 4; 
const int y_max = 4; 
const int x_min = 4; 
const int y_min = 4; 


const double PI =  3.1415926;
/* QUESTÃO 1
int Pmedio( double resultado , double m1){
    
    int x , y;
    
    x = m1;
    
    y = x - resultado;
    
    
   return y;
    
}

int fPontos( double x1 , double y1 , double x2 , double y2 ,  double m1 , double m2 ){
    
    int r1 , r2 , mfim , resul , saida;
    
    r1 = y2 - y1;
    
    r2 = x2 - x1;
    
    mfim= r1 / r2;
    
    
    resul = mfim * (-x1) + y1;
     
    saida = Pmedio(resul , m1);
   
        if (((saida < x_min)&&(m2 < y_min))||((saida> x_max)&&(m2 > y_max)))
             cout << "Ponto fora da região de tolerancia ";
        else
            cout <<  " Ponto na região" ;
        
    return saida;
   
    }
  
int main()
{
  
  
   int resultado = fPontos( 1 , 2 , 3 , 4 , 2, 3);
   
 
  
}*/ 
/* QUESTÃO 2
int DPmedio( double x1 , double y1 , double m1 , double m2){
    
    int r1 , r2 , pot1 , pot2 , resul;
    
    r1 = m2 - y1;
    
    pot1 = pow(r1 ,2 );
    
    r2 = m2 - x1;
    
    pot2 = pow(r2 , 2);
    
    resul = sqrt(pot1 + pot2);
    
   return resul;
    
}
int GerarCodigo(double x, double y) 
{ 
   
    int code = TOL; 
  
    if (x < x_min) 
        code |= ESQU; 
    else if (x > x_max) 
        code |= DIR; 
    if (y < y_min)
        code |=  EMBAIXO  ; 
    else if (y > y_max)
        code |= EMCIMA; 
  
    return code; 
} 
int fPontos( double x1 , double y1 , double x2 , double y2 ,  double m1 , double m2 ){
    
    int r1 , r2 ,  resul , saida , pot1 , pot2 , MP1 , MP2;
    
    r1 = y2 - y1;
    
    pot1 = pow(r1 ,2 );
    
    r2 = x2 - x1;
    
    pot2 = pow(r2 , 2);
    
    resul = sqrt(pot1 + pot2); // resultado P1 E P2
    
    MP1 = DPmedio(x1 , y1 , m1 , m2); //calculo da distancia em M em relação a P1
    MP2 = DPmedio(x2 , y2 , m1 , m2); //calculo da distancia em M em relação a P2
    
    saida = GerarCodigo(MP1 ,MP2);
    
        if (saida == 0) { 
           
           cout << "tolerancia" << endl;
        }
        else{
            cout << "tddolerancia" << endl;
        }
        
    }
int main()
{
  
  
   int resultado = fPontos(  4, 4 , 4 , 4 , 4, 4);
   
 
  
}*/


/* QUESTÃO 3 


int calcAngulo (double v1x , double v1y , double v2x , double v2y ){
    int cossteta ,  resultado;
    
    
    cossteta = (v1x * v2x) + (v1y * v2y) / (sqrt(pow(v1x,2)+pow(v2x, 2 ))) * (sqrt( pow(v1y ,2) + pow(v2y , 2)));
    
    
    // converte em graus
    
    resultado = acos(cossteta)*180/PI;
    
    return resultado;
     
    
    
    
    
}


int fPontos(double m1 , double m2 ){
    int P1x , P1y , P2x , P2y , P3x , P3y ,P4x, P4y;
    int v1  , cv1x , cv1y , v2 , cv2x , cv2y , v3 , cv3y ,  cv3x , v4 , cv4x ,  cv4y ;
    int saida1 ,  saida2 , saida3 , saida4 , soma; 
   // ponto P1
   P1x = 4;
   P1y = 2;
   
   
   // ponto P2
   P2x = 4;
   P2y = 2;
   
   
   // ponto P3
   
   P3x = 4;
   P3y = 2;
   
   // ponto P4
   P4x = 4;
   P4y = 2;
   
   
    //coordenadas do vetor1
    cv1x   = (P1x - m1); 
    cv1y   = (P1y - m2); 
    
     //coordenadas do vetor2
    cv2x = (P2x - m1); 
    cv2y = (P2y - m2); 
    
    //coordenadas do vetor3
    cv3y = ( P3x - m2);
    cv3x = ( P3y - m2);
     //coordenadas do vetor4
    cv4x = (P4x - m2);
    cv4y = (P4y - m2);
    
    // calculo do angulo do vetor v1 e v2
    
   saida1 = calcAngulo(cv1x , cv1y , cv2x , cv2y);
   
   // calculo do angulo do vetor v1 e v2
   
   saida2 = calcAngulo(cv2x , cv2y , cv3y , cv3x);
   
   // calculo do angulo do vetor v3 e v4   
   
   saida3 = calcAngulo(cv3y , cv3x , cv4x , cv4y);
   
   // calculo do angulo do vetor v4 e v1
   saida4 = calcAngulo(cv4x , cv4y ,cv1x , cv1y);
   
   
   
    soma = saida4 + saida3 +saida2 +saida1;
    
    if(soma == 360)
    
        cout << "Ponto interno  " << endl;
    else 
        cout << "Ponto extterno  " << endl;



     return soma;
     
}
int main()
{
  // poligono com  4 lados 
  // 4  pontos
  // 4 vertices
  // ponto medio
  
  // P1 , P2,  P3 , P4  
   int resultado = fPontos( 4, 4 );
 
  return 0;
}*/

/* QUESTÃO 4  */


int equacaoIm( double P1x, double P1y , double P2x , double P2y,  double  cv1x ,  double  cv1y ){
    int resultado;
     
    resultado = (P1y - P2y)*cv1x  + (P2x - P1x) * cv1y  + ((P1x*P2y) + (P2x * P1y));
    
    return resultado;
    
    
}

int fPontos(double m1 , double m2 ){
   
    int P1x , P1y , P2x , P2y , P3x , P3y ,P4x, P4y;
    
    int v1  , cv1x , cv1y , v2 , cv2x , cv2y , v3 , cv3y ,  cv3x , v4 , cv4x ,  cv4y ;
    int eqimp1 , eqimp2 , eqimp3 , eqimp4;
    
   // ponto P1
   P1x = 4;
   P1y = 2;
   
   
   // ponto P2
   P2x = 4;
   P2y = 2;
   
   
   // ponto P3
   
   P3x = 4;
   P3y = 2;
   
   // ponto P4
   P4x = 4;
   P4y = 2;
  
   
   //coordenadas do vetor1
    cv1x   = (P1x - m1); 
    cv1y   = (P1y - m2); 
    
     //coordenadas do vetor2
    cv2x = (P2x - m1); 
    cv2y = (P2y - m2); 
    
    //coordenadas do vetor3
    cv3y = ( P3x - m2);
    cv3x = ( P3y - m2);
     //coordenadas do vetor4
    cv4x = (P4x - m2);
    cv4y = (P4y - m2);
   
    // substituir as coordenadas do vetor nos pontos para encontrar a implicita
    //EQUAÇÃ DA RETA IMPLICITA AX +BY + C = 0 A
    // calculo apenas do v1 , v2
    eqimp1 = equacaoIm(P1x ,P1y , P2x , P2y , cv1x , cv1y);
    eqimp2 = equacaoIm(P3x ,P3y , P4x , P4y ,  cv2x , cv2y);
    
    if ((eqimp1 > 0)&&(eqimp2 > 0))
        cout << "ponto a direita da reta" << endl;
    if((eqimp1 == 0)&&(eqimp2 == 0))
        cout << "ponto sobre a reta" << endl;
    if((eqimp1 < 0)&&(eqimp2 < 0))
        cout << "ponto esquerda da reta" << endl;


    return eqimp1;
     
}

int main()
{
  // EQUAÇÃ DA RETA IMPLICITA AX +BY + C = 0 A  A = Y1 - Y2	B = X2 - X1	C = X1*Y2 - X2*Y1
  
  // P1 , P2,  P3
  int resultado = fPontos( 4, 4 );
 
  return 0;
}
