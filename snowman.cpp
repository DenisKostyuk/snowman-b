#include <iostream>
#include <string>
#include <array>
#include "snowman.hpp"
using namespace std;

namespace ariel {   
    const int zero = 0;
    const int one = 1;
    const int two = 2;
    const int three = 3;
    const int four = 4;
    const int five = 5;
    const int six = 6;
    const int seven = 7;
    const int eight = 8;
    const int ten = 10;
    string snowman(int a){
        std::string snowmanRet;
        int count = zero;
        int reversedNumber = zero;
        int remainder = zero;
        while(a != zero) { // makes a reverse to the input
            remainder = a%ten;
            reversedNumber = reversedNumber*ten + remainder;
            a /= ten;
        }
        int numberInput = reversedNumber; //will check the number of digits of the input
        while(numberInput != zero) {
            numberInput = numberInput / ten;
            count++;
        }
        if(count == eight){
            std::array<string,eight> snowman;
            std::array<string,four> hats = {" _===_" , "  ___\n ....." , "   _\n  /_\\" , "  ___\n (_*_)"}; // hat
            std::array<string,four> nose = {"," , "." , "_" , " "}; // nose
            std::array<string,four> leftEye = {"." , "o" , "O" , "-"}; // left eye
            std::array<string,four> rightEye = {"." , "o" , "O" , "-"}; //right eye
            std::array<string,four> X = {"<" , "\\" , "/" , " "}; // left arm
            std::array<string,four> Y = {">" , "/" , "\\" , " "}; // right arm
            std::array<string,four> T = {" : " , "] [", "> <", "   "}; //torso
            std::array<string,four> B = {" : ", "\" \"", "___" , "   "}; // base
            int curr = zero;
            std::string structure = {"HNLRXYTB"};
            int counter = zero;
            int leftArmRaised = zero; 
            int rightArmRaised = zero;
            int True = one;
            int False = zero;
            while(reversedNumber != zero ){ // always gets the number and init the snowman with the right element
                char partOfBody = structure.at(counter);
                curr = reversedNumber%ten;
                if(curr < zero || curr > four || curr == zero ){
                    throw std::out_of_range("Invalid input");    
                }
                if(partOfBody == 'H'){
                    snowman.at(counter) = hats.at(curr-one);
                }else if(partOfBody == 'N'){
                    snowman.at(counter) = nose.at(curr-one);
                }else if(partOfBody == 'L'){
                    snowman.at(counter) = leftEye.at(curr-one);
                }else if(partOfBody == 'R'){
                     snowman.at(counter) = rightEye.at(curr-one);
                }else if(partOfBody == 'X'){
                    snowman.at(counter) = X.at(curr-one); //left arm
                    if(curr == two){
                        leftArmRaised = True;
                    }
                }else if(partOfBody == 'Y'){
                    snowman.at(counter) = Y.at(curr-one); //right arm
                    if(curr == two){
                        rightArmRaised = True;
                    }
                }else if(partOfBody == 'T'){
                    snowman.at(counter) = T.at(curr-one);
                }else if(partOfBody == 'B'){
                    snowman.at(counter) = B.at(curr-one);
                }
                reversedNumber = reversedNumber/ten;
                counter = counter + one;
            }
            if(leftArmRaised == True && rightArmRaised == False){
                snowmanRet = snowman[zero]+"\n"+"\\("+snowman[two]+snowman[one]+snowman[three]+")"+"\n"+" ("+snowman[six]+")"+snowman[five]+"\n"+" ("+snowman[seven]+")";
            }else if(leftArmRaised == False && rightArmRaised == True){
                snowmanRet = snowman[zero]+"\n"+" ("+snowman[two]+snowman[one]+snowman[three]+")/"+"\n"+snowman[four]+"("+snowman[six]+")"+"\n"+" ("+snowman[seven]+")";
            }
            else if(leftArmRaised ==  True && rightArmRaised == True){
                snowmanRet = snowman[zero]+"\n"+"\\("+snowman[two]+snowman[one]+snowman[three]+")/"+"\n"+" ("+snowman[six]+")"+"\n"+" ("+snowman[seven]+")";
            }
            else{
                snowmanRet = snowman[zero]+"\n"+" ("+snowman[two]+snowman[one]+snowman[three]+")"+"\n"+snowman[four]+"("+snowman[six]+")"+snowman[five]+"\n"+" ("+snowman[seven]+")";
            }
        }
        else{
            throw std::out_of_range("Invalid input");
        }
        return snowmanRet;
    }
}

