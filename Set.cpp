#include <iostream>

int main(){
int cardnum(12);
std::cout << "For each card, please enter the number, color, shading, and shape ie: 1rfd for 1 red full diamond";
    char card[(cardnum*4)-1];
    int num[cardnum-1];
    int color[cardnum-1];
    int shade[cardnum-1];
    int shape[cardnum-1];

    /*
      int num[cardnum-1] = {1,1,3,2,3,3,2,3,3,1,2,2};
    int color[cardnum-1] = {2,2,3,2,2,2,1,2,1,2,1,1};
    int shade[cardnum-1] = {2,3,1,2,2,3,1,3,3,3,3,2};
    int shape[cardnum-1] = {2,3,2,3,3,2,2,3,1,1,1,2};
    */
/*characteristic to number key:
    Number: 1-1     Color:  1-r     Shading: 1-empty    Shape:  1-oval
            2-2             2-g              2-half             2-diamond
            3-3             3-p              3-full             3-squiggle

*/
//table input

    for (int i = 0; i < cardnum; i ++){
        std::cout << std::endl << "Card " << i+1 << ": ";
        std::cin >> num[i];
        std::cin >> color[i];
        std::cin >> shade[i];
        std::cin >> shape[i];
    }
    
    int choice(0);
    while (choice >= 0){ //table output 
        std::cout << "\nWhat card do you want to display?" << std::endl;
        std:: cin >> choice;
        if (choice < 0){
            std::cout <<" finding set...\n";
            break;
        }
        std::cout << "Card #" << choice 
        <<  "\n Number: " << num[choice-1] 
        << "\n Color: " << color[choice-1] 
        << "\n Shade: " << shade[choice-1] 
        << "\n Shape: " << shape[choice-1];
    }
    int numcheck(0);
    int colcheck(0);
    int shadecheck(0);
    int shapecheck(0);
    bool set = false;
    for (int i = 0; i < cardnum; i ++){

        for (int k = i+1; k < cardnum; k ++){
            for (int j = k+1; j < cardnum; j ++){
                numcheck =num[i] + num[k] + num[j]; //add the numbers together
                colcheck =color[i]+color[k]+color[j];
                shadecheck = shade[i]+shade[k]+shade[j];
                shapecheck = shape[i]+shape[k]+shape[j];
                if (numcheck%3 ==0 && colcheck%3 == 0 && shadecheck%3 ==0 && shapecheck%3 ==0){
                    std::cout << "\nnumber match oncards : "<< i+1 <<" " << k+1 <<" " << j+1;
                    set = true;
                }
            }
        }
    }
    if (!set){
        std::cout << "\nThere is not set. :(";
    }
    return 0;
}