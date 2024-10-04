// Online C++ compiler to run C++ program online
#include <iostream>
#include<random>
#include<map>

int n,val,temp,k,i;
int score[10]={0};
char a;
int wins=0;

std::map<int,int> m; //to assign the values of

void printboard(){
    std::cout<<" ---+---+---+---+---+---+---+---+---+---\n";
    std::cout<<"| "<<m[100]<<" | "<<m[99]<<" | "<<m[98]<<" | "<<m[97]<<" | "<<m[96]<<" | "<<m[95]<<" | "<<m[94]<<" | "<<m[93]<<" | "<<m[92]<<" | "<<m[91]<<" |\n";
    std::cout<<" ---+---+---+---+---+---+---+---+---+---\n";
    std::cout<<"| "<<m[81]<<" | "<<m[82]<<" | "<<m[83]<<" | "<<m[84]<<" | "<<m[85]<<" | "<<m[86]<<" | "<<m[87]<<" | "<<m[88]<<" | "<<m[89]<<" | "<<m[90]<<" |\n";
    std::cout<<" ---+---+---+---+---+---+---+---+---+---\n";
    std::cout<<"| "<<m[80]<<" | "<<m[79]<<" | "<<m[78]<<" | "<<m[77]<<" | "<<m[76]<<" | "<<m[75]<<" | "<<m[74]<<" | "<<m[73]<<" | "<<m[72]<<" | "<<m[71]<<" |\n";
    std::cout<<" ---+---+---+---+---+---+---+---+---+---\n";
    std::cout<<"| "<<m[61]<<" | "<<m[62]<<" | "<<m[63]<<" | "<<m[64]<<" | "<<m[65]<<" | "<<m[66]<<" | "<<m[67]<<" | "<<m[68]<<" | "<<m[69]<<" | "<<m[70]<<" |\n";
    std::cout<<" ---+---+---+---+---+---+---+---+---+---\n";
    std::cout<<"| "<<m[60]<<" | "<<m[59]<<" | "<<m[58]<<" | "<<m[57]<<" | "<<m[56]<<" | "<<m[55]<<" | "<<m[54]<<" | "<<m[53]<<" | "<<m[52]<<" | "<<m[51]<<" |\n";
    std::cout<<" ---+---+---+---+---+---+---+---+---+---\n";
    std::cout<<"| "<<m[41]<<" | "<<m[42]<<" | "<<m[43]<<" | "<<m[44]<<" | "<<m[45]<<" | "<<m[46]<<" | "<<m[47]<<" | "<<m[48]<<" | "<<m[49]<<" | "<<m[50]<<" |\n";
    std::cout<<" ---+---+---+---+---+---+---+---+---+---\n";
    std::cout<<"| "<<m[40]<<" | "<<m[39]<<" | "<<m[38]<<" | "<<m[37]<<" | "<<m[36]<<" | "<<m[35]<<" | "<<m[34]<<" | "<<m[33]<<" | "<<m[32]<<" | "<<m[31]<<" |\n";
    std::cout<<" ---+---+---+---+---+---+---+---+---+---\n";
    std::cout<<"| "<<m[21]<<" | "<<m[22]<<" | "<<m[23]<<" | "<<m[24]<<" | "<<m[25]<<" | "<<m[26]<<" | "<<m[27]<<" | "<<m[28]<<" | "<<m[29]<<" | "<<m[30]<<" |\n";
    std::cout<<" ---+---+---+---+---+---+---+---+---+---\n";
    std::cout<<"| "<<m[20]<<" | "<<m[19]<<" | "<<m[18]<<" | "<<m[17]<<" | "<<m[16]<<" | "<<m[15]<<" | "<<m[14]<<" | "<<m[13]<<" | "<<m[12]<<" | "<<m[11]<<" |\n";
    std::cout<<" ---+---+---+---+---+---+---+---+---+---\n";
    std::cout<<"| "<<m[1]<<" | "<<m[2]<<" | "<<m[3]<<" | "<<m[4]<<" | "<<m[5]<<" | "<<m[6]<<" | "<<m[7]<<" | "<<m[8]<<" | "<<m[9]<<" | "<<m[10]<<" |\n";
    std::cout<<" ---+---+---+---+---+---+---+---+---+---\n";
}


int dice(){//picks random val from 1-6
   std::random_device rd;
   std::default_random_engine eng(rd());
   std::uniform_int_distribution<int> dist(1, 6);
   return dist(eng); 
}

void dierollcall(){ // tp prompt the user to roll the die & assign val
    std::cout<<"plyr "<<k<<" enter d to roll the die: ";
    std::cin>>a;
    if(a=='d'){val=dice();}
    else{
        while(a!='d'){
            std::cout<<"player "<<k<<" enter valid character to roll the die: ";
            std::cin>>a;
            if(a=='d'){
                val=dice();
                break;}
        }
    }
}

void ladder(){ //to handle conditions for ladder
    if((temp+val<=100)){
        m[score[k]]=0;
        score[k]=score[k]+val;
        m[score[k]]=k;
        printboard();
    }
    while(val==6||score[k]==20||score[k]==41||score[k]==70||score[k]==99){ 
        temp=score[k];
        dierollcall();
        m[score[k]]=0; 
        score[k]=score[k]+val;
        m[score[k]]=k;
        printboard();
    }
}

int main() {
    for(i=1;i<=100;i++) {
        m[i]=0; 
    }
    std::cout<<"Enter the number of players: ";
    std::cin>>n;
    k=n;
    while(wins!=n){
        for(k;k!=0;k--){
            temp=score[k];
            dierollcall();
            if((temp+val<=100)){
                m[score[k]]=0;
                score[k]=score[k]+val;
                m[score[k]]=k;
                printboard();
            }    
            while(val==6){ // to repeat when dice val is 6
                temp=score[k];
                dierollcall();
                m[score[k]]=0;
                score[k]=score[k]+val;
                m[score[k]]=k;
                printboard();
            }
            if(score[k]==98){score[k]=63;}//for snakes
            else if(score[k]==87){score[k]=42;}
            else if(score[k]==51){score[k]=1;}
            else if(score[k]==56){score[k]=30;}
            else if(score[k]==45){score[k]=3;}
            else{ 
                    if(score[k]==53){score[k]=70;dierollcall();ladder();}
                    if(score[k]==10){score[k]=20;dierollcall();ladder();}
                    if(score[k]==34){score[k]=41;dierollcall();ladder();}
                    if(score[k]==33){score[k]=70;dierollcall();ladder();}
                    if(score[k]==83){score[k]=99;dierollcall();ladder();}
                }
            
            if(score[k]==100){
                wins++;
                std::cout<<"player "<<k<<" won: "<<wins<<"position";}
        }
        k=n;        
    }
    return 0;
}
    
